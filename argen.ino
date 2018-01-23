#include "argen.h"

long volatile lFreqBasicHz;
long volatile lFreqLowHz;
long volatile lVoltageuV;
byte volatile byMode;
byte volatile byCursorPosition;

Timer xBlinkCursorTimer, xKeyboardScanTimer, xDDSsetTimer;

void setup() 
{
	lFreqBasicHz = 1000;
	lFreqLowHz = 100;
	lVoltageuV = 1000;
	byMode = MODE_SWEEP;
	byCursorPosition = 0;
		
	vInitScreen();
	xBlinkCursorTimer.every(CURSOR_BLINK_PERIOD_MS, vBlinkCursor);
	
	vInitKeyboard();
	xKeyboardScanTimer.every(KEYBOARD_SCAN_PERIOD_MS, vMainScreenControl);

	
	vInitDDS();
	xDDSsetTimer.every(DDS_SET_PERIOD_MS, vDDSset);
	//vDDSset();

	//Serial.begin(9600);
}


void loop() 
{
	xBlinkCursorTimer.update();	
	xKeyboardScanTimer.update();
	xDDSsetTimer.update();	
}











