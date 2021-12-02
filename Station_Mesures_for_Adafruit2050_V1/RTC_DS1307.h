// Fichier RTC_DS1307.h
// Contient les définitions de types de données associées aux fonctions
//  de manipulation du circuit d'horloge RTC DS1307

#include <Arduino.h>

// Définition de type de données pour gestion de la date


// Définition de type de données pour gestion de l'heure

// Définition de type de données pour gestion de la date et l'heure sur RTC DS1307


// Définition de type de données pour gestion des fuseaux horaires


// Définition de constantes symboliques
// Circuit RTC DS1307 : adressage I2C
#define DS1307_I2C_ADDRESS 0x68 // adresse I2C du circuit DS1307 : 110 1000
#define ADR_REG_SECONDE B00000000 // adresse du registre des secondes
