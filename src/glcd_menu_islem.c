////
#define glcd_rect_satir1 glcd_rect(7, 21, 120, 28, Yes, ON)
#define glcd_rect_satir2 glcd_rect(7, 29, 120, 36, Yes, ON)
#define glcd_rect_satir3 glcd_rect(7, 37, 120,44, Yes, ON)
#define glcd_rect_satir4 glcd_rect(7, 45, 120, 52, Yes, ON)
#define glcd_rect_satir5 glcd_rect(7, 53, 120, 60, Yes, ON)
#define glcd_rect_satir1_s glcd_rect(7, 21, 120, 28, Yes, OFF)
#define glcd_rect_satir2_s glcd_rect(7, 29, 120, 36, Yes, OFF)
#define glcd_rect_satir3_s glcd_rect(7, 37, 120,44, Yes, OFF)
#define glcd_rect_satir4_s glcd_rect(7, 45, 120, 52, Yes, OFF)
#define glcd_rect_satir5_s glcd_rect(7, 53, 120, 60, Yes, OFF)


#define btn_yukari U  // donanýmda butonlar ters konulduðu için aþaðýdaki yazýlýmda yer deðiþtirilmiþ  
#define btn_asagi D   // U --> ASAGI,  D-->YUKARI olmustur.
#define btn_sag R
#define btn_sol L

char kapilar[230]="1-Ogretmenler Odasi,2-Alan Deposu,3-Sef Odasi,4-Proje Odasi,5-Temizlik Odasi,6-PCB/Mekanik Atl.,7-Hab. Atl. Lab.,8-End. Atl. Lab.,9-Alan Girisi,10-Bilgisayar Lab.,11-Mak. Atl. Lab.,12-Olcme Atl. Lab.,";
signed int glcd_sayfa=0,glcd_satir=0,kapiNo=0;
char btn_yon=0;
long kapi_no=0;
boolean sayfa1_disp=false,sayfa2_disp=false,sayfa3_disp=false;
// kaynak dizideki virgülleri sayar iki virgül arasýndaki karakterleri yüklenecek
//olan dizinin elemanlarýna atar. sira_no yüklenecek olan karakterlerin bittiði yerdir.
void kapi_char_al(char kaynak_dizi[],char* yukle_dizi,int sira_no)
{
   int i=0;
   int say=0;
  for(i=0;i<strlen(kaynak_dizi);++i)
  {
    if(kaynak_dizi[i]==',')say++; 
    if(say==sira_no)break;
    if(say==sira_no-1)
    {
      if(sira_no==1)*yukle_dizi++=kaynak_dizi[i];
      else *yukle_dizi++=kaynak_dizi[i+1];
    }
  }
  *yukle_dizi--='\0';//dizinin son karakterinin sýfýr olmasý garantileniyor.
}
void c_sil(char s[],char c)
{
   int a=0;
   for(a=0;a<strlen(s);a++)
   {
      if(s[a]==c)s[a]=0;
   }
}
void sayfa0(void)
{
    strcpy(buf_text,"-KAPILAR-");
    glcd_text57(15, 4, buf_text, 2, ON) ;
    
    clearTag(buf_text);  
    kapi_char_al(kapilar,buf_text,1);
    c_sil(buf_text,',');
    glcd_text57(8, 21, buf_text,1, ON) ;
    
    clearTag(buf_text);
    kapi_char_al(kapilar,buf_text,2);
    c_sil(buf_text,',');
    glcd_text57(8, 29, buf_text,1, ON) ;
    
    clearTag(buf_text);
    kapi_char_al(kapilar,buf_text,3);
    c_sil(buf_text,',');
    glcd_text57(8, 37, buf_text,1, ON) ;
    
    clearTag(buf_text);
    kapi_char_al(kapilar,buf_text,4);
    c_sil(buf_text,',');
    glcd_text57(8, 45, buf_text,1, ON) ;
    
    clearTag(buf_text);
    kapi_char_al(kapilar,buf_text,5);
    c_sil(buf_text,',');
    glcd_text57(8, 53, buf_text,1, ON) ;
    sayfa1_disp=true;
}
void sayfa1(void)
{
    strcpy(buf_text,"-KAPILAR-");
    glcd_text57(15, 4, buf_text, 2, ON) ;
    clearTag(buf_text); 
    
    kapi_char_al(kapilar,buf_text,6);
    c_sil(buf_text,',');
    glcd_text57(8, 21, buf_text,1, ON) ;
    
    clearTag(buf_text);
    kapi_char_al(kapilar,buf_text,7);
    c_sil(buf_text,',');
    glcd_text57(8, 29, buf_text,1, ON) ;
    
    clearTag(buf_text);
    kapi_char_al(kapilar,buf_text,8);
    c_sil(buf_text,',');
    glcd_text57(8, 37, buf_text,1, ON) ;
    
    clearTag(buf_text);
    kapi_char_al(kapilar,buf_text,9);
    c_sil(buf_text,',');
    glcd_text57(8, 45, buf_text,1, ON) ;
    
    clearTag(buf_text);
    kapi_char_al(kapilar,buf_text,10);
    c_sil(buf_text,',');
    glcd_text57(8, 53, buf_text,1, ON) ;
    sayfa2_disp=true;
}
void sayfa2(void)
{
    strcpy(buf_text,"-KAPILAR-");
    glcd_text57(15, 4, buf_text, 2, ON) ;
    
    clearTag(buf_text);  
    kapi_char_al(kapilar,buf_text,11);
    c_sil(buf_text,',');
    glcd_text57(8, 21, buf_text,1, ON) ;
    
    clearTag(buf_text);
    kapi_char_al(kapilar,buf_text,12);
    c_sil(buf_text,',');
    glcd_text57(8, 29, buf_text,1, ON) ;
    sayfa3_disp=true;
}

