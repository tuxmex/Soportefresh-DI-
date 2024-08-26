#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <ArduinoJson.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define DHTPIN 23
#define DHTTYPE DHT11

#define BOX_WIDTH 50
#define BOX_HEIGHT 20
#define BOX_X ((SCREEN_WIDTH - BOX_WIDTH) / 2)
#define BOX_Y ((SCREEN_HEIGHT - BOX_HEIGHT) / 2 - 10)
#define MAX_TEMPERATURE 40  // Temperatura máxima para llenar la barra

#define LED_PIN 4      // Pin del LED
#define BUZZER_PIN 15  // Pin del buzzer

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Fernando1";
const char* password = "123456789";

const char* mqtt_server = "192.168.108.116";
const int mqtt_port = 1883;
const char* subscribe_topic = "soporte/led_valor";
const char* publish_topic = "soporte/parpadeo";

WiFiClient espClient;
PubSubClient client(espClient);

int currentMenuIndex = 0;
const int menuItemsCount = 4;
bool showData = false;
bool showGraphTemperature = false;
bool showGraphHumidity = false;
unsigned long lastDataUpdate = 0;
unsigned long lastQueryTime = 0;
bool ledBlinking = false;
unsigned long ledBlinkStartTime = 0; // Tiempo de inicio del parpadeo del LED
const unsigned long dataUpdateInterval = 2000;
bool inAlarmMenu = false;           // Estado para saber si estamos en el menú de alarma
int alarmMenuIndex = 0;             // Índice de la opción seleccionada dentro del menú de alarma
const int alarmMenuItemsCount = 2;  // Número de opciones en el menú de alarma


#define MAX_POINTS 3
#define POINT_RADIUS 2
float temperatureHistory[MAX_POINTS] = { 0 };
int temperatureIndex = 0;

float humidityHistory[MAX_POINTS] = { 0 };
int humidityIndex = 0;

int ldrValue = 0;
String lightCondition = "";

float currentTemperature = 0;
float currentHumidity = 0;

// Variables para el buzzer
unsigned long buzzerStartTime = 0;
const unsigned long BUZZER_DURATION = 5000;  // Duración del buzzer en milisegundos
bool buzzerActive = false;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  dht.begin();
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(mqttCallback);
  reconnect();

  // Configurar los pines del LED y del buzzer
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);     // Asegurarse de que el LED esté apagado al inicio
  digitalWrite(BUZZER_PIN, LOW);  // Asegurarse de que el buzzer esté apagado al inicio

  display.clearDisplay();
  updateMenuDisplay();
}

void loop() {
  // Asegurarse de que el cliente MQTT esté conectado
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long currentTime = millis();

  // Consultar el servidor cada 30 segundos
  if (currentTime - lastQueryTime >= 30000) {
    lastQueryTime = currentTime;
    client.publish(publish_topic, "1"); // Publica "1" al tema "soporte/parpadeo" para consultar
  }

  // Manejo del buzzer
  if (currentTemperature >= 30) {
    if (!buzzerActive) {
      buzzerStartTime = millis();
      buzzerActive = true;
      digitalWrite(BUZZER_PIN, HIGH);  // Encender el buzzer
    }
    if (buzzerActive && millis() - buzzerStartTime >= 5000) {
      digitalWrite(BUZZER_PIN, LOW);
      buzzerActive = false;
    }
  } else {
    if (buzzerActive) {
      digitalWrite(BUZZER_PIN, LOW);  // Apagar el buzzer inmediatamente
      buzzerActive = false;
    }
  }

  // Actualización de los datos de sensores y publicación en MQTT
  static unsigned long lastPublishTime = 0;
  if (currentTime - lastPublishTime > 10000) {
    lastPublishTime = currentTime;

    // Leer los valores de los sensores
    currentTemperature = dht.readTemperature();
    currentHumidity = dht.readHumidity();
    ldrValue = analogRead(34);
    lightCondition = (ldrValue <= 100) ? "Luz abundante" : "Luz escasa";

    // Encender el LED si el valor del LDR es mayor o igual a 100
    digitalWrite(LED_PIN, (ldrValue >= 100) ? HIGH : LOW);

    // Publicar los datos de los sensores
    String payload = "Temperatura: " + String(currentTemperature) + "C, Humedad: " + String(currentHumidity) + "%, LDR: " + String(ldrValue);
    if (client.publish("soporte/datos", payload.c_str())) {
      Serial.println("Mensaje publicado con éxito");
    } else {
      Serial.println("Error al publicar el mensaje");
    }
  }

  // Actualizar la pantalla en función del estado del menú
  if (showData) {
    if (millis() - lastDataUpdate > dataUpdateInterval) {
      lastDataUpdate = millis();
      displayData();
    }
  } else if (showGraphTemperature) {
    updateGraphTemperature();
  } else if (showGraphHumidity) {
    updateGraphHumidity();
  } else {
    updateMenuDisplay();
  }

  // Manejo del parpadeo del LED
  blinkLED();
}





