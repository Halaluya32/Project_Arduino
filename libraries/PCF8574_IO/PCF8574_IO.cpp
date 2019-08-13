/*
 * PCF8574/PCF8574T library for SAMD21 base.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */

#include "PCF8574_IO.h"

#if Number_of_PC8574 > 0
	void exp_isr0(void) { EXP_IO[0].read_port(); }
#endif
#if Number_of_PC8574 > 1
	void exp_isr1(void) { EXP_IO[1].read_port(); }
#endif
#if Number_of_PC8574 > 2
	void exp_isr2(void) { EXP_IO[2].read_port(); }
#endif
#if Number_of_PC8574 > 3
	void exp_isr3(void) { EXP_IO[3].read_port(); }
#endif
#if Number_of_PC8574 > 4
	void exp_isr4(void) { EXP_IO[4].read_port(); }
#endif								
#if Number_of_PC8574 > 5			
	void exp_isr5(void) { EXP_IO[5].read_port(); }
#endif								
#if Number_of_PC8574 > 6			
	void exp_isr6(void) { EXP_IO[6].read_port(); }
#endif								
#if Number_of_PC8574 > 7			
	void exp_isr7(void) { EXP_IO[7].read_port(); }
#endif								
#if Number_of_PC8574 > 8			
	void exp_isr8(void) { EXP_IO[8].read_port(); }
#endif								
#if Number_of_PC8574 > 9			
	void exp_isr9(void) { EXP_IO[9].read_port(); }
#endif
#if Number_of_PC8574 > 10
	void exp_isr10(void) { EXP_IO[10].read_port();}
#endif
#if Number_of_PC8574 > 11
	void exp_isr11(void) { EXP_IO[11].read_port();}
#endif
#if Number_of_PC8574 > 12
	void exp_isr12(void) { EXP_IO[12].read_port();}
#endif
#if Number_of_PC8574 > 13
	void exp_isr13(void) { EXP_IO[13].read_port();}
#endif
#if Number_of_PC8574 > 14
	void exp_isr14(void) { EXP_IO[14].read_port();}
#endif
#if Number_of_PC8574 > 15
	void exp_isr15(void) { EXP_IO[15].read_port();}
#endif

	
	//Private
void PCF8574_IO::set_isr(void)
{
	pinMode(INT_pin, INPUT);
	switch (Address)
	{
		#if Number_of_PC8574 > 0
			case 0x20: attachInterrupt(INT_pin, exp_isr0, FALLING); break;
		#endif
		#if Number_of_PC8574 > 1
			case 0x21: attachInterrupt(INT_pin, exp_isr1, FALLING); break;
		#endif
		#if Number_of_PC8574 > 2
			case 0x22: attachInterrupt(INT_pin, exp_isr2, FALLING); break;
		#endif
		#if Number_of_PC8574 > 3
			case 0x23: attachInterrupt(INT_pin, exp_isr3, FALLING); break;
		#endif
		#if Number_of_PC8574 > 4
			case 0x24: attachInterrupt(INT_pin, exp_isr4, FALLING); break;
		#endif
		#if Number_of_PC8574 > 5
			case 0x25: attachInterrupt(INT_pin, exp_isr5, FALLING); break;
		#endif
		#if Number_of_PC8574 > 6
			case 0x26: attachInterrupt(INT_pin, exp_isr6, FALLING); break;
		#endif
		#if Number_of_PC8574 > 7
			case 0x27: attachInterrupt(INT_pin, exp_isr7, FALLING); break;
		#endif
		#if Number_of_PC8574 > 8
			case 0x38: attachInterrupt(INT_pin, exp_isr8, FALLING); break;
		#endif
		#if Number_of_PC8574 > 9
			case 0x39: attachInterrupt(INT_pin, exp_isr9, FALLING); break;
		#endif
		#if Number_of_PC8574 > 10
			case 0x3A: attachInterrupt(INT_pin, exp_isr10, FALLING); break;
		#endif
		#if Number_of_PC8574 > 11
			case 0x3B: attachInterrupt(INT_pin, exp_isr11, FALLING); break;
		#endif
		#if Number_of_PC8574 > 12
			case 0x3C: attachInterrupt(INT_pin, exp_isr12, FALLING); break;
		#endif
		#if Number_of_PC8574 > 13
			case 0x3D: attachInterrupt(INT_pin, exp_isr13, FALLING); break;
		#endif
		#if Number_of_PC8574 > 14
			case 0x3E: attachInterrupt(INT_pin, exp_isr14, FALLING); break;
		#endif
		#if Number_of_PC8574 > 15
			case 0x3F: attachInterrupt(INT_pin, exp_isr15, FALLING); break;
		#endif
	}

}

void PCF8574_IO::read_port(void)
{
	Wire.requestFrom(Address, 1);    	    // request 1 bytes from slave device #Address
	while (Wire.available())    			// slave may send less than requested
	{
		PortValue = Wire.read(); 			// receive a byte as Unsigned INT8
	}	
}


