// Fichier GPS.h

// Définition des types de données pour gestion des données GPS


// Définition de constantes symboliques

extern char NMEA[100];
extern char * msg[100];

// Fonctions prototypes

void get_msg();
char** parscer(char trame[100]);
int Test_Synchro_GPS();
