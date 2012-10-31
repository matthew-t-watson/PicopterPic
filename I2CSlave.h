
#include "p30F6011A.h"
#include "SimulatedRegister.h"

struct FlagType
{
	unsigned char AddrFlag:1;
	unsigned char DataFlag:1;
};
extern struct FlagType Flag;

//Function prototypes
void SetupI2CSlave(void);
void _ISR _SI2CInterrupt(void);
