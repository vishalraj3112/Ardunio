int analogPin = 0;// potentiometer wiper (middle terminal) connected to analog pin 3
int analogPin1=1;
int analogPin2=3;
                       // outside leads to ground and +5V

int val = 0;  // variable to store the value read
int val1 =0;
int val2=0;


void setup()

{

  Serial.begin(9600);  
  pinMode(6,OUTPUT);//  setup serial

}



void loop()

{

  val = analogRead(analogPin); 
   val1=analogRead(analogPin1);
   val2=analogRead(analogPin2);
   // read the input pin

   
  Serial.print("Wire 1 value:");
  Serial.print(val);// debug value
 Serial.println("  ");
 Serial.print("Wire 2 value:");
 Serial.println(val1);
 Serial.println("  ");
 Serial.print("Wire 3 value:");
 Serial.println(val2);
 delay(1000);
 if( val==1023 && val1==0 &&val2<=150 &&val2>=50)
 {digitalWrite(6,HIGH);
}
}
 
