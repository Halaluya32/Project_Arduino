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

#ifndef _PCF8574_IO_h
#define _PCF8574_IO_h

#include "Arduino.h"
#include "wire.h"

#define Number_of_PC8574 5

class PCF8574_IO
{
private:
	uint8_t Address;
	uint8_t PortValue;
	uint8_t INT_pin;
	void set_isr(void);
protected:


public:	
	PCF8574_IO(uint8_t Addr, bool isPCF87574A, uint8_t EXINT_PIN);
	PCF8574_IO(uint8_t Addr, uint8_t EXINT_PIN);
	PCF8574_IO(uint8_t Addr);
	void init(uint8_t init_val = 0xFF);
	void change_int_pin(uint8_t New_INT_pin);
	void read_port(void);
	uint8_t port_out(uint8_t Value);
	uint8_t port_in(void);
	uint8_t pin_out(uint8_t Bit_No, uint8_t L0H1);
	uint8_t pin_in(uint8_t Bit_No);
};

extern PCF8574_IO EXP_IO[Number_of_PC8574];

extern void exp_init();
extern void exp_pin_out(uint8_t exp_pin_no, uint8_t L0H1);
#endif