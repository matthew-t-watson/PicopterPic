
#include "SimulatedRegister.h"

struct buffer_struct buffer; //Declared here to limit scope to file

unsigned int make16(unsigned char H, unsigned char L)
{
	return ((H<<8)|L);
}	

unsigned char registerRead(unsigned char address)
{
	switch(address)
	{
		case REG_PWM1H:
			return(getPWM1()>>8);
		case REG_PWM1L:
			return(getPWM1());
		case REG_PWM2H:
			return(getPWM2()>>8);
		case REG_PWM2L:
			return(getPWM2());
		case REG_PWM3H:
			return(getPWM3()>>8);
		case REG_PWM3L:
			return(getPWM3());
		case REG_PWM4H:
			return(getPWM4()>>8);
		case REG_PWM4L:
			return(getPWM4());
		case REG_PWM5H:
			return(getPWM5()>>8);
		case REG_PWM5L:
			return(getPWM5());
		case REG_PWM6H:
			return(getPWM6()>>8);
		case REG_PWM6L:
			return(getPWM6());
		case REG_PWMFIRE:
			return(0);
		
		case REG_RX1H:
			return(RX1>>8);
		case REG_RX1L:
			return(RX1);
		case REG_RX2H:
			return(RX2>>8);
		case REG_RX2L:
			return(RX2);
		case REG_RX3H:
			return(RX3>>8);
		case REG_RX3L:
			return(RX3);
		case REG_RX4H:
			return(RX4>>8);
		case REG_RX4L:
			return(RX4);
		case REG_RX5H:
			return(RX5>>8);
		case REG_RX5L:
			return(RX5);
		case REG_RX6H:
			return(RX6>>8);
		case REG_RX6L:
			return(RX6);
	}
	return(0); //Requested register not found
}

void registerWrite(unsigned char address, unsigned char value)
{
	switch(address)
	{
		case REG_PWM1H:
			buffer.PWM1H = value;
			break;
		case REG_PWM1L:
			buffer.PWM1L = value;
			break;
		case REG_PWM2H:
			buffer.PWM2H = value;
			break;
		case REG_PWM2L:
			buffer.PWM2L = value;
			break;
		case REG_PWM3H:
			buffer.PWM3H = value;
			break;
		case REG_PWM3L:
			buffer.PWM3L = value;
			break;
		case REG_PWM4H:
			buffer.PWM4H = value;
			break;
		case REG_PWM4L:
			buffer.PWM4L = value;
			break;
		case REG_PWM5H:
			buffer.PWM5H = value;
			break;
		case REG_PWM5L:
			buffer.PWM5L = value;
			break;
		case REG_PWM6H:
			buffer.PWM6H = value;
			break;
		case REG_PWM6L:
			buffer.PWM6L = value;
			break;
		case REG_PWMFIRE:
			setPWM1(make16(buffer.PWM1H, buffer.PWM1L));
			setPWM2(make16(buffer.PWM2H, buffer.PWM2L));
			setPWM3(make16(buffer.PWM3H, buffer.PWM3L));
			setPWM4(make16(buffer.PWM4H, buffer.PWM4L));
			setPWM5(make16(buffer.PWM5H, buffer.PWM5L));
			setPWM6(make16(buffer.PWM6H, buffer.PWM6L));
			OutputCompareFire();
			break;
		
		case REG_RX1H:
			buffer.RX1H = value;
			break;
		case REG_RX1L:
			buffer.RX1L = value;
			RX1 = make16(buffer.RX1H, buffer.RX1L);
			break;
		case REG_RX2H:
			buffer.RX2H = value;
			break;
		case REG_RX2L:
			buffer.RX2L = value;
			RX2 = make16(buffer.RX2H, buffer.RX2L);
			break;
		case REG_RX3H:
			buffer.RX3H = value;
			break;
		case REG_RX3L:
			buffer.RX3L = value;
			RX3 = make16(buffer.RX3H, buffer.RX3L);
			break;
		case REG_RX4H:
			buffer.RX4H = value;
			break;
		case REG_RX4L:
			buffer.RX4L = value;
			RX4 = make16(buffer.RX4H, buffer.RX4L);
			break;
		case REG_RX5H:
			buffer.RX5H = value;
			break;
		case REG_RX5L:
			buffer.RX5L = value;
			RX5 = make16(buffer.RX5H, buffer.RX5L);
			break;
		case REG_RX6H:
			buffer.RX6H = value;
			break;
		case REG_RX6L:
			buffer.RX6L = value;
			RX6 = make16(buffer.RX6H, buffer.RX6L);
			break;
	}	
}
