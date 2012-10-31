
#include "p30F6011A.h"

extern const long fosc;

extern unsigned int RX1;
extern unsigned int RX2;
extern unsigned int RX3;
extern unsigned int RX4;
extern unsigned int RX5;
extern unsigned int RX6;

//Function prototypes
void SetupInputCapture();
void _ISR _IC1Interrupt(void);
void _ISR _IC2Interrupt(void);
void _ISR _IC3Interrupt(void);
void _ISR _IC4Interrupt(void);
void _ISR _IC5Interrupt(void);
void _ISR _IC6Interrupt(void);
void _ISR _T4Interrupt(void);
