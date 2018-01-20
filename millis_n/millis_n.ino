unsigned long x;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
x = millis();
Serial.print("Time");
Serial.println(x);
}
