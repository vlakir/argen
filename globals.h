#pragma once

#include <Arduino.h>

#define MODE_SIN 0
#define MODE_PULSE 1
#define MODE_TRIANGLE 2
#define MODE_SWEEP 3

#define KEY_PRESSED_NONE 0
#define KEY_PRESSED_UP 1
#define KEY_PRESSED_DOWN 2
#define KEY_PRESSED_MODE 3

#define KEY_UP_IO_PORT 2
#define KEY_DOWN_IO_PORT 3
#define KEY_MODE_IO_PORT 4

#define CURSOR_BLINK_PERIOD_MS 250
#define KEYBOARD_SCAN_PERIOD_MS 50
#define DDS_SET_PERIOD_MS 1000
#define KEYBOARD_DEADLOCK_MS 100


extern long volatile lFreqBasicHz;
extern long volatile lFreqLowHz;
extern long volatile lVoltageuV;
extern byte volatile byMode;
extern byte volatile byCursorPosition;



