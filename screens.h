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
static String _xFreqRepresentation (long lFreqHz);
static String _xVoltageRepresentation (long lVoltageuV);
static String _xModeRepresentation (byte byMode);
static void _printLCD(String xValue);
static void _setCursor(byte byColNum, byte byRowNum);

