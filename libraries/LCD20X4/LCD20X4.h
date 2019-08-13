/*
 * Charactor LCD 20x4 library with PCF8574 controled for SAMD21 base.
 *
 * work with PCF8574_IO Library from Interphonic SAMD21 Project
 *
 * DataSheet Url : https://www.es.co.th/Schemetic/PDF/LCD020N004BTMIET.PDF
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

#ifndef _LCD20X4_h
#define _LCD20X4_h

#include "PCF8574_IO.h"

/********************************************************/
#define LCD_Backlight_pin 4 
#define RS_pin  5
#define RW_pin  6
#define EN_pin  7
#define CTRL_IC_ADDR 3 
#define DATA_IC_ADDR 4
/********************************************************/

#define BitMode_4 4
#define BitMode_8 8

class LCD20x4
{
	private:
		uint8_t X, Y,BM;
		uint8_t read(uint8_t RS);
		void	write(uint8_t RS, uint8_t data);
		uint8_t read_8bit(uint8_t RS);
		void	write_8bit(uint8_t RS,uint8_t data);
		uint8_t read_4bit(uint8_t RS);
		void	write_4bit(uint8_t RS, uint8_t data);
		void	entry(uint8_t ID, uint8_t SH);
		void	disp_ctrl(uint8_t D, uint8_t C, uint8_t B);
		void	shift(uint8_t SC, uint8_t RL);
		void	func_set(uint8_t DL, uint8_t N, uint8_t F);
		void	set_CGRAM(uint8_t Addr);
		void	set_DDRAM(uint8_t Addr);
		uint8_t	chk_busy(void);
		void	write_data(uint8_t Data);
		uint8_t read_data(void);
		void	init_4bit(bool Cursor_ON = true, bool Cursor_Blink = true);
		void	init_8bit(bool Cursor_ON = true, bool Cursor_Blink = true);
	protected:
		
	public:
		LCD20x4(char BitMode);
		void clr_disp(void);	
		void home(void);
		void init(bool Cursor_ON = true, bool Cursor_Blink = true);
		void put(const char c);
		void printf(const char *format, ...);
		void set_cursor(uint8_t show, uint8_t blink, uint8_t move_direction, uint8_t shift);
		void move_cursor(uint8_t pos);
		void move_cursor(uint8_t col, uint8_t row);
		void backlight(bool ON);
};

extern LCD20x4 lcd;
#endif