#include "argen.h"

long volatile lFreqBasicHz;
long volatile lFreqLowHz;
long volatile lOutputuV;
char volatile cMode;
char volatile cCursorPosition;
bool volatile bNoBlinkCursor = false;

Timer xBlinkCursorTimer, xControlTimer, xDDSsetTimer;

void setup() {
	lFreqBasicHz = FREQ_BASIC_INIT_VALUE_HZ;
	lFreqLowHz = FREQ_LOW_INIT_VALUE_HZ;
	lOutputuV = OUTPUT_INIT_VALUE_UV;
	cMode = MODE_INIT_VALUE;
	cCursorPosition = CURSOR_POS_INIT_VALUE;

	vInitScreen();
	xBlinkCursorTimer.every(CURSOR_BLINK_PERIOD_MS, vBlinkCursor);

	vInitControl();
	xControlTimer.every(KEYBOARD_SCAN_PERIOD_MS, vMainScreenControl);

	vInitDDS();
	xDDSsetTimer.every(DDS_SET_PERIOD_MS, vDDSset);

	//Serial.begin(9600);
}

void loop() {
	xBlinkCursorTimer.update();
	xControlTimer.update();
	xDDSsetTimer.update();
}











