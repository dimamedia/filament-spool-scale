# Blind spool scale
Scale for blind filament spools to see how much is left

The scale code is for Attiny85 chip with 128x32 I2C OLED display and HX711 5kg load cell.

## Pinout

```
                -| 5               VCC |- 
  LOAD CELL SCK -| 3    ATtiny85     2 |- SCL LCD
  LOAD CELL DT  -| 4                 1 |-
                -| GND               0 |- SDA LCD
```
