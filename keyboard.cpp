#include "keyboard.h"

void vInitKeyboard() {
	pinMode(KEY_UP_IO_PORT, INPUT_PULLUP);
	pinMode(KEY_DOWN_IO_PORT, INPUT_PULLUP);
	pinMode(KEY_MODE_IO_PORT, INPUT_PULLUP);
}

byte byScanKeyboard() {
	byte byKeyPressed;
	if (digitalRead(KEY_MODE_IO_PORT) == LOW)
		byKeyPressed = KEY_PRESSED_MODE;
	else if (digitalRead(KEY_UP_IO_PORT) == LOW)
		byKeyPressed = KEY_PRESSED_UP;
	else if (digitalRead(KEY_DOWN_IO_PORT) == LOW)
		byKeyPressed = KEY_PRESSED_DOWN;
	else
		byKeyPressed = KEY_PRESSED_NONE;
	return byKeyPressed;
}


