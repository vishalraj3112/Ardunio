void setup() {
pinMode(2,INPUT_PULLUP);
pinMode(3,INPUT_PULLUP);
pinMode(4,INPUT_PULLUP);
pinMode(5,INPUT_PULLUP);
Serial.begin(9600);

}

void loop() {
  if(digitalRead(2)==LOW){
    Serial.println("l"); 
  }
  else if(digitalRead(3)==LOW){
    Serial.println("r");
  }
   else if(digitalRead(4)==LOW){
    Serial.println("d");
  }
   else if(digitalRead(5)==LOW){
    Serial.println("u");
  }
 
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
    
  delay(30);
  // put your main code here, to run repeatedly:

}
