#include <SoftwareSerial.h> // Librería para usar el puerto serial con el módulo Bluetooth
#include <Servo.h> 

Servo primerPisoServo1;  //creamos un objeto servo 
Servo primerPisoServo2;  //creamos un objeto servo 


Servo segundoPisoServo1;  //creamos un objeto servo 
Servo segundoPisoServo2;  //creamos un objeto servo 

// pines servos
int pinPrimerPisoServo1 = 3;
int pinPrimerPisoServo2 = 5;
int pinSegundoPisoServo1 = 6;
int pinSegundoPisoServo2 = 9;

// angulos
int posMinP1 = 90;
int posMaxP1 = 180;

int posMaxP2 = 90;
int posMinP2 = 180;

// Definir los pines para el módulo Bluetooth HC-05
SoftwareSerial BTSerial(10, 11); // RX, TX

void setup() {
  primerPisoServo1.attach(pinPrimerPisoServo1);
  primerPisoServo2.attach(pinPrimerPisoServo2);

  segundoPisoServo1.attach(pinSegundoPisoServo1);
  segundoPisoServo2.attach(pinSegundoPisoServo2);

  // mover a posicion minima servos
  primerPisoServo1.write(posMinP1);
  primerPisoServo2.write(posMinP1);

  segundoPisoServo1.write(posMinP2);
  segundoPisoServo2.write(posMinP2);


  Serial.begin(9600); // Iniciar el puerto serial para la PC
  BTSerial.begin(9600); // Iniciar el puerto serial para el Bluetooth a 9600 baudios

  Serial.println("Esperando datos desde Bluetooth...");
}

void loop() {

  String comando = leerDatos(); // Llamar a la función para leer datos

  moverCasa(comando);
  
  if (comando != '\0') { // '\0' significa que no se recibió ningún dato
    Serial.print("comando: ");
    Serial.println(comando); // Mostrar el dato recibido en el monitor serie
  }
}




void moverCasa( String comando){
    if (comando == "C1") {
    Serial.println("abrir primer piso");
    primerPisoServo1.write(posMaxP1);
    primerPisoServo2.write(posMaxP1);
  } 
  else if (comando == "C2") {
    Serial.println("cerrar primer piso");
    primerPisoServo1.write(posMinP1);
    primerPisoServo2.write(posMinP1);
  } 
  else if (comando == "C3") {
    Serial.println("abrir segundo piso");
    segundoPisoServo1.write(posMaxP2);
    segundoPisoServo2.write(posMaxP2);
  } 
  else if (comando == "C4") {
    Serial.println("cerrar segundo piso");
    segundoPisoServo1.write(posMinP2);
    segundoPisoServo2.write(posMinP2);
  } 
  else if (comando == "C5") {
    Serial.println("abrir ambos pisos");
    primerPisoServo1.write(posMaxP1);
    primerPisoServo2.write(posMaxP1);
    segundoPisoServo1.write(posMaxP2);
    segundoPisoServo2.write(posMaxP2);
  } 
  else if (comando == "C6") {
    Serial.println("cerrar ambos pisos");
    primerPisoServo1.write(posMinP1);
    primerPisoServo2.write(posMinP1);
    segundoPisoServo1.write(posMinP2);
    segundoPisoServo2.write(posMinP2);
  } 
  else {
    Serial.println("Comando no reconocido");
  }
}


// Función para leer datos desde el módulo Bluetooth y retornar el carácter recibido
String leerDatos() {
  String comando = "";
  
  // Leer primer carácter
  if (BTSerial.available()) {
    char primerCaracter = BTSerial.read(); // Leer el primer carácter
    comando += primerCaracter; // Añadir el primer carácter al comando

    // Esperar a que el segundo carácter esté disponible
    while (!BTSerial.available()) {
    }

    // Leer segundo carácter
    char segundoCaracter = BTSerial.read(); // Leer el segundo carácter
    comando += segundoCaracter; // Añadir el segundo carácter al comando
  }

  return comando; 
}

