# Nombre del proyecto Soportefresh-DI-

## Visión  del proyecto
El objetivo principal de este proyecto es diseñar y desarrollar un dispositivo innovador que permita a sus usuarios monitorear datos del ambiente, como la temperatura, humedad y luz, proporcionando información valiosa para mejorar su bienestar y comodidad en la vida diaria, aunque el mercado actual cuenta con varios dispositivos que ofrecen monitoreo ambiental, este proyecto se enfoca en integrar estas capacidades en un solo dispositivo portátil que no solo permite al usuario conocer y controlar mejor su entorno, sino que también contribuye a mantener una mayor comodidad en diversas situaciones cotidianas. Este dispositivo beneficiará a una amplia gama de personas, brindándoles mayor control sobre las condiciones ambientales a las que están expuestos.

-Profesionales: Trabajadores de oficinas y profesionales de campo que buscan monitorear las condiciones ambientales, como la temperatura, humedad y luz, para mantener un entorno de trabajo cómodo y saludable.

-Deportistas: Corredores, ciclistas, excursionistas y campistas que necesitan conocer y controlar las condiciones ambientales para optimizar su rendimiento y mantenerse cómodos durante sus actividades.

-Personas con necesidades médicas especiales: Aquellos con problemas de regulación de la temperatura o condiciones de salud crónicas que requieren un monitoreo constante de las condiciones ambientales para asegurar su bienestar y comodidad.

-Público en general: Personas que viven en climas cálidos o usuarios interesados en tecnología de bienestar que desean monitorear el ambiente a su alrededor para mantenerse cómodos y mejorar su calidad de vida.

## Integrantes
- Jesus Fernando Gonzalez Pedroza
- Edna Nazaret Martinez Prado

## Software Empleado

<div align="center">

| ID | Software    | Versión | Tipo                                                    |
|----|-------------|---------|---------------------------------------------------------|
| 01 | Github      | N/A     | Plataforma de alojamiento (licencia libre)              |
| 02 | Arduino IDE | 2.3.2   | Entorno de desarrollo (licencia libre)                  |
| 03 | Krita       | 4.4.3   | Software de pintura digital e ilustración - Licencia pública general GNU (versión 3 o posterior)              |
| 04 | Tinkercad   | N/A     | Herramienta para crear modelos tridimensionales - (Licencia libre)    |
| 05 | Paint       | 22H2    | Programa editor de imágenes desarrollado por Microsoft - (Licencia libre)    |
| 06 | Visual Studio Code | 1.92.2 | Editor de código desarrollado por Microsoft - (Licencia libre) |
| 07 | Flutter | 3.22.2 | Framework de desarrollo de aplicaciones móviles y web desarrollado por Google - (Licencia libre) | 
| 08 | Mosquitto | 2.0.18 | Broker de mensajes MQTT desarrollado por Eclipse Foundation - (Licencia libre) | 
| 09 | HeidiSQL | 12.3.0.6589 | Herramienta de gestión y administración de bases de datos - (Licencia libre) | 
| 10 | Node-RED | 3.1.9 | Plataforma de desarrollo para aplicaciones IoT basada en flujo - (Licencia libre) |

</div>

## Software librerias
<div align="center">

| ID  | Librería              | Versión | Por/Para                                            |
|-----|-----------------------|---------|----------------------------------------------------|
| 01  | Wire                  | -       | Arduino/Comunicación I2C                            |
| 02  | Adafruit GFX Library  | 1.11.5  | Adafruit/Dibujos gráficos básicos                   |
| 03  | Adafruit SSD1306      | 2.5.7   | Adafruit/Controlador de pantalla OLED               |
| 04  | WiFi                  | 1.0     | Arduino/Conectividad WiFi                           |
| 05  | PubSubClient          | 2.8.0   | Nick O’Leary/Cliente MQTT para Arduino              |
| 06  | DHT                   | 1.4.6   | Adafruit/Sensor de temperatura y humedad DHT11      |
| 07  | ArduinoJson           | 6.20.1  | Benoît Blanchon/Manipulación de JSON en Arduino     |

</div>


## Hardware Empleado

