
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int upButtonState = 0;
int downButtonState = 0;

void setup() {
  myservo.attach(2);  // attaches the servo on pin 2 to the servo object
  //pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  myservo.write(0);
}


void loop() {
  // button
  upButtonState = digitalRead(A1); // up 
  downButtonState = digitalRead(A0); // down 
  if (upButtonState == HIGH) {
    if (pos < 110) {
      pos = pos + 1;
      myservo.write(pos);
    }
    //Serial.println("hi");
  }
  if (downButtonState == HIGH) {
    if (pos > 0) {
      pos = pos-1;
      myservo.write(pos); 
    }
  }
  
  delay(10);


  // potentiometer... FAIL :(
  /*
  int potValue = analogRead(A0);
  Serial.println(potValue);
  myservo.write(potValue * 0.17); // convert a 0-1023 to 0-180
  */
  //delay(1); // add a 1s delay before reading the potentiometer again


  // old code for just looping back and forth
  /*
  for (pos = 150; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }*/
 
}
