#include "screens.h"

LiquidCrystal_I2C xLCD(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
ConvertToCyrLCD xConverter = ConvertToCyrLCD(UTF8);

void vInitScreen() 
{
	xLCD.begin(20,4); 
	xLCD.noBlink();
	xLCD.backlight();	
	xLCD.clear();
	byCursorPosition = 0;
	vMainSqreen();
}

void vMainSqreen() 
{	
	xLCD.setCursor(1,0);
	
	if (byMode==MODE_SWEEP)
	{
		printLCD(F("Fверх = "));
	} else {
		printLCD(F("Fосн = "));
	}
	
	printLCD(xFreqRepresentation(lFreqBasicHz));
	
	xLCD.setCursor(1,1);
	printLCD(F("Режим: "));
	printLCD(xModeRepresentation (byMode));

	if (byMode==MODE_SWEEP)
	{
		xLCD.setCursor(1,2);
		printLCD(F("Fнижн = "));
		printLCD(xFreqRepresentation(lFreqLowHz));
	} 
	
	xLCD.setCursor(1,3);
	printLCD(F("Амплитуда: "));
	printLCD(xVoltageRepresentation(lVoltageuV));
	
	vBlinkCursor ();
}

void vBlinkCursor()
{
	static bool bBlink;
	xLCD.setCursor(0, byCursorPosition);
	if (bBlink)
	{
		printLCD(F(">"));
	}
	else {
		printLCD(F(" "));
	}
	bBlink = !bBlink;
}

void vClearRow(byte RowNum) {
	xLCD.setCursor(0, RowNum);
	printLCD(F("                    "));
}

void vClearAll() {
	xLCD.clear();
}

static String xFreqRepresentation (long lFreqHz) 
{
	String xResult;
	if (lFreqHz < 10000) 
	{
		xResult = String((double) lFreqHz, 0) + String(F("Гц"));
	} else if (lFreqBasicHz < 1e6) {
		xResult = String(((double) lFreqHz)/1000, 0) + String(F("кГц"));
	} else {
		xResult = String(((double) lFreqHz)/1e6, 1) + String(F("MГц"))	;
	}
	return xResult;
}

static String xVoltageRepresentation (long lVoltageuV) 
{
	String xResult;
	if (lVoltageuV < 1000) 
	{
		xResult = String((double) lVoltageuV, 0) + String(F("мкВ"));
	} else if (lVoltageuV < 1e4) {
		xResult = String(((double) lVoltageuV)/1000, 1) + String(F("мВ"));
	}
	else if (lVoltageuV < 1e6) {
		xResult = String(((double)lVoltageuV) / 1000, 0) + String(F("мВ"));
	} else {
		xResult = String(((double) lVoltageuV)/1e6, 1) + String(F("В"))	;
	}
	return xResult;
}

static String xModeRepresentation (byte byMode) 
{
	String xResult;
	switch (byMode) 
	{
		case MODE_SIN: {xResult = String(F("синус"));break;}
		case MODE_PULSE: {xResult = String(F("меандр"));break;}
		case MODE_TRIANGLE: {xResult = String(F("треугольник"));break;}
		case MODE_SWEEP: {xResult = String(F("ГКЧ"));break;}
		default: xResult = String(F("неопределен"));
	}	
	return xResult;
}

static void printLCD(String xValue) {
	xLCD.print(xConverter.convert(xValue));
}



