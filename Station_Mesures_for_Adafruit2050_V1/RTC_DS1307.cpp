// Fichier RTC_DS1307.cpp
// Fonctions de gestion du circuit d'horloge RTC DS1307
// Affichage de la date et de l'heure sur terminal série : 

// Initialisation des paramètres de l'horloge : 
// Acquisition de la date et de l'heure : 
// 2 fonctions additionnelles :
//  - byte decToBcd(byte val); Conversion Décimal vers BCD
//  - byte bcdToDec(byte val); Conversion BCD vers Décimal


#include <Arduino.h>
#include <Wire.h>
#include "RTC_DS1307.h"

horloge_RTC horloge;

/*--------------------------------------------------------------------------------------------*/
// Fonctions de gestion du circuit DS1307
/*--------------------------------------------------------------------------------------------*/
// Convert normal decimal numbers to binary coded decimal (OK)
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
uint8_t decToBcd(uint8_t val) {
    return ((val / 10 * 16) + (val % 10)); 
 }
/*--------------------------------------------------------------------------------------------*/
// Convert binary coded decimal to normal decimal numbers (OK)
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
uint8_t bcdToDec(uint8_t val) {
    return ((val / 16 * 10) + (val % 16));
}
/*--------------------------------------------------------------------------------------------*/
// Arret du circuit d'horloge DS1307 (OK)
// Mise à 1 du bit 7 (CH) du registre des secondees d'adresse 0x00
// Consequence : Mise à zero des secondes
/*--------------------------------------------------------------------------------------------*/

/*Function: The clock timing will stop */
void stopClock(void) {       // set the ClockHalt bit high to stop the rtc
    Wire.beginTransmission(DS1307_I2C_ADDRESS);
    Wire.write((uint8_t)0x00);                      // Register 0x00 holds the oscillator start/stop bit
    Wire.endTransmission();
    Wire.requestFrom(DS1307_I2C_ADDRESS, 1);
    horloge.horaire.seconde = Wire.read() | 0x80;       // save actual seconds and OR sec with bit 7 (sart/stop bit) = clock stopped
    Wire.beginTransmission(DS1307_I2C_ADDRESS);
    Wire.write((uint8_t)0x00);
    Wire.write((uint8_t) horloge.horaire.seconde);                    // write seconds back and stop the clock
    Wire.endTransmission();
}

/*--------------------------------------------------------------------------------------------*/
// Initialisation des paramétres de date et heure de l'horloge
// 1) Mise à jour des registres de date et heure du DS1307
// 2) Démarrer l'horloge
// 3) Définir le mode 24h pour l'horloge
/*--------------------------------------------------------------------------------------------*/

void begin() {
    Wire.begin();
}
/*Function: The clock timing will start */
void startClock(void) {      // set the ClockHalt bit low to start the rtc
    Wire.beginTransmission(DS1307_I2C_ADDRESS);
    Wire.write((uint8_t)0x00);                      // Register 0x00 holds the oscillator start/stop bit
    Wire.endTransmission();
    Wire.requestFrom(DS1307_I2C_ADDRESS, 1);
    horloge.horaire.seconde = Wire.read() & 0x7f;       // save actual seconds and AND sec with bit 7 (sart/stop bit) = clock started
    Wire.beginTransmission(DS1307_I2C_ADDRESS);
    Wire.write((uint8_t)0x00);
    Wire.write((uint8_t) horloge.horaire.seconde);                    // write seconds back and start the clock
    Wire.endTransmission();
}

/*--------------------------------------------------------------------------------------------*/
// Lire les registres de l'horloge pour récupérer heure, minutes, seconde,...
// Retourne la date et l'heure
/*--------------------------------------------------------------------------------------------*/

/*Function: Read time and date from RTC */
horloge_RTC getTime() {
    // Reset the register pointer
    Wire.beginTransmission(DS1307_I2C_ADDRESS);
    Wire.write((uint8_t)0x00);
    Wire.endTransmission();
    Wire.requestFrom(DS1307_I2C_ADDRESS, 7);
    // A few of these need masks because certain bits are control bits
    horloge.horaire.seconde     = bcdToDec(Wire.read() & 0x7f);
    horloge.horaire.minute     = bcdToDec(Wire.read());
    horloge.horaire.heure       = bcdToDec(Wire.read() & 0x3f);// Need to change this if 12 hour am/pm
    horloge.calendrier.jour_semaine  = bcdToDec(Wire.read());
    horloge.calendrier.jour_mois = bcdToDec(Wire.read());
    horloge.calendrier.mois      = bcdToDec(Wire.read());
    horloge.calendrier.annee       =bcdToDec( Wire.read());

    return horloge;
}


/*Frunction: Write the time that includes the date to the RTC chip */
void setTime(horloge_RTC horloge) {
    Serial.println("seconde setTime ");
    Serial.println(horloge.horaire.seconde);
    Wire.beginTransmission(DS1307_I2C_ADDRESS);
    Wire.write((uint8_t)0x00);
    Wire.write(decToBcd( horloge.horaire.seconde));// 0 to bit 7 starts the clock
    Wire.write(decToBcd( horloge.horaire.minute));
    Wire.write(decToBcd(horloge.horaire.heure));  // If you want 12 hour am/pm you need to set bit 6
    Wire.write(decToBcd( horloge.calendrier.jour_semaine));
    Wire.write(decToBcd( horloge.calendrier.jour_mois));
    Wire.write(decToBcd( horloge.calendrier.mois));
    Wire.write(decToBcd(horloge.calendrier.annee));
    Wire.endTransmission();
}



/*--------------------------------------------------------------------------------------------*/
