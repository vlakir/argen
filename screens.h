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
void vClearCursorWay();
void vBlinkCursor ();
void vBackLightOff();
void vBackLightOn();
void vBackLightFadeOff();
void vBackLightFadeOn();
static String _xFreqRepresentation (long lFreqHz);
static String _xVoltageRepresentation (long lVoltageuV);
static String _xModeRepresentation (byte byMode);
static void _vPrintLCD(String xValue);
static void _vPrintLCDwithSpaces(String xValue, byte byStartPosition);
static void _vSetCursor(byte byColNum, byte byRowNum);
static void _vBackLightPWM(char cBright, long lTimeMS);

