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

#ifndef _Space_board_LCD20x4_h
#define _Space_board_LCD20x4_h

#include "LCD20x4.h"

 /********************************************************/
#define UP_pin  0 
#define DW_pin  1
#define Lf_pin  2
#define Rt_pin  3
#define OK_pin  4

#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3

#define SW_IC_ADDR  0
#define LED_IC_ADDR 3 
/********************************************************/

/*
/////////////////////////////////////
/	Keypress[0] - Up switch
/	Keypress[1] - Down switch
/	Keypress[2] - Left switch
/	Keypress[3] - Right switch
/	Keypress[4] - OK switch
/
/   LED[0] - LED of LCD backlight
/	onboard LED is LED[1] to LED[4]
/////////////////////////////////////
*/


#define pressUP		'U'
#define pressDOWN	'D'
#define pressLeft	'L'
#define pressRight	'R'
#define PressOK		'O'

#define releaseUP	 'u'
#define releaseDOWN	 'd'
#define releaseLeft	 'l'
#define releaseRight 'r'
#define releaseOK	 'o'

class SP_LCD
{
	private:
		char keypress[6];
		uint8_t keymask;
	protected:

	public:
		SP_LCD(void);
		void init(bool Cursor_ON, bool Cursor_Blink);
		uint8_t getkey(void);
		void ledlight(uint8_t LED_No, bool ON);
		char* get_keypress(void);
};

extern SP_LCD space_lcd;
#endif

