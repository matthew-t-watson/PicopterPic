

#include "p30F6011A.h"

unsigned int RX1 = 0;
unsigned int RX2 = 0;
unsigned int RX3 = 0;
unsigned int RX4 = 0;
unsigned int RX5 = 0;
unsigned int RX6 = 0;
unsigned int trash = 0;

void SetupInputCapture()
{
	IC1CONbits.ICSIDL = 0; //Continue in idle mode
	IC1CONbits.ICTMR = 1; //Use Timer2
	IC1CONbits.ICI = 0b00; //Interrupt on every capture
	IC1CONbits.ICM = 0b001; //Capture and interupt very edge
	
	IC2CONbits.ICSIDL = 0; //Continue in idle mode
	IC2CONbits.ICTMR = 1; //Use Timer2
	IC2CONbits.ICI = 0b00; //Interrupt on every capture
	IC2CONbits.ICM = 0b001; //Capture and interupt very edge
	
	IC3CONbits.ICSIDL = 0; //Continue in idle mode
	IC3CONbits.ICTMR = 1; //Use Timer2
	IC3CONbits.ICI = 0b00; //Interrupt on every capture
	IC3CONbits.ICM = 0b001; //Capture and interupt very edge
	
	IC4CONbits.ICSIDL = 0; //Continue in idle mode
	IC4CONbits.ICTMR = 1; //Use Timer2
	IC4CONbits.ICI = 0b00; //Interrupt on every capture
	IC4CONbits.ICM = 0b001; //Capture and interupt very edge
	
	IC5CONbits.ICSIDL = 0; //Continue in idle mode
	IC5CONbits.ICTMR = 1; //Use Timer2
	IC5CONbits.ICI = 0b00; //Interrupt on every capture
	IC5CONbits.ICM = 0b001; //Capture and interupt very edge
	
	IC6CONbits.ICSIDL = 0; //Continue in idle mode
	IC6CONbits.ICTMR = 1; //Use Timer2
	IC6CONbits.ICI = 0b00; //Interrupt on every capture
	IC6CONbits.ICM = 0b001; //Capture and interupt very edge
	
	IEC0bits.IC1IE = 1; //Enable interrupt	
	IEC0bits.IC2IE = 1; //Enable interrupt	
	IEC1bits.IC3IE = 1; //Enable interrupt	
	IEC1bits.IC4IE = 1; //Enable interrupt	
	IEC1bits.IC5IE = 1; //Enable interrupt	
	IEC1bits.IC6IE = 1; //Enable interrupt	
}

void _ISR _IC1Interrupt(void)
{	
	if(PORTDbits.RD8 == 1)
	{
		TMR2 = 0; //Restart timer2 to start timing from rising edge onwards
		trash = IC1BUF;
	}	
	else if(PORTDbits.RD8 == 0)
	{
		RX1 = IC1BUF;
	}
	IFS0bits.IC1IF = 0; //Clear IC1 interrupt flag
}

void _ISR _IC2Interrupt(void)
{	
	if(PORTDbits.RD9 == 1)
	{
		TMR2 = 0; //Restart timer2 to start timing from rising edge onwards
		trash = IC2BUF;
	}	
	else if(PORTDbits.RD9 == 0)
	{
		RX2 = IC2BUF;
	}
	IFS0bits.IC2IF = 0; //Clear IC1 interrupt flag
}

void _ISR _IC3Interrupt(void)
{	
	if(PORTDbits.RD10 == 1)
	{
		TMR2 = 0; //Restart timer2 to start timing from rising edge onwards
		trash = IC3BUF;
	}	
	else if(PORTDbits.RD10 == 0)
	{
		RX3 = IC3BUF;
	}
	IFS1bits.IC3IF = 0; //Clear IC1 interrupt flag
}

void _ISR _IC4Interrupt(void)
{	
	if(PORTDbits.RD11 == 1)
	{
		TMR2 = 0; //Restart timer2 to start timing from rising edge onwards
		trash = IC4BUF;
	}	
	else if(PORTDbits.RD11 == 0)
	{
		RX4 = IC4BUF;
	}
	IFS1bits.IC4IF = 0; //Clear IC1 interrupt flag
}

void _ISR _IC5Interrupt(void)
{	
	if(PORTDbits.RD4 == 1)
	{
		TMR2 = 0; //Restart timer2 to start timing from rising edge onwards
		trash = IC5BUF;
	}	
	else if(PORTDbits.RD4 == 0)
	{
		RX5 = IC5BUF;
	}
	IFS1bits.IC5IF = 0; //Clear IC1 interrupt flag
}

void _ISR _IC6Interrupt(void)
{	
	if(PORTDbits.RD5 == 1)
	{
		TMR2 = 0; //Restart timer2 to start timing from rising edge onwards
		trash = IC6BUF;
	}	
	else if(PORTDbits.RD5 == 0)
	{
		RX6 = IC6BUF;
	}
	IFS1bits.IC6IF = 0; //Clear IC1 interrupt flag
}
