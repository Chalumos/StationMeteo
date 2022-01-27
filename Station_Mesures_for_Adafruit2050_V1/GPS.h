// Fichier GPS.h
#include "RTC_DS1307.h"
// Définition des types de données pour gestion des données GPS


// Définition de constantes symboliques

extern char NMEA[100];
extern char * msg[100];

// Fonctions prototypes

void get_msg();
char** GPS_msg_parse(char trame[100]);
int Test_Synchro_GPS();
void Choix_Msg_NMEA();
int testChaine(char str1[6], char str2[6]);
horloge_RTC ExtractionDateHeure();
