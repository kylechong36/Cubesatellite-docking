#include "LIDARLite_v4LED.h"

LIDARLite_v4LED myLIDAR; //Click here to get the library: http://librarymanager/All#SparkFun_LIDARLitev4 by SparkFun

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
  Serial.begin(115200);
  Serial.println("Connection test");
  Wire.begin(); //Join I2C bus

  //check if LIDAR will acknowledge over I2C
  if (myLIDAR.begin() == false) {
    Serial.println("Device did not acknowledge! Freezing.");
    while(1);
  }
  Serial.println("LIDAR acknowledged!");

  pinMode (driverPUL, OUTPUT);
  pinMode (driverDIR, OUTPUT);
  pinMode (driverONx, OUTPUT);
  pinMode (driverONy, OUTPUT);
  pinMode (driverONz, OUTPUT);

}

void loop() {


    Serial.println("Auto move x, or manually move y or z");
    Serial.println("0 = x(auto), 1 = y, 2 = z");

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
      automove();
      //manualmove();
      break;

      case 1:

      digitalWrite(driverONx, HIGH);
      digitalWrite(driverONy, LOW);
      digitalWrite(driverONz, HIGH);
      manualmove();
      break;

      case 2:

      digitalWrite(driverONx, HIGH);
      digitalWrite(driverONy, HIGH);
      digitalWrite(driverONz, LOW);
      manualmove();
      break;

    }
}

void automove() {

  float distance = getDistance(distance)*39.37;

  digitalWrite(driverDIR, HIGH);
  Serial.println(distance);

  
  for (int i=0; i <distance*1000; i++){
  digitalWrite(driverPUL, HIGH);
  delay(1);
  digitalWrite(driverPUL,LOW);
  delay(1);
  }
  

  // Assuming getDistance() returns the distance
 // while (distance >= 0.1) {
    // Measure distance and store the result
    //delay(300);
   // distance = getDistance(distance);
   // digitalWrite(driverPUL, HIGH);
   // delay(1);
  //  digitalWrite(driverPUL,LOW);
  //  delay(1);
 // }
  //analogWrite(driverPUL, 0);
}


void manualmove() {

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

/* void testmove(bool k) {

  if (k== true) {
    for(int i = 0; i < 10; i++){
    digitalWrite(driverPUL, HIGH);
    delay(1);
    digitalWrite(driverPUL,LOW);
    delay(1);
      digitalWrite(driverPUL, HIGH);
    delay(1);
    digitalWrite(driverPUL,LOW);
    delay(1);
      digitalWrite(driverPUL, HIGH);
    delay(1);
    digitalWrite(driverPUL,LOW);
    delay(1);
    }
  }

  else
    digitalWrite(driverPUL, HIGH);
}
*/

float getDistance(float distance) {
  float newDistance(distance);

  //getDistance() returns the distance reading in cm
  newDistance = myLIDAR.getDistance();
  newDistance = newDistance/140;

  //Print to Serial port
  Serial.print(newDistance);
  Serial.println(" m");
  delay(20);  //Don't hammer too hard on the I2C bus
  return(newDistance);
}