<div align="center">

  | Nombre                         | Imagen                                                                                       | Descripción                                     | Cantidad |
  |--------------------------------|----------------------------------------------------------------------------------------------|-------------------------------------------------|----------|
  | ESP32                          | ![Imagen1](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/esp32.jpg)       | Microcontrolador con Wi-Fi y Bluetooth integrado| 1        |
  | USB (Transferencia de datos)   | ![Imagen2](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/usb.jpg)         | Cable estándar para la transferencia de datos   | 1        |
  | Sensor DHT11                   | ![Imagen4](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/dht11.jpg)       | Sensor de temperatura y humedad                 | 1        |
  | Zumbador                       | ![Imagen10](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/zumbador.jpg)   | Dispositivo que emite sonido                    | 1        |
  | Pantalla Oled                      | ![Imagen12](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/Pantalla%20Oled.jpg)   | Dispositivo de visualización                    | 1        |
  | Cables Jumper| ![Imagen13](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/CablesJumper.jpg)|  | 60        |
  | Fotorresistencia                       | ![Imagen14](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/Fotorresistencia.jpg)   | Es una resistencia, cuyo valor en ohmios, varía ante las variaciones de la luz.                    | 1        |

</div>


## Historias de usuario épicas 
### Historia de Usuario Épica 1: Monitoreo de Factores Ambientales y del Usuario
**Como** usuario del dispositivo inteligente,  
**quiero** que el dispositivo pueda detectar y monitorear diversos factores ambientales y corporales,  
**para que** pueda obtener información en tiempo real sobre mi entorno y mi estado de salud.

### Historia de Usuario Épica 2: Activar diversos actuadores conforme a los factores ambientales o del usuario
**Como** usuario del dispositivo inteligente,  
**quiero** que el dispositivo pueda activar diferentes actuadores para diversos propositos conforme a los factores ambientales y corporales,  
**para que** pueda aprovechar las funcionaledades del dispositivo.

### Historia de Usuario Épica 3: Creacion de interfaz para monitoreo y control
**Como** usuario del dispositivo inteligente,  
**quiero** que el dispositivo tenga una interfaz donde pueda monitorear los factores ambientales y corporales ademas de activar a su conveniencia las funcionalidades incorporadas,  
**para que** pueda conocer de manera grafica los factores ambientales y corporales y/o activacion de las funcionaledes del dispositivo.

   
# Prototipo propuesto
## Primer Boceto
![Primer Boceto](https://github.com/Fer33U/Soportefresh-DI-/blob/main/Bocetos/BocetoProyecto.png)

## Arquitectura del proyecto
### Sensores
  -Sensor DHT11 
  -Sensor de luz (Fotorresistencia)
  -Sensor de pulso cardiaco
### Actuadores
  -Ventilador
  -Zumbador
  -Motor de vibración
  -Pantalla oled
### Controladores
  -ESP32
### Plataforma de base de datos
  -SQLite (Posible cambio)
### Protocolo de comunicación
  -MQTT (Message Queuing Telemetry Transport)
### Gestión de energía
  -Bateria recargcable
### Dispositivos receptores y/o transmisores
  -Adaptadores de corriente y conectores
  
## Tablero kanban
A continuacion se puede encontrar el tablero kanban creado en la herramienta de Trello
https://trello.com/invite/b/tsSt2txj/ATTI4163c73ce090c5162d09b6ca5659eec044670458/soportefresh
### Sprint 1
![Sprint 1](https://github.com/Fer33U/Soportefresh-DI-/blob/main/SprintsTrello/SprintsTrello.png) 
  
## Circuito diseñado para el proyecto completo 
| Nombre    | Versión | Sprint | Ilustración  |
|-----------|---------|-------------|---------|
| Ventilador | 1.0.0   | Sprint 1| ![Ilustración](https://github.com/Fer33U/Soportefresh-DI-/blob/main/Circuitos/Ventilador%20V1.0.png)  |

## Resultados
### Sprint 1
  -Encender mini ventilador conforme a la temperatuta ambiente:
  Se logro codificar la funcionalidad de encender el mini ventilador cuando hay una temperatura mayor o igual a 34 grados.
  
  -Codigo:
  
  ![CodigoVentilador](https://github.com/Fer33U/Soportefresh-DI-/blob/main/Sprints/Sprint%201/CodigoVentilador.png) 
  
  -Circuito:
  
  ![CircuitoVentilador](https://github.com/Fer33U/Soportefresh-DI-/blob/main/Sprints/Sprint%201/CircuitoVentilador.jpeg)

  -Conclusiones:
  Se observo que se requiere adquirir componentes nuevos que sean necesarios para poder realizar la funcionalidad de la "linterna", se adquiriran en el siguiente sprint lo necesario para continuar con el proyecto, como sensores y otros actuadores necesarios.




  
