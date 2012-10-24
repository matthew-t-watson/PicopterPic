#include "p30F6011A.h"

//Simulated register names and addresses
#define PWM1H 0
#define PWM1L 1
#define PWM2H 2
#define PWM2L 3
#define PWM3H 4
#define PWM3L 5
#define PWM4H 6
#define PWM4L 7
#define PWM5H 8
#define PWM5L 9
#define PWM6H 10
#define PWM6L 11
#define PWMFIRE 12
#define RX1H 13
#define RX1L 14
#define RX2H 15
#define RX2L 16
#define RX3H 17
#define RX3L 18
#define RX4H 19
#define RX4L 20
#define RX5H 21
#define RX5L 22
#define RX6H 23
#define RX6L 24


unsigned char registerRead(address)
{
	switch(address)
	{
		case PWM1H:
			return(OC1R>>8);
		case PWM1L:
			return(OC1R);
		case PWM2H:
			return(OC2R>>8);
		case PWM2L:
			return(OC2R);
		case PWM3H:
			return(OC3R>>8);
		case PWM3L:
			return(OC3R);
		case PWM4H:
			return(OC4R>>8);
		case PWM4L:
			return(OC4R);
		case PWM5H:
			return(OC7R>>8);
		case PWM5L:
			return(OC7R);
		case PWM6H:
			return(OC8R>>8);
		case PWM6L:
			return(OC8R);
		case PWMFIRE:
			return(O);
		
		case RX1H:
			return(RX1>>8);
		case RX1L:
			return(RX1);
		case RX2H:
			return(RX2>>8);
		case RX2L:
			return(RX2);
		case RX3H:
			return(RX3>>8);
		case RX3L:
			return(RX3);
		case RX4H:
			return(RX4>>8);
		case RX4L:
			return(RX4);
		case RX5H:
			return(RX5>>8);
		case RX5L:
			return(RX5);
		case RX6H:
			return(RX6>>8);
		case RX6L:
			return(RX6);
	}	
}

void registerWrite(address, value)
{
	switch(address)
	{
		case PWM1H:
		break;
		
		case RX1H:
		break;
	}	
}
