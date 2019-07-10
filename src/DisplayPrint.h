#ifndef DISPLAYPRINT_H
#define DISPLAYPRINT_H

#include <Print.h>
#include "Adafruit_SSD1306.h"
#include <memory>

class DisplayPrint : public Print {
public:
    using character = uint8_t; // makes code more readable (?)

    DisplayPrint(Adafruit_SSD1306 &disp);
    size_t write(character) override;
    size_t write(const character *buffer, size_t size) override;
    size_t p_write(Iterator first, Iterator last); // use as helper for write
    size_t p_write(Iterator it); // use as helper for write
private:
    using Iterator = character*;

    Iterator end(const character* s, size_t sz) {
        return s + sizeof(character) * sz; // might not need to multiply with sizeof(character)
    }

    Iterator begin(const character* s) {
        return s;
    }

    // Adafruit_SSD1306 &_display;
    std::unique_ptr<Adafruit_SSD1306> _display;
};

#endif