/*
 * AVR_atmega32.c
 *
 * Created: 2/21/2021 2:07:06 AM
 * Author : General
 */ 

#ifndef	 F_CPU
#define  F_CPU	 8000000
#endif

#include "DIO_Interface.h"
#include "UART.h"
#include "Keypad.h"

#define OPEN_CLOSE_LOCK      'D'
#define FAN_AUTO_MANUAL      'F'
#define LIGHT_AUTO_MANUAL    'L'

#define STOP_LIGHT           '1'
#define START_LIGHT_10       '2'
#define START_LIGHT_25       '3'
#define START_LIGHT_50       '4'
#define START_LIGHT_75       '5'
#define START_LIGHT_100      '6'

#define STOP_FAN             '7'
#define START_FAN_10         '8'
#define START_FAN_25         '9'
#define START_FAN_50         'A'
#define START_FAN_75         'B'
#define START_FAN_100        'C'


int main(void)
{
	u8 str[100]={0},input_ch=0,uart_ch=0,keypad_ch=DEFAULT_KEY;
	DIO_Init();
	UART_Init();
    while (1) 
    {
	uart_ch=UART_Receive_periodic();
	keypad_ch=Keypad_GetKey();
	if		(uart_ch!=0)								input_ch=uart_ch;
	else if (keypad_ch!=DEFAULT_KEY)					input_ch=keypad_ch;
	else                                                input_ch=0;	
	if(input_ch!=0)
	{
	UART_Send(input_ch);
	keypad_ch=DEFAULT_KEY;
	uart_ch=0;
	input_ch=0;	
	}
    }
}