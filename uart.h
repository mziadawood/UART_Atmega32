/*
 * uart.h
 *
 * Created: 07/09/2016 02:12:40
 *  Author: Muhammed Zia Dawood
 */ 

#ifndef UART_H_
#define UART_H_

#include <stdio.h>

#define UART_NO_DATA 0x0100



void UARTinit(void);

// Receive a single char or UART_NO_DATA, if nothing received
uint16_t UARTgetChar(void);

// Send a single char
void UARTputChar(uint8_t c);

// Send a string
void UARTsendString(const char *s);

int getString(char *arr);

int available(void);






#endif /* USART_H_ */