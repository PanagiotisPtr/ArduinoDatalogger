#include "Display.h"

void Display::displayHeading(const char* header, const char* text) {
    display.clearDisplay();
    display.setTextColor(WHITE);

    display.setTextSize(2);
    display.setCursor(0,0);
    display.print(header);

    display.setCursor(0,32);
    display.setTextSize(1);
    display.print(text);

    display.display();
}


// Why 'byte' and not unsigned char?
void Display::displayDatalogger(bool running, const char* fileName, 
                                const char* mode, short ch1, short ch2, 
                                byte percentage) {
    display.clearDisplay();
    display.setTextColor(WHITE);

    // could be it's own function 
    display.setTextSize(1);
    display.setCursor(60,16);
    display.print("CH1");
    display.setCursor(60,32);
    display.print("CH2");
    display.setCursor(0,16);
    display.print("File");
    display.setCursor(0,42);
    display.print("Mode:");
    display.setCursor(30, 42);
    display.print(mode);

    // could be it's own function 
    display.setTextSize(2);
    display.setCursor(0,0);
    display.print(running ? "Running" : "Ready");

    // could be it's own function 
    display.setCursor(80,16);
    display.print(String(adcToVoltage(ch1),2));
    display.setCursor(80,32);
    display.print(String(adcToVoltage(ch2),2));
    display.setCursor(0, 24);
    display.print(fileName);
    
    // could be it's own function but doesn't have to be
    display.drawRect(12, 57, 104, 6, WHITE);
    display.fillRect(14, 59, percentage, 3, WHITE);

    display.display();
}