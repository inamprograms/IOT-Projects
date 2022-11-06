#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

WiFiClient client;  
String request;
HTTPClient http;

const int trigPin = D6;
const int echoPin = D5;

long duration;
int distance;

void setup() {
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);   
  Serial.begin(9600);

  WiFi.disconnect();
  WiFi.begin("Inam ul Rehman","in123456");
  while(!(WiFi.status() == WL_CONNECTED)){
    Serial.println("<con>");
    delay(100);
    }
}



void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);
  distance = (duration * .0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
//  Serial.print("Duration: ");
//  Serial.println(duration);
  delay(100);

  if(client.connect("api.thingspeak.com",80)){
    request = "http://api.thingspeak.com/apps/thinghttp/send_request?api_key=2T9K1JBYFQ4PSFH7&distance=";
    request += "Dustbin is full";
    if(distance <= 10)
    {
      http.begin(client , request);
      http.GET();
      http.end();
      Serial.println("Request sent!");
      Serial.println(request);
      
      }
      delay(100);
    }

} 
