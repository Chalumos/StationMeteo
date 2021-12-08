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

/*--------------------------------------------------------------------------------------------*/
// Fonctions de gestion du circuit DS1307
/*--------------------------------------------------------------------------------------------*/
// Convert normal decimal numbers to binary coded decimal (OK)
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Convert binary coded decimal to normal decimal numbers (OK)
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Arret du circuit d'horloge DS1307 (OK)
// Mise à 1 du bit 7 (CH) du registre des secondees d'adresse 0x00
// Consequence : Mise à zero des secondes
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Initialisation des paramétres de date et heure de l'horloge
// 1) Mise à jour des registres de date et heure du DS1307
// 2) Démarrer l'horloge
// 3) Définir le mode 24h pour l'horloge
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Lire les registres de l'horloge pour récupérer heure, minutes, seconde,...
// Retourne la date et l'heure
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
