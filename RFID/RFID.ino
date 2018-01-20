#include <SPI.h>
#include <MFRC522.h>
#include<Wire.h>
#include<LiquidCrystal.h>
int buzzer=8;
char charBuf[14];
//int button=2;
//int i=0, buzz =8;
//int ldrStatus

//int btns =2;

 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);// Create MFRC522 instance.
 LiquidCrystal lcd(7,6,5,4,3,2);
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(5,0);
  lcd.print("Welcome");
  Wire.begin(8);
  Wire.onRequest(requestEvent);
   Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();
  
  pinMode(buzzer,OUTPUT);
  //pinMode(button,INPUT);
  //Serial.begin(9600);
   //attachInterrupt(1,interrupt1, RISING);   
}


void loop() {


funk();
//  q();
  if(millis()<=60000)
  {
      if((millis()/1000)%10==0)
      {
          func1(100);
          delay(1000);
      }
  }
  if(millis()>60000 && millis()<=120000)
  {
      if(((millis()/1000)-60)%7==0)
      {
          func1(100);
          delay(1000);
      }
  }
  if(millis()>120000 && millis()<=170000)
  {
       if(((millis()/1000)-120)%4==0)
       {
          func1(100);
          delay(1000);
       }
  }
   if(millis()>170000 && millis()<=180000)
  {
       if((millis()/1000)%1==0)
       {
          func1(60);
          delay(1000);
       }
  }

}  
/*
  
if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
     
  }//Show UID on serial monitor
  Serial.print("UID tag :");
  String content1= " ";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
     
  }
  
  Serial.println();
  Serial.print("Message : ");
  int flag=0;
  content.toUpperCase();
  if (content.substring(1) == "E5 B1 5F 1C") //change here the UID of the card/cards that you want to give access
{ //Serial.print(content.substring(1) );

     //flag=1;
 //   int x=millis();
    delay(1000);
    fuck();
    return();
   // else
 //{   
 if(flag==10)
 {last();
 }
 }
  //  break();
// 

  
 
 else   {
    Serial.println(" Access denied");
  }
  /*goto PQR;
  ABC: last();
  PQR: ;
*/
 String stringone;
  

void funk(){
  //int flag=0;
  static int flag=0;
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
 return;
    //flag++;
  }
 
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    //flag++;
  //return;
  }
  //Show UID on serial monitor
//delay(1000);
 // Serial.print(flag);
//  return;
  /*if(flag>=10)
   {last();
   }
    */
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  
  
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
//     letter=byte(mfrc522.uid.uidByte[i],HEX);
     
      
     stringone=String(mfrc522.uid.uidByte[i],HEX);
    
   
    content.toCharArray(charBuf,14);
    
   
      

     
    
     //flag++;
  }


  Serial.println();
 
  content.toUpperCase();
  
  Serial.print("Message : ");
 
 
  
  if(content.substring(1) == "E5 B1 5F 1C" ) //change
//   here the UID of the card/cards that you want to give access
  {flag++;
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Authorised...");
     //Serial.println("going");
    
  
  // content.substring(1) = "E5 B1 5F 1B";
  delay(3000);
   Serial.println(flag);
 
    Serial.println();
    
    if(flag>=10)
   {
    last();
   }
    
    }
 //    
  
//  
//}
 else   {
  Serial.println(" Access denied");
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("Access denied!");
   delay(3000);
 }
 lcd.clear();
 lcd.setCursor(5,0);
 lcd.print("Welcome");
  

  }
  void requestEvent(){
  //int time2=0;
  //int time1=millis();
  //while(time2<=time1+5000){
    
 for(int i=0;i<16;i++){
  Serial.print(charBuf[i]);
 Wire.write(charBuf[i]); 
 }
  //time2=millis();
  }
  

 
byte letter;
 
  

  void func1(int x) {
    digitalWrite(buzzer,HIGH);
    delay(x);
    digitalWrite(buzzer,LOW);
}
void last()
{
  Serial.println(" done");
  // digitalWrite(buzzer,HIGH);
    //delay(500);
 //digitalWrite(buzzer,LOW);

}

 
  
  

