// Fichier TFT_Affichage.h
// Spécifique à l'écran TFT Adafruit 2050

#include <Arduino.h>


// Définition de constantes symboliques
// Définition de la résolution du shield TFT : commune aux shields écran utilisés
#define TFT_X 320 // Axe horizontal
#define TFT_Y 480 // Axe vertical

// Définition de couleurs sur 16 bits
#define BLACK      0x0000     // (0, 0, 0)
#define DARKGREEN  0x0500     // (0, 128, 0) 0x03E0 valeur initiale
#define MAROON     0x7800     // (128, 0, 0)
#define BLUE       0x001F     // (0, 0, 255)
#define RED        0xF800     // (255, 0, 0)
#define GREEN      0x07E0     // (0, 255, 0)
#define CYAN       0x07FF     // (0, 255, 255)
#define MAGENTA    0xF81F     // (255, 0, 255)
#define YELLOW     0xFFE0     // (255, 255, 0)
#define ORANGE     0xFD20     // (255, 165, 0)
#define WHITE      0xFFFF     // (255, 255, 255)

/*--------------------------------------------------------------------------------*/
// Spécifique au shield écran TFT + dalle tactile Adafruit_2050_TFT
// Arduino Mega2560, mode Data parallèle

// Broches de contrôle écran TFT
#define LCD_CS A0
#define LCD_CD A1
#define LCD_WR A2
#define LCD_RD A3
#define LCD_RESET A4 // optional

// Pour mémo
//   D0 connects to digital pin 22
//   D1 connects to digital pin 23
//   D2 connects to digital pin 24
//   D3 connects to digital pin 25
//   D4 connects to digital pin 26
//   D5 connects to digital pin 27
//   D6 connects to digital pin 28
//   D7 connects to digital pin 29

// Gestion du rétroéclairage
#define BACKLITE_PIN 46 // Broche de gestion du rétro éclairage de l'écran TFT
#define BACKLITE_0 0 // Intensité du rétroclairage à 0
#define BACKLITE_5 5 // Intensité du rétroclairage à 5
#define BACKLITE_128 128 // Intensité du rétroclairage à 128

/*----------------------------------------*/
// Gestion de l'affichage de la date

// Gestion de l'affichage de l'heure

// Gestion de l'affichage de l'indicateur heure Eté - Hiver

// Gestion de l'affichage de la ville de référence du fuseau horaire

// Gestion de l'affichage de l'état de synchro du module GPS sous forme d'un disque

/*----------------------------------------*/
// Gestion de l'affichage de la température sur écran TFT : validé le 10.12.2019

// Gestion de l'affichage de la pression sur écran TFT

// Gestion de l'affichage de la variation moyenne de pression sur une heure

// Gestion de l'affichage de la mesure d'humidité
#define TFT_HUMIDITY_POINT_DECIMAL_X 65 // Coordonnées écran TFT du point décimal valeur de l'humidité
#define TFT_HUMIDITY_Y 225

// Gestion de l'affichage de l'IAQ

// Gestion de l'affichage de l'IAQ_Acc

// Gestion de l'affichage de la variation moyenne de pression sur une heure

// Définition des dimensions de la zone affichage historique de la pression moyenne

// Définition de la plage de pression pour affichage historique moyenne de la pression, en hPa
#define MOY_PRESSION_MIN 940.0 // Valeur min relevée au niveau de la mer; Valeur par défaut
#define MOY_PRESSION_MAX 1040.0 // Valeur max par défaut

// Gestion affichage écran Menu_General
// Texte 1 : Ete-Hiver
// Texte 2 : Infos GPS
// Texte 3 : Fuseau Horaire
// Texte 4 : Info BME680
// Texte 5 : Annuler

// Gestion de l'affichage du Menu de choix heure été / heure hiver
// Texte 1 : Heure Ete
// Texte 2 : Heure Hiver

// Gestion de l'affichage du menu de choix du fuseau horaire

// Gestion affichage des données GPS

// Gestion affichage données du BME680

// Fonctions prototypes
