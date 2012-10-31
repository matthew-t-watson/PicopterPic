
#include "PWMSingleShot.h"

void SetupOutputCompareSingleShot()
{
	//Set tristates to outputs
	TRISDbits.TRISD0 = 0;
	TRISDbits.TRISD1 = 0;
	TRISDbits.TRISD2 = 0;
	TRISDbits.TRISD3 = 0;
	TRISDbits.TRISD6 = 0;
	TRISDbits.TRISD7 = 0;
	
	//OC modules setup
	OC1CONbits.OCM = 0b000; //Disable for now, will write 0b010 later to initiate pulse
	OC2CONbits.OCM = 0b000; //Disable for now, will write 0b010 later to initiate pulse
	OC3CONbits.OCM = 0b000; //Disable for now, will write 0b010 later to initiate pulse
	OC4CONbits.OCM = 0b000; //Disable for now, will write 0b010 later to initiate pulse
	OC7CONbits.OCM = 0b000; //Disable for now, will write 0b010 later to initiate pulse
	OC8CONbits.OCM = 0b000; //Disable for now, will write 0b010 later to initiate pulse	
	OC1CONbits.OCTSEL = 1; //Use timer3
	OC2CONbits.OCTSEL = 1; //Use timer3
	OC3CONbits.OCTSEL = 1; //Use timer3
	OC4CONbits.OCTSEL = 1; //Use timer3
	OC7CONbits.OCTSEL = 1; //Use timer3
	OC8CONbits.OCTSEL = 1; //Use timer3
	OC1R = 0;
	OC2R = 0;
	OC3R = 0;
	OC4R = 0;
	OC7R = 0;
	OC8R = 0;
	
	//Timer3 setup
	IEC0bits.T3IE = 0; //Disable timer3 interrupt
	T3CONbits.TON = 0; //Disable timer
	T3CONbits.TSIDL = 0; //Continue operation in idle mode
	T3CONbits.TGATE = 0; //Timer gate accumulation disabled
	T3CONbits.TCKPS = 0b00; //Timer prescale 1:1, 1:8, 1:64, 1:256
	T3CONbits.TCS = 0; //Internal clock source
	PR3 = 65535; //Period register	
	TMR3=0;
	T3CONbits.TON = 1; //Enable timer
}

//Start PWM pulses of length specified by OCxR registers
void OutputCompareFire()
{
	TMR3=0;
	OC1CONbits.OCM = 0b010;
	OC2CONbits.OCM = 0b010;
	OC3CONbits.OCM = 0b010;
	OC4CONbits.OCM = 0b010;
	OC7CONbits.OCM = 0b010;
	OC8CONbits.OCM = 0b010;
	//The PWM outputs will now remain high until each OCxR register matches TMR3
}

void setPWM1(unsigned int value)
{
	OC1R = value;
}

void setPWM2(unsigned int value)
{
	OC2R = value;
}

void setPWM3(unsigned int value)
{
	OC3R = value;
}

void setPWM4(unsigned int value)
{
	OC4R = value;
}

void setPWM5(unsigned int value)
{
	OC7R = value;
}

void setPWM6(unsigned int value)
{
	OC8R = value;
}

unsigned int getPWM1()
{
	return OC1R;
}

unsigned int getPWM2()
{
	return OC2R;
}

unsigned int getPWM3()
{
	return OC3R;
}

unsigned int getPWM4()
{
	return OC4R;
}

unsigned int getPWM5()
{
	return OC7R;
}

unsigned int getPWM6()
{
	return OC8R;
}

