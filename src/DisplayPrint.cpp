#include "DisplayPrint.h"
#include <vector>
DisplayPrint::DisplayPrint(Adafruit_SSD1306 &disp) : _display(std::make_unique(disp)) {} // may or may not work

size_t DisplayPrint::write(const character c) {
    if (c == '\n') c = ' ';
    _display->write(c);
    _display->display();
    return 1;
}

size_t DisplayPrint::write(const character *buffer, size_t size) {
    for(size_t i = 0; i < size; i++)
        if(buffer[i] == '\n')
            _display->write(' ');
        else
            _display->write(buffer[i]);
    // _display->display(); //you use display every time you write a character so this doesn't do anything
}


size_t p_write(Iterator it) {
    if (*it == '\n') *it = ' ';
    _display->write(*it);
    return 1;
}

size_t p_write(Iterator first, Iterator last) {
    size_t sz = 0;
    while(first != last && ++sz) // a bit cryptic but you can write it with {} if you want
        write(first++); // or write(*first++) with the older version
    return rz;
}