// Fichier GPS.c
// Fonction de gestion du module GPS
// Acquisition d'un message NMEA
// Parser un message NMEA
// Savoir si le module GPS est synchronisé
// Définir le type de message NMEA renvoyé par le module GPS
// Extraire les données de date et d'heure depuis les données GPS



#include <Arduino.h>
#include "GPS.h"



/*
Contenu du tableau de chaînes de caractères GPGGA_Data
  [0] nmea_msg; // Nom du message
  [1] heure;
  [2] latitude;
  [3] hemisphere; // Nord (N) ou Sud (S)
  [4] longitude;
  [5] longitude_orientation; // Est (E) ou Ouest (O)
  [6] validation des données : (1 ou 2) active ou 0 void (invalide);
  [7] satelites used; // Nombre de satellite utilisés;
  [8] HDOP; // Horizontal Dilution of Precision
  [9] Altitude;
  [10] Unité pour l'altitude; // M pour mètre
  [11] Geoid separation;
  [12] Unité pour geoid separation : M pour mètre
  [13] Age of Diff. Corr
  [14]Diff. Ref. Station ID

Contenu du tableau de chaînes de caractéres GPRMC_Data
  [0] nmea_msg; // Nom du message
  [1] heure;
  [2] validation des données : A active ou V void (invalide);
  [3] latitude;
  [4] hemisphere; // Nord (N) ou Sud (S)
  [5] longitude;
  [6] longitude_orientation; // Est (E) ou Ouest (O)
  [7] speed; // Speed over the ground in knots;
  [8] track; // Track angle in degrees True; Angle de déplacement
  [9] date;
  [10] magnet_declin; // Déclinaison magnétique en degrés
  [11] magnet_declin_orientation; // Est ou ouest
  
  Champs 10 et 11 non disponibles de base sur le module SIM28
*/

/*--------------------------------------------------------------------------------------------*/
// Fonctions de gestion du module GPS

/*--------------------------------------------------------------------------------------------*/
// Récupérer message depuis le module GPS
/*--------------------------------------------------------------------------------------------*/
// Ici votre code



void get_msg(){
  int count=0;

  if (Serial1.available()){
    while(Serial1.available() ){
      NMEA[count++]=Serial1.read();
      if (count==64) break;
    }
    //Serial.write(NMEA,count);
    NMEA[count]='\0';
    count=0;
  }
  //Serial.println(NMEA);
  //return NMEA;
}


 

char** parscer(char trame[100]){
  
  int index=0;
  int cpt=0;
  int caze=0;
  char* pointeur=trame;
  
  while(trame[index]!='\0'){     

    if (trame[index] == ',' ){
      trame[index]='\0';
      msg[caze++]= pointeur;
      pointeur=pointeur+cpt+1;
      cpt=0;
      index++;
    }    
    else {
      index++;
      cpt++;
    }
  }   
  msg[caze]=pointeur;
  /*
  for(int i = 0; i<16; i++){
      Serial.write(msg[0]);
      Serial.write('\n');
  }
  */

  //return msg;
}

/*--------------------------------------------------------------------------------------------*/
// Parser un message NMEA
// Paramètre d'entrée : le message NMEA à parser
// Valeur retournée : le tableau de chaines de caractéres des différents champs du message NMEA
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Test pour savoir si le module GPS reçoit des messages corrects
// Valeur retournée : boolean flag
//  flag = 0 si pas de synchronisation, flag = 1 si synchronisation
// Valable pour les messages de type GPRMC et GPGGA
/*--------------------------------------------------------------------------------------------*/

int Test_Synchro_GPS(){
  if ( (strcmp(msg[0],"$GPRMC") == 0) && (strcmp(msg[2],"A") == 0) ){ 
    return 1;
  }
  else if( (strcmp(msg[0],"$GPGGA") == 0) && (strcmp(msg[6],0) != 0) ){
    return 1;
  }

  return 0;
}

/*--------------------------------------------------------------------------------------------*/
// Choix du type de message retourné par le module GPS
// Paramètre : la commande PMTK sous la forme d'une chaine de caractères
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Extraction de la date et de l'heure depuis les données GPS
// Date au format jjmmyy : chaine de caractéres
// Heure au format hhmmss : chaine de caractéres en temps UTC
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
// Conversion coordonnées géographiques GPS en dd°.xxxxxx
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
