// Fichier Station_Mesures_for_Adafruit2050_V1.ino

// Mise en oeuvre horloge temps réel : circuit DS1307 Dallas Semi Conducteur
// Mise en oeuvre module GPS
// Mise en oeuvre Capteur BME680
// Mise en oeuvre écran TFT Adafruit 2050
// Mise en oeuvre dalle tactile shield écran Adafruit 2050
// Gestion du rétroéclairage

// Option d'implémentation
// Enregistrement des paramètres de compensation de Température et Pression en EEPROM
//   - A effectuer une seule fois lors du setup
//   - Dépendant du capteur BME680 utilisé
//   - Mise à jour du Flag MAJ_PARAM_COMP_BME680_FLAG par #define pour stockage en EEPROM
//    - cf. fichier BME680_Sensor.h

// Option d'implémentation
// Enregistrement de la correction heure été - hiver en EEPROM
//  - @EEPROM : 100
//  - Paramétre : Correction_Ete_Hiver
//  - Effectuée uniquement lors du premier téléchargement du code

// Option d'implémentation
// Enregistrement / lecture de la compensation de la température et de la pression en EEPROM
//  - @EEPROM : 000
//  - offset_pression
//  - offset_temperature
//  - Gestion du flag MAJ_PARAM_COMP_BME680_FLAG dans BME280.h

// Sortie sur terminal série
//#define SERIAL_DEBUG // Pour activer l'affichage sur le terminal série

// Communication :
//   - DS1307 : bus I2C
//   - Module GPS : port série1
//   - Capteur BME680 : bus I2C

// Version Environnement Arduino : 1.8.8
// Cible matérielle : Atmega 2560_R3

// Version : 1.0
// Squelette programme projet tutoré2

// Inclure les fichiers d'en tête de base
#include <Wire.h> // Pour l'utilisation du bus I2C
#include <EEPROM.h> // Pour stockage des paramètres de compensation de Température et Pression en eeprom
#include <math.h> 
#include <avr/pgmspace.h> // Pour stockage de variables globales dans la mémoire de programme


// Fichier d'en tête spécifiques
//#include "RTC_DS1307.h"       // Pour le circuit d'horloge RTC DS1307
//#include "GPS.h"              // Pour le module GPS
//#include "Calendrier.h"       // Pour gestion correction date et heure
//#include "Affichage.h"        // Pour affichage sur le terminal série
//#include "TFT_Affichage.h"    // Pour affichage sur l'écran TFT
//#include "BME680_Sensor.h"    // Pour gestion du capteur BME680
//#include "Tactile.h"          // Pour gestion de la dalle tactile
//#include "bsec1.4.7.4.h"      // Pour le capteur BME680 : librairie bsec ver 1.4.7.4

// Inclure les bibliothèques pour gestion de l'écran TFT Adafruit 2050
//#include "Adafruit_GFX.h" // Bibliothéque graphique : primitives d'affichage
//#include "Adafruit_TFTLCD.h" // Gestion du processeur graphique
// Définir l'objet tft 

// Inclure la bibliothéque de gestion de la dalle tactile
//#include "TouchScreen.h"

//  Constantes symboliques pour initialisation registre de comptage du Timer 1

//  Constantes symboliques pour initialisation registre de comptage du Timer 3

// Variables globales
// - Pour le circuit RTC DS1307
   
// - Pour gestion de l'affichage du jour de la semaie et du mois de l'année


// - Pour le module GPS


// - Pour la gestion de l'heure et de la date

// - Pour la gestion de la mise à jour de l'horloge RTC via GPS

// - Pour gestion des fuseaux horaires

// - Pour initialisation des données de fuseau horaire

// - Fuseau horaire par défaut

// - Pour le capteur BME680

// - Pour la dalle tactile

// - Gestion de l'historique de la valeur moyenne de pression et de la variation de pression moyenne

// - Gestion du rétroéclairage écran TFT (option)

/*--------------------------------------------------------------------------------------------*/
// Routine d'IT TImer1 sur Overflow registre de comptage
ISR(TIMER1_OVF_vect)
{
  
}
/*--------------------------------------------------------------------------------------------*/
// Routine d'IT TImer3 sur Overflow registre de comptage
ISR(TIMER3_OVF_vect)
{
  
}
/*--------------------------------------------------------------------------------------------*/
void setup(void)
{
  // Déclaration des variables locales
  
  // Initialisation Bus I2C, liaisons série
  Wire.begin(); // Gestion de la prise de contrôle du bus I2C par le Maitre
  Serial.begin(115200); // Initialiser les paramètres de la sortie série0, moniteur série par défaut
  Serial1.begin (9600); // Initialiser les paramètres de la sortie série1 pour le module GPS

  // Inititialisation de l'écran TFT
  
  Serial.println ("Initialisation Ecran TFT done");

  // Initialisation des registres du Timer1
  //  - Définition d'une base de temps de 0.5s
  //  - Utilisation Timer1 avec IT sur débordement du registre de comptage
  
  Serial.println ("Initialisation Timer1 : done");

  // Initialisation des registres du Timer3
  //  - Définition d'une base de temps de 0.5s
  //  - Utilisation Timer1 avec IT sur débordement du registre de comptage
  
  Serial.println ("Initialisation Timer3 : done");

  // Inititialisation Module GPS : message de type $GPRMC par défaut
  
  Serial.println ("Initialisation module GPS done");


  // Initialisation des données de fuseau horaire
  // {"France", "Paris", {0,0,1}}; Par défaut : fuseau horaire Paris, Id = ID_FUSEAU_HORAIRE_PAR_DEFAULT

  // Lancer le démarrage de la RTC DS1307 et init de la date et de l'heure

  Serial.println ("Initialisation RTC : done");

  // Initialisation du capteur BME680
  // Gérer les paramètres de compensation de Température et Pression
  
  // Afficher la version de la librairie Bosch utilisée
  
  // Acquérir une première mesure de la température, pression, humidité, iaq, iaq_accuracy
  
  // Ajuster la zone d'affichage du graphe d'évolution de la pression moyenne
  
  Serial.println ("Initialisation BME680 done");


  Serial.println ("\nFin setup");
  Serial.println ("\nStation_Mesures V1.0 Projet tutore2 2021-2022");
  Serial.println ("Projet tutore2 2021-2022");
  delay (5000);
  
  // Acquisition de la date et de l'heure courantes

  // Initialisations des différents flags et variables de contrôle
  
}
/*--------------------------------------------------------------------------------------------*/
void loop() 
{
  // Gestion du rétroéclairage : optionnel
  
  // Gestion du rafraichissement de l'affichage de la date, heure, indicateursynchro GPS,...
  

  // Acquisition des données capteur BME680 et MàJ cumul pression
  

  // Mise à jour des éléments de pression moyenne

  // Pour savoir si le GPS délivre des messages valides

  // Gestion de la mise à jour de la date et de l'heure avec le module GPS
  // Fin MàJ date et heure via module GPS

  // Gestion de la dalle tactile                                     
  // Fin gestion dalle tactile 

  // Gestion des menus 

} // Fin loop
