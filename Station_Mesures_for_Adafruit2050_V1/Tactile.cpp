// Fichier Tactile.cpp
// Gestion de la dalle tactile écran Adafruit 2050

#include <Arduino.h>
//#include "TouchScreen.h"
//#include "Adafruit_TFTLCD.h"
// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 300 ohms across the X plate
#include "Tactile.h"

//extern TouchScreen ts;
//extern Adafruit_TFTLCD tft;

/*--------------------------------------------------------------------------------------------*/
// Acquisition point d'appui sur la dalle tactile
// La fonction Point_DalleTactile prend en compte les écrans :
// - Adafruit 2050
/*--------------------------------------------------------------------------------------------*/
/*
TSPoint Point_DalleTactile (void)
{
  TSPoint p = {0, 0, 0};

  //Pour dalle tactile shield écran Adafruit_2050_TFT
  p = ts.getPoint();
  // Mise à l'échelle 0->1023 vers tft.width() et tft.height()
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());
  
  return p;
}
*/
/*--------------------------------------------------------------------------------------------*/
