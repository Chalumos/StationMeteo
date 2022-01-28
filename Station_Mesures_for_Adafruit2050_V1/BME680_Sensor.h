// Fichier BME680_Sensor.h


#include <Arduino.h>

extern String output;

// Définition de constantes symboliques
#define OFFSET_PRESSION_COMPENSATION 610L // Correction de la mesure de pression en Pa par rapport aux relevés météo
#define OFFSET_TEMPERATURE_COMPENSATION -5 // Correction de la mesure de temperature en 1/10 de °C

// Ci-dessous option
//#define MAJ_PARAM_COMP_BME680_FLAG // Pour provoquer le stockage des paramètres de compensation en EEPROM (valeur 1)
//#undef MAJ_PARAM_COMP_BME680_FLAG // Pour inhiber le stockage des paramètres de compensation en EEPROM (valeur 0)

String  ExtractionDonneesBME680();
// Fonctions prototypes
void checkIaqSensorStatus(void); // Vérifier l'état du capteur
void errLeds(void); // Gestion de la led sur port 13 en cas d'erreur capteur BME680