//Public
PCF8574_IO::PCF8574_IO(uint8_t Addr, bool isPCF87574A, uint8_t EXINT_PIN)
{
	if (Addr < 8)
	{
		if (isPCF87574A)	Address = 0x38 + (Addr);
		else				Address = 0x20 + (Addr);
		INT_pin = EXINT_PIN;
		PortValue = 0;
	}
}

PCF8574_IO::PCF8574_IO(uint8_t Addr, uint8_t EXINT_PIN)
{
	if (Addr < 8) Address = 0x20 + (Addr);
	else Address = 0x30 + (Addr);
	INT_pin = EXINT_PIN;
	PortValue = 0;
}

PCF8574_IO::PCF8574_IO(uint8_t Addr)
{
	if (Addr < 8) Address = 0x20 + (Addr);
	else Address = 0x30 + (Addr);
	INT_pin = 0xFF;
	PortValue = 0;
}

void PCF8574_IO::init(uint8_t init_val)
{
	Wire.begin();
	//Wire.
	port_out(init_val);
	port_in();
	if(INT_pin != 0xFF)set_isr();
}

void PCF8574_IO::change_int_pin(uint8_t New_INT_pin)
{
	INT_pin = New_INT_pin;
	set_isr();
}

uint8_t PCF8574_IO::port_out(uint8_t Value)
{
	PortValue = Value;
	Wire.beginTransmission(Address); 		// transmit to device #Address
	Wire.write(Value);               		// sends one byte  
	return Wire.endTransmission();    		// stop transmitting
}

uint8_t PCF8574_IO::port_in(void)
{
	if (INT_pin == 0xFF) read_port();

	return PortValue;
}

uint8_t PCF8574_IO::pin_out(uint8_t Bit_No, uint8_t L0H1)
{
	if (L0H1)PortValue |= (uint8_t)(1 << Bit_No);
	else PortValue &= (uint8_t)(~(1 << Bit_No));
	return port_out(PortValue);
}

uint8_t PCF8574_IO::pin_in(uint8_t Bit_No)
{
	return port_in() >> Bit_No;
}

PCF8574_IO EXP_IO[Number_of_PC8574]{ {0,SW_INT},{1},{2},{3},{4} };

void exp_init()
{
	#if Number_of_PC8574 > 0 
		EXP_IO[0].init(InitPort0);
	#endif
	#if Number_of_PC8574 > 1
		EXP_IO[1].init(InitPort1);
	#endif
	#if Number_of_PC8574 > 2
		EXP_IO[2].init(InitPort2);
	#endif
	#if Number_of_PC8574 > 3
		EXP_IO[3].init(InitPort3);
	#endif
	#if Number_of_PC8574 > 4
		EXP_IO[4].init(InitPort4);
	#endif
	#if Number_of_PC8574 > 5
		EXP_IO[5].init(InitPort5);
	#endif
	#if Number_of_PC8574 > 6
		EXP_IO[6].init(InitPort6);
	#endif
	#if Number_of_PC8574 > 7
		EXP_IO[7].init(InitPort7);
	#endif
	#if Number_of_PC8574 > 8
		EXP_IO[8].init(InitPort9);
	#endif
	#if Number_of_PC8574 > 8
		EXP_IO[9].init(InitPort9);
	#endif
	#if Number_of_PC8574 > 10
		EXP_IO[10].init(InitPort10);
	#endif
	#if Number_of_PC8574 > 11
		EXP_IO[11].init(InitPort11);
	#endif
	#if Number_of_PC8574 > 12
		EXP_IO[12].init(InitPort12);
	#endif
	#if Number_of_PC8574 > 13
		EXP_IO[13].init(InitPort13);
	#endif
	#if Number_of_PC8574 > 14
		EXP_IO[14].init(InitPort14);
	#endif
	#if Number_of_PC8574 > 15
		EXP_IO[15].init(InitPort15);
	#endif	
	
}

void exp_pin_out(uint8_t exp_pin_no, uint8_t L0H1)
{
	if (exp_pin_no >= 0x58)
	{

	}
	else if (exp_pin_no >= 0x50)EXP_IO[4].pin_out(exp_pin_no - 0x50, L0H1);
	else if (exp_pin_no >= 0x48)EXP_IO[3].pin_out(exp_pin_no - 0x48, L0H1);
	else if (exp_pin_no >= 0x40)EXP_IO[2].pin_out(exp_pin_no - 0x40, L0H1);
	else if (exp_pin_no >= 0x38)EXP_IO[1].pin_out(exp_pin_no - 0x38, L0H1);
	else if (exp_pin_no >= 0x30)EXP_IO[0].pin_out(exp_pin_no - 0x30, L0H1);
	else digitalWrite(exp_pin_no, L0H1);
}