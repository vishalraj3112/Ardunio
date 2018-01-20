//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include<Wire.h>

// Set these to run example.
#define FIREBASE_HOST "techteamproject-14b8d.firebaseio.com"
#define FIREBASE_AUTH "xYFEvk3XNhUWCGZcSpT7WamBum7llIIh3GbTx2MB"
#define WIFI_SSID "vishal"
#define WIFI_PASSWORD "01025927"

void setup() {
  Wire.begin();
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;
String myString="";
char c='0';

void loop() {
  Wire.requestFrom(8,9);

    while(Wire.available()){
      c=Wire.read();
      myString.concat(String(c));
      Serial.print(c);
     
     
    }
     
    Serial.println();
    myString.toUpperCase();
    Firebase.setString("siesgst/student/Student_UID",myString);
    delay(1000);
  // set value

  Firebase.setInt("siesgst/student/1/status",10);

  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }

  
  // update value
 
}
