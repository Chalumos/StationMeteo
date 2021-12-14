// Fichier RTC_DS1307.h
// Contient les définitions de types de données associées aux fonctions
//  de manipulation du circuit d'horloge RTC DS1307


#ifndef __DS1307_H__
#define __DS1307_H__

#include <Arduino.h>

#define DS1307_I2C_ADDRESS 0x68

#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6
#define SUN 7

// Définition de type de données pour gestion de la date
struct horlogeDate {
        uint8_t jour_semaine;
        uint8_t jour_mois;
        uint8_t mois;
        uint8_t annee;
    };
// Définition de type de données pour gestion de l'heure
struct horlogeHeure {
        uint8_t seconde;
        uint8_t minute;
        uint8_t heure;
    };

// Définition de type de données pour gestion de la date et l'heure sur RTC DS1307
struct horloge_RTC {
       horlogeHeure horaire;
       horlogeDate calendrier;
    };
  


// Définition de type de données pour gestion des fuseaux horaires

    uint8_t decToBcd(uint8_t val);
    uint8_t bcdToDec(uint8_t val);

    void begin();
    void startClock(void);
    void stopClock(void);
    void setTime(horloge_RTC horloge);
    horloge_RTC getTime(void);
    void fillByHMS(uint8_t _hour, uint8_t _minute, uint8_t _second);
    void fillByYMD(uint16_t _year, uint8_t _month, uint8_t _day);
    void fillDayOfWeek(uint8_t _dow);



// Définition de constantes symboliques
// Circuit RTC DS1307 : adressage I2C
#define DS1307_I2C_ADDRESS 0x68 // adresse I2C du circuit DS1307 : 110 1000
#define ADR_REG_SECONDE B00000000 // adresse du registre des secondes
#endif
