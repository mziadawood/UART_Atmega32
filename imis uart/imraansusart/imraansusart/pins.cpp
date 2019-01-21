/*
 * pins.cpp
 *
 * Created: 09/08/2016 19:01:55
 *  Author: Muhammed Zia Dawood
 */ 

#define sbi(port,bit)  (port) |= (1 << (bit))
#define cbi(port,bit)  (port) &= ~(1 << (bit))
#include <avr/io.h>


void pinMode(int pin,int IO)
{
	if (pin==0)
	{
		if(IO==0)
		{
			cbi(DDRB, 0); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRB, 0); //pin 4 port b for output
		}
	}
	
	else if (pin==1)
	{
		if(IO==0)
		{
			cbi(DDRB,1); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRB, 1); //pin 4 port b for output
		}
	}
	
	else if (pin==2)
	{
		if(IO==0)
		{
			cbi(DDRB,2); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRB, 2); //pin 4 port b for output
		}
	}
	else if (pin==3)
	{
		if(IO==0)
		{
			cbi(DDRB,3); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRB, 3); //pin 4 port b for output
		}
	}
	else if (pin==4)
	{
		if(IO==0)
		{
			cbi(DDRB,4); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRB, 4); //pin 4 port b for output
		}
	}
	
	else if (pin==5)
	{
		if(IO==0)
		{
			cbi(DDRB,5); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRB, 5); //pin 4 port b for output
		}
	}
	else if (pin==6)
	{
		if(IO==0)
		{
			cbi(DDRB,6); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRB, 6); //pin 4 port b for output
		}
	}
	else if (pin==7)
	{
		if(IO==0)
		{
			cbi(DDRB,7); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRB, 7); //pin 4 port b for output
		}
	}
	
	
	
	else if (pin==8)
	{
		if(IO==0)
		{
			cbi(DDRD, 0); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRD, 0); //pin 4 port b for output
		}
	}
	
	else if (pin==9)
	{
		if(IO==0)
		{
			cbi(DDRD,1); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRD, 1); //pin 4 port b for output
		}
	}
	
	else if (pin==10)
	{
		if(IO==0)
		{
			cbi(DDRD,2); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRD, 2); //pin 4 port b for output
		}
	}
	else if (pin==11)
	{
		if(IO==0)
		{
			cbi(DDRD,3); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRD, 3); //pin 4 port b for output
		}
	}
	else if (pin==12)
	{
		if(IO==0)
		{
			cbi(DDRD,4); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRD, 4); //pin 4 port b for output
		}
	}
	
	else if (pin==13)
	{
		if(IO==0)
		{
			cbi(DDRD,5); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRD, 5); //pin 4 port b for output
		}
	}
	else if (pin==14)
	{
		if(IO==0)
		{
			cbi(DDRD,6); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRD, 6); //pin 4 port b for output
		}
	}
	else if (pin==15)
	{
		if(IO==0)
		{
			cbi(DDRD,7); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRD, 7); //pin 4 port b for output
		}
	}
	
	//ddddd
	if (pin==16)
	{
		if(IO==0)
		{
			cbi(DDRC, 0); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRC, 0); //pin 4 port b for output
		}
	}
	
	else if (pin==17)
	{
		if(IO==0)
		{
			cbi(DDRC,1); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRC, 1); //pin 4 port b for output
		}
	}
	
	else if (pin==18)
	{
		if(IO==0)
		{
			cbi(DDRC,2); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRC, 2); //pin 4 port b for output
		}
	}
	else if (pin==19)
	{
		if(IO==0)
		{
			cbi(DDRC,3); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRC, 3); //pin 4 port b for output
		}
	}
	else if (pin==20)
	{
		if(IO==0)
		{
			cbi(DDRC,4); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRC, 4); //pin 4 port b for output
		}
	}
	
	else if (pin==21)
	{
		if(IO==0)
		{
			cbi(DDRC,5); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRC, 5); //pin 4 port b for output
		}
	}
	else if (pin==22)
	{
		if(IO==0)
		{
			cbi(DDRC,6); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRC, 6); //pin 4 port b for output
		}
	}
	else if (pin==23)
	{
		if(IO==0)
		{
			cbi(DDRC,7); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRC, 7); //pin 4 port b for output
		}
	}
	
	if (pin==24)
	{
		if(IO==0)
		{
			cbi(DDRA, 7); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRA, 7); //pin 4 port b for output
		}
	}
	
	else if (pin==25)
	{
		if(IO==0)
		{
			cbi(DDRA,6); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRA, 6); //pin 4 port b for output
		}
	}
	
	else if (pin==26)
	{
		if(IO==0)
		{
			cbi(DDRA,5); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRA, 5); //pin 4 port b for output
		}
	}
	else if (pin==27)
	{
		if(IO==0)
		{
			cbi(DDRA,4); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRA, 4); //pin 4 port b for output
		}
	}
	else if (pin==28)
	{
		if(IO==0)
		{
			cbi(DDRA,3); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRA, 3); //pin 4 port b for output
		}
	}
	
	else if (pin==29)
	{
		if(IO==0)
		{
			cbi(DDRA,2); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRA, 2); //pin 4 port b for output
		}
	}
	else if (pin==30)
	{
		if(IO==0)
		{
			cbi(DDRA,1); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRA, 1); //pin 4 port b for output
		}
	}
	else if (pin==31)
	{
		if(IO==0)
		{
			cbi(DDRA,0); //pin 4 port b for inputput
			
		}
		
		else if(IO==1)
		{
			sbi(DDRA, 0); //pin 4 port b for output
		}
	}
	
}




