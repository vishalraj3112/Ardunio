//blue team
#include <IRLib.h>
#include <EEPROM.h>
#define btnAddr 0
#define dthAddr 1

int RECV_PIN = 2;
int btn=5;
long debounce=200;


int flag = 0;
int btncnt = 0; //no. of bullets
int read2 = 0;
long time = 0;
int read;
int disableSend = 0;
long l = 0;

int dth = 0;
int led = 1;
long t1 = 0;
int t3 = 0;
int flag1 = 0;
int oldValue = 0;

int flag2=0;

IRrecv My_Receiver(RECV_PIN);
IRsend My_Sender;

IRdecode My_Decoder;
unsigned int Buffer[RAWBUF];

void setup()
{
  Serial.begin(9600);
  pinMode(btn,INPUT);
   dth=EEPROM.read(dthAddr);
  btncnt=EEPROM.read(btnAddr);

  My_Receiver.enableIRIn(); // Start the receiver
  My_Decoder.UseExtnBuf(Buffer);
}

void checkForInput(){
    if (My_Receiver.GetResults(&My_Decoder)) {
    //Restart the receiver so it can be capturing another code
    //while we are working on decoding this one.
     
    My_Decoder.decode();
    TIMSK2 = 0;  
    if(My_Decoder.value == 29986)
      {
        EEPROM.write(btnAddr,0);
        EEPROM.write(dthAddr,0);
        btncnt=EEPROM.read(btnAddr);
        dth=EEPROM.read(dthAddr);
      }
    if (My_Decoder.value == 3021 && dth <= 20)
    {
      dth++;
      EEPROM.write(dthAddr,dth);
      digitalWrite(buzz, HIGH);
      delay(200);//500 se change kiya
     
      //Serial.println("inside receiver loop right");
      //Serial.println(My_Decoder.value, HEX);
      delay(100);
    }
    //My_Decoder.DumpResults();

    Serial.println("inside receiver loop");
    Serial.println(My_Decoder.value,HEX);
    delay(100); 
    My_Receiver.resume();
    My_Receiver.enableIRIn();
  //  My_Receiver.resume();
  }
  
  }
void loop() {

  
  //if (Serial.read() != -1) {
    read = digitalRead(btn);
  if (read == LOW && millis() - time > debounce)
  { 
    if (btncnt < 500 && flag1==0)
    {
      //Serial.println("send loop");
      My_Sender.send(RC5, 0xbcd, 20); //data to be sent
     
     
      Serial.println(btncnt);
      btncnt++;
      EEPROM.write(btnAddr,btncnt);
      if(btncnt>=500)
      {
        flag1=1;
      }
    }
    My_Receiver.enableIRIn();
    checkForInput();
    My_Receiver.enableIRIn();
    time = millis();
    
  }
  if (flag1 == 1 || flag2==1)
    {
      //Serial.println("set hua flag");
      lcd.clear();
      lcd.setCursor(2,0);
      //Serial.println("GAME OVER!!!");
      lcd.print("GAME OVER!!!");
      digitalWrite(buzz,HIGH);
      digitalWrite(rumble,HIGH);
      delay(10000);
    }
  checkForInput();
}
