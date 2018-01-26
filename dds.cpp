#include "dds.h"

AD9833 gen(10);

void vInitDDS() {
	gen.Begin();
	gen.EnableOutput(false);
	gen.ApplySignal(SINE_WAVE, REG0, 1000);
	gen.SetOutputSource(REG0);
	gen.EnableOutput(true);


}

void vDDSset() {

}



