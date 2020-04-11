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

## Pinagem

|    Pinagem LCD| Função                    |  Raspberry | WiringPi |       |
|---------------|:-------------------------:|------------|:--------:|------:|
| Pino  4 LCD   | RS ou /CS  chip select    | pino 24    | 10       | CS0   |
| Pino  5 LCD   | RW ou /SID Sserial data   | pino 19    | 12       | MOSI  |
| Pino  6 LCD   | EN ou /SCLK serial clock  | pino 23    | 14       | SCLK  |
| Pino 17 LCD   | RST                       | pino 22    |  6       | Reset | 