void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Conectado");
}

void reconnect() {
  // Loop hasta que el ESP32 esté conectado
  while (!client.connected()) {
    Serial.print("Intentando conexión MQTT...");
    
    // Intentar conectar
    if (client.connect("ESP32Client")) {
      Serial.println("conectado");
      // Suscribirse a los tópicos necesarios
      client.subscribe("soporte/control");
      client.subscribe("soporte/led_valor"); // Suscripción al tópico adicional
    } else {
      // Imprimir el estado de error y esperar antes de reintentar
      Serial.print("fallo, rc=");
      Serial.print(client.state());
      Serial.println(" reintentando en 5 segundos");
      delay(5000);
    }
  }
}


void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String message = "";
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Mensaje recibido en tópico: ");
  Serial.println(topic);
  Serial.print("Mensaje: ");
  Serial.println(message);

  // Manejo de comandos de menú
  if (String(topic) == "soporte/control") {
    if (message == "UP") {
      if (inAlarmMenu) {
        alarmMenuIndex = (alarmMenuIndex - 1 + alarmMenuItemsCount) % alarmMenuItemsCount;
      } else {
        currentMenuIndex = (currentMenuIndex - 1 + menuItemsCount) % menuItemsCount;
      }
    } else if (message == "DOWN") {
      if (inAlarmMenu) {
        alarmMenuIndex = (alarmMenuIndex + 1) % alarmMenuItemsCount;
      } else {
        currentMenuIndex = (currentMenuIndex + 1) % menuItemsCount;
      }
    } else if (message == "SELECT") {
      Serial.print("Seleccionado: ");
      Serial.println(currentMenuIndex);
      if (inAlarmMenu) {
        if (alarmMenuIndex == 0) {
          digitalWrite(BUZZER_PIN, HIGH);  // Activar buzzer
          Serial.println("Buzzer activado");
        } else if (alarmMenuIndex == 1) {
          digitalWrite(BUZZER_PIN, LOW);   // Desactivar buzzer
          Serial.println("Buzzer desactivado");
        }
      } else {
        if (currentMenuIndex == 0) {
          showData = true;
          showGraphTemperature = false;
          showGraphHumidity = false;
        } else if (currentMenuIndex == 1) {
          showData = false;
          showGraphTemperature = false;
          showGraphHumidity = true;
        } else if (currentMenuIndex == 2) {
          showData = false;
          showGraphTemperature = true;
          showGraphHumidity = false;
        } else if (currentMenuIndex == 3) {
          inAlarmMenu = true;
          alarmMenuIndex = 0; // Resetear la selección del menú de alarma
          updateMenuDisplay();
          return; // Salir para evitar la actualización del menú principal
        }
      }
    } else if (message == "BACK") {
      if (inAlarmMenu) {
        inAlarmMenu = false;
        updateMenuDisplay();
      } else {
        Serial.println("Regresando al menú principal");
        showData = false;
        showGraphTemperature = false;
        showGraphHumidity = false;
      }
    }

    updateMenuDisplay();
  } else if (String(topic) == "soporte/led_valor") {
    // Manejo del tópico adicional
    DynamicJsonDocument doc(1024);
    String payloadStr;
    for (int i = 0; i < length; i++) {
      payloadStr += (char)payload[i];
    }

    DeserializationError error = deserializeJson(doc, payloadStr);
    if (error) {
      Serial.print("Error al deserializar JSON: ");
      Serial.println(error.c_str());
      return;
    }

    int led_valor = doc["led_valor"]; // Extrae el valor de "led_valor" del JSON
    Serial.print("Valor de led_valor: ");
    Serial.println(led_valor); // Imprime el valor para depuración

    if (led_valor == 1) {
      Serial.println("Activando parpadeo del LED");
      ledBlinking = true;
      ledBlinkStartTime = millis(); // Reiniciar el tiempo de parpadeo
    } else {
      ledBlinking = false;
      digitalWrite(LED_PIN, LOW); // Apagar el LED si el valor no es 1
    }
  }
}




