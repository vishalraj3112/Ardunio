void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT_PULLUP);
Serial.begin(19200);

}
int x=0;

void loop() {
 if(digitalRead(2)==HIGH)
 {Serial.println("l");
 }else
 {}
 delay(500);
  
  // put your main code here, to run repeatedly:

}
