#include<Wire.h>
void setup() {
  Wire.begin(8);
  Wire.onRequest(requestEvent);
  // put your setup code here, to run once:

}

void loop() {
  delay(100);
  // put your main code here, to run repeatedly:

}

char myChar[4]="abc";
void requestEvent(){
  Wire.write(myChar[3]);
}

