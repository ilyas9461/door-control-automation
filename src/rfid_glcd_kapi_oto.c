#include <rfid_glcd_kapi_oto.h>
#define GLCD_WIDTH   128  
#use fast_io (E)
//#use fast_io (C)
//#use fast_io (D)
//#include <STDLIB.H> //rand() fonk. kullanýlbilmesi için....
//#define FAST_GLCD                                     
#include <HDM64GS12_lys.c>
//#include <glcd.c>
#include <graphics.c>
#include <math.h> 
#include <string.h>

char c=0;
int len=0;
char kart_id[9]="Kart ID:";
char index[5];
char buf_text[21]="";
char lys[9]="LYS-2012";
char kart_bilgi[13];
long adc_deger=0;
int1 kart_oku=false;

#define glcd_clear glcd_fillScreen(OFF)
#include "logo_ttteml.c"
#include "Id_12_fonk.c"
#include "rfid_kapi_oto_fonk.c"
#include "rfid_kapi_oto_kesmeler.c"
#include "glcd_menu_islem.c"


void main()
{
   sr_disable;
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_DIV_8);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_wdt(WDT_OFF);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_2);
   set_timer0(bit16_20ms);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_timer_3(T3_DISABLED|T3_DIV_BY_1);
   setup_ccp1(CCP_OFF);
   
   set_tris_e(0x00);output_e(0x00);
   //set_tris_d(0x00);set_tris_c(0x00);
   //output_d(0x00);output_c(0x00);
   reset_id12();
   bipp(50,1,buzzer);
   glcd_init(ON);
   //kapi_no=0;hc595_yaz(kapi_no,16);
   
   ext_int_edge(H_TO_L);
   enable_interrupts(INT_EXT);//EXT1-2 olabilir
   //enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   set_adc_channel(0);
   delay_us(200);
   ilk_ekran();
   fputs("ilk ekran",PC);
   
   while(1)
   { 
     id_oku(); 
   }//while(1)
}
