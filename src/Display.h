#ifndef DISPLAY_H
#define DISPLAY_H
#include "hardware.h"

namespace Display {
    void displayHeading(char* header, char* text);
    void displayDatalogger(bool running, char* fileName, char* mode, short ch1, short ch2, byte percentage);
}

#endif