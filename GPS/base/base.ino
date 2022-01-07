unsigned char buffer[64];                   // buffer array for data receive over serial port
int count=0; 

void bufferArray(); 
void parscer();
int Test_Synchro_GPS();
char msg[64];
int n=0;
int afficherCarac = 0;



// counter for buffer array
void setup()
{
    Serial1.begin(9600);                 // the SoftSerial baud rate
    Serial.begin(9600);                     // the Serial port of Arduino baud rate.
}
 
void loop()
{
    if (Serial1.available())                     // if date is coming from software serial port ==> data is coming from SoftSerial shield
    {
        while(Serial1.available())               // reading data into char array
        {
            buffer[count++]=Serial1.read();      // writing data into array
            if(count == 64)break;
        }
        bufferArray();
        parscer();
        
       //Serial.write(buffer,count); // if no data transmission ends, write buffer to hardware serial port
        //clearBufferArray();                         // call clearBufferArray function to clear the stored data from the array
        count = 0;                                  // set counter of while loop to zero 
    }
    //if (Serial1.available())                 // if data is available on hardware serial port ==> data is coming from PC or notebook
    //Serial1.write(buffer,count);        // write it to the SoftSerial shield
    //Serial1.write("\n"); 
}
 
 
void clearBufferArray()                     // function to clear buffer array
{
    for (int i=0; i<count;i++)
    {
        buffer[i]=NULL;
    }                      // clear all index of array with command NULL
}

void parscer(){
  for (int i =0;i<64;i++){    
    if (buffer[i] == ',' ){
      n++;
      Serial.write("\n");
    }    
    else {
      msg[n]=buffer[i];
      //delay(500);
      Serial.write(msg[n]);      
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
        buffer[i]=NULL;
      }
       
     if (buffer[i] == '*' ){
        afficherCarac = 0;
        buffer[count] = "\n" ;
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
