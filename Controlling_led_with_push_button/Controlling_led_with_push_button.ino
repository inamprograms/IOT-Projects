int led = 9;
int button_state = 2;
void setup() {
   pinMode(led,OUTPUT);
   pinMode(button_state,INPUT);
}

void loop() {
    if(digitalRead(button_state) == 1){
      digitalWrite(led,HIGH);
      }
     else{
        digitalWrite(led,LOW);
     }
}
