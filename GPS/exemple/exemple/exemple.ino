#include <SoftwareSerial.h>
void bufferArray();
void clearBufferArray();
void parscer();
unsigned char buffer[64];

char str[] = "salut,toi";
char delim[] = ",";


int count=0;   
int afficherCarac = 0;
char *ptr = strtok(buffer, delim);

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600); 
}

void loop() {
  if (Serial1.available())                    
    { 
        while(Serial1.available())            
        {
//          Serial.write(Serial1.read(),count);
         
            buffer[count++]=Serial1.read(); 
            //if(count == 64)break;
          }  
   }
        //bufferArray();
        
        parscer();
        //*gpsStream =  strtok(gpsStream,",");
        //Serial.println(gpsStream);
        //Serial.write(buffer,count);    
        //Serial.print("\n");          
        clearBufferArray();                      
        count = 0;                               
}

void clearBufferArray()                     
{
    for (int i=0; i<count;i++)
    { buffer[i]=NULL;}                      
}

void bufferArray()                     
{
    for (int i=0; i<count;i++)
    {
      if (buffer[i] == 36 ){
          afficherCarac = 1;
      }
      
      if (afficherCarac == 0 ){
        buffer[i]=NULL;
      }
       
     if (buffer[i] == 42 ){
        afficherCarac = 0;
      } 
                       
  }
}
void parscer(){
   while (ptr != NULL)
  {
    Serial.println(ptr);
    ptr = strtok(NULL, delim);
  
  }
  
}
