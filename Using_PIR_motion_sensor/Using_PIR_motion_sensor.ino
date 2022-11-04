int ledPin = 9;
int inputPin = 2;
int val = 0;

void setup() {
  
  pinMode(ledPin,OUTPUT);
  pinMode(inputPin,INPUT);
}

void loop() {
  val = digitalRead(inputPin);
  
  if(val == 1){
    digitalWrite(ledPin,HIGH);
    }
  else{
    digitalWrite(ledPin,LOW);
   }
}
