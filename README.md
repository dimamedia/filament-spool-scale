# Filament spool scale
Scale for blind filament spools to see how much is left

The scale code is for Attiny85 chip with 128x32 I2C OLED display and HX711 5kg load cell.

## Parts needed

[Thingiverse: filament spool scale](https://www.thingiverse.com/thing:3909051)

## Wiring pinout

```
Attiny85:

                             -| P5      VCC |- 5V, HX711 VCC, LCD VCC
                   HX711 SCK -| P3       P2 |- SCL LCD
                   HX711 DT  -| P4       P1 |-
     HX711 GND, LCD GND, GND -| GND      P0 |- SDA LCD


OR Attiny85 dev board:

           LCD VCC, HX711 VCC -| 5V      P0 |- LCD SDA
      LCD GND, HX711 GND, GND -| GND     P1 |- 
           5V OR STEP UP VOUT -| VIN     P2 |- LCD SCL
                                         P3 |- HX711 SCK
                                         P4 |- HX711 DT
                                         P5 |-
 
HX711:

              LOAD CELL RED   -| E+     GND |- GND, ATTINY85 GND
              LOAD CELL BLACK -| E-      DT |- ATTINY85 P4
              LOAD CELL WHITE -| A-     SCK |- ATTINY85 P3
              LOAD CELL GREEN -| A+     VCC |- VCC, ATTINY85 VCC
                              -| B-
                              -| B+
                
                
OLED 128x32:

    GND |- ATTINY85 GND
    VCC |- ATTINY85 5V/VCC
    SCL |- ATTINY85 P0
    SDA |- ATTINY85 P2
```

## Note

HX711 adapter require strict 5v source to work properly. Some switching power sources for cell phones cause faulty working in this scale. That why I use step up voltage regulator instead of attiny85 board's usb.
