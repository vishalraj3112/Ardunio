/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0; // variable to store the servo position
int x=0;
int x1=0;

void setup() {
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);
}

void loop() {
  x=digitalRead(2);
  x1=digitalRead(3);
  if(x==HIGH){
    myservo.write(180);
    Serial.print("1\n");
  }if(x1==HIGH){
    myservo.write(120);
    Serial.print("2\n");
  }
  else 
  {myservo.write(150);
  Serial.print("0\n");
  
}
}
