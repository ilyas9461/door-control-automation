long zmn_say=0;
#define bit16_20ms 0x3CAF
#define zmn_say_basla {set_timer0(bit16_20ms);zmn_say=0;}

void ogr_sayfa0(void)
{
    strcpy(buf_text,"-OGRENCILER-");
    glcd_text57(18, 3, buf_text, 1, ON) ;
    
    clearTag(buf_text);  
    strcpy(buf_text,"1-...");
    glcd_text57(3, 15, buf_text, 1, ON) ;
    clearTag(buf_text);  
    strcpy(buf_text,"2-...");
    glcd_text57(3, 25, buf_text, 1, ON) ;
    clearTag(buf_text);  
    strcpy(buf_text,"3-...");
    glcd_text57(3, 35, buf_text, 1, ON) ;
    clearTag(buf_text);  
    strcpy(buf_text,"4-....");
    glcd_text57(3, 45, buf_text, 1, ON) ;
    clearTag(buf_text);  
);  
}
void ogr_sayfa1(void)
{
    clearTag(buf_text);
    strcpy(buf_text,"-OGRENCILER-");
    glcd_text57(18, 3, buf_text, 1, ON) ;

}
#define res_sure 500    //250==>5 saniye, 20mS TIMER0 overflow zamaný...
void bilgi_menu(void);
#INT_TIMER0
void timer0_isr(void)
{
  zmn_say++;
  if(zmn_say>res_sure) reset_cpu();
  set_timer0(bit16_20ms); 
}
#int_EXT   //1-2 olabilir 3 tane harici kesme var 18F452'de
void  EXT_isr(void) 
{
  disable_interrupts(INT_EXT);
  disable_interrupts(GLOBAL);
  
  enable_interrupts(INT_TIMER0);
  enable_interrupts(GLOBAL);
  delay_ms(250);
  bilgi_menu();
  while(1)
   {   
     adc_deger = read_adc();
     delay_ms(200);
     if(btn_chr_cev(adc_deger)=='U'){glcd_clear; bitmap_danis_mek(0,0);zmn_say_basla;}
     if(btn_chr_cev(adc_deger)=='D'){glcd_clear; bitmap_kelebek(0,0);zmn_say_basla;}
     if(btn_chr_cev(adc_deger)=='L'){glcd_clear;ogr_sayfa0();zmn_say_basla;}
     if(btn_chr_cev(adc_deger)=='R'){glcd_clear;ogr_sayfa1();zmn_say_basla;}
     if(!input(PIN_B0))break;
  }
  delay_ms(200);
  reset_cpu();
}

//!#int_RDA
//!void  RDA_isr(void) 
//!{
//!  //fgets(buf_text,PC);
//!  glcd_clear;
//!  strcpy(buf_text,"RX Kesmesi ...");       //128x64
//!  glcd_text57(3, 3, buf_text, 1, ON) ;//(x,y....
//!}
void bilgi_menu(void)
{
  glcd_clear;
  glcd_rect(2,2,52,26,NO,ON);
  strcpy(buf_text,"GRUP");      
  glcd_text57(6, 8, buf_text, 2, ON) ;
  
  glcd_rect(65,2,117,26,NO,ON);
  strcpy(buf_text,"RFID");
  glcd_text57(69, 8, buf_text, 2, ON) ;
  
  glcd_rect(2,36,52,58,NO,ON);
  strcpy(buf_text,"?");
  glcd_text57(23, 40, buf_text, 2, ON) ;
  
  glcd_rect(65,36,117,58,NO,ON);
  strcpy(buf_text,"X");       
  glcd_text57(86, 40, buf_text, 2, ON) ;
}
