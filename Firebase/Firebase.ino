#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>



#include "SoftwareSerial.h"




#define FIREBASE_URL''paramters-1e66b.firebaseio.com''
#define FIREBASE_SERECT ''cglExw7hQD2u5ojNaTrcu2rXdRsFsvBM4BG48uy3''
#define WIFI_SSID ''Virgo1409''
#define WIFI_PASSWORD ''Quangtuan140998''

#define SENSOR A0            //pH meter Analog output to Arduino Analog Input 0
#define OFFSET 30.32            //deviation compensate
#define LED 13
#define SAMPLING_INTERVAL 20
#define PRINT_INTERVAL 800
#define ARRAY_LENGTH  40    //times of collection

String mystring;
//int PH_ARRAY[ARRAY_LENGTH];   //Store the average value of the sensor feedback
//int PH_ARRAY_INDEX=0;    
float ph = A0;
float ph_data = 0;

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(ph ,INPUT);
  // connect to wifi.
  pinMode(D0,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
      {
    Serial.print(".");
    delay(500);
      }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_URL, FIREBASE_SERECT);
 
   Firebase.setString("PH value","empty");
}
void loop()
{
 
ph_data = analogRead(ph);
myString = String(ph_data); 
Serial.println(myString); 
Firebase.setString("Ph_value",myString);
delay(2000);            
}
