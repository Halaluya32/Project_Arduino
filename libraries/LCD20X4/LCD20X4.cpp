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

#include "LCD20X4.h"
#include <stdio.h>
#include <stdarg.h>

#define CMD_Clear_disp  0x01
#define CMD_Return_Home 0x02
#define CMD_Entry_Mode  0x04
#define CMD_Disp_Ctrl   0x08
#define CMD_Cursor_SH   0x10
#define CMD_Func_Set    0x20
#define CMD_Set_CGRAM	0x40
#define CMD_Set_DDRAM	0x80

const uint8_t char_addr[4][20] = {	{0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13},
									{0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50,0x51,0x52,0x53},
									{0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27},
									{0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67} };




//Private
uint8_t LCD20x4::read(uint8_t RS)
{
	uint8_t res = 0;
	EXP_IO[CTRL_IC_ADDR].pin_out(RS_pin, RS);
	EXP_IO[CTRL_IC_ADDR].pin_out(RW_pin, 1);
	EXP_IO[CTRL_IC_ADDR].pin_out(EN_pin, HIGH);
	//delayMicroseconds(1);
	res = EXP_IO[DATA_IC_ADDR].port_in();
	EXP_IO[CTRL_IC_ADDR].pin_out(EN_pin, LOW);
	return res;
}

void LCD20x4::write(uint8_t RS, uint8_t data)
{
	EXP_IO[CTRL_IC_ADDR].pin_out(RS_pin, RS);
	EXP_IO[CTRL_IC_ADDR].pin_out(RW_pin, 0);
	EXP_IO[CTRL_IC_ADDR].pin_out(EN_pin, HIGH);
	//delayMicroseconds(1);
	EXP_IO[DATA_IC_ADDR].port_out(data);
	EXP_IO[CTRL_IC_ADDR].pin_out(EN_pin, LOW);
}


void	LCD20x4::entry(uint8_t ID, uint8_t SH) 
{ 
	while (0x80 & chk_busy());
	write(0, CMD_Entry_Mode | (ID << 1) | SH); 
}

void	LCD20x4::disp_ctrl(uint8_t D, uint8_t C, uint8_t B) 
{ 
	while (0x80 & chk_busy()); 
	write(0, CMD_Disp_Ctrl | (D << 2) | (C << 1) | B); 
}

void	LCD20x4::shift(uint8_t SC, uint8_t RL) { write(0, CMD_Cursor_SH | (SC << 3) | (RL << 2)); }

void	LCD20x4::func_set(uint8_t DL, uint8_t N, uint8_t F) { write(0, CMD_Func_Set | (DL << 4) | (N << 3) | (F << 2)); }

void	LCD20x4::set_CGRAM(uint8_t Addr) { write(0, CMD_Set_CGRAM | Addr); }

void	LCD20x4::set_DDRAM(uint8_t Addr) { write(0, CMD_Set_DDRAM | Addr); }

uint8_t LCD20x4::chk_busy(void) { delayMicroseconds(100); return read(0); }

void	LCD20x4::write_data(uint8_t Data) 
{ 
	while (0x80 & chk_busy()); 
	write(1, Data); 	

	X++; 
	if (X >= 20)
	{
		Y++;
		if (Y >= 4)
		{
			Y = 3;
			X = 19;
		}
		else X = 0;
	}
}

uint8_t LCD20x4::read_data(void) 
{ 
	while (0x80 & chk_busy()); 
	X++;
	if (X >= 20)
	{
		Y++;
		if (Y >= 4)
		{
			Y = 3;
			X = 19;
		}
		else X = 0;
	}

	return read(1); 
}

void	LCD20x4::put(const char c)
{
	uint8_t tx, ty;
	switch (c)
	{
		case '\0':	break;
		case '\r':	X = 0; 
					break;
		case '\n':	if(Y<4)Y++; 
					break;
		case '\b':	if (X > 0)X--;
					else
					{
						if (Y > 0)
						{
							Y--; 
							X = 20;
						}
					}
					tx = X;
					ty = Y;
					set_DDRAM(char_addr[Y][X]);
					write_data(' ');
					X = tx;
					Y = ty;
					break;
		default  :	write_data(c);					
					break;
	}
	set_DDRAM(char_addr[Y][X]);
}

//Public
LCD20x4::LCD20x4(void) 
{
	X = 0;
	Y = 0;
}

void	LCD20x4::clr_disp(void) 
{ 
	while (0x80 & chk_busy()); 
	write(0, CMD_Clear_disp); 
	X = 0;
	Y = 0;
}

void	LCD20x4::home(void)     
{ 
	while (0x80 & chk_busy()); 
	write(0, CMD_Return_Home);
	X = 0;
	Y = 0;
}

void LCD20x4::init(bool Cursor_ON,bool Cursor_Blink) 
{   
	delay(500);
	backlight(false);

	func_set(1, 1, 0);						// Function set (Interface is 8 bit long.)
	delay(5);
	func_set(1, 1, 0);						// Function set (Interface is 8 bit long.)
	delay(1);
	func_set(1, 1, 0);						// Function set (Interface is 8 bit long.)
	while (0x80 & chk_busy());
	func_set(1, 1, 0);						// Function set (Interface is 8 bit long.)
	disp_ctrl(0, 0, 0);						//Display off, Curser off, Blink off
	clr_disp();								//Clear Display and Wait for Busy
	disp_ctrl(1, Cursor_ON, Cursor_Blink);	//Display on, Curser on, Blink on
	entry(1,0);								//Assign Cursor moving inclease direction, Cursor move

	backlight(true);	
}

void LCD20x4::print(const char *format, ...)
{
	char buf[23];
	uint8_t i;
	va_list args;	
	va_start(args, format);
	vsprintf(buf, format, args);
	perror(buf);
	va_end(args);
	i = 0;
	do {
		put(buf[i++]);
	} while (buf[i] != '\0');
	SerialUSB.println(X);
	SerialUSB.println(Y);
}

void LCD20x4::set_cursor(uint8_t show, uint8_t blink, uint8_t move_direction, uint8_t shift)
{
	disp_ctrl(1, show, blink);
	while (chk_busy() & 0x80);
	entry(move_direction, shift);
	while (chk_busy() & 0x80);
}

void LCD20x4::move_cursor(uint8_t pos) 
{
	Y = pos / 20;
	X = pos % 20;
	set_DDRAM(char_addr[Y][X]);
}
void LCD20x4::move_cursor(uint8_t col, uint8_t row)
{
	X = col;
	Y = row;
	set_DDRAM(char_addr[Y][X]);
}

void LCD20x4::backlight(bool ON)
{
	if (ON)EXP_IO[CTRL_IC_ADDR].pin_out(LCD_Backlight_pin, HIGH);
	else EXP_IO[CTRL_IC_ADDR].pin_out(LCD_Backlight_pin, LOW);
}
LCD20x4 lcd;