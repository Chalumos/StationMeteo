const int led = 12;
const int led2 = LED_BUILTIN;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT); 
  pinMode(led2,OUTPUT);  

}

void loop() {
  digitalWrite(led, HIGH);  
  for(int i=0; i<3000;i=i+1000){  
    digitalWrite(led2, HIGH);   
    delay(500);  
    digitalWrite(led2, LOW);    
    delay(500);  
    }
  digitalWrite(led, LOW);  
  for(int i=0; i<3000;i=i+1000){  
    digitalWrite(led2, HIGH);   
    delay(500);  
    digitalWrite(led2, LOW);    
    delay(500);  
    }  
}
