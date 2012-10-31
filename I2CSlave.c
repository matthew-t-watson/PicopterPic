#include "I2CSlave.h"

struct FlagType Flag;
unsigned char address = 0;
unsigned char temp;

void SetupI2CSlave(void)
{
	I2CCONbits.I2CEN = 0; //Disable module
	I2CCONbits.SMEN = 1; //Enable smbus I/O levels
	I2CADD = 0x50; //Set address
	Flag.AddrFlag = 0;	//Initialise AddFlag
	Flag.DataFlag = 0;	//Initialise DataFlag
	IPC3bits.SI2CIP = 7; //Priority 7 interrupt
	IEC0bits.SI2CIE = 1; //Enable interrupts
	I2CCONbits.I2CEN = 1; //Enable module
}

void _ISR _SI2CInterrupt(void) //I2C slave interrupt
{
	IEC0bits.SI2CIE = 0; //Disable interrupts
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
			I2CCONbits.SCLREL = 1;	//Release SCL line
		}
		else if(Flag.DataFlag)
		{
			registerWrite(address, I2CRCV);// store data into register
			I2CCONbits.SCLREL = 1;	//Release SCL line
			address++; //Increment address pointer incase stop bit isn't recieved / another byte comes through
		}
	}
	else if((I2CSTATbits.R_W == 1)&&(I2CSTATbits.D_A == 0)) //Been told to put data on bus, must already have desired register address
	{
		temp = I2CRCV; //ditch stored address
		I2CTRN = registerRead(address); //Read data from register & send data to I2C transmit buffer, setting D/A in the process
		I2CCONbits.SCLREL = 1;	//Release SCL line
		address++; //Increment address for next read
	}
	else if((I2CSTATbits.R_W == 1)&&(I2CSTATbits.D_A == 1)) //D/A hasn't been reset, master must want more data
	{
		I2CTRN = registerRead(address); //Read data from RAM & send data to I2C master device
		I2CCONbits.SCLREL = 1;	//Release SCL line
		address++;
	}
	_SI2CIF = 0;	//clear I2C1 Slave interrupt flag
	IEC0bits.SI2CIE = 1; //Enable interrupts
}
