#include "DisplayPrint.h"
#include <vector>
DisplayPrint::DisplayPrint(Adafruit_SSD1306 &disp) : _display(disp) {}

size_t DisplayPrint::write(uint8_t c) {
    if (c == '\n') c = ' ';
    _display.write(c);
    _display.display();
    return 1;
}

size_t DisplayPrint::write(const uint8_t *buffer, size_t size) {
    for(size_t i = 0; i < size; i++)
        if(buffer[i] == '\n')
            _display.write(' ');
        else
            _display.write(buffer[i]);
    _display.display();
}