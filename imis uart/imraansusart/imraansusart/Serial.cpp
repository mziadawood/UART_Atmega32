/*
 * Serial.cpp
 *
 * Created: 9/19/2016 9:50:03 PM
 *  Author: Imran
 */ 

#define F_CPU 16000000UL
#define BAUD 4800
#define MYUBBR ((F_CPU / (BAUD * 16UL)) - 1)
#define BUFFER_SIZE 32

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>


#define sbi(port,bit)  (port) |= (1 << (bit))
#define cbi(port,bit)  (port) &= ~(1 << (bit))
#include "Serial.h"

struct ring_buffer
{
	unsigned char buffer[BUFFER_SIZE];
	int head;
	int tail;
};

struct data_buffer
{
	unsigned char buffer[BUFFER_SIZE];
	int location;
};


ring_buffer rx_buffer  =  {  { 0 } , 0, 0 };
ring_buffer tx_buffer =	  { { 0 }, 0, 0 };
ring_buffer dt_buffer  =  { { 0 }, 0, 0 };
	
//Stepper stepper = Stepper(200, &PORTD, 2);
//Servo *servo;
//Stepper *stepper;

	

inline int read_char(ring_buffer *_buffer)
{
	// if the head isn't ahead of the tail, we don't have any characters
	if (_buffer->head == _buffer->tail) {
		return -1;
		} else {
		unsigned char c = _buffer->buffer[_buffer->tail];
		_buffer->tail = (unsigned int)(_buffer->tail + 1) % BUFFER_SIZE;
		return c;
	}
}

inline int store_char(unsigned char c, ring_buffer *_buffer)
{
	int i = (unsigned int)(_buffer->head + 1) % BUFFER_SIZE;

	// if we should be storing the received character into the location
	// just before the tail (meaning that the head would advance to the
	// current location of the tail), we're about to overflow the buffer
	// and so we don't write the character or advance the head.
	if (i != _buffer->tail) {
		_buffer->buffer[_buffer->head] = c;
		_buffer->head = i;
		return 0;
	} else {
		return -1;
	}
}

/*inline int toInteger(char s[],ring_buffer *_tx_buffer )
{
	uint8_t i;
	int n, sign;
	//skip white space
	for (i=0; s[i]==' ' || s[i] == '\n' || s[i] == '\t'; i++)
	;
	//sign
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	sign = (s[i++] == '-') ? -1 : 1;
	
	//convert
	for (n=0; s[i]>='0' && s[i]<='9'; i++)
		n = 10*n + s[i] - '0';
	
	return (sign*n);
}*/

volatile int streamStart = 0;
inline void SerialHandler(ring_buffer *_tx_buffer, ring_buffer *_rx_buffer, ring_buffer *_dt_buffer/*, Servo *_servo, Stepper *_stepper , */)
{
	cli();
	volatile int chi = read_char(_rx_buffer);
	
	if (chi != -1) { 
		volatile char c = (char) chi;
		store_char(c, _tx_buffer);
		if (!streamStart) {
			if (c == '<')  {
				streamStart = 1;
			}
		} else if (c == '>') {
			streamStart = 0;
			uint8_t saveA = 4;
			uint8_t saveB = 5;
			
			char arrA[5] = {0};
			char arrB[5] = {0};

			uint8_t i = 0;
			uint8_t j = 0;
			
			int inta = 0;
			int intb = 0;
			
			int daC = read_char(_dt_buffer);
			while (daC != -1)
			{
				char ch = (char) daC;	
			    if ((j < 5) && (i < 25) ) {
					if (ch == '#') {
						if ((j > 0) && (i == saveA)) arrA[j] = ' ';
						if ((j > 0) && (i == saveB)) arrB[j] = ' ';	
						i++;
						j=0;					
					} else if (i == saveA) {
						arrA[j] = ch;
						j++;
					} else if (i == saveB) {
						arrB[j] = ch;
						j++;
					}					
				}
				daC = read_char(_dt_buffer);
			}
			//Debug char array
			/*for (uint8_t z=0; z<3; z++) {
				store_char(arrA[z], _tx_buffer);
			}
			uint8_t sizeb = sizeof(arrB)/sizeof(char);

			for (uint8_t z=0; z<sizeb; z++) {
				
			}*/
			
		    inta = atoi(arrA);
		    intb = atoi(arrB);
		    sbi(DDRD, 4);
		
			if (inta == 120) 
			 sbi(PORTD,4);
			else PORTD = 0;
			
			//if (intb == -120) PORTD = 0xFF;
			//else PORTD = 0;	
			
		} else if (streamStart){
			store_char(c, _dt_buffer);
		}
		
		chi = read_char(_rx_buffer);
	}		

	UCSRB |= (1<<UDRIE);
	sei();

}



ISR(USART_RXC_vect)
{
	unsigned char c  =  UDR;
	store_char(c, &rx_buffer);
	SerialHandler(&tx_buffer, &rx_buffer, &dt_buffer);
}

ISR(USART_UDRE_vect)
{
	int ci = read_char(&tx_buffer);
	if (ci == -1){
		UCSRB &= ~(1 << UDRIE);
	} else {
		UDR = (unsigned char)ci;
	} 
}

Serial::Serial() 
{


}

// Public Methods //////////////////////////////////////////////////////////////

void Serial::begin()
{
	// set baud rate
	UBRRH = (uint8_t)(MYUBBR >> 8);
	UBRRL = (uint8_t)(MYUBBR);
	// enable receive and transmit
	UCSRB = (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);
	// set frame format
	//UCSRC =  (1 << USBS) | (3 << UCSZ0);	// asynchron 8n1
	UCSRC =  (1 << USBS) | (3 << UCSZ0)|(1<<URSEL);
	
	sei();
}
/*
void Serial::end()
{
	UCSRB = 0;
}

int Serial::available(void)
{
  return (unsigned int)(BUFFER_SIZE + _rx_buffer->head - _rx_buffer->tail) % BUFFER_SIZE;
}

int Serial::peek(void)
{
  if (_rx_buffer->head == _rx_buffer->tail) {
    return -1;
  } else {
    return _rx_buffer->buffer[_rx_buffer->tail];
  }
}*/

int Serial::read(void){
	 return read_char(&rx_buffer);
}

void Serial::writeChar(uint8_t c)
{
   	int dta = store_char(c, &tx_buffer);
   	
   	while (dta == -1){};
   	// enable uart data interrupt (send data)
   	UCSRB |= (1<<UDRIE);
}
/*
void Serial::sendString(const char *s) 
{
  while (*s)   {
    this->writeChar(*s);
    s++;
  }
}*/
