# Casa-Bluetooh

# Proyecto: Control de Puertas con Servomotores y Bluetooth

## Descripción

Este proyecto permite controlar servomotores para abrir y cerrar dos pisos de una casa utilizando un módulo Bluetooth HC-06 y un Arduino. A través de una aplicación o dispositivo Bluetooth, se envían comandos para mover los servos a posiciones específicas, lo que simula la apertura y cierre de puertas en un sistema automatizado.

## Componentes

- **Arduino Uno** o cualquier otra placa compatible con Arduino.
- **Módulo Bluetooth HC-06**.
- **2 Servomotores o mas** para controlar las puertas de los dos pisos.
- **Cables y Protoboard** para las conexiones.

## Conexiones

- **Servos**:
  - Servomotor 1 (primer piso): Pin 9.
  - Servomotor 2 (primer piso): Pin 10.
  - Servomotor 3 (segundo piso): Pin 11.
  - Servomotor 4 (segundo piso): Pin 12.

- **Módulo Bluetooth HC-05**:
  - VCC → 5V
  - GND → GND
  - TX → Pin 10 (RX del Arduino)
  - RX → Pin 11 (TX del Arduino)

## Instrucciones

1. **Configuración del Hardware**:
   - Conecta los servomotores a los pines especificados de tu placa Arduino.
   - Conecta el módulo Bluetooth HC-05 a los pines RX y TX del Arduino.
   - Conecta la alimentación del Arduino al puerto USB de tu computadora.

2. **Carga del Código**:
   - Abre el archivo de código en el IDE de Arduino y selecciona la placa y el puerto correctos.
   - Sube el código al Arduino.

3. **Uso del Bluetooth**:
   - Empareja tu dispositivo Bluetooth (móvil o PC) con el módulo HC-05.
   - Una vez emparejado, abre una terminal Bluetooth (puedes usar una aplicación como "Bluetooth Terminal" en Android).
   - Envía los siguientes comandos para controlar los servomotores:
     - **C1**: Abrir primer piso.
     - **C2**: Cerrar primer piso.
     - **C3**: Abrir segundo piso.
     - **C4**: Cerrar segundo piso.
     - **C5**: Abrir ambos pisos.
     - **C6**: Cerrar ambos pisos.

4. **Monitoreo Serial**:
   - Abre el monitor serial en el IDE de Arduino para ver los mensajes y los comandos que recibe el Arduino.

## Funcionalidad

El código implementado permite mover los servos de manera independiente o conjunta, controlados por comandos enviados a través del Bluetooth. El Arduino interpreta los comandos recibidos y mueve los servomotores a las posiciones deseadas, simulando la apertura y cierre de puertas en la estructura. Todo con el fin de abrir el techo del primer y segundo piso de una casa domotica.

