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
| ESP32                          | ![Imagen1](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/esp32.jpg)           | Microcontrolador con Wi-Fi y Bluetooth integrado | 1        |
| USB (Transferencia de datos)   | ![Imagen2](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/usb.jpg)             | Cable estándar para la transferencia de datos    | 1        |
| Sensor DHT11                   | ![Imagen4](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/dht11.jpg)           | Sensor de temperatura y humedad                  | 1        |
| Zumbador                       | ![Imagen10](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/zumbador.jpg)       | Dispositivo que emite sonido                     | 1        |
| Pantalla Oled                  | ![Imagen12](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/Pantalla%20Oled.jpg)| Dispositivo de visualización                     | 1        |
| Cables Jumper                  | ![Imagen13](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/CablesJumper.jpg)   | Cables para conexiones                           | 60       |
| Fotorresistencia               | ![Imagen14](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/Fotorresistencia.jpg)| Resistencia que varía según la luz               | 1        |
| Batería recargable             | ![Imagen15](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/bateriarecarcable.jpg)| Fuente de energía portátil                       | 1        |
| LED                            |![Imagen16](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/leds.jpg)| Diodo emisor de luz                              | 2        |
| Tela                           |![Imagen17](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/tela.jpg)| Material textil                                  | 40 cm    |
| Hilo                           |![Imagen18](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/hilo.jpg)| Material de costura                              | 1 rollo  |
| Relleno de poliéster           |![Imagen19](https://github.com/Fer33U/Soportefresh-DI-/blob/main/hardware/relleno.jpg)| Material para relleno                            | 200 gr   |


</div>


## Historias de usuario épicas 
### Historia de Usuario Épica 1: Monitoreo de Factores Ambientales
**Como** usuario del dispositivo inteligente,  
**quiero que** el dispositivo pueda detectar y monitorear diversos factores ambientales,  
**para que** pueda obtener información en tiempo real sobre mi entorno.

---
### Historia de Usuario Épica 2: Activar Diversos Actuadores Conforme a los Factores Ambientales.
**Como** usuario del dispositivo inteligente,  
**quiero que** el dispositivo pueda activar diferentes actuadores para diversos propósitos conforme a los factores ambientales,  
**para que** pueda aprovechar las funcionalidades del dispositivo.

---
### Historia de Usuario Épica 3: Creación de Interfaz para Monitoreo y Control
**Como** usuario del dispositivo inteligente,  
**quiero que** el dispositivo tenga una interfaz donde pueda monitorear los factores ambientales, además de activar a su conveniencia las funcionalidades incorporadas,  
**para que** pueda conocer de manera gráfica los factores ambientales y/o la activación de las funcionalidades del dispositivo.

   
# Prototipo propuesto
## Primer Boceto
![Primer Boceto](https://github.com/Fer33U/Soportefresh-DI-/blob/main/Bocetos/BocetoProyecto.png)

## Arquitectura del Proyecto

### Sensores
- Sensor DHT11
- Sensor de luz (fotorresistencia)

### Actuadores
- Zumbador
- Pantalla OLED
- LEDs

### Controladores
- ESP32

### Plataforma de Base de Datos
- HeidiSQL

### Protocolo de Comunicación
- MQTT (Message Queuing Telemetry Transport)

### Gestión de Energía
- Batería recargable

### Dispositivos Receptores y/o Transmisores
- Adaptadores de corriente y conectores

  
## Tablero kanban
A continuacion se puede encontrar el tablero kanban creado en la herramienta de Trello
https://trello.com/invite/b/tsSt2txj/ATTI4163c73ce090c5162d09b6ca5659eec044670458/soportefresh
### Sprints
![Sprints](https://github.com/Fer33U/Soportefresh-DI-/blob/main/Sprints/SPRINTS.png) 
  
## Circuito diseñado para el proyecto completo 
| Nombre    | Versión | Sprint  | Ilustración  |
|-----------|---------|---------|--------------|
| Ventilador | 1.0.0   | Sprint 1 | ![Ilustración](https://github.com/Fer33U/Soportefresh-DI-/blob/main/Circuitos/Ventilador%20V1.0.png) |
| Ventilador | 2.0.0   | Sprint 3 | ![Ilustración2](https://github.com/Fer33U/Soportefresh-DI-/blob/main/Circuitos/CirtcuitoFinal.png) |


## Resultados
### Sprint 1
  - Encender mini ventilador conforme a la temperatuta ambiente:
  Se logro codificar la funcionalidad de encender el mini ventilador cuando hay una temperatura mayor o igual a 34 grados.
  
  - Codigo:
  
  ![CodigoVentilador](https://github.com/Fer33U/Soportefresh-DI-/blob/main/Sprints/Sprint%201/CodigoVentilador.png) 
  
  - Circuito:
  
  ![CircuitoVentilador](https://github.com/Fer33U/Soportefresh-DI-/blob/main/Sprints/Sprint%201/CircuitoVentilador.jpeg)

  - Conclusiones:
  Se observo que se requiere adquirir componentes nuevos que sean necesarios para poder realizar la funcionalidad de la "linterna", se adquiriran en el siguiente sprint lo necesario para continuar con el proyecto, como sensores y otros actuadores necesarios.

### Sprint 2
  - Descripción:
    Durante este sprint se implementaron cambios significativos en el backlog, las historias de usuario y la arquitectura del proyecto. Se redefinió el objetivo y el enfoque del desarrollo, ya que se encontraron complicaciones importantes en la activación del ventilador y los motores de vibración. Estos desafíos llevaron a una reevaluación del proyecto para abordar mejor las dificultades encontradas.
    
  - Conclusiones:
    Se decidió realizar ajustes en los componentes y en el enfoque del proyecto para superar las complicaciones experimentadas. Estos cambios permitirán un desarrollo más eficiente y adaptado a las necesidades detectadas durante el sprint.

### Sprint 3
  - Descripción:
    En este sprint se completó la configuración del código para el ESP32 y del aplicativo en Flutter, garantizando su interconexión con las funcionalidades y gráficos previstos. Además, se construyó el collarín utilizando tela, se ensambló el circuito en su totalidad y se llevaron a cabo pruebas exhaustivas para verificar el correcto funcionamiento del sistema.
- Código
Podrás encontrar el código de todo el proyecto correspondiente a lo siguiente:
  - **App Flutter**: [Ruta a la URL](http://example.com/flutter-app)
  - **Arduino IDE**: [Ruta a la URL](https://github.com/Fer33U/Soportefresh-DI-/tree/main/Sprint%203/Arduino%20IDE)
  - **Node-RED**: [Ruta a la URL](https://github.com/Fer33U/Soportefresh-DI-/tree/main/Sprint%203/Node-red)

- Circuito
![CircuitoFinal](https://github.com/Fer33U/Soportefresh-DI-/blob/main/Sprint%203/Circuito.jpeg)
- Conclusiones:
    El desarrollo del proyecto enfrentó diversas complicaciones y requirió ajustes significativos para la finalización del dispositivo. No obstante, este proceso ha sido altamente educativo, proporcionando unaintegrac comprensión profunda sobre la ión de software y hardware en aplicaciones diversas. La experiencia adquirida será invaluable para futuros proyectos que exijan una combinación efectiva de ambas disciplinas.




  
