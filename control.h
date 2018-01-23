#pragma once

#include "globals.h"
#include "avdweb_VirtualDelay.h"
#include "screens.h"
#include "keyboard.h"

void vMainScreenControl();
static long _lChangeValue(long lFreq, long lDivider);
static long _lDeltaValue(long lFreq);
