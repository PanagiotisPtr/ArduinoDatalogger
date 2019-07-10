#ifndef HARDWARE_H
#define HARDWARE_H

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SdFat.h>
#include "FreeStack.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET    4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SPI_SPEED SD_SCK_MHZ(18)
#define SD_CS PA4

extern Adafruit_SSD1306 display;
extern SdFat sd;

float adcToVoltage(short adc);

#endif