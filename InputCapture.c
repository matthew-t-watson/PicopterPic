
#include "InputCapture.h"

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
	
	IPC0bits.IC1IP = 6; //Priotity 6 interrupts
	IPC1bits.IC2IP = 6;
	IPC7bits.IC3IP = 6;
	IPC7bits.IC4IP = 6;
	IPC7bits.IC5IP = 6;
	IPC7bits.IC6IP = 6;
	
	IEC0bits.IC1IE = 1; //Enable interrupt	
	IEC0bits.IC2IE = 1; //Enable interrupt	
	IEC1bits.IC3IE = 1; //Enable interrupt	
	IEC1bits.IC4IE = 1; //Enable interrupt	
	IEC1bits.IC5IE = 1; //Enable interrupt	
	IEC1bits.IC6IE = 1; //Enable interrupt	
	
	//Timer2 setup, used to measure pulse length
	IEC0bits.T2IE = 0; //Disable timer3 interrupt
	T2CONbits.TON = 0; //Disable timer
	T2CONbits.TSIDL = 0; //Continue operation in idle mode
	T2CONbits.TGATE = 0; //Timer gate accumulation disabled
	T2CONbits.TCKPS = 0b00; //Timer prescale 1:1, 1:8, 1:64, 1:256
	T2CONbits.TCS = 0; //Internal clock source
	PR2 = 65535; //Period register	
	TMR2=0;
	T2CONbits.TON = 1; //Enable timer
	
	//Timer4 setup, used to check for signal loss, period of 30ms (enough for two input signals)
	IEC1bits.T4IE = 0; //Disable timer3 interrupt
	T4CONbits.TON = 0; //Disable timer
	T4CONbits.TSIDL = 0; //Continue operation in idle mode
	T4CONbits.TGATE = 0; //Timer gate accumulation disabled
	T4CONbits.TCKPS = 0b10; //Timer prescale 1:1, 1:8, 1:64, 1:256
	T4CONbits.TCS = 0; //Internal clock source
	PR4 = (fosc*0.03)/(4*64); //Period register, set to 30ms with prescaler of 64
	TMR4=0;
	T4CONbits.TON = 1; //Enable timer
	IEC1bits.T4IE = 1; //Enable timer3 interrupt
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

void _ISR _T4Interrupt(void)
{
	//Signal lost
}
