// Fichier BME680_Sensor.cpp
// Fonctions de gestion du capteur BME680
// Acquisition des mesures depuis le capteur BME680
// - Température en °C dans [-40.0; 80.0]
// - Pression en hPa dans [900.00; 13000.00]
// - Humidité en % dans [0.0; 100.0]
// - IAQ : mesure dans [0.0; 500.0] (IAQ ; Index Air Quality)
// - IAQ_Acc : valeur dans {0, 1, 2, 3} (Précision de la mesure de l'Index Air Quality)
// - CO2 en ppm (Concentration en CO2)
// - COV en ppm (Concentration des Composés Organo Volatiles)

#include <Arduino.h>
//#include "bsec1.4.7.4.h"

//extern Bsec BME680_iaqSensor;
//extern String output;

/*--------------------------------------------------------------------------------------------*/
// Fonctions additionnelles de gestions du capteur BME680
/*--------------------------------------------------------------------------------------------*/
/*
void errLeds(void) // Gestion de la led sur port 13 en cas d'erreur capteur BME680
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}
*/
/*--------------------------------------------------------------------------------------------*/
/*
void checkIaqSensorStatus(void) // Vérifier l'état du capteur
{
  if (BME680_iaqSensor.status != BSEC_OK) 
  {
    if (BME680_iaqSensor.status < BSEC_OK) 
    {
      output = "BSEC error code : " + String(BME680_iaqSensor.status);
      Serial.println(output);
      for (;;)
        errLeds(); //Halt in case of failure
    } else 
    {
      output = "BSEC warning code : " + String(BME680_iaqSensor.status);
      Serial.println(output);
    }
  }

  if (BME680_iaqSensor.bme680Status != BME680_OK) 
  {
    if (BME680_iaqSensor.bme680Status < BME680_OK) 
    {
      output = "BME680 error code : " + String(BME680_iaqSensor.bme680Status);
      Serial.println(output);
      for (;;)
        errLeds(); //Halt in case of failure
    } else 
    {
      output = "BME680 warning code : " + String(BME680_iaqSensor.bme680Status);
      Serial.println(output);
    }
  }
}
*/
/*--------------------------------------------------------------------------------------------*/
