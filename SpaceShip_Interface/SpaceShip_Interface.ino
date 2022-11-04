int led_greeen = 9;
int led_red = 10;
int led_yellow = 11;
int button = 2;

void setup() {
  
  pinMode(button,OUTPUT);
  pinMode(led_greeen,OUTPUT);
}

void loop() {
  if(digitalRead(button) == 0){
    digitalWrite(led_red,HIGH);
    digitalWrite(led_yellow,LOW);
    digitalWrite(led_greeen,LOW);
    }
  else{
    digitalWrite(led_red,LOW);
    digitalWrite(led_yellow,LOW);
    digitalWrite(led_greeen,HIGH);  
    delay(250);
    digitalWrite(led_yellow,HIGH);
    digitalWrite(led_greeen,LOW); 
    delay(250);
    
    }
}
