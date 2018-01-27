#include "control.h"

VirtualDelay xKeyboardDeadlockDelay, xBackLightOffDelay;
bool bKeyboardDeadlock;

void vInitControl() {
	vInitKeyboard();
	vBackLightOn();
	xKeyboardDeadlockDelay.start(KEYBOARD_DEADLOCK_MS);
	xBackLightOffDelay.start(BACKLIGHT_OFF_AFTER_S * 1000);
}

void vMainScreenControl() {
	byte byKeyPressed = KEY_PRESSED_NONE;

	if (!bKeyboardDeadlock) {
		byKeyPressed = byScanKeyboard();
		switch (byKeyPressed) {
		case KEY_PRESSED_MODE:
			_vIfModeKeyPressed();
			break;
		case KEY_PRESSED_UP:
			_vIfUpKeyPressed();
			break;
		case KEY_PRESSED_DOWN:
			_vIfDownKeyPressed();
			break;
		case KEY_PRESSED_NONE: {
			_vIfNoKeyPressed();
			break;
		}
		default: {}
		}
	}

	if (xKeyboardDeadlockDelay.elapsed()) 
		bKeyboardDeadlock = false;
	if (xBackLightOffDelay.elapsed()) 
		vBackLightOff();
}

static long _lChangeValue(long lValue, long lDivider) {
	long lResult = lValue;
	if (lValue <= (1e7 - 1e5) && lValue >= 1) {
		lResult += _lDeltaValue(lValue) / lDivider;
	}

	if (lResult == 0) lResult = 1;
	return lResult;
}

static long _lDeltaValue(long lValue) {
	long lResult = 0;

	if (lValue < 100) {
		lResult = 1;
	} else if (lValue < 1000) {
		lResult = 10;
	} else if (lValue < 1e4) {
		lResult = 100;
	} else if (lValue < 1e5) {
		lResult = 1000;
	} else if (lValue < 1e6) {
		lResult = 1e4;
	} else {
		lResult = 1e5;
	}

	return lResult;
}

static void _vIfModeKeyPressed() {
	if (cCursorPosition < 3) {
		cCursorPosition++;
		if ((cCursorPosition == 2) && (cMode != MODE_SWEEP)) {
			cCursorPosition++;
		}
	} else {
		cCursorPosition = 0;
	}
	vClearCursorWay();
	_vAfterKeyPress();
}

static void _vIfUpKeyPressed() {
	_vUpOrDown(1);
	_vAfterKeyPress();
}

static void _vIfDownKeyPressed() {
	_vUpOrDown(-1);
	_vAfterKeyPress();
}

static void _vUpOrDown(char cIncrement) {
	switch (cCursorPosition) {
	case 0:
		lFreqBasicHz = _lChangeValue(lFreqBasicHz, cIncrement);
		break;
	case 1:		
		cMode += cIncrement;
		if (cMode > 3)
			cMode = 3;
		if (cMode < 0)
			cMode = 0;
		vClearAll();
		break;
	case 2:
		lFreqLowHz = _lChangeValue(lFreqLowHz, cIncrement);
		break;
	case 3:
		lOutputuV = _lChangeValue(lOutputuV, cIncrement);
		break;
	default: {}
	}
}

static void _vIfNoKeyPressed() {
	bNoBlinkCursor = false;
}

static void _vAfterKeyPress() {
	vBackLightOn();
	bNoBlinkCursor = true;
	vMainSqreen();
	bKeyboardDeadlock = true;
	xKeyboardDeadlockDelay.start(KEYBOARD_DEADLOCK_MS);
	vBackLightOn();
	xBackLightOffDelay.start(BACKLIGHT_OFF_AFTER_S * 1000);
}