void displayData() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.println("Temperatura ambiental:");
  display.setCursor(0, 10);
  display.print(currentTemperature);
  display.println(" C");

  display.setCursor(0, 25);
  display.println("Humedad ambiental:");
  display.setCursor(0, 35);
  display.print(currentHumidity);
  display.println(" %");

  display.setCursor(0, 50);
  display.print("LDR: ");
  display.print(lightCondition);

  display.display();
}

void updateGraphTemperature() {
  // Limpiar toda la pantalla
  display.clearDisplay();

  // Configurar el tamaño del texto
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Dibujar el marco de la barra de temperatura
  int boxX = BOX_X;
  int boxY = BOX_Y;
  display.drawRect(boxX, boxY, BOX_WIDTH, BOX_HEIGHT, SSD1306_WHITE);

  // Escalar la temperatura actual para la barra (máximo de 40°C)
  float temperatureRatio = constrain(currentTemperature / MAX_TEMPERATURE, 0, 1);
  int fillWidth = (int)(BOX_WIDTH * temperatureRatio);

  // Dibujar la barra de temperatura rellena
  display.fillRect(boxX, boxY, fillWidth, BOX_HEIGHT, SSD1306_WHITE);

  // Mostrar el dato de la temperatura completamente a la izquierda de la pantalla
  display.setCursor(0, SCREEN_HEIGHT - 10);  // Ajustar la posición del texto a la izquierda
  display.print("Temperatura: ");
  display.print(currentTemperature);
  display.print("C");

  // Mostrar la gráfica
  display.display();
}

void updateGraphHumidity() {
  // Limpiar toda la pantalla
  display.clearDisplay();

  // Configurar el tamaño del texto
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Dibujar el marco de la barra de humedad
  int boxX = BOX_X;
  int boxY = BOX_Y;
  display.drawRect(boxX, boxY, BOX_WIDTH, BOX_HEIGHT, SSD1306_WHITE);

  // Escalar la humedad actual para la barra (máximo de 100%)
  float humidityRatio = constrain(currentHumidity / 100.0, 0, 1);
  int fillWidth = (int)(BOX_WIDTH * humidityRatio);

  // Dibujar la barra de humedad rellena
  display.fillRect(boxX, boxY, fillWidth, BOX_HEIGHT, SSD1306_WHITE);

  // Mostrar el dato de la humedad completamente a la izquierda de la pantalla
  display.setCursor(0, SCREEN_HEIGHT - 10);  // Ajustar la posición del texto a la izquierda
  display.print("Humedad: ");
  display.print(currentHumidity);
  display.print("%");

  // Mostrar la gráfica
  display.display();
}

void updateMenuDisplay() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  if (inAlarmMenu) {
    for (int i = 0; i < alarmMenuItemsCount; i++) {
      display.setCursor(0, i * 10);
      if (i == alarmMenuIndex) {
        display.print("> ");
      }
      if (i == 0) {
        display.print("Activar");
      } else if (i == 1) {
        display.print("Desactivar");
      }
    }
  } else {
    for (int i = 0; i < menuItemsCount; i++) {
      display.setCursor(0, i * 10);
      if (i == currentMenuIndex) {
        display.print("> ");
      }
      if (i == 0) {
        display.print("Datos");
      } else if (i == 1) {
        display.print("Grafica Humedad");
      } else if (i == 2) {
        display.print("Grafica Temperatura");
      } else if (i == 3) {
        display.print("Alarma");
      }
    }
  }

  display.display();
}




void blinkLED() {
  static unsigned long ledBlinkStartTime = 0;
  static unsigned long lastBlinkEndTime = 0;
  static bool ledBlinking = false;
  
  unsigned long currentTime = millis();
  
  if (ledBlinking) {
    // Verificar si han pasado 5 segundos para detener el parpadeo
    if (currentTime - ledBlinkStartTime < 5000) {
      if ((currentTime - ledBlinkStartTime) % 1000 < 500) {
        digitalWrite(LED_PIN, HIGH); // Encender LED
      } else {
        digitalWrite(LED_PIN, LOW); // Apagar LED
      }
    } else {
      digitalWrite(LED_PIN, LOW); // Asegurarse de que el LED esté apagado
      ledBlinking = false;
      lastBlinkEndTime = currentTime;
    }
  } else {
    // Verificar si han pasado 40 segundos para iniciar el parpadeo
    if (currentTime - lastBlinkEndTime >= 40000) {
      ledBlinking = true;
      ledBlinkStartTime = currentTime;
    }
  }
}