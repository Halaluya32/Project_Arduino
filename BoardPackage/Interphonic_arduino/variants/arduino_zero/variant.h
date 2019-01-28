/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/*
Modify for Support Interphonic Arduino Project (SAMD21)
*/


#ifndef _VARIANT_SPACE_BOARD_
#define _VARIANT_SPACE_BOARD_

// The definitions here needs a SAMD core >=1.6.10
#define ARDUINO_SAMD_VARIANT_COMPLIANCE 10610

/*----------------------------------------------------------------------------
 *        Definitions
 *----------------------------------------------------------------------------*/

/** Frequency of the board main oscillator */
#define VARIANT_MAINOSC		(32768ul)

/** Master clock frequency */
#define VARIANT_MCK			  (48000000ul)

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
#include "SERCOM.h"
#include "Uart.h"
#endif // __cplusplus

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*----------------------------------------------------------------------------
 *        Pins
 *----------------------------------------------------------------------------*/

// Number of pins defined in PinDescription array
#define PINS_COUNT           (37u)
#define NUM_DIGITAL_PINS     (14u)
#define NUM_ANALOG_INPUTS    (10u)
#define NUM_ANALOG_OUTPUTS   (0u)
#define analogInputToDigitalPin(p)  ((p < 10u) ? (p) : -1)

#define digitalPinToPort(P)        ( &(PORT->Group[g_APinDescription[P].ulPort]) )
#define digitalPinToBitMask(P)     ( 1 << g_APinDescription[P].ulPin )
#define portOutputRegister(port)   ( &(port->OUT.reg) )
#define portInputRegister(port)    ( &(port->IN.reg) )
#define portModeRegister(port)     ( &(port->DIR.reg) )
#define digitalPinHasPWM(P)        ( g_APinDescription[P].ulPWMChannel != NOT_ON_PWM || g_APinDescription[P].ulTCChannel != NOT_ON_TIMER )

/*
 * digitalPinToTimer(..) is AVR-specific and is not defined for SAMD
 * architecture. If you need to check if a pin supports PWM you must
 * use digitalPinHasPWM(..).
 *
 * https://github.com/arduino/Arduino/issues/1833
 */
/*
 * Analog pins
 */
#define PIN_A0               (0ul)
#define PIN_A1               (1ul)
#define PIN_A2               (2ul)
#define PIN_A3               (3ul)
#define PIN_A4               (4ul)
#define PIN_A5               (5ul)
#define PIN_A6               (6ul)
#define PIN_A7               (7ul)
#define PIN_A8               (8ul)
#define PIN_A9               (9ul)

static const uint8_t A0  = PIN_A0;
static const uint8_t A1  = PIN_A1;
static const uint8_t A2  = PIN_A2;
static const uint8_t A3  = PIN_A3;
static const uint8_t A4  = PIN_A4;
static const uint8_t A5  = PIN_A5;
static const uint8_t A6  = PIN_A6;
static const uint8_t A7  = PIN_A7;
static const uint8_t A8  = PIN_A8;
static const uint8_t A9  = PIN_A9;

#define ADC_RESOLUTION		12

/*
 * Digital pins
 */
#define PIN_D0               (0ul)
#define PIN_D1               (1ul)
#define PIN_D2               (2ul)
#define PIN_D3               (3ul)
#define PIN_D4               (4ul)
#define PIN_D5               (5ul)
#define PIN_D6               (6ul)
#define PIN_D7               (7ul)
#define PIN_D8               (8ul)
#define PIN_D9               (9ul)
#define PIN_D10              (10ul)
#define PIN_D11              (11ul)
#define PIN_D12              (12ul)
#define PIN_D13              (13ul)

//PC8574 - Addr 00
#define PIN_EXP0_0			 0x30
#define PIN_EXP0_1			 0x31
#define PIN_EXP0_2			 0x32
#define PIN_EXP0_3			 0x33
#define PIN_EXP0_4			 0x34
#define PIN_EXP0_5			 0x35
#define PIN_EXP0_6			 0x36
#define PIN_EXP0_7			 0x37
  
//PC8574 - Addr 01  
#define PIN_EXP1_0			 0x38
#define PIN_EXP1_1			 0x39
#define PIN_EXP1_2			 0x3A
#define PIN_EXP1_3			 0x3B
#define PIN_EXP1_4			 0x3C
#define PIN_EXP1_5			 0x3D
#define PIN_EXP1_6			 0x3E
#define PIN_EXP1_7			 0x3F

//PC8574 - Addr 02
#define PIN_EXP2_0			 0x40
#define PIN_EXP2_1			 0x41
#define PIN_EXP2_2			 0x42
#define PIN_EXP2_3			 0x43
#define PIN_EXP2_4			 0x44
#define PIN_EXP2_5			 0x45
#define PIN_EXP2_6			 0x46
#define PIN_EXP2_7			 0x47
      
//PC8574 - Addr 03	  
#define PIN_EXP3_0			 0x48
#define PIN_EXP3_1			 0x49
#define PIN_EXP3_2			 0x4A
#define PIN_EXP3_3			 0x4B
#define PIN_EXP3_4			 0x4C
#define PIN_EXP3_5			 0x4D
#define PIN_EXP3_6			 0x4E
#define PIN_EXP3_7			 0x4F

