#define TCNT1_TIMER1 61610U // Période entre 2 IT Timer1 sur Overflow registre de comptage (environ 0.25s)
int t_led = 4;
volatile int tTimeOut = t_led;
const int led = 12;

ISR(TIMER1_OVF_vect){
 TIMSK1 &= B11111110; // Bloquer les IT Timer 1
  
  tTimeOut --;
    
  TIFR1 |= B00000001; // Réarmer à 1 le flag TOV1 de l'IT Timer 1
  TCNT1 = TCNT1_TIMER1; // Recharger le registre de comptage du Timer 1 
  TIMSK1 |= B0000001; // Autoriser les IT Timer 1
  SREG |= B10000000; // Autoriser toutes les IT/
}

void setup() {
  // put your setup code here, to run once:
    Serial.begin (115200);
    pinMode(led,OUTPUT);
    
    // Initialisation des registres du Timer1
    //  - Définition d'une base de temps de 0.25s
    //  - Utilisation Timer1 avec IT sur débordement du registre de comptage
    noInterrupts(); // Bloquer toutes les interruptions
    TCCR1A = B00000000; // TCCR1A = Ox00 Mode normal
    TCCR1B = B00000000; // Mode normal, Timer 1 arrété
    TCCR1C = 0B00000000;
    TIFR1 |= B00000001; // Pour que les IT Timer 1 puissent être prises en compte; Mise à 1 du bit TOV1
    TIMSK1 |= B00000001; // Pour autoriser les IT sur débordement Timer 1; Mise à 1 du bit TOEI1
    TCNT1 = TCNT1_TIMER1; // Charger le contenu du registre de comptage du Timer 1
    interrupts (); // Autoriser toutes les interruptions
    TCCR1B |= B00000101; // Pour définir valeur de prescaler Timer 1 à 1024 et démarrer le compteur

}

void loop() {
  if(tTimeOut <= 0){
    if(digitalRead(led) == LOW){
      digitalWrite(led,HIGH);
    }else{
       digitalWrite(led,LOW);
    }
    //lecture date heure et affichage
    // remise à 1 de tTimeOut
    tTimeOut = t_led;
  }
}
