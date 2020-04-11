# display_st7920_raspberry
writing to the st7920 lcd display in text mode with Raspberry-Pi

Rudivels@ 11/04/2020

Este programa surgiu da necessidade de fazer um programa simples e direto para 
escrever texto no Display 128x64 ST7920 no modo grafico a partir do Raspberry-Pi
sem muita sofisticação.

Hardware Raspberry (com o software Debian)
Display ST7920

Essa primeira versão foi escrito "from scratch" baseado na rotina em assembler presente
no datasheet do display. 
O display é configurado para trabalhar em no modo serial
A única biblioteca não padrão é o WiringPi disponível em http://wiringpi.com/

# Pinagem
// Pino  4 LCD funcao RS ou /CS  chip select        === Fio branco  === ligado a Raspberry pino 24 WiringPi 10 SPI0 CS0
// Pino  5 LCD funcao RW ou /SID Sserial data input === Fio cinza   === ligado a Raspberry pino 19 WiringPi 12 SPI0 MOSI
// Pino  6 LCD funcao EN ou /SCLK serial clock      === Fio violeta === ligado a Raspberry pino 23 WiringPi 14 SPI0 SCLK
// Pino 17 LCD funcao RST                           === Fio amarela === ligado a Raspberry pino 22 WiringPi  6 PIO  Reset 

