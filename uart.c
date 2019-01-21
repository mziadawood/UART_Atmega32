/*
 * uart.c
 *
 * Created: 07/09/2016 02:19:47
 *  Author: Muhammed Zia Dawood
 */ 

#define F_CPU 16000000UL
#include <inttypes.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "uart.h"


#define BAUD 9600

#define MYUBBR ((F_CPU / (BAUD * 16UL)) - 1)
#define BUFFER_SIZE 64//16


volatile static uint8_t rx_buffer[BUFFER_SIZE] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
volatile static uint8_t tx_buffer[BUFFER_SIZE] = "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
volatile static uint8_t rx_head = 0;
volatile static uint8_t rx_tail = 0;
volatile static uint8_t tx_head = 0;
volatile static uint8_t tx_tail = 0;





/*
 * UARTinit
 */
void UARTinit(void) 
{

   
     // set baud rate
     UBRRH = (uint8_t)(MYUBBR >> 8);
     UBRRL = (uint8_t)(MYUBBR);
     // enable receive and transmit
     UCSRB = (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);
     // set frame format
     UCSRC = (1<<URSEL)|(1 << USBS) | (3 << UCSZ0);	// asynchronous 8n1   i took out
}


/*
 * UARTgetChar
 * Gets a single char from the receive buffer.
 */

uint16_t UARTgetChar(void) 
{
  uint16_t c = 0;
  uint8_t tmp_tail = 0;
  if (rx_head == rx_tail) 
  {
    return UART_NO_DATA;
  }
  tmp_tail = (rx_tail + 1) % BUFFER_SIZE;
  c = rx_buffer[rx_tail];
  rx_tail = tmp_tail;
  return c;
}


/*
 * UARTputChar
 * Puts a single char. Wait  until there is enough space in buffer
 */
void UARTputChar(uint8_t c) {
  uint8_t tmp_head = (tx_head + 1) % BUFFER_SIZE;
  // wait for space in buffer
  while (tmp_head == tx_tail) {
    ;
  }
  tx_buffer[tx_head] = c;
  tx_head = tmp_head;
  // enable UART data interrupt (send data)
  UCSRB |= (1<<UDRIE);
}


/*
 * UARTsendString
 * Sends a string using pointers
 */
void UARTsendString(const char *s) 
{
  while (*s) 
  {
    UARTputChar(*s);
    s++;
  }
}


/* 
 * USART_UDRE_vect
 * ISR User Data Register Empty
 * Send a char out of buffer via UART. If sending is complete, 
 * disable the interrupt.
 */
ISR(USART_UDRE_vect) 
{
  uint8_t tmp_tail = 0;
  if (tx_head != tx_tail) 
  {
    tmp_tail = (tx_tail + 1) % BUFFER_SIZE;
    UDR = tx_buffer[tx_tail];
    tx_tail = tmp_tail;
  }
  else 
  {
    // disable this interrupt if nothing more to send
    UCSRB &= ~(1 << UDRIE);
  }
}

/*
 * USART_RX_vect 
 * Receives a char from UART and stores it in ring buffer.
 */
volatile int data_count=0;
volatile int data_count_temp=0;
volatile int startflag= 0;
volatile char data_in[64];
int usedflag =1;
#define sbi(port,bit)  (port) |= (1 << (bit))
#define cbi(port,bit)  (port) &= ~(1 << (bit))

ISR(USART_RXC_vect) 
{   

		if (startflag ==0)
		{
		   char c = UDR;
		   if (c == '<')
		   startflag = 1;
		}
		
		
		else if (startflag==1) 
	     {

			  
				 data_in[data_count] = UDR;
	 
				 if (data_in[data_count] =='>')
				 {
					 data_in[data_count]=NULL;
					 
					// char *s = data_in;
		 
				//	UARTsendString("\n");  
			    //  UARTsendString(&data_in);     //echo back receives string!	 
				//	UARTsendString("\n sent ");
					 startflag=0;
					 usedflag=0;
					 data_count_temp = data_count;
					 data_count = 0; 
		 
				 }

				 else
				 {
					 data_count++;             // notify main of receipt of data.
				 }
				 
		 }
		 
		 
	
		 

	/*      
	
						 
						 for (int z=0;z<data_count;z++)
						 {
							 UARTputChar(data_in[z]);
							 UARTsendString("\n string above ? ");
						 }
		*/			 
	/*
  uint8_t tmp_head = 0;
  uint8_t tmp_tail = 0;
  
  tmp_head = (rx_head + 1) % BUFFER_SIZE;
  if (tmp_head == rx_tail) 
  {
     //buffer overflow
  }
  else 
  {
    rx_buffer[rx_head] = UDR;
    rx_head = tmp_head;
	
	if (rx_head != rx_tail)
	{			
		tmp_tail = (rx_tail + 1) % BUFFER_SIZE;
		rx_tail = tmp_tail;
	}	

  }
  
  */
  
}



int getString(char arr[])
{
	
	if (usedflag==0)
	{
		  for (int i=0;i<data_count_temp;i++)
		   {
			arr[i] = data_in[i];
			data_in[i]=NULL;//testing
		   }
            
		//datac=data_count_temp  
		data_count_temp=0;
		usedflag=1;
		return 1;
	}
	else
	{return 0;}
	
}

int available(void)
{
  return ((unsigned int)(BUFFER_SIZE + rx_head - rx_tail)) % BUFFER_SIZE;
}
