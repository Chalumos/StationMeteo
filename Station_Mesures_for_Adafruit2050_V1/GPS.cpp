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
  Serial.println(NMEA);
}



/*--------------------------------------------------------------------------------------------*/
// Parser un message NMEA
// Paramètre d'entrée : le message NMEA à parser
// Valeur retournée : le tableau de chaines de caractéres des différents champs du message NMEA
/*--------------------------------------------------------------------------------------------*/
char** GPS_msg_parse(char trame[100]){
  
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
  
  //Serial.println(msg[9]);
  /*
  for(int i = 0; i<16; i++){
      Serial.write(msg[i]);
      Serial.write('\n');
  }
  */
}
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
void Choix_Msg_NMEA(){
  char format[5] = "";
  int i = 0;
  

  while (Serial.available() > 0){
    format[i++]=Serial.read();
  }

  if(testChaine("GPGGA",format) == 1) {
     Serial1.write("$PMTK314,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n");  //signal GPGGA
     Serial.println("Le format du signal devient GPGGA ");
  }
  else if(testChaine("GPRMC",format) == 1) {
    Serial1.write("$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n" );  //signal GPRMC
    Serial.println("Le format du signal devient GPRMC ");
  }
 
}

int testChaine(char str1[6], char str2[6]){
  for(int i = 0; i<5; i++){
    if(str1[i] != str2[i]){
      return 0;
    }
  }
  return 1;
}
/*--------------------------------------------------------------------------------------------*/
// Extraction de la date et de l'heure depuis les données GPS
// Date au format jjmmyy : chaine de caractéres
// Heure au format hhmmss : chaine de caractéres en temps UTC
/*--------------------------------------------------------------------------------------------*/
horloge_RTC ExtractionDateHeure(){
  horloge_RTC newHorloge;
  
  if ( (strcmp(msg[0],"$GPRMC") == 0) ){
    /* Date */
  char *date= "";
  char jj[3]= "";
  char mm[3]= "";
  char yy[3]= "";
  date = msg[9];

  jj[0] = date[0];
  jj[1] = date[1];
  mm[0] = date[2];
  mm[1] = date[3];
  yy[0] = date[4];
  yy[1] = date[5];

  newHorloge.calendrier.jour_mois = atoi(jj);
  newHorloge.calendrier.mois = atoi(mm);
  newHorloge.calendrier.annee = atoi(yy);
  }
  
  
  /* Horaire */
  char *horaire= "";
  char hh[3]= "";
  char minute[3]= "";
  char ss[3]= "";
  horaire = msg[1];

  hh[0] = horaire[0];
  hh[1] = horaire[1];
  minute[0] = horaire[2];
  minute[1] = horaire[3];
  ss[0] = horaire[4];
  ss[1] = horaire[5];

  
  if ( (strcmp(msg[0],"$GPRMC") == 0) ){
    /* Gestion heure hiver/ete */
    if (newHorloge.calendrier.mois >= 11 || newHorloge.calendrier.mois <= 3){
      newHorloge.horaire.heure = atoi(hh) + 1;
    }
    else {
     newHorloge.horaire.heure = atoi(hh);
    }
  }
  else {
     newHorloge.horaire.heure = atoi(hh);
  }
 
  newHorloge.horaire.minute = atoi(minute);
  newHorloge.horaire.seconde  = atoi(ss);

  return newHorloge;
  /*
  Serial.print("Time => ");
  Serial.print(newHorloge.horaire.heure);
  Serial.print(" : ");
  Serial.print(newHorloge.horaire.minute);
  Serial.print(" : ");
  Serial.println(newHorloge.horaire.seconde);
 
  Serial.print("Date => ");
  Serial.print(newHorloge.calendrier.jour_mois);
  Serial.print(" / ");
  Serial.print(newHorloge.calendrier.mois);
  Serial.print(" / ");
  Serial.println(newHorloge.calendrier.annee);
  */
  
}
/*--------------------------------------------------------------------------------------------*/
// Conversion coordonnées géographiques GPS en dd°.xxxxxx
/*--------------------------------------------------------------------------------------------*/
// Ici votre code
/*--------------------------------------------------------------------------------------------*/
