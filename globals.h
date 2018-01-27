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

#define CURSOR_BLINK_PERIOD_MS 500UL
#define KEYBOARD_SCAN_PERIOD_MS 50UL
#define DDS_SET_PERIOD_MS 1000UL
#define KEYBOARD_DEADLOCK_MS 100UL
#define BACKLIGHT_OFF_AFTER_S 60UL

#define FREQ_BASIC_INIT_VALUE_HZ 1000UL
#define FREQ_LOW_INIT_VALUE_HZ 100UL
#define OUTPUT_INIT_VALUE_UV 1000UL
#define MODE_INIT_VALUE MODE_SWEEP
#define CURSOR_POS_INIT_VALUE 0

extern long volatile lFreqBasicHz;
extern long volatile lFreqLowHz;
extern long volatile lOutputuV;
extern byte volatile byMode;
extern byte volatile byCursorPosition;
extern bool volatile noBlinkCursor;



