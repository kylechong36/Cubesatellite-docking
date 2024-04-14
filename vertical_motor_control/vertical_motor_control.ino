// Arduino prototyping stepper motor 
// Last edited 2/9/2024 by Kyle Chong

// Define pins

#include <avr/io.h>
#include <avr/interrupt.h>

/*int driverPUL = 7;    // PUL- pin
int driverDIR = 6;    // DIR- pin
int driverON = 10;     // Turns driver on/off
int spd = A0;       // Potentiometer
int Value = 0;*/

int driverPUL = 2;
int driverDIR = 3;
int driverONx = 4;
int driverONy = 5;
int driverONz = 6;

float frequency;
int direction;
int motor;
 
// Variables
 
int pd = 500;       // Pulse Delay period
float spd = 0;
 
void setup() {
 
  //pinMode (2, INPUT);
  //pinMode (5, INPUT);
  pinMode (driverPUL, OUTPUT);
  pinMode (driverDIR, OUTPUT);
  pinMode (driverONx, OUTPUT);
  pinMode (driverONy, OUTPUT);
  pinMode (driverONz, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {


    Serial.println("Which motor would you like to use");
    Serial.println("0 = x, 1 = y, 2 = z");

    while (Serial.available() != 0) {
      Serial.read();
    }
    while (Serial.available() == 0) {
    }

    motor = Serial.parseInt();

    switch(motor) {

      case 0:
      digitalWrite(driverONx, LOW);
      digitalWrite(driverONy, HIGH);
      digitalWrite(driverONz, HIGH);
      break;

      case 1:

      digitalWrite(driverONx, HIGH);
      digitalWrite(driverONy, LOW);
      digitalWrite(driverONz, HIGH);
      break;

      case 2:

      digitalWrite(driverONx, HIGH);
      digitalWrite(driverONy, HIGH);
      digitalWrite(driverONz, LOW);
      break;

    }

    Serial.println("Enter Frequency");

    while (Serial.available() != 0) {
      Serial.read();
    }

    while (Serial.available() == 0) {
    }
    frequency = Serial.parseInt();

    Serial.println("Enter Direction");

    while (Serial.available() != 0) {
      Serial.read();
    }

    while (Serial.available() == 0) {
    }
    direction = Serial.parseInt();

    if (direction)
      digitalWrite(driverDIR,HIGH);

    else if (!direction)
      digitalWrite(driverDIR,LOW);

    spd = (1/frequency)*1000;

    for (int i = 0; i <1000; i++){
    digitalWrite(driverPUL, HIGH);
    delay(spd);
    digitalWrite(driverPUL,LOW);
    delay(spd);
}
  Serial.println(spd);
}