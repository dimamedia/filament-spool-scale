/*
 * Blind spool scale V1.0
 * 2019-10-10
 * Author: Dima Tsvetkov
 * GNU v3 License
 */

#include <Tiny4kOLED.h>
#include <HX711.h>

#define DOUT 4 // Data pin for scale adapter
#define CLK 3 // Clock pin for scale adapter

#define SMALL_CASE 118 // Small 3D printed airtight spool case's weight in gramms
#define BIG_CASE 240 // // Small 3D printed airtight spool case's weight in gramms
#define SMALL_SPOOL 109 // 3DJake small empty spool's weight in gramms
#define BIG_SPOOL 254 // Fillamentum's 200mm empty spool's weight in gramms
#define 250_FILAMENT  250 // 250g filament
#define 500_FILAMENT  500 // 500g filament
#define SILICA 6 // approx 6g

HX711 scale;

float calibration_factor = 383950; // calibration setting

void setup() {
  scale.begin(DOUT, CLK);
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  //long zero_factor = scale.read_average(); //Get a baseline reading

  oled.begin();
  oled.clear();
  oled.on();
}

void loop() {
  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  oled.setFont(FONT8X16);
  oled.setCursor(0, 0);
  oled.print(F("Weight: "));
  oled.print(scale.get_units()*1000, 0);
  oled.print(" g ");

  oled.setFont(FONT6X8);

  // Small spool weight
  float real_weight = scale.get_units()*1000-SMALL_CASE-SMALL_SPOOL-SILICA;
  float pros = (real_weight/250_FILAMENT)*100;
  if(pros < 0) pros = 0;
  oled.setCursor(0, 2);
  oled.print(F("3DJake 250: "));
  oled.print(pros, 0);
  oled.print(F("% "));

  // Big spool weight
  real_weight = scale.get_units()*1000-BIG_CASE-BIG_SPOOL-SILICA;
  pros = (real_weight/500_FILAMENT)*100;
  if(pros < 0) pros = 0;
  oled.setCursor(0, 3);
  oled.print(F("Fillamentum 500: "));
  oled.print(pros, 0);
  oled.print(F("% "));


  delay(200);
}
