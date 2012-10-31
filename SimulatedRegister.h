
#include "p30F6011A.h"
#include "PWMSingleShot.h"
#include "InputCapture.h"
#include "RegisterDefinitions.h"

//Struct to store data prior to make16()
struct buffer_struct
{
	unsigned char PWM1H;
	unsigned char PWM1L;
	unsigned char PWM2H;
	unsigned char PWM2L;
	unsigned char PWM3H;
	unsigned char PWM3L;
	unsigned char PWM4H;
	unsigned char PWM4L;
	unsigned char PWM5H;
	unsigned char PWM5L;
	unsigned char PWM6H;
	unsigned char PWM6L;
	
	unsigned char RX1H;
	unsigned char RX1L;
	unsigned char RX2H;
	unsigned char RX2L;
	unsigned char RX3H;
	unsigned char RX3L;
	unsigned char RX4H;
	unsigned char RX4L;
	unsigned char RX5H;
	unsigned char RX5L;
	unsigned char RX6H;
	unsigned char RX6L;	
};	

//Function prototypes
unsigned char registerRead(unsigned char address);
void registerWrite(unsigned char address, unsigned char value);

