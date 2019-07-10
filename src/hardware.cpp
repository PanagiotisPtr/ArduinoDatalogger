#include "hardware.h"

float adcToVoltage(float adc) { // cast to float to avoid rounding errors
    return adc / 1024.0 * 3 / 2;
}