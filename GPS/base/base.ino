char buffer[64];                   // buffer array for data receive over serial port
int count=0; 

void bufferArray(); 
void parscer();
int Test_Synchro_GPS();

char msg[15][10];
int n=0;
int m=0;
int afficherCarac = 0;



// counter for buffer array
void setup()
{
    Serial1.begin(9600);                 // the SoftSerial baud rate
    Serial.begin(9600);                     // the Serial port of Arduino baud rate.
    //Serial.println("test");
}
 
void loop()
{
    if (Serial1.available())                     // if date is coming from software serial port ==> data is coming from SoftSerial shield
    {
        while(Serial1.available() && count<=64)               // reading data into char array
        {
            buffer[count++]=Serial1.read();      // writing data into array
            //Serial.print("le caractere recupérer est :");
           // Serial.println(buffer[count-1]);
        }
        //bufferArray();
        //Serial.print("le buffer est :");
        //Serial.println(buffer);
        parscer();
        
       //Serial.write(buffer,count); // if no data transmission ends, write buffer to hardware serial port
        clearBufferArray();                         // call clearBufferArray function to clear the stored data from the array
        count = 0;                                  // set counter of while loop to zero 
    } 
}
 
 
void clearBufferArray()                     // function to clear buffer array
{
    for (int i=0; i<64;i++)
    {
        buffer[i]=0;
    }                      // clear all index of array with command NULL
}

void parscer(){
  for (int i =0;i<64;i++){    
    if (buffer[i] == ',' ){
      msg[n][m]='\0';
      n++;
      m=0;
      Serial.println(msg[n]);
    }    
    else {
      msg[n][m]=buffer[i];
      m++;
      Serial.println("hifzjfehfzofzehfezhfeho");
      //delay(500);
           
    }
  }  
}

void bufferArray()               
{
    for (int i=0; i<count;i++)
    {
      if (buffer[i] == '$' ){
          afficherCarac = 1;
      }
      
      if (afficherCarac == 0 ){
        buffer[i]=0;
      }
       
     if (buffer[i] == '*' ){
        afficherCarac = 0;
        buffer[count] = '\0' ;
      }                    
  }

}

int Test_Synchro_GPS(){
  if (msg[1]=="$GPRMC" && msg[2]=="A"){
    return 1;
  }
  else if(msg[1]=="$GPGGA" && msg[15]=="*"){
    return 1;
  }
  else return 0;
}
