

#include <Servo.h>

// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 2;  // the number of the pushbutton pin
const int ledPin1 = 13;    // the number of the LED pin

const int buttonPin2 = 3;
const int ledPin2 = 14;

const int buttonPin3 = 4;
const int ledPin3 = 15;

const int buttonPin5 = 5;

Servo myservo1, myservo2, myservo3;  // create servo object to control a servo


// variables will change:
int buttonState1 = 0;  // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState5 = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin5, INPUT);

  myservo1.attach(9);
  myservo2.attach(10);
  myservo3.attach(11);

}

// twelve servo objects can be created on most boards

int pos1 = 0;
int pos2 = 0;
int pos3 = 0;    // variable to store the servo position

//void setup() {
  //myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  //myservo2.attach(10);
  //myservo3.attach(11);
//}

//void setup2() {
  //  myservo2.attach(10);
//}

//void setup3() {
  //  myservo3.attach(11);

//}


void loop() {

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState5 = digitalRead(buttonPin5);


  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  /*if (buttonState1 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin1, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin1, LOW);
  }

  if (buttonState2 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin2, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin2, LOW);
  }

  if (buttonState3 == HIGH) {
    // turn LED on:
    digitalWrite(ledPin3, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin3, LOW);
  }*/

  if(buttonState1 == HIGH) {
    if(pos1 <= 180 && buttonState5 == HIGH){
      pos1 += 1;
      myservo1.write(pos1);
      delay(10);
    }
    else if (pos1 > 0 && buttonState5 == LOW){
      pos1 = pos1 - 1;
      myservo1.write(pos1);
      delay(10);

    }
  }

  if(buttonState2 == HIGH) {
    if(pos2 <= 180 && buttonState5 == HIGH){
      pos2 += 1;
      myservo2.write(pos2);
      delay(10);
    }
    else if (pos2 > 0 && buttonState5 == LOW){
      pos2 = pos2 - 1;
      myservo2.write(pos2);
      delay(10);

    }
  }

  if(buttonState3 == HIGH) {
    if(pos3 <= 180 && buttonState5 == HIGH){
      pos3 += 1;
      myservo3.write(pos3);
      delay(10);
    }
    else if (pos3 > 0 && buttonState5 == LOW){
      pos3 = pos3 - 1;
      myservo3.write(pos3);
      delay(10);

    }
  }

    /*for (pos1 = 0; pos1 <= 180; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos1);             // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
    for (pos1 = 180; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos1);
             // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  
  }*/

  /*if( buttonState2== HIGH) {
    for (pos2 = 0; pos2 <= 180; pos2 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos2);             // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
    for (pos2 = 180; pos2 >= 0; pos2 -= 1) { // goes from 180 degrees to 0 degrees
    myservo2.write(pos2);
             // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  
  }

  if(buttonState3 == HIGH) {
    for (pos3 = 0; pos3 <= 180; pos3 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo3.write(pos3);             // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
    for (pos3 = 180; pos3 >= 0; pos3 -= 1) { // goes from 180 degrees to 0 degrees
    myservo3.write(pos3);
             // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  
  }


  /*for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }*/
}
