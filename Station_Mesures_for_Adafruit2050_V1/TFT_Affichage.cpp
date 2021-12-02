// Fichier TFT_Affichage.cpp
// Routines de gestion d'affichage sur écran TFT Adafruit 2050

#include <Arduino.h>
#include "TFT_Affichage.h"

// Pour gestion de l'affichage de la date depuis le circuit RTC

/*--------------------------------------------------------------------------------------------*/
// Gestion de l'affichage graphique des données du circuit horloge RTC DS1307
// Affichage de la date.
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Gestion de l'affichage graphique des données du circuit horloge RTC DS1307
// Affichage de l'heure.
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Gestion de l'affichage indicateur heure Eté - hiver
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Gestion de l'affichage Ville de référence du fuseau horaire
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Gestion de l'affichage de l'état de synchronisation du module GPS 
// Si Synchro_GPS == 0 : pas de synchro;
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------*/
// Gestion de l'affichage d'une mesure sur écran TFT
// Fonction générique
// mesure : valeur à afficher. Dans [0.00; 9999.99]
// n_dec : nombre de digits de la partie décimale. Valeur max : 2. Si 0, valeur entière.
// n_ent : nombre de digits de la partie entière. Valeur max : 4
// couleur : couleur d'affichage sur écran TFT. Codée sur 16 bits
// taille_caract : taille des caractéres
// pos_ref_x : position de référence selon x sur afficheur
// pos_ref_y : position de référence selon y sur afficheur
// unité : chaîne de caractères pour afficher l'unité de la mesure (hPa, %,...)
// signe_flag : flag pour gérer l'affichage du signe de la mesure. Si 0 : pas d'affichage du signe de la mesure
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Gestion de l'affichage graphique de la valeur de température sur écran TFT
// Mesure de température exprimée en degrés, valeur réelle
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Gestion de l'affichage de la variation de la valeur moyenne de pression
// Valeurs en hPa. Valeurs réelles
/*--------------------------------------------------------------------------------------------*/
void TFT_Affiche_Delta_Pression (float delta_moyenne_pression, float delta_moyenne_pression_prec)
{
  // Ici votre code
}
/*--------------------------------------------------------------------------------------------*/
// Gestion de l'affichage de la valeur de l'IAQ : valeur réelle dans [0.0; 500.0]
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Gestion de l'affichage de la valeur de l'IAQ_Acc
// Valeur entière dans {1,2,3,4}
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Tracé de l'historique de la valeur moyenne de la pression en hPa
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Mise en forme de l'écran d'invite de choix : 
//   MàJ heure été - hiver
//   Choix heure hiver 
//   Choix Fuseau Horaire
//   Info GPS
//   Info BME680
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Gestion de l'écran d'affichage des données issues du GPS
// Heure UTC, Date, Latitude, Longitude, Altitude
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Affichage des données du BME680
// Température, Pression, Humidité, IAQ, IAQAcc, eCO2, eCOV
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Menu de choix du fuseau horaire
// Affichage sur écran des éléments permanents (validé le 24.11.2021)
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Gérer l'affichage des fuseaux horaires sur écran TFT
// Id_Fuseau_Horaire : Id du fuseau horaire en cours
// TFT_Id_Tab_GMT : indice du premier fuseau affiché
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
