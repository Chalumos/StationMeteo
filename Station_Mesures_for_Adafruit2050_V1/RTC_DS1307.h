// Fichier RTC_DS1307.h
// Contient les définitions de types de données associées aux fonctions
//  de manipulation du circuit d'horloge RTC DS1307


#ifndef __DS1307_H__
#define __DS1307_H__

#include <Arduino.h>

// Définition de constantes symboliques
// Circuit RTC DS1307 : adressage I2C
#define DS1307_I2C_ADDRESS 0x68 // adresse I2C du circuit DS1307 : 110 1000  
#define ADR_REG_SECONDE B00000000 // adresse du registre des secondes

#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6
#define SUN 7

// Définition de type de données pour gestion de la date
typedef struct {
        uint8_t jour_semaine;
        uint8_t jour_mois;
        uint8_t mois;
        uint8_t annee;
    } horlogeDate;
    
// Définition de type de données pour gestion de l'heure
typedef struct {
        uint8_t seconde;
        uint8_t minute;
        uint8_t heure;
    } horlogeHeure;

// Définition de type de données pour gestion de la date et l'heure sur RTC DS1307
typedef struct {
       horlogeHeure horaire;
       horlogeDate calendrier;
    }horloge_RTC;

// Définition de type de données pour gestion des fuseaux horaires

    uint8_t decToBcd(uint8_t val);
    uint8_t bcdToDec(uint8_t val);

    void begin();
    void startClock(void);
    void stopClock(void);
    void setTime(horloge_RTC horloge);
    horloge_RTC getTime(void);




#endif
