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
zoneUtc listeUtcW[14];
zoneUtc listeUtcE[12];



void zoneUtcConstructeur() {
  /* TODO OPTIMISER CREATION*/

  /* Zone East*/
  zoneUtc utc0;
  utc0.zoneUtc = 0;
  utc0.longitudeUtcMin = 0;
  utc0.longitudeUtcMax = 7.5;
  utc0.longitude_orientation = 'E';
   
  zoneUtc utc1;
  utc1.zoneUtc = 1;
  utc1.longitudeUtcMin = 7.5;
  utc1.longitudeUtcMax = 22.5 ;
  utc1.longitude_orientation = 'E';

  zoneUtc utc2;
  utc2.zoneUtc = 2;
  utc2.longitudeUtcMin = 22.5;
  utc2.longitudeUtcMax = 37.5;
  utc2.longitude_orientation = 'E';

 zoneUtc utc3;
  utc3.zoneUtc = 3;
  utc3.longitudeUtcMin = 37.5;
  utc3.longitudeUtcMax = 52.5;
  utc3.longitude_orientation = 'E';

  zoneUtc utc4;
  utc4.zoneUtc = 4;
  utc4.longitudeUtcMin = 52.5;
  utc4.longitudeUtcMax = 67.5;
  utc4.longitude_orientation = 'E';

  zoneUtc utc5;
  utc5.zoneUtc = 5;
  utc5.longitudeUtcMin = 67.5;
  utc5.longitudeUtcMax = 82.5;
  utc5.longitude_orientation = 'E';

  zoneUtc utc6;
  utc6.zoneUtc = 6;
  utc6.longitudeUtcMin = 82.5;
  utc6.longitudeUtcMax = 97.5;
  utc6.longitude_orientation = 'E';

  zoneUtc utc7;
  utc7.zoneUtc = 7;
  utc7.longitudeUtcMin = 97.5;
  utc7.longitudeUtcMax = 112.5;
  utc7.longitude_orientation = 'E';

  zoneUtc utc8;
  utc8.zoneUtc = 8;
  utc8.longitudeUtcMin = 112.5;
  utc8.longitudeUtcMax = 127.5;
  utc8.longitude_orientation = 'E';

  zoneUtc utc9;
  utc9.zoneUtc = 9;
  utc9.longitudeUtcMin = 127.5;
  utc9.longitudeUtcMax = 142.5;
  utc9.longitude_orientation = 'E';

  zoneUtc utc10;
  utc10.zoneUtc = 10;
  utc10.longitudeUtcMin = 142.5;
  utc10.longitudeUtcMax = 157.5;
  utc10.longitude_orientation = 'E';

  zoneUtc utc11;
  utc11.zoneUtc = 11;
  utc11.longitudeUtcMin = 157.5;
  utc11.longitudeUtcMax = 172.5;
  utc11.longitude_orientation = 'E';

  zoneUtc utc12;
  utc12.zoneUtc = 12;
  utc12.longitudeUtcMin = 172.5;
  utc12.longitudeUtcMax = 180;
  utc12.longitude_orientation = 'E';


  /* Zone West*/
  zoneUtc utc_0;
  utc_0.zoneUtc = 0;
  utc_0.longitudeUtcMin = 0;
  utc_0.longitudeUtcMax = 7.5 ;
  utc_0.longitude_orientation = 'W';
  
  zoneUtc utc_1;
  utc_1.zoneUtc = -1;
  utc_1.longitudeUtcMin = 7.5;
  utc_1.longitudeUtcMax = 22.5 ;
  utc_1.longitude_orientation = 'W';

  zoneUtc utc_2;
  utc_2.zoneUtc = -2;
  utc_2.longitudeUtcMin = 22.5;
  utc_2.longitudeUtcMax = 37.5 ;
  utc_2.longitude_orientation = 'W';

  zoneUtc utc_3;
  utc_3.zoneUtc = -3;
  utc_3.longitudeUtcMin = 37.5;
  utc_3.longitudeUtcMax = 52.5;
  utc_3.longitude_orientation = 'W';

  zoneUtc utc_4;
  utc_4.zoneUtc = -4;
  utc_4.longitudeUtcMin = 52.5;
  utc_4.longitudeUtcMax = 67.5;
  utc_4.longitude_orientation = 'W';

  zoneUtc utc_5;
  utc_5.zoneUtc = -5;
  utc_5.longitudeUtcMin = 67.5;
  utc_5.longitudeUtcMax = 82.5;
  utc_5.longitude_orientation = 'W';

  zoneUtc utc_6;
  utc_6.zoneUtc = -6;
  utc_6.longitudeUtcMin = 82.5;
  utc_6.longitudeUtcMax = 97.5;
  utc_6.longitude_orientation = 'W';

  zoneUtc utc_7;
  utc_7.zoneUtc = -7;
  utc_7.longitudeUtcMin = 97.5;
  utc_7.longitudeUtcMax = 112.5;
  utc_7.longitude_orientation = 'W';

  zoneUtc utc_8;
  utc_8.zoneUtc = -8;
  utc_8.longitudeUtcMin = 112.5;
  utc_8.longitudeUtcMax = 127.5;
  utc_8.longitude_orientation = 'W';

  zoneUtc utc_9;
  utc_9.zoneUtc = -9;
  utc_9.longitudeUtcMin = 127.5;
  utc_9.longitudeUtcMax = 142.5;
  utc_9.longitude_orientation = 'W';

  zoneUtc utc_10;
  utc_10.zoneUtc = -10;
  utc_10.longitudeUtcMin = 142.5;
  utc_10.longitudeUtcMax = 157.5;
  utc_10.longitude_orientation = 'W';

  zoneUtc utc_11;
  utc_11.zoneUtc = -11;
  utc_11.longitudeUtcMin = 157.5;
  utc_11.longitudeUtcMax = 172.5;
  utc_11.longitude_orientation = 'W';

  zoneUtc utc_12;
  utc_12.zoneUtc = -12;
  utc_12.longitudeUtcMin = 172.5;
  utc_12.longitudeUtcMax = 180;
  utc_12.longitude_orientation = 'W';

  listeUtcW[12] = utc_12;
  listeUtcW[11] = utc_11;
  listeUtcW[10] = utc_10;
  listeUtcW[9] = utc_9;
  listeUtcW[8] = utc_8;
  listeUtcW[7] = utc_7;
  listeUtcW[6] = utc_6;
  listeUtcW[5] = utc_5;
  listeUtcW[4] = utc_4;
  listeUtcW[3] = utc_3;
  listeUtcW[2] = utc_2;
  listeUtcW[1] = utc_1;
  listeUtcW[0] = utc_0;
  
  listeUtcE[0] = utc0;
  listeUtcE[1] = utc1;
  listeUtcE[2] = utc2;
  listeUtcE[3] = utc3;
  listeUtcE[4] = utc4;
  listeUtcE[5] = utc5;
  listeUtcE[6] = utc6;
  listeUtcE[7] = utc7;
  listeUtcE[8] = utc8;
  listeUtcE[9] = utc9;
  listeUtcE[10] = utc10;
  listeUtcE[11] = utc11;
  listeUtcE[12] = utc12;
  
}



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
horloge_RTC Extract_date_heure_from_GPS(){
  
  horloge_RTC newHorloge;
    /* Date */
  char *date= "";
  char jj[3]= "";
  char mm[3]= "";
  char yy[3]= "";
  date = msg[9];

    /* Horaire */
  char *horaire= "";
  char hh[3]= "";
  char minute[3]= "";
  char ss[3]= "";
  horaire = msg[1];

  jj[0] = date[0];
  jj[1] = date[1];
  mm[0] = date[2];
  mm[1] = date[3];
  yy[0] = date[4];
  yy[1] = date[5];

  hh[0] = horaire[0];
  hh[1] = horaire[1];
  minute[0] = horaire[2];
  minute[1] = horaire[3];
  ss[0] = horaire[4];
  ss[1] = horaire[5];

  newHorloge.calendrier.jour_mois = atoi(jj);
  newHorloge.calendrier.mois = atoi(mm);
  newHorloge.calendrier.annee = atoi(yy);


  /* Gestion heure hiver/ete */
  if (newHorloge.calendrier.mois >= 11 || newHorloge.calendrier.mois <= 3){
    newHorloge.horaire.heure = atoi(hh) + 1;
  }
  else {
   newHorloge.horaire.heure = atoi(hh);
  }
 
  newHorloge.horaire.minute = atoi(minute);
  newHorloge.horaire.seconde  = atoi(ss);

  return newHorloge;
}
/*--------------------------------------------------------------------------------------------*/
// Conversion coordonnées géographiques GPS en dd°.xxxxxx
/*--------------------------------------------------------------------------------------------*/
horloge_RTC Correction_Heure_Date() {
  horloge_RTC newHorloge;

  if(Test_Synchro_GPS){
    newHorloge = Extract_date_heure_from_GPS();
    zoneUtcConstructeur();
    char *longitude= "";
    char longitudeOrientation;
    double vraiLongitude;
    char extractLongitude[6];
    
    /* SIGNAL GPRMC*/
    if( (strcmp(msg[0],"$GPRMC") == 0) ){
      longitude = msg[5];
      //longitude = "00888.1165";
      longitudeOrientation = msg[6][0];
     
      
    }
    else if ( (strcmp(msg[0],"$GPGGA") == 0) ){
      longitude = msg[4];
      longitudeOrientation = msg[5][0];
    }
    extractLongitude[0] = longitude[0];
    extractLongitude[1] = longitude[1];
    extractLongitude[2] = longitude[2];
    extractLongitude[3] = '.';
    extractLongitude[4] = longitude[3];
    extractLongitude[5] = longitude[4];
    vraiLongitude = atof(extractLongitude);
    
    if( longitudeOrientation == 'W') {
      for(int i = 0;i<13;i++){
        if( (listeUtcW[i].longitudeUtcMin < vraiLongitude) && (vraiLongitude < listeUtcW[i].longitudeUtcMax) ){
            newHorloge.horaire.heure += listeUtcW[i].zoneUtc;
            if(newHorloge.horaire.heure > 23) {
              newHorloge.horaire.heure = 24 - newHorloge.horaire.heure; 
              newHorloge.calendrier.jour_mois += 1;
              if((newHorloge.calendrier.jour_mois > 29) && (horlogeRtc.calendrier.mois%2 == 0) ){
                horlogeRtc.calendrier.mois++;
                newHorloge.calendrier.jour_mois = 1;
              }
              if((newHorloge.calendrier.jour_mois > 30) && (horlogeRtc.calendrier.mois%2 != 0) ){
                horlogeRtc.calendrier.mois++;
                newHorloge.calendrier.jour_mois = 1;
              }
                
            }
        }
      }
    }
    else if( longitudeOrientation == 'E') {
      for(int i = 0;i<15;i++){
        if( (listeUtcE[i].longitudeUtcMin < vraiLongitude) && (vraiLongitude < listeUtcE[i].longitudeUtcMax) ){
            newHorloge.horaire.heure += listeUtcE[i].zoneUtc;
        }
      }
    }
  }
  return newHorloge;
}
/*--------------------------------------------------------------------------------------------*/