void digitalWrite(int pin, int value)
{
	if (pin==0)
	{
		if(value==0)
		{
			cbi(PORTB,0);
			
		}
		
		if(value==1)
		{
			sbi(PORTB,0);
		}
	}
	
	
	else if (pin==1)
	{
		if(value==0)
		{
			cbi(PORTB,1); //pin 4 port b for inputput
			
		}
		
		if(value==1)
		{
			sbi(PORTB,1); //pin 4 port b for output
		}
	}
	
	
	else if (pin==2)
	{
		if(value==0)
		{
			cbi(PORTB,2); //pin 4 port b for inputput
			
		}
		
		else if(value==1)
		{
			sbi(PORTB,2); //pin 4 port b for output
		}
	}
	
	
	else if (pin==3)
	{
		if(value==0)
		{
			cbi(PORTB,3); //pin 4 port b for inputput
			
		}
		
		if(value==1)
		{
			sbi(PORTB,3); //pin 4 port b for output
		}
	}
	
	
	else if (pin==4)
	{
		if(value==0)
		{
			cbi(PORTB,4); //pin 4 port b for inputput
			
		}
		
		if(value==1)
		{
			sbi(PORTB,4); //pin 4 port b for output
		}
	}
	
	
	
	else if (pin==5)
	{
		if(value==0)
		{
			cbi(PORTB,5); //pin 4 port b for inputput
			
		}
		
		else if(value==1)
		{
			sbi(PORTB,5); //pin 4 port b for output
		}
	}
	
	
	
	
	else if (pin==6)
	{
		if(value==0)
		{
			cbi(PORTB,6); //pin 4 port b for inputput
			
		}
		
		if(value==1)
		{
			sbi(PORTB,6); //pin 4 port b for output
		}
	}
	
	else if (pin==7)
	{
		if(value==0)
		{
			cbi(PORTB,7); //pin 4 port b for inputput
			
		}
		
		if(value==1)
		{
			sbi(PORTB,7); //pin 4 port b for output
		}
	}
	
	
//ffff
	if (pin==8)
	{
		if(value==0)
		{
			cbi(PORTD,0);
			
		}
		
		if(value==1)
		{
			sbi(PORTD,0);
		}
	}
	
	
	else if (pin==9)
	{
		if(value==0)
		{
			cbi(PORTD,1); //pin 4 port b for inputput
			
		}
		
		if(value==1)
		{
			sbi(PORTD,1); //pin 4 port b for output
		}
	}
	
	
	else if (pin==10)
	{
		if(value==0)
		{
			cbi(PORTD,2); //pin 4 port b for inputput
			
		}
		
		else if(value==1)
		{
			sbi(PORTD,2); //pin 4 port b for output
		}
	}
	
	
	else if (pin==11)
	{
		if(value==0)
		{
			cbi(PORTD,3); //pin 4 port b for inputput
			
		}
		
		if(value==1)
		{
			sbi(PORTD,3); //pin 4 port b for output
		}
	}
	
	
	else if (pin==12)
	{
		if(value==0)
		{
			cbi(PORTD,4); //pin 4 port b for inputput
			
		}
		
		if(value==1)
		{
			sbi(PORTD,4); //pin 4 port b for output
		}
	}
	
	
	
	else if (pin==13)
	{
		if(value==0)
		{
			cbi(PORTD,5); //pin 4 port b for inputput
			
		}
		
		else if(value==1)
		{
			sbi(PORTD,5); //pin 4 port b for output
		}
	}
	
	
	
	
	else if (pin==14)
	{
		if(value==0)
		{
			cbi(PORTD,6); //pin 4 port b for inputput
			
		}
		
		if(value==1)
		{
			sbi(PORTD,6); //pin 4 port b for output
		}
	}
	
	else if (pin==15)
	{
		if(value==0)
		{
			cbi(PORTD,7); //pin 4 port b for inputput
			
		}
		
		if(value==1)
		{
			sbi(PORTD,7); //pin 4 port b for output
		}
	}
	
	
		if (pin==16)
		{
			if(value==0)
			{
				cbi(PORTC,0);
				
			}
			
			if(value==1)
			{
				sbi(PORTC,0);
			}
		}
		
		
		else if (pin==17)
		{
			if(value==0)
			{
				cbi(PORTC,1); //pin 4 port b for inputput
				
			}
			
			if(value==1)
			{
				sbi(PORTC,1); //pin 4 port b for output
			}
		}
		
		
		else if (pin==18)
		{
			if(value==0)
			{
				cbi(PORTC,2); //pin 4 port b for inputput
				
			}
			
			else if(value==1)
			{
				sbi(PORTC,2); //pin 4 port b for output
			}
		}
		
		
		else if (pin==19)
		{
			if(value==0)
			{
				cbi(PORTC,3); //pin 4 port b for inputput
				
			}
			
			if(value==1)
			{
				sbi(PORTC,3); //pin 4 port b for output
			}
		}
		
		
		else if (pin==20)
		{
			if(value==0)
			{
				cbi(PORTC,4); //pin 4 port b for inputput
				
			}
			
			if(value==1)
			{
				sbi(PORTC,4); //pin 4 port b for output
			}
		}
		
		
		
		else if (pin==21)
		{
			if(value==0)
			{
				cbi(PORTC,5); //pin 4 port b for inputput
				
			}
			
			else if(value==1)
			{
				sbi(PORTC,5); //pin 4 port b for output
			}
		}
		
		
		
		
		else if (pin==22)
		{
			if(value==0)
			{
				cbi(PORTC,6); //pin 4 port b for inputput
				
			}
			
			if(value==1)
			{
				sbi(PORTC,6); //pin 4 port b for output
			}
		}
		
		else if (pin==23)
		{
			if(value==0)
			{
				cbi(PORTC,7); //pin 4 port b for inputput
				
			}
			
			if(value==1)
			{
				sbi(PORTC,7); //pin 4 port b for output
			}
		}
		if (pin==24)
		{
			if(value==0)
			{
				cbi(PORTA,7);
				
			}
			
			if(value==1)
			{
				sbi(PORTA,7);
			}
		}
		
		
		else if (pin==25)
		{
			if(value==0)
			{
				cbi(PORTA,6); //pin 4 port b for inputput
				
			}
			
			if(value==1)
			{
				sbi(PORTA,6); //pin 4 port b for output
			}
		}
		
		
		else if (pin==26)
		{
			if(value==0)
			{
				cbi(PORTA,5); //pin 4 port b for inputput
				
			}
			
			else if(value==1)
			{
				sbi(PORTA,5); //pin 4 port b for output
			}
		}
		
		
		else if (pin==27)
		{
			if(value==0)
			{
				cbi(PORTA,4); //pin 4 port b for inputput
				
			}
			
			if(value==1)
			{
				sbi(PORTA,4); //pin 4 port b for output
			}
		}
		
		
		else if (pin==28)
		{
			if(value==0)
			{
				cbi(PORTA,3); //pin 4 port b for inputput
				
			}
			
			if(value==1)
			{
				sbi(PORTA,3); //pin 4 port b for output
			}
		}
		
		
		
		else if (pin==29)
		{
			if(value==0)
			{
				cbi(PORTA,2); //pin 4 port b for inputput
				
			}
			
			else if(value==1)
			{
				sbi(PORTA,2); //pin 4 port b for output
			}
		}
		
		
		
		
		else if (pin==30)
		{
			if(value==0)
			{
				cbi(PORTA,1); //pin 4 port b for inputput
				
			}
			
			if(value==1)
			{
				sbi(PORTA,1); //pin 4 port b for output
			}
		}
		
		else if (pin==31)
		{
			if(value==0)
			{
				cbi(PORTA,0); //pin 4 port b for inputput
				
			}
			
			if(value==1)
			{
				sbi(PORTA,0); //pin 4 port b for output
			}
		}
	
}