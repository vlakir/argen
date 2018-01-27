#include "screens.h"

LiquidCrystal_I2C xLCD(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
ConvertToCyrLCD xConverter = ConvertToCyrLCD(UTF8);

void vInitScreen() {
	xLCD.begin(20, 4);
	xLCD.noBlink();
	xLCD.clear();
	cCursorPosition = 0;
	vMainSqreen();
}

void vMainSqreen() {
	_vSetCursor(1, 0);

	if (cMode == MODE_SWEEP) {
		_vPrintLCD(F("Fверх = "));
	} else {
		_vPrintLCD(F("Fосн  = "));
	}

	_vPrintLCDwithSpaces(_xFreqRepresentation(lFreqBasicHz), 9);

	_vSetCursor(1, 1);
	_vPrintLCD(F("Режим: "));
	_vPrintLCDwithSpaces(_xModeRepresentation(cMode), 8);

	if (cMode == MODE_SWEEP) {
		_vSetCursor(1, 2);
		_vPrintLCD(F("Fнижн = "));
		_vPrintLCDwithSpaces(_xFreqRepresentation(lFreqLowHz), 9);
	}

	_vSetCursor(1, 3);
	_vPrintLCD(F("Амплитуда: "));
	_vPrintLCDwithSpaces(_xVoltageRepresentation(lOutputuV), 12);

	vBlinkCursor();
}

void vBlinkCursor() {
	static bool bBlink;
	_vSetCursor(0, cCursorPosition);
	if (bNoBlinkCursor) {
		_vPrintLCD(F(">"));
	} else {
		if (bBlink) {
			_vPrintLCD(F(">"));
		} else {
			_vPrintLCD(F(" "));
		}
	}
	bBlink = !bBlink;
}

void vClearRow(byte byRowNum) {
	_vSetCursor(0, byRowNum);
	_vPrintLCD(F("                    "));
}

void vClearAll() {
	xLCD.clear();
}

void vClearCursorWay() {
	for (byte i = 0; i <= 3; i++) {
		_vSetCursor(0, i);
		_vPrintLCD(F(" "));
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


static void _vPrintLCD(String xValue) {
	xLCD.print(xConverter.convert(xValue));
}


static void _vPrintLCDwithSpaces(String xValue, byte byStartPosition) {
	//add spaces up to full row
	String xResult = xConverter.convert(xValue);
	byte bySpacesLength = (20 - byStartPosition) - xResult.length();
	for (byte i = 1; i < (bySpacesLength); i++) {
		xResult += " ";
	}
	xLCD.print(xResult);
}

static void _vSetCursor(byte byColNum, byte byRowNum) {
	xLCD.setCursor(byColNum, byRowNum);
}



