#pragma once

#include "globals.h"
#include <Wire.h>
#include "LiquidCrystal_I2C.h"
#include "CyrLCDconverter.h"
#include "avdweb_VirtualDelay.h"

void vInitScreen();
void vMainSqreen();
void vClearRow(byte RowNum);
void vClearAll();
void vBlinkCursor ();
static String xFreqRepresentation (long lFreqHz);
static String xVoltageRepresentation (long lVoltageuV);
static String xModeRepresentation (byte byMode);

