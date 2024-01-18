#include <LiquidCrystal.h>

//Crear el objeto LCD con los números correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Variable booleanos que lee el boton de encendido , etc...
boolean parpadeo = false, 
        encendido = false, 
        boton;

// int variables
int analogPin = A5,
    digitalPin = 6,
    ledParpadeo = 10,
	lectura;
// all output pins
int pins[] = {A0, A1, A2, A3, A4, 8, 9, 10};
// length of pins array
int arrLength = sizeof(pins) / sizeof(pins[0]);

// float variables
float HighBlue1 = 1.5;//Umbral de tensión al que se enciende el led
float HighGreen1 = 1.45, 
      HighGreen2 = 1.40,
      MediumYellow1 = 1.35,
      MediumYellow2 = 1.3,
      LowRed1 = 1.20,
      LowRed2 = 1.10;

float NoPila = 0.4, 
	  Voltaje;


void setup() {
  // Inicializar el LCD con el número de  columnas y filas del LCD
  lcd.begin(16, 2);

  pinMode(digitalPin, INPUT);
  // parsing all pins in the pins array
  for (byte i = 0; i < arrLength; i++) {
    //Definicion que el pin sirva en modo *salida*
  		pinMode(pins[i],OUTPUT);
	}
}

void loop() {
  boton = digitalRead(digitalPin);
  
  if(boton) {
    // clear display
    lcd.clear();
	encendido = !encendido;
    
    // Print a message to the LCD.
    encendido 
      ? lcd.print("Script started") 
      : lcd.print("End...");
    
    delay(500);
  }
  
  if(encendido){
    lectura = analogRead(analogPin);
    Voltaje = lectura * 0.0048;
    
    Serial.println(Voltaje);
    lcd.setCursor(0, 0);
    lcd.print("Battery voltage");
    // Ubicamos el cursor en la primera posición(columna:0) de la segunda línea(fila:1)
    lcd.setCursor(0, 1);
    // Escribimos el número de segundos trascurridos
    lcd.print(String(Voltaje) + " volts");
    
    parpadeo = !parpadeo;
    
    // if parpadeo light else unlight 
    parpadeo 
      ? digitalWrite(10,HIGH) 
      : digitalWrite(10,LOW);

    //Condiciónes para revisar si cumple un determinado voltaje
    lightCondition(Voltaje > LowRed2, 8);
    lightCondition(Voltaje > LowRed1, 9);
    lightCondition(Voltaje > MediumYellow2, A0);
    lightCondition(Voltaje > MediumYellow1, A1);
    lightCondition(Voltaje > HighGreen2, A2);
    lightCondition(Voltaje > HighGreen1, A3);
    lightCondition(Voltaje > HighBlue1, A4);
  
  }
  else{
    // apagar todos los leds
    parpadeo = false;
    
     // parsing all pins in the pins array
  	for (byte i = 0; i < arrLength; i++) {
    // apagamos cada led
      digitalWrite(pins[i], LOW);
	}
    
    // clear display
  	lcd.clear();
  }
  delay(100);
}

// function define LED shine
void lightCondition(char condition, int pin) {
  //Condición si cumple un determinado voltaje
  return (condition) ? digitalWrite(pin, HIGH) : digitalWrite(pin, LOW);
}
