#include "Display.h"

void Display::displayHeading(char* header, char* text) {
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