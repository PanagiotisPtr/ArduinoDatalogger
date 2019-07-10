#ifndef DISPLAY_H
#define DISPLAY_H
#include "hardware.h"

namespace Display {
    void displayHeading(char* header, char* text);
    // A bit too many parameters. Would be good if there was a way to reduce them.
    void displayDatalogger(bool running, const char* fileName, 
                           const char* mode, short ch1, short ch2, byte percentage);
}

#endif