#pragma once

#include "globals.h"
#include "avdweb_VirtualDelay.h"
#include "screens.h"
#include "keyboard.h"

void vInitControl();
void vMainScreenControl();
static long _lChangeValue(long lFreq, long lDivider);
static long _lDeltaValue(long lFreq);
static void _vIfModeKeyPressed();
static void _vIfUpKeyPressed();
static void _vIfDownKeyPressed();
static void _vUpOrDown(char cIncrement);
static void _vIfNoKeyPressed();
static void _vAfterKeyPress();
