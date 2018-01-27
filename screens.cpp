#include "screens.h"

LiquidCrystal_I2C xLCD(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
ConvertToCyrLCD xConverter = ConvertToCyrLCD(UTF8);

void vInitScreen() {
	xLCD.begin(20, 4);
	xLCD.noBlink();
	//xLCD.backlight();

	//xLCD.noBacklight();

	xLCD.clear();
	byCursorPosition = 0;
	vMainSqreen();
}

void vMainSqreen() {
	_setCursor(1, 0);

	if (byMode == MODE_SWEEP) {
		_printLCD(F("Fверх = "));
	} else {
		_printLCD(F("Fосн  = "));
	}

	_printLCDwithSpaces(_xFreqRepresentation(lFreqBasicHz), 9);

	_setCursor(1, 1);
	_printLCD(F("Режим: "));
	_printLCDwithSpaces(_xModeRepresentation(byMode), 8);

	if (byMode == MODE_SWEEP) {
		_setCursor(1, 2);
		_printLCD(F("Fнижн = "));
		_printLCDwithSpaces(_xFreqRepresentation(lFreqLowHz), 9);
	}

	_setCursor(1, 3);
	_printLCD(F("Амплитуда: "));
	_printLCDwithSpaces(_xVoltageRepresentation(lOutputuV), 12);

	vBlinkCursor();
}

void vBlinkCursor() {
	static bool bBlink;
	_setCursor(0, byCursorPosition);
	if (noBlinkCursor) {
		_printLCD(F(">"));
	} else {
		if (bBlink) {
			_printLCD(F(">"));
		} else {
			_printLCD(F(" "));
		}
	}
	bBlink = !bBlink;
}

void vClearRow(byte byRowNum) {
	_setCursor(0, byRowNum);
	_printLCD(F("                    "));
}

void vClearAll() {
	xLCD.clear();
}

void vClearCursorWay() {
	for (byte i = 0; i <= 3; i++) {
		_setCursor(0, i);
		_printLCD(F(" "));
	}
}

void vBackLightOff() {
	xLCD.noBacklight();
}

void vBackLightOn() {
	xLCD.backlight();
}


static String _xFreqRepresentation(long lFreqHz) {
	String xResult;
	if (lFreqHz < 10000) {
		xResult = String((double)lFreqHz, 0) + String(F("Гц"));
	} else if (lFreqBasicHz < 1e6) {
		xResult = String(((double)lFreqHz) / 1000, 0) + String(F("кГц"));
	} else {
		xResult = String(((double)lFreqHz) / 1e6, 1) + String(F("MГц"));
	}
	return xResult;
}

static String _xVoltageRepresentation(long lVoltageuV) {
	String xResult;
	if (lVoltageuV < 1000) {
		xResult = String((double)lVoltageuV, 0) + String(F("мкВ"));
	} else if (lVoltageuV < 1e4) {
		xResult = String(((double)lVoltageuV) / 1000, 1) + String(F("мВ"));
	} else if (lVoltageuV < 1e6) {
		xResult = String(((double)lVoltageuV) / 1000, 0) + String(F("мВ"));
	} else {
		xResult = String(((double)lVoltageuV) / 1e6, 1) + String(F("В"));
	}
	return xResult;
}

static String _xModeRepresentation(byte byMode) {
	String xResult;
	switch (byMode) {
	case MODE_SIN: { xResult = String(F("синус")); break; }
	case MODE_PULSE: { xResult = String(F("меандр")); break; }
	case MODE_TRIANGLE: { xResult = String(F("треугольник")); break; }
	case MODE_SWEEP: { xResult = String(F("ГКЧ")); break; }
	default: xResult = String(F("неопределен"));
	}
	return xResult;
}


static void _printLCD(String xValue) {
	xLCD.print(xConverter.convert(xValue));
}


static void _printLCDwithSpaces(String xValue, byte byStartPosition) {
	//add spaces up to full row
	String xResult = xConverter.convert(xValue);
	byte bySpacesLength = (20 - byStartPosition) - xResult.length();
	for (byte i = 1; i < (bySpacesLength); i++) {
		xResult += " ";
	}
	xLCD.print(xResult);
}

static void _setCursor(byte byColNum, byte byRowNum) {
	xLCD.setCursor(byColNum, byRowNum);
}



