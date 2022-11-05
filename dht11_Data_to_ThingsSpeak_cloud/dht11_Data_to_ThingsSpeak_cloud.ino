#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define DHTTYPE DHT11

WiFiClient client;      
int DHTPin = 13; 
int var;
float temp,hum;
String request_string;
String thingsSpeakAddresss = "https://api.thingspeak.com/update?";
HTTPClient http;
DHT dht(DHTPin, DHTTYPE);
void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(DHTPin,INPUT);
  WiFi.disconnect();
  WiFi.begin("Inam ul Rehman", "in123456");
  while(!(WiFi.status()== WL_CONNECTED)){
    Serial.println("<con>");
    delay(300);
    }
  }

void loop() {
   long state = digitalRead(DHTPin);
   if(state == 1)
   {
      var = 1;
      Serial.println("Sensor is reading data");
      thingSpeakUpdate();
      delay(1000);
    }
    else
    {
      var = 0;
      Serial.println("Sensor is not reading data");
      thingSpeakUpdate(); 
      delay(1000);
      }

  hum = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.println(hum);
  Serial.print("Temperature: ");
  Serial.println(temp);
}

void thingSpeakUpdate(){
  if(client.connect("api.thingspeak.com",80)){
      request_string = thingsSpeakAddresss;
      request_string += "api_key=";
      request_string += "DVTVAETM5SHS8J44";
      request_string += "&";
      request_string += "field1=";
      request_string += var;
      request_string += "&";
      request_string += "field2=";
      request_string += temp;
      request_string += "&";
      request_string += "field3=";
      request_string += hum;
      http.begin(client , request_string);
      http.GET();
      http.end();
      delay(1000);
    }
  
  }
