/*
 * Space Board LCD library with PCF8574 controled for SAMD21 base.
 *
 * work with LCD20x4 Library from Interphonic SAMD21 Project
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

#include "Space_board_LCD20x4.h"

const uint8_t LED_NUMBER[5] = { LCD_Backlight_pin,LED1,LED2,LED3,LED4 };
//private

//public
SP_LCD::SP_LCD(void)
{
	keypress[0] = 'u';
	keypress[1] = 'd';
	keypress[2] = 'l';
	keypress[3] = 'r';
	keypress[4] = 'o';
	keypress[5] = 0;
	keymask = (1 << UP_pin) | (1 << DW_pin) | (1 << Lf_pin) | (1 << Rt_pin) | (1 << OK_pin);
}

void SP_LCD::init(bool Cursor_ON, bool Cursor_Blink)
{
	lcd.init(Cursor_ON,Cursor_Blink);
	EXP_IO[LED_IC_ADDR].pin_out(LED1, HIGH);
	EXP_IO[LED_IC_ADDR].pin_out(LED2, HIGH);
	EXP_IO[LED_IC_ADDR].pin_out(LED3, HIGH);
	EXP_IO[LED_IC_ADDR].pin_out(LED4, HIGH);
}

uint8_t SP_LCD::getkey(void)
{
	uint8_t tmp;
	tmp = EXP_IO[SW_IC_ADDR].port_in() & 0x1F;
	if (tmp & (1 << UP_pin))keypress[0] = 'u'; else keypress[0] = 'U';
	if (tmp & (1 << DW_pin))keypress[1] = 'd'; else keypress[1] = 'D';
	if (tmp & (1 << Lf_pin))keypress[2] = 'l'; else keypress[2] = 'L';
	if (tmp & (1 << Rt_pin))keypress[3] = 'r'; else keypress[3] = 'R';
	if (tmp & (1 << OK_pin))keypress[4] = 'o'; else keypress[4] = 'O';
	return tmp & keymask;
}

void SP_LCD::ledlight(uint8_t LED_No, bool ON)
{
	if(ON)EXP_IO[LED_IC_ADDR].pin_out(LED_NUMBER[LED_No], HIGH);
	else  EXP_IO[LED_IC_ADDR].pin_out(LED_NUMBER[LED_No], LOW);
}

char* SP_LCD::get_keypress(void) {return keypress;}

SP_LCD space_lcd;