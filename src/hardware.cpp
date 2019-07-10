#include "hardware.h"

float adcToVoltage(short adc) {
    return adc / 1024.0 * 3 / 2;
}