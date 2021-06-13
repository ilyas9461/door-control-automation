
#define id12_etkisiz  output_low(id12_rst_pin)
#define RFID_START_BYTE 0x02 
#define RFID_END_BYTE   0x03 

#define id12_rst_pin PIN_A1
#define buzzer PIN_A2
int1 tanimli_kart=0;
//ÝLK GELEN KARTLAR
char tag1[13] = "4E0004502D37"; //...
char tag2[13] = "4E000470744E"; //...
//
char tag3[13] = "4800E51A8B3C";//...
char tag4[13] = "4800E504D871";//...
char tag5[13] = "4800E50C6DCC";//...
char tag6[13] = "4800E4F2ACF2";//Yedek1
char tag7[13] = "4800E4ED9CDD";//Yedek2
//EETA olanlar
char tag8[13] = "0000B6EB114C";//60177
char tag9[13] = "0000B6AF4C55";//44876
char tag10[13] ="0000B6C53B48";//50491
char tag11[13] ="0000B7932206";//37666
char tag12[13] ="0000B793E8CC";//37864
//
void bipp(int sure,int sayi,long pin)                              
{
   int a=0;
   for(a=0;a<sayi;a++)
   {
     output_high(pin);delay_ms(sure/2);output_low(pin);delay_ms(sure/2); 
   }                                      
}

void reset_id12(){
  output_low(id12_rst_pin);
  output_high(id12_rst_pin);
  delay_ms(150);
}

void clearTag(char* s){
  for(;*s!='\0';s++){*s = '\0';}
}

boolean compareTag(char one[], char two[]){
int i;
  if(strlen(one) == 0) return false; //boþ
  for(i = 0; i < 12; i++){
    if(one[i] != two[i]) return false;
  }

  return true; //iki dizi ayný
}

void id_menu_kapi(void);

void id_oku(void)
{
  clearTag(kart_bilgi);
  do{
    c = fgetc(id12);
  }
  //while ( c !='2');                 //similasyon için 
  while ((c != RFID_START_BYTE));// Devre için kullanýlmalý
  fgets(kart_bilgi,id12);
  //delay_ms(100);
 
  if(strlen(kart_bilgi)==13)
  {
    kart_oku=true;
  }else{
    glcd_clear;
    strcpy(buf_text,"!!! HATA !!!");
    glcd_text57(28, 24,buf_text, 1, ON) ;
    strcpy(buf_text,"Tekrar dene...");
    glcd_text57(27, 32,buf_text, 1, ON) ;
  } 
  if(kart_oku==1)
  {
    glcd_clear;
    if(compareTag(kart_bilgi,tag1)){
      tanimli_kart=1;
      bipp(2,50,buzzer);
      bitmap_cicek(0,0);
      strcpy(buf_text,"... Bey");
      glcd_text57(50, 8, buf_text, 1, OFF) ;  
      delay_ms(1000);
      id_menu_kapi();
    }
    if(compareTag(kart_bilgi,tag2)){
      tanimli_kart=1;
      bipp(2,50,buzzer);
      bitmap_cicek(0,0);
      strcpy(buf_text,"... Bey");
      glcd_text57(50, 8, buf_text, 1, OFF) ; 
      delay_ms(1000);
      id_menu_kapi();
    }
    if(compareTag(kart_bilgi,tag3)){
      tanimli_kart=1;
      bipp(2,50,buzzer);
      bitmap_cicek(0,0);
      strcpy(buf_text,"... H.");
      glcd_text57(50, 8, buf_text, 1, OFF) ; 
      delay_ms(1000);
      id_menu_kapi();
    }
    if(compareTag(kart_bilgi,tag4)){
      tanimli_kart=1;
      bipp(2,50,buzzer);
      bitmap_cicek(0,0);
      strcpy(buf_text,"... Bey");
      glcd_text57(50, 8, buf_text, 1, OFF) ; 
      delay_ms(1000);
      id_menu_kapi();
    }
    if(compareTag(kart_bilgi,tag5)){
      tanimli_kart=1;
      bipp(2,50,buzzer);
      bitmap_cicek(0,0);
      strcpy(buf_text,"... H.");
      glcd_text57(50, 8, buf_text, 1, OFF) ; 
      delay_ms(1000);
      id_menu_kapi();
    }
    if(compareTag(kart_bilgi,tag6)){
      tanimli_kart=1;
      bipp(2,50,buzzer);
      bitmap_cicek(0,0);
      strcpy(buf_text,"E.E.T.A.");
      glcd_text57(50, 8, buf_text, 1, OFF) ; 
      delay_ms(1000);
      id_menu_kapi();
    }
    if(compareTag(kart_bilgi,tag7)){
      tanimli_kart=1;
      bipp(2,50,buzzer);
      bitmap_cicek(0,0);
      strcpy(buf_text,"E.E.T.A.");
      glcd_text57(50, 8, buf_text, 1, OFF) ; 
      delay_ms(1000);
      id_menu_kapi();
    }
    if(compareTag(kart_bilgi,tag8)){
      tanimli_kart=1;
      bipp(2,50,buzzer);
      bitmap_cicek(0,0);
      strcpy(buf_text,"E.E.T.A.");
      glcd_text57(50, 8, buf_text, 1, OFF) ; 
      delay_ms(1000);
      id_menu_kapi();
    }
    if(compareTag(kart_bilgi,tag9)){
      tanimli_kart=1;
      bipp(2,50,buzzer);
      bitmap_cicek(0,0);
      strcpy(buf_text,"E.E.T.A.");
      glcd_text57(50, 8, buf_text, 1, OFF) ; 
      delay_ms(1000);
      id_menu_kapi();
    }
    if(compareTag(kart_bilgi,tag10)){
      tanimli_kart=1;
      bipp(2,50,buzzer);
      bitmap_cicek(0,0);
      strcpy(buf_text,"E.E.T.A.");
      glcd_text57(50, 8, buf_text, 1, OFF) ; 
      delay_ms(1000);
      id_menu_kapi();
    }
    if(compareTag(kart_bilgi,tag11)){
      tanimli_kart=1;
      bipp(2,50,buzzer);
      bitmap_cicek(0,0);
      strcpy(buf_text,"E.E.T.A.");
      glcd_text57(50, 8, buf_text, 1, OFF) ; 
      delay_ms(1000);
      id_menu_kapi();
    }
    if(compareTag(kart_bilgi,tag12)){
      tanimli_kart=1;
      bipp(2,50,buzzer);
      bitmap_cicek(0,0);
      strcpy(buf_text,"E.E.T.A.");
      glcd_text57(50, 8, buf_text, 1, OFF) ; 
      delay_ms(1000);
      id_menu_kapi();
    }
    if(!tanimli_kart){
      glcd_clear;   
      glcd_rect(1, 1, 127, 63, YES, ON);
      strcpy(buf_text,"Tanimsiz");
      glcd_text57(15, 8, buf_text, 2, OFF) ; 
      strcpy(buf_text,"KART");
      glcd_text57(30, 30, buf_text, 2, OFF) ;
      bipp(3,750,buzzer);
      delay_ms(1500);
      reset_cpu();       
    }
  }
}


