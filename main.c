#include "main.h"

void SetupModules()
{	
	//SetupInputCapture();
	//SetupOutputCompareSingleShot();
	SetupI2CSlave();
}	

int main()
{
	SetupModules();
	TRISDbits.TRISD0 = 0;
	while(1)
	{
		LATDbits.LATD0 = ~LATDbits.LATD0;
	}	
}