void id_menu_kapi(void)
{
    disable_interrupts(INT_EXT);
    disable_interrupts(GLOBAL);
    enable_interrupts(INT_TIMER0);
    enable_interrupts(GLOBAL);
    
    bit_set(kapi_no,kapiNo); hc595_yaz(kapi_no,16);
    delay_ms(500);kapi_no=0; hc595_yaz(0,16);
    
    while(1)
   { 
       if ((!sayfa1_disp)&&(glcd_sayfa==0))
       {
          glcd_clear;sayfa3_disp=false;sayfa2_disp=false;
          glcd_rect(1, 1, 127, 63, NO, ON);
          sayfa0();

          if(btn_yon=='D'){
            kapi_char_al(kapilar,buf_text,5);c_sil(buf_text,',');
            glcd_rect_satir5; glcd_text57(8, 53, buf_text,1, OFF) ;
          }
          else{ 
            kapi_char_al(kapilar,buf_text,1);c_sil(buf_text,',');
            glcd_rect_satir1; glcd_text57(8, 21, buf_text,1, OFF) ;
          }
       }
       if ((!sayfa2_disp)&&(glcd_sayfa==1))
       {
          glcd_clear;sayfa1_disp=false;sayfa3_disp=false;
          glcd_rect(1, 1, 127, 63, NO, ON);
          sayfa1();
          
          if(btn_yon=='D') glcd_rect_satir5;
          else glcd_rect_satir1;
          kapi_char_al(kapilar,buf_text,6);
          if(btn_yon=='D'){
            kapi_char_al(kapilar,buf_text,10);c_sil(buf_text,',');
            glcd_rect_satir5; glcd_text57(8, 53, buf_text,1, OFF) ;
          }
          else{
            kapi_char_al(kapilar,buf_text,6);c_sil(buf_text,',');
            glcd_rect_satir1; glcd_text57(8, 21, buf_text,1, OFF) ;
         }
      }
        if ((!sayfa3_disp)&&(glcd_sayfa==2))
       {
          glcd_clear;sayfa2_disp=false;sayfa1_disp=false;
          glcd_rect(1, 1, 127, 63, NO, ON);
          sayfa2();
          //glcd_satir=0;
          if(btn_yon=='D') glcd_rect_satir5;
          else glcd_rect_satir1;
          kapi_char_al(kapilar,buf_text,11);
          if(btn_yon=='D'){
            glcd_rect_satir5; glcd_text57(8, 21, buf_text,1, ON) ;
          }
          else{
            glcd_rect_satir1; glcd_text57(8, 21, buf_text,1, OFF) ;
          }
       }
     adc_deger = read_adc();
     btn_yon=btn_chr_cev(adc_deger);
     if(adc_deger>50)
     {
        delay_ms(200);  
        if(btn_yon=='U'){
          glcd_satir++;kapiNO++;
          if(glcd_satir>4)glcd_satir=4;
          if(kapiNo>11) kapiNo=11;
          if(kapiNo<5){glcd_sayfa=0;glcd_satir=kapiNo;}
          if((kapiNo>4)&&(kapiNo<10)){glcd_sayfa=1;glcd_satir=kapiNo-5;}
          if((kapiNo>9)&&(kapiNo<12)){glcd_sayfa=2;glcd_satir=kapiNo-10;}
          zmn_say_basla;
        }
        if(btn_yon=='D'){
          glcd_satir--;kapiNo--;
          if(glcd_satir<0)glcd_satir=0;
          if(kapiNo<0) kapiNo=0;
          if(kapiNo<5){glcd_sayfa=0;glcd_satir=kapiNo;}
          if((kapiNo>4)&&(kapiNo<10)){glcd_sayfa=1;glcd_satir=kapiNo-5;}
          if((kapiNo>9)&&(kapiNo<12)){glcd_sayfa=2;glcd_satir=kapiNo-10;}
          zmn_say_basla;
        }
        switch(glcd_satir)
        {
            case 0:
               if(btn_yon=='U'){
                  glcd_rect_satir1;
                  clearTag(buf_text);
                  if(glcd_sayfa==0)kapi_char_al(kapilar,buf_text,1);
                  if(glcd_sayfa==1)kapi_char_al(kapilar,buf_text,6);
                  if(glcd_sayfa==2)kapi_char_al(kapilar,buf_text,11);
                  c_sil(buf_text,',');
                  glcd_text57(8, 21, buf_text,1, OFF) ;  
               }else {
                  if(btn_yon=='D')
                  {
                      glcd_rect_satir2_s;
                      clearTag(buf_text);
                      //kapi_char_al(kapilar,buf_text,2);
                      if(glcd_sayfa==0)kapi_char_al(kapilar,buf_text,2);
                      if(glcd_sayfa==1)kapi_char_al(kapilar,buf_text,7);
                      if(glcd_sayfa==2)kapi_char_al(kapilar,buf_text,12);
                      c_sil(buf_text,',');
                      glcd_text57(8, 29, buf_text,1, ON) ;
                      
                      glcd_rect_satir1;
                      clearTag(buf_text);
                      //kapi_char_al(kapilar,buf_text,1);
                      if(glcd_sayfa==0)kapi_char_al(kapilar,buf_text,1);
                      if(glcd_sayfa==1)kapi_char_al(kapilar,buf_text,6);
                      if(glcd_sayfa==2)kapi_char_al(kapilar,buf_text,11);
                      c_sil(buf_text,',');
                      glcd_text57(8, 21, buf_text,1, OFF) ;  
                  }
               }
             break;
             case 1:
               if(btn_yon=='U'){
                  glcd_rect_satir1_s;
                  if(glcd_sayfa==2)kapi_char_al(kapilar,buf_text,11);
                  glcd_text57(8, 21, buf_text,1, ON) ;
                  
                  glcd_rect_satir2;
                  clearTag(buf_text);
                  //kapi_char_al(kapilar,buf_text,2);
                  if(glcd_sayfa==0)kapi_char_al(kapilar,buf_text,2);
                  if(glcd_sayfa==1)kapi_char_al(kapilar,buf_text,7);
                  if(glcd_sayfa==2)kapi_char_al(kapilar,buf_text,12);
                  c_sil(buf_text,',');
                  glcd_text57(8, 29, buf_text,1, OFF) ;
               } else{
                  if(btn_yon=='D')
                  {
                      glcd_rect_satir3_s;
                      glcd_text57(8, 37, buf_text,1, ON) ;
                      
                      glcd_rect_satir2;
                      clearTag(buf_text);
                      //kapi_char_al(kapilar,buf_text,2);
                      if(glcd_sayfa==0)kapi_char_al(kapilar,buf_text,2);
                      if(glcd_sayfa==1)kapi_char_al(kapilar,buf_text,7);
                      if(glcd_sayfa==2)kapi_char_al(kapilar,buf_text,12);
                      c_sil(buf_text,',');
                      glcd_text57(8, 29, buf_text,1, OFF) ;  
                  }
               }
             break;
             case 2:
               if(btn_yon=='U'){
                  glcd_rect_satir2_s;
                  glcd_text57(8, 29, buf_text,1, ON) ;
                  
                  glcd_rect_satir3;
                  clearTag(buf_text);
                  //kapi_char_al(kapilar,buf_text,3);
                  if(glcd_sayfa==0)kapi_char_al(kapilar,buf_text,3);
                  if(glcd_sayfa==1)kapi_char_al(kapilar,buf_text,8);
                  if(glcd_sayfa==2)kapi_char_al(kapilar,buf_text,12);
                  c_sil(buf_text,',');
                  glcd_text57(8, 37, buf_text,1, OFF) ;
               }else{
                  if(btn_yon=='D')
                  {
                      glcd_rect_satir4_s;
                      glcd_text57(8, 45, buf_text,1, ON) ;

                      glcd_rect_satir3;
                      clearTag(buf_text);
                      //kapi_char_al(kapilar,buf_text,3);
                      if(glcd_sayfa==0)kapi_char_al(kapilar,buf_text,3);
                      if(glcd_sayfa==1)kapi_char_al(kapilar,buf_text,8);
                      if(glcd_sayfa==2)kapi_char_al(kapilar,buf_text,12);
                      c_sil(buf_text,',');
                      glcd_text57(8, 37, buf_text,1, OFF) ;  
                  }
               }
            break;
            case 3:
               if(btn_yon=='U'){
                  glcd_rect_satir3_s;
                  glcd_text57(8, 37, buf_text,1, ON) ;
                  
                  glcd_rect_satir4;
                  clearTag(buf_text);
                  //kapi_char_al(kapilar,buf_text,4);
                  if(glcd_sayfa==0)kapi_char_al(kapilar,buf_text,4);
                  if(glcd_sayfa==1)kapi_char_al(kapilar,buf_text,9);
                  if(glcd_sayfa==2)kapi_char_al(kapilar,buf_text,12);
                  c_sil(buf_text,',');
                  glcd_text57(8, 45, buf_text,1, OFF) ;
               }else{
                  if(btn_yon=='D')
                  {
                      glcd_rect_satir5_s;
                      clearTag(buf_text);
                      kapi_char_al(kapilar,buf_text,5);
                      glcd_text57(8, 54, buf_text,1, ON) ;
                      
                      glcd_rect_satir4;
                      clearTag(buf_text);
                      //kapi_char_al(kapilar,buf_text,4);
                      if(glcd_sayfa==0)kapi_char_al(kapilar,buf_text,4);
                      if(glcd_sayfa==1)kapi_char_al(kapilar,buf_text,9);
                      if(glcd_sayfa==2)kapi_char_al(kapilar,buf_text,12);
                      c_sil(buf_text,',');
                      glcd_text57(8, 45, buf_text,1, OFF) ;
                  }
               }
            break;
            case 4:
               if(btn_yon=='U'){
                  glcd_rect_satir4_s;
                  glcd_text57(8, 45, buf_text,1, ON) ;
                  
                  glcd_rect_satir5;
                  clearTag(buf_text);
                  //kapi_char_al(kapilar,buf_text,5);
                  if(glcd_sayfa==0)kapi_char_al(kapilar,buf_text,5);
                  if(glcd_sayfa==1)kapi_char_al(kapilar,buf_text,10);
                  if(glcd_sayfa==2)kapi_char_al(kapilar,buf_text,12);
                  c_sil(buf_text,',');
                  glcd_text57(8, 54, buf_text,1, OFF) ;
               }else{
                  //clearTag(buf_text);
               }
            break;
        }//switch        
     }//if(adc_deger>50)
     if(!input(PIN_B0))
     {
         delay_ms(250);
         glcd_clear;
         bitmap_kapi_acik(0,0);
         kapi_char_al(kapilar,buf_text,kapiNo+1);
         c_sil(buf_text,',');
         glcd_text57(3, 1, buf_text,1, ON) ; 
         strcopy(buf_text,"! ACILDI !");
         glcd_text57(30, 10, buf_text, 1, ON) ;//(x,y....
         //kapi_no|=(1<<glcd_satir);
         bit_set(kapi_no,kapiNo); hc595_yaz(kapi_no,16);
         delay_ms(1500);
         hc595_yaz(0,16);
         glcd_clear;
         delay_ms(300);
         disable_interrupts(INT_TIMER0);
         reset_cpu();//bütün baslangýç ayarlarýný geri yükler...
         break;
     }//switch
  }//while  
    kart_oku=false;
    reset_id12();  
}