//PC8574 - Addr 04
#define PIN_EXP4_0			 0x50
#define PIN_EXP4_1			 0x51
#define PIN_EXP4_2			 0x52
#define PIN_EXP4_3			 0x53
#define PIN_EXP4_4			 0x54
#define PIN_EXP4_5			 0x55
#define PIN_EXP4_6			 0x56
#define PIN_EXP4_7			 0x57
              

static const uint8_t D0   = PIN_D0;
static const uint8_t D1   = PIN_D1;
static const uint8_t D2   = PIN_D2;
static const uint8_t D3   = PIN_D3;
static const uint8_t D4   = PIN_D4;
static const uint8_t D5   = PIN_D5;
static const uint8_t D6   = PIN_D6;
static const uint8_t D7   = PIN_D7;
static const uint8_t D8   = PIN_D8;
static const uint8_t D9   = PIN_D9;
static const uint8_t D10  = PIN_D10;
static const uint8_t D11  = PIN_D11;
static const uint8_t D12  = PIN_D12;
static const uint8_t D13  = PIN_D13;

#define PIN_BUSY             (14ul) 
#define PIN_RW485            (16ul) 
#define PIN_INT0             (17ul) 
#define PIN_INT1             (18ul) 
#define PIN_INT2             (19ul) 
#define PIN_INT3             (20ul) 

static const uint8_t GLCD_BSY  = PIN_BUSY;
static const uint8_t RS485_RW  = PIN_RW485;
static const uint8_t ETH_INT   = PIN_INT0;
static const uint8_t GSM_WAKE  = PIN_INT1;
static const uint8_t LCD_INT   = PIN_INT2;
static const uint8_t SW_INT    = PIN_INT3;

/*
 * Serial interfaces
 */
// Serial0 (GSM)
#define PIN_SERIAL0_RX       (22ul)
#define PIN_SERIAL0_TX       (21ul)
#define PAD_SERIAL0_TX       (UART_TX_PAD_0)
#define PAD_SERIAL0_RX       (SERCOM_RX_PAD_1)

// Serial4 (WIFI)
#define PIN_SERIAL4_RX      (24ul)
#define PIN_SERIAL4_TX      (23ul)
#define PAD_SERIAL4_TX      (UART_TX_PAD_2)
#define PAD_SERIAL4_RX      (SERCOM_RX_PAD_3)

// Serial4 (RS485)
#define PIN_SERIAL5_RX      (26ul)
#define PIN_SERIAL5_TX      (25ul)
#define PAD_SERIAL5_TX      (UART_TX_PAD_0)
#define PAD_SERIAL5_RX      (SERCOM_RX_PAD_1)


/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO         (29u)
#define PIN_SPI_MOSI         (27u)
#define PIN_SPI_SCK          (28u)
#define PERIPH_SPI           sercom1
#define PAD_SPI_TX           SPI_PAD_0_SCK_1
#define PAD_SPI_RX           SERCOM_RX_PAD_3

static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK  ;

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA         (30u)
#define PIN_WIRE_SCL         (31u)
#define PERIPH_WIRE          sercom2
#define WIRE_IT_HANDLER      SERCOM2_Handler

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

/*
 * USB
 */
#define PIN_USB_HOST_ENABLE (15ul)
#define PIN_USB_DM          (28ul)
#define PIN_USB_DP          (29ul)

/*
 * Ethernet 
 */ 
#define PIN_SPI_SS_ETHERNET_LIB PIN_EXP1_4
#define PIN_ETHERNET_RESET		PIN_EXP1_5
#define PIN_ETHERNET_INT		17 

/*
 * GSM
 */ 
 #define PIN_GSM_RESET          PIN_EXP2_0
 #define PIN_GSM_Data_Disable	PIN_EXP2_1
/*
 * LORA 
 */ 
 #define PIN_SPI_SS_LORA_LIB  	PIN_EXP1_0
 #define PIN_LORA_TX_SWITCH  	PIN_EXP1_3
 #define PIN_LORA_RX_SWITCH		PIN_EXP1_2
 #define PIN_LORA_RESET			PIN_EXP1_1
  
/*
 * SDMC 
 */ 
 #define PIN_SPI_SS_SD_LIB  	PIN_EXP1_6
 
#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#ifdef __cplusplus

/*	=========================
 *	===== SERCOM DEFINITION
 *	=========================
*/
extern SERCOM sercom0;
extern SERCOM sercom1;
extern SERCOM sercom2;
extern SERCOM sercom3;
extern SERCOM sercom4;
extern SERCOM sercom5;

extern Uart Serial0;
extern Uart Serial4;
extern Uart Serial5;

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_USBVIRTUAL      SerialUSB
//#define SERIAL_PORT_MONITOR         SerialUSB
#define GSMcomm                     Serial0
#define WIFIcomm                    Serial4
#define RS485comm                   Serial5
#endif /* _VARIANT_ARDUINO_ZERO_ */