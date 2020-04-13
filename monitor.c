// Programa monitor Raspberry com LCD ST7920 mostra IP
// Interface de comandos simples com teclado de 3 botoes
// Biblioteca de LCD ST7920 testado e funcioando
// Rudi @ 09/04/2020

#include <wiringPi.h>           //WiringPi headers
#include <stdio.h>              //Needed for the printf function below
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// A definicao dos pinos do Raspberry e a configuracao do display estah neste arquivo 
#include "lib_st7920textmode.h"

// Pino  4 LCD funcao RS ou /CS  chip select        === Fio branco  === ligado a Raspberry pino 24 WiringPi 10 SPI0 CS0
// Pino  5 LCD funcao RW ou /SID Sserial data input === Fio cinza   === ligado a Raspberry pino 19 WiringPi 12 SPI0 MOSI
// Pino  6 LCD funcao EN ou /SCLK serial clock      === Fio violeta === ligado a Raspberry pino 23 WiringPi 14 SPI0 SCLK
// Pino 17 LCD funcao RST                           === Fio amarela === ligado a Raspberry pino 22 WiringPi  6 PIO  Reset 
//#define CS     10  
//#define SID    12  
//#define SCLK   14    
//#define RESET   6   
//#define LED     0 

#define LED     0 

char IPpath[20];

int leia_IP(void)
{
 FILE *fp;
 fp = popen("hostname -I", "r");
 strcpy(IPpath,"Sem numero IP   ");
 if (fp == NULL) {
    strcpy(IPpath,"Erro abertura   ");
    return(0);
  }
 fgets(IPpath, 16, fp); 
 IPpath[15]=0;
 pclose(fp);
 return(1);
}

int main(void)
{
 int res;
 int i=0;
 char datum[80];
 time_t rawtime;  // timer = time(NULL);
 struct tm * timeinfo;
 res=leia_IP();

 time(&rawtime); 
 strftime(datum, 20, "%m-%d %H:%M:%S", localtime(&rawtime)); 
 // puts(datum);
 // puts(IPpath); 
 setup_rasp_lcd(); 
 lcd_str("Monitor IP  "); 
 goto_lcd(2,1); 
 lcd_str(IPpath);
 goto_lcd(3,1); 
 lcd_str(datum);
 while(1) 
 { 
  time(&rawtime);
  strftime(datum,20, "%m-%d %H:%M:%S", localtime(&rawtime)); 
  goto_lcd(4,1);
  lcd_str(datum);
  if (i++ > 5) {
   res=leia_IP();
   goto_lcd(2,1);
   if (res==1) lcd_str(IPpath); else lcd_str("Sem IP wifi    ");
   i=0; 
  }
  digitalWrite(LED, HIGH); delay(400);
  digitalWrite(LED, LOW);  delay(400);
 }
} 
 

