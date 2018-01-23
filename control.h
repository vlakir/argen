#pragma once

#include "globals.h"
#include "avdweb_VirtualDelay.h"
#include "screens.h"
#include "keyboard.h"

void vInitKeyboard();
void vMainScreenControl();
byte byScanKeyboard();
static long lChangeValue(long lFreq, long lDivider);
static long lDeltaValue(long lFreq);
