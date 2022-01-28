// Fichier Affichage.h
// Routines d'affichage :
//  Sur le terminal série

#include <Arduino.h>
#include "RTC_DS1307.h"

// Définition de constantes symboliques

// Fonctions prototypes
void affichageCapteur();
void affichageDateHeure(horloge_RTC horlogeRtc);
void affichageTestSynchroGPS();
