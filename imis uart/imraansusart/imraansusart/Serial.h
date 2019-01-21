/*
 * Serial.h
 *
 * Created: 9/19/2016 9:50:16 PM
 *  Author: Imran
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_

/*
HardwareSerial.h - Hardware serial library for Wiring
Copyright (c) 2006 Nicholas Zambetti.  All right reserved.
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.
This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.
You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
Modified 28 September 2010 by Mark Sproul
*/


#include <inttypes.h>
#include <stdio.h>
//#include "Stepper.h"
//#include "Servo.h"

//#include "Servo.h"

struct ring_buffer;

class Serial 
{
	private:
		ring_buffer *_rx_buffer;
		ring_buffer *_tx_buffer;
		ring_buffer *_dt_buffer;
	    
	public:
		
		Serial();
		//Serial(Servo *_servo/*, Stepper *_stepper*/);
		
		void begin(void);
		void end();
		int available(void);
		int peek(void);
		
		int read(void);
		void flush(void);
		void writeChar(uint8_t);

		void sendString(const char *s);

		//void SerialHandler(void);


		// In your main just say:
		// Serial ser = Serial();
		// ser.begin();
		// kla
		
};

//extern Serial serial;


#endif /* SERIAL_H_ */