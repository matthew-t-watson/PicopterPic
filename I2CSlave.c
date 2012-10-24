#include "p30F6011A.h"
#include "I2CSlave.h"

struct FlagType Flag;
unsigned char address = 0;
unsigned char temp;

void SetupI2C(void)
{
	I2CCONbits.I2CEN = 0; //Disable module
	Flag.AddrFlag = 0;	//Initlize AddFlag
	Flag.DataFlag = 0;	//Initlize DataFlag
	_SI2CIE = 1; //Enable interrupts
	I2CCONbits.I2CEN = 1; //Enable module
}

void _ISR _SI2CInterrupt(void) //I2C slave interrupt
{
	if((I2CSTATbits.R_W == 0)&&(I2CSTATbits.D_A == 0))	//Address matched, writing register address to slave
	{
		temp = I2CRCV;		//dummy read to remove stored address value
		Flag.AddrFlag = 1;	//next byte will be address
		Flag.DataFlag = 0;
	}
	else if((I2CSTATbits.R_W == 0)&&(I2CSTATbits.D_A == 1))	//Check for data	
	{
		if(Flag.AddrFlag)
		{
			Flag.AddrFlag = 0;	
			Flag.DataFlag = 1;	//next byte is data
			address = I2CRCV;
		}
		else if(Flag.DataFlag)
		{
			registerWrite(address, I2CRCV);// store data into RAM
			address++; //Increment address pointer incase stop bit isn't recieved / another byte comes through
		}
	}
	else if((I2CSTATbits.R_W == 1)&&(I2CSTATbits.D_A == 0)) //Been told to put data on bus, must already have desired register address
	{
		temp = I2CRCV; //ditch stored address
		I2CTRN = registerRead(address); //Read data from register & send data to I2C transmit buffer, setting D/A in the process
		address++; //Increment address for next read
	}
	else if((I2CSTATbits.R_W == 1)&&(I2CSTATbits.D_A == 1)) //D/A hasn't been reset, master must want more data
	{
		I2CTRN = registerRead(address); //Read data from RAM & send data to I2C master device
		address++;
	}
	_SI2CIF = 0;	//clear I2C1 Slave interrupt flag
}
