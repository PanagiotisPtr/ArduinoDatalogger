#include "DisplayPrint.h"

DisplayPrint::DisplayPrint(Adafruit_SSD1306 &disp) : _display(disp) {}

size_t DisplayPrint::write(uint8_t c) {
    if (c == '\n') c = ' ';
    _display.write(c);
    _display.display();
    return 1;
}