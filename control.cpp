#include "control.h"

VirtualDelay xVdelay;
bool bKeyboardDeadlock;

void vMainScreenControl()
{
	
	DO_ONCE(xVdelay.start(100));
	byte byKeyPressed = KEY_PRESSED_NONE;

	
	if (!bKeyboardDeadlock) {
		byKeyPressed = byScanKeyboard();
		switch (byKeyPressed)
		{
		case KEY_PRESSED_MODE:
			if (byCursorPosition < 3)
			{
				byCursorPosition++;
				if ((byCursorPosition == 2) && (byMode != MODE_SWEEP))
				{
					byCursorPosition++;
				}
			}
			else
			{
				byCursorPosition = 0;
			}
			vClearAll();
			break;
		case KEY_PRESSED_UP:
			switch (byCursorPosition)
			{
				case 0:
					lFreqBasicHz = _lChangeValue(lFreqBasicHz, 1);
					vClearRow(byCursorPosition);
					break;
				case 1:
					if (byMode<3) {
						byMode++;
					}
					vClearAll();
					break;
				case 2:
					lFreqLowHz = _lChangeValue(lFreqLowHz, 1);
					vClearRow(byCursorPosition);
					break;
				case 3:
					lVoltageuV = _lChangeValue(lVoltageuV, 1);
					vClearRow(byCursorPosition);
					break;
				default: {}
			}						
			break;
		case KEY_PRESSED_DOWN:
			switch (byCursorPosition)
			{
			case 0:
				lFreqBasicHz = _lChangeValue(lFreqBasicHz, -1);
				vClearRow(byCursorPosition);
				break;
			case 1:
				if (byMode>0) {
					byMode--;
				}
				vClearAll();
				break;
			case 2:
				lFreqLowHz = _lChangeValue(lFreqLowHz, -1);
				vClearRow(byCursorPosition);
				break;
			case 3:
				lVoltageuV = _lChangeValue(lVoltageuV, -1);
				vClearRow(byCursorPosition);
				break;
			default: {}
			}
			break;
		case KEY_PRESSED_NONE: {}
		default: {}
		}

		if (byKeyPressed!= KEY_PRESSED_NONE)
		{
			vMainSqreen();
			bKeyboardDeadlock = true;
			xVdelay.start(KEYBOARD_DEADLOCK_MS);
		}
	}

	if (xVdelay.elapsed()) bKeyboardDeadlock = false;
	
}

static long _lChangeValue(long lValue, long lDivider)
{
	long lResult = lValue;
	if (lValue <= (1e7 - 1e5) && lValue>1)
	{
		lResult += _lDeltaValue(lValue)/lDivider;
	}
	return lResult;
}


static long _lDeltaValue(long lValue)
{
	long lResult = 0;
	
	if (lValue<100)
	{
		lResult = 1;
	} else if (lValue < 1000) 
	{
		lResult = 10;
	} else if (lValue < 1e4) 
	{
		lResult = 100;
	} else if (lValue < 1e5) 
	{
		lResult = 1000;
	} else if (lValue < 1e6) 
	{
		lResult = 1e4;
	}
	else 
	{
		lResult = 1e5;
	}

	return lResult;
}