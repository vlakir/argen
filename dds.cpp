#include "dds.h"

AD9833 gen(10);

void vInitDDS() {
	gen.Begin();
	gen.EnableOutput(false);
	gen.ApplySignal(SINE_WAVE, REG0, FREQ_BASIC_INIT_VALUE_HZ);
	gen.SetOutputSource(REG0);
	gen.EnableOutput(true);


}

void vDDSset() {
	
	WaveformType xWaveformType;

	switch (cMode) {
		case MODE_SIN: 
			xWaveformType = SINE_WAVE;
			break;
		case MODE_PULSE:
			xWaveformType = SQUARE_WAVE;
			break;
		case MODE_TRIANGLE:
			xWaveformType = TRIANGLE_WAVE;
			break;
		case MODE_SWEEP:
			xWaveformType = SINE_WAVE;
			break;
		default:
			xWaveformType = SINE_WAVE;
	}
	
	if (cMode!= MODE_SWEEP) {
		gen.EnableOutput(true);
		gen.ApplySignal(xWaveformType, REG0, lFreqBasicHz);
	}
	else { //2do: sweeping		
		
		unsigned long ulStepSweep = (lFreqBasicHz - lFreqLowHz) / SWEEP_DISCRETE;
		gen.EnableOutput(true);

		gen.ApplySignal(SINE_WAVE, REG0, lFreqLowHz);

		for (int i = 0; i < SWEEP_DISCRETE; i++) {
			gen.IncrementFrequency(REG0, ulStepSweep);
			delayMicroseconds (SWEEP_DELAY_US);
		}
		gen.EnableOutput(false);
	}

}



