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
#define SWEEP_PERIOD_MS 200UL
#define SWEEP_DISCRETE 200UL

#define SWEEP_DELAY_CORRECTION_US 145
#define SWEEP_DELAY_US SWEEP_PERIOD_MS * 1000 / SWEEP_DISCRETE - SWEEP_DELAY_CORRECTION_US

#define FREQ_BASIC_INIT_VALUE_HZ 1000UL
#define FREQ_LOW_INIT_VALUE_HZ 20UL
#define OUTPUT_INIT_VALUE_UV 1000UL
#define MODE_INIT_VALUE MODE_SIN
#define CURSOR_POS_INIT_VALUE 0

#define BACKLIGHT_OFF_AFTER_S 30UL
#define BACKLIGHT_FADE_TIME_MS 500UL

extern long volatile lFreqBasicHz;
extern long volatile lFreqLowHz;
extern long volatile lOutputuV;
extern char volatile cMode;
extern char volatile cCursorPosition;
extern bool volatile bNoBlinkCursor;



