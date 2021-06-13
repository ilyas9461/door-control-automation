#byte PORTE = 0xF84
#bit clock = PORTE.0
#bit data = PORTE.1
#bit load = PORTE.2

#define sr_en_pin PIN_B5
#define sr_disable output_high(sr_en_pin)
#define sr_enable output_low(sr_en_pin)

//veri'nin yaz_bit kadar bitini(8,16,32..) 74HC595'e data pinlerine yazar.
void hc595_yaz(int16 veri,int8 yaz_bit)
{ 
   int x;
  sr_enable;
  load=0; 
  for(x=0;x<yaz_bit;++x)                           
  {
    if (bit_test(veri,((yaz_bit-1)-x))) 
        data=1; 
    else data=0;   
    clock=1;//delay_ms(1000);
    clock=0;
  }                                      
 load=1;            
}//Sonu 

int btn_chr_cev(long deger)
{
   if((deger>=150)&&(deger<300)) return 'D';    //Aþaðý
   if((deger>=350)&&(deger<500)) return 'U';    //yukarý
   if((deger>=600)&&(deger<800)) return 'R';    //Sað
   if((deger>=1000)) return 'L';                //Sol
   
   if(deger<=1)return 0;
}

void kup_ciz(int x,int y,int mod)
{
   int a,aa,bb;  // aa, bb açý için bb/aa tan t için        
   if(mod==1){a=30;aa=10;bb=8;} 
   if(mod==0){a=15;aa=5;bb=4;}          
   glcd_rect(x, y, x+a, y+a, NO, ON); //Dikdörtgen                                         
   glcd_line(x, y, x+aa, y-bb, YES) ;            //1. açýlý          
   glcd_line(x+a, y, x+a+aa, y-bb, YES) ;        //2. açýlý  
   glcd_line(x+a, y+a, x+a+aa, y+a-bb, YES) ;    // 3. açýlý 
   glcd_line(x+aa, y-bb,x+a+aa,y-bb, YES) ;      //1. açýlý çizgi ytay   
   glcd_line(x+a+aa, y+a-bb,x+a+aa,y-bb, YES) ; // açaýlý çizgi dikey  
   if(mod==1)
   {
      glcd_circle((x+(a/3)), (y+(a/6)), 3, YES, ON);    
      glcd_circle((x+(a/3)), (y+(a/6)+(a/3)), 3, YES, ON); 
      glcd_circle((x+(a/3)), (y+(a/6)+(2*a/3)), 3, YES, ON); 
      
      glcd_circle((x+(2*a/3)),(y+(a/6)),3, YES, ON);
      glcd_circle(x+(2*a/3),(y+(a/6)+(a/3)),3,YES,ON);
      glcd_circle(x+(2*a/3),(y+(a/6)+(2*a/3)),3, YES,ON);
   }
   if(mod==0)
   {
      glcd_circle((x+(a/3)), (y+(a/5)), 1, YES, ON);    
      glcd_circle((x+(a/3)), (y+(a/5)+(a/3)), 1, YES, ON); 
      glcd_circle((x+(a/3)), (y+(a/5)+(2*a/3)), 1, YES, ON); 
      
      glcd_circle((x+(2*a/3)),(y+(a/5)),1, YES, ON);
      glcd_circle(x+(2*a/3),(y+(a/5)+(a/3)),1,YES,ON);
      glcd_circle(x+(2*a/3),(y+(a/5)+(2*a/3)),1, YES,ON);
   }
}///kup_ciz()
void dispVolt(long adc) {
   char voltage[10];
   sprintf(voltage, "Volt=%1.2f V", (float)adc * .0048828125); // Converts adc to text
   //voltage[4] = '\0';                              // Limit shown digits to 3
   glcd_text57(45, 28, voltage, 1, ON); 
   glcd_circle(70,55,7,NO,ON);
}
void ilk_ekran(void)
{
                            
   glcd_clear;   
   glcd_rect(1, 1, 127, 63, YES, ON);
   strcpy(buf_text,"< RFID KAPI Acma >");
   glcd_text57(12,10, buf_text, 1, OFF) ;        
   delay_ms(300); 
   strcpy(buf_text,"Turk Telekom Teknik");
   glcd_text57(6, 28, buf_text, 1, OFF) ;
   delay_ms(300); 
   strcpy(buf_text,"Endustri Mes. Lisesi");
   glcd_text57(6, 40, buf_text, 1, OFF) ;
   delay_ms(1000);
   glcd_clear;
   bitmap_tt_logo(0,0);
}
