#include <18F452.h>
//#include <18F4620.h>
#device adc=10

//!#FUSES NOWDT                    //No Watch Dog Timer
//!//#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale
//!#FUSES XT//HS                       //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
//!#FUSES PROTECT                  //Code protected from reads
//!#FUSES NOOSCSEN                 //Oscillator switching is disabled, main oscillator is source
//!#FUSES NOBROWNOUT               //No brownout reset
//!#FUSES BORV20                   //Brownout reset at 2.0V
//!#FUSES NOPUT                    //No Power Up Timer
//!#FUSES STVREN                   //Stack full/underflow will cause reset
//!#FUSES NODEBUG                  //No Debug mode for ICD
//!#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
//!#FUSES WRT                      //Program Memory Write Protected
//!#FUSES WRTD                     //Data EEPROM write protected
//!#FUSES WRTB                     //Boot block write protected
//!#FUSES WRTC                     //configuration registers write protected
//!#FUSES CPD                      //Data EEPROM Code Protected
//!#FUSES CPB                      //Boot Block Code Protected
//!#FUSES EBTR                     //Memory protected from table reads
//!#FUSES EBTRB                    //Boot block protected from table reads
//#fuses XT,NOWDT,NOPROTECT,NOLVP
#fuses HS,NOWDT,NOPROTECT,NOLVP
#use delay(clock=20000000)
//#use delay(clock=4000000)
#use rs232(baud=9600,parity=N,xmit=PIN_B4,rcv=PIN_B3,bits=8,ERRORS,stream=id12)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,ERRORS,stream=PC)

