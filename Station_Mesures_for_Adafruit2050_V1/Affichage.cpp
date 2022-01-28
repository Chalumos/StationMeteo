// Fichier Affichage.cpp

// Routines d'affichage sur le terminal série
//   Affichage de la date et de l'heure sur terminal série
//   Affichage Indicateur Ete-Hiver sur le terminal série
//   Affichage Ville de référence fuseau horaire sur le terminal série
//   Affichage Indicateur de synchro sur le terminal série
//   Affichage des mesures du capteur BME680 sur le terminal série
//   Affichage de l'historique des mesures de valeur moyenne de pression atmosphérique sur le terminal série

#include <Arduino.h>
#include "Affichage.h"
#include "BME680_Sensor.h"
#include "RTC_DS1307.h"
#include "GPS.h"

// Pour gestion de l'affichage de la date depuis le circuit RTC

/*--------------------------------------------------------------------------------------------*/
// Affichage de la date et de l'heure sur le terminal série
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
void affichageDateHeure(horloge_RTC horlogeRtc) {
  Serial.println("--------------DONNEES HORLOGE RTC-------------- ");
  Serial.print("Time => ");
  Serial.print(horlogeRtc.horaire.heure);
  Serial.print(" : ");
  Serial.print(horlogeRtc.horaire.minute);
  Serial.print(" : ");
  Serial.println(horlogeRtc.horaire.seconde);
  Serial.print("Date => ");
  Serial.print(horlogeRtc.calendrier.jour_semaine);
  Serial.print(" / ");
  Serial.print(horlogeRtc.calendrier.jour_mois);
  Serial.print(" / ");
  Serial.print(horlogeRtc.calendrier.mois);
  Serial.print(" / ");
  Serial.println(horlogeRtc.calendrier.annee);
  Serial.println("--------------FIN DONNES HORLOGE RTC--------------  \n");
}
/*--------------------------------------------------------------------------------------------*/
// Affichage indicateur heure Eté - hiver sur le terminal série
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Affichage Ville de référence du fuseau horaire sur le terminal série
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Affichage de l'état de synchronisation du module GPS  sur le terminal série
// Si Synchro_GPS == 0 : pas de synchro;
/*--------------------------------------------------------------------------------------------*/
void affichageTestSynchroGPS() {
  Serial.println("--------------TEST SYNCHRO GPS-------------- ");
  if(Test_Synchro_GPS()) {
      Serial.println("Signal GPS valide ");
    }
    else{
      Serial.println("Signal GPS invalide attention ! ");
    }
  Serial.println("--------------FIN TEST SYNCHRO GPS--------------  \n");
}
/*--------------------------------------------------------------------------------------------*/
// Affichage des données du capteur  sur le terminal série
/*--------------------------------------------------------------------------------------------*/
void affichageCapteur() {
  Serial.println("--------------DONNEES CAPTEUR BME680-------------- ");
  Serial.println(ExtractionDonneesBME680());
  Serial.println("--------------FIN DONNES CAPTEUR BME680--------------  \n");
 }
/*--------------------------------------------------------------------------------------------*/
// Afficher les données du graphe d'évolution de la valeur moyenne de la pression atmosphérique
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
