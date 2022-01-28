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
#include "bsec.h"

extern Bsec BME680_iaqSensor;
extern String output;


bsec_virtual_sensor_t sensorList[10] = {
  BSEC_OUTPUT_RAW_TEMPERATURE,
  BSEC_OUTPUT_RAW_PRESSURE,
  BSEC_OUTPUT_RAW_HUMIDITY,
  BSEC_OUTPUT_RAW_GAS,
  BSEC_OUTPUT_IAQ,
  BSEC_OUTPUT_STATIC_IAQ,
  BSEC_OUTPUT_CO2_EQUIVALENT,
  BSEC_OUTPUT_BREATH_VOC_EQUIVALENT,
  BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_TEMPERATURE,
  BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_HUMIDITY,
};

String  ExtractionDonneesBME680() {
  
  unsigned long time_trigger = millis();
  BME680_iaqSensor.begin(BME680_I2C_ADDR_PRIMARY, Wire);
  BME680_iaqSensor.updateSubscription(sensorList, 10, BSEC_SAMPLE_RATE_LP);
  
  if (BME680_iaqSensor.run()) {  // si on a des donnes

    output = "Température : " + String(BME680_iaqSensor.temperature) + " °C";
    output += "\n";
    output += "Pression atmosphérique :  " + String(BME680_iaqSensor.pressure) + " hPa";
    output += "\n";
    output += "Taux d'humidité : " + String(BME680_iaqSensor.humidity) + " %";
    output += "\n";
    output += "IAQ : " + String(BME680_iaqSensor.iaq);
    output += "\n";
    output += "IAQ Accuracy : " + String(BME680_iaqSensor.iaqAccuracy);
    output += "\n";
    output += "CO2 : " + String(BME680_iaqSensor.co2Equivalent) + " ppm";
    output += "\n";
    output += "COV : " + String(BME680_iaqSensor.breathVocEquivalent) + " ppm";

    return output;
  }
  return output;
}
/*--------------------------------------------------------------------------------------------*/
// Fonctions additionnelles de gestions du capteur BME680
/*--------------------------------------------------------------------------------------------*/

void errLeds(void) // Gestion de la led sur port 13 en cas d'erreur capteur BME680
{
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

/*--------------------------------------------------------------------------------------------*/

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

/*--------------------------------------------------------------------------------------------*/
