#include "p30F6011A.h"
#include "PWMSingleShot.h"
#include "InputCapture.h"
#include "I2CSlave.h"

const long fosc = 7372800;

//CONFIGURATION BITS
_FOSC (XT) //External crystal
_FWDT (WDT_OFF) //No WDT
_FBORPOR (PWRT_64 & BORV_27 & PBOR_ON & MCLR_EN) //64ms power on timer, 2.7v brownout
_FBS (WR_PROTECT_BOOT_OFF & NO_BOOT_CODE & NO_BOOT_EEPROM & NO_BOOT_RAM) //boot segment code can be written, no boot segment, no boot eeprom, no boot ram
_FSS (WR_PROT_SEC_OFF & NO_SEC_CODE & NO_SEC_EEPROM & NO_SEC_RAM) //No security
_FGS (GWRP_OFF & CODE_PROT_OFF) //No write protect
_FICD (PGD) //Use standard PGC and PGD

//Function prototypes
void SetupModules();
int main();
