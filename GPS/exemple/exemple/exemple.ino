#include <SoftwareSerial.h>

//Serial serial1;
unsigned char buffer[64];
int count=0;   

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600); 
  Serial.println("hello 1");
}

void loop() {
  //Serial.println("hello 2"); 
  if (Serial1.available())                    
    { 
        while(Serial1.available())            
        {
            buffer[count++]=Serial1.read(); 
            Serial1.println("hello 3");  
            if(count == 64)break;
        }
        Serial.println("hello 4");   
        Serial.write(buffer,count);              
        clearBufferArray();                      
        count = 0;                               
    }
}

void clearBufferArray()                     
{
    for (int i=0; i<count;i++)
    { buffer[i]=NULL;}                      
}
