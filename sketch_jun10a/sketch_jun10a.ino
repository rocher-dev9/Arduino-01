#include <LiquidCrystal.h>

//Crear el objeto LCD con los números correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int analogPin = A5;
int digitalPin = 6;
int ledParpadeo = 10;
int parpadeo = 0;
int lectura;
int boton; //Variable que lee el boton de encendido
int encendido;
float Voltaje;
float HighBlue1 = 1.5;//Umbral de tensión al que se enciende el led
float HighGreen1 = 1.45;
float HighGreen2 = 1.40;
float MediumYellow1 = 1.35;
float MediumYellow2 = 1.3;
float LowRed1 = 1.20;
float LowRed2 = 1.10;
float NoPila = 0.4;

void setup() {
  // Inicializar el LCD con el número de  columnas y filas del LCD
  lcd.begin(16, 2);
  encendido = 0;
  pinMode(digitalPin, INPUT);
  pinMode(A0,OUTPUT);//Definicion que el pin sirva en modo *salida*
  pinMode(A1,OUTPUT);//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*
  pinMode(A2,OUTPUT);//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*
  pinMode(A3,OUTPUT);//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*
  pinMode(A4,OUTPUT);//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*
  pinMode(8,OUTPUT);//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*
  pinMode(9,OUTPUT);//Definicion que el pin sirva en modo *salida*//Definicion que el pin sirva en modo *salida*
  pinMode(10,OUTPUT);//Definicion que el pin sirva en modo *salida*
}

void loop() {
  
  boton = digitalRead(digitalPin);
  if(boton) {
    encendido = !encendido;
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
    lcd.print(Voltaje);
    lcd.print(" volts");
    
    parpadeo = !parpadeo;
    if(parpadeo) digitalWrite(10,HIGH);
    else digitalWrite(10,LOW);

    if(Voltaje > LowRed2) digitalWrite(8,HIGH);//Condición si cumple un determinado voltaje
    else digitalWrite(8,LOW);//Condición si cumple un determinado voltaje
    if(Voltaje > LowRed1) digitalWrite(9,HIGH);//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje
    else digitalWrite(9,LOW);//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje
    if(Voltaje > MediumYellow2) digitalWrite(A0,HIGH);//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje
    else digitalWrite(A0,LOW);//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje
    if(Voltaje > MediumYellow1) digitalWrite(A1,HIGH);//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje
    else digitalWrite(A1,LOW);//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje
    if(Voltaje > HighGreen2) digitalWrite(A2,HIGH);//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje
    else digitalWrite(A2,LOW);//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje//Condición si cumple un determinado voltaje
    if(Voltaje > HighGreen1) digitalWrite(A3,HIGH);
    else digitalWrite(A3,LOW);//Condición si cumple un determinado voltaje
    if(Voltaje > HighBlue1) digitalWrite(A4,HIGH);//Condición si cumple un determinado voltaje
    else digitalWrite(A4,LOW);//Condición si cumple un determinado voltaje
  
  }
  else{
  	lcd.clear();
  }
  delay(100);
}