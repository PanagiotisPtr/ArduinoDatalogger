#include "hardware.h"
#include "Display.h"
#include "DisplayPrint.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
SPIClass SPI_1 = SPIClass();
SdFat sd;

void setup() {
  pinMode(PC13, OUTPUT);
  digitalWrite(PC13,LOW);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while(1) {
      digitalWrite(PC13,HIGH);//If the display fails, we have no way of displaying this other than flashing the board LED on and off.
      delay(1000);
      digitalWrite(PC13,LOW);
      delay(1000);
    }
  }
  Display::displayHeading("Starting", "Initialising the SD card");
  // Setup SD card 
  if (!sd.begin(SD_CS, SPI_SPEED)) {
    if (sd.cardErrorCode() == 0x20) {
      Display::displayHeading("Error!","No card present. Please rectify and press the reset button.");
      while(1);
    } else {
      DisplayPrint errorPrinter(display);
      Display::displayHeading("Error!", "");
      display.setCursor(0,16);
      sd.initErrorHalt(&errorPrinter);
    }
  }
  Display::displayHeading("Starting", "SD card initialised");

  delay(1000);

  Display::displayHeading("Success", "Well done!");
}

void loop() {
}

