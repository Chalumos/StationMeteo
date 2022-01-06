char str[] = "strtok needs toi be called several times to split a string";
int init_size = strlen(str);
char delim[] = "ai";
char *ptr = strtok(str, delim);

void setup() {
  Serial.begin(9600);

}

void loop() {
  
  
  
  while (ptr != NULL)
  {
    Serial.println(ptr);
    ptr = strtok(NULL, delim);
  
  }
}
