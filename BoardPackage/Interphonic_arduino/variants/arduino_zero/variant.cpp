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


/*
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * + Pin number +  Space Board pin  |  PIN   | Label/Name        | Comments (* is for default peripheral in use)        |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |            |Analog Current Mode|        |                   |                                                      |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |     0      |                   |  PA 2  |D[0]/A[0]/PTC_Y[0] | *AIN[0]  /EXTINT[2]                                  |
 * |     1      |                   |  PA 3  |D[1]/A[1]/PTC_Y[1] | *AIN[1]  /EXTINT[3]                                  |
 * |     2      |                   |  PA 6  |D[2]/A[2]/PTC_Y[4] | *AIN[6]                                              |
 * |     3      |                   |  PA 7  |D[3]/A[3]/PTC_Y[5] | *AIN[7]                                              |
 * |     4      |                   |  PB 2  |D[4]/A[4]/PTC_Y[8] | *AIN[10] /EXTINT[2]                                  |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |            |Analog Voltage Mode|        |                   |                                                      |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |     5      |                   |  PB 8  |D[5]/A[5]/PTC_Y[14]| *AIN[2 ] / PWM4_CH0   /  TC4_CH0                     |
 * |     6      |                   |  PB 9  |D[6]/A[6]/PTC_Y[15]| *AIN[3 ] / PWM4_CH1   /  TC4_CH1      /  EXTINT[9]   |
 * |     7      |                   |  PA 8  |D[7]/A[7]/PTC_X[0] | *AIN[16] / PWM0_CH0   /  TCC0_CH0     /  EXTINT[NMI] |
 * |     8      |                   |  PA 9  |D[8]/A[8]/PTC_X[1] | *AIN[17] / PWM0_CH1   /  TCC0_CH1     /  EXTINT[9]   |
 * |     9      |                   |  PA10  |D[9]/A[9]/PTC_X[2] | *AIN[18] / NOT_ON_PWM /  NOT_ON_TIMER /  EXTINT[10]  |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |            | Digital IO Pin    |        |                   |                                                      |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |     10     |                   |  PA11  |D[10]/PCT_X[3]     | *Digital IO / EXTINT[11]                             |
 * |     11     |                   |  PA18  |D[11]/PCT_X[6]     | *Digital IO / PWM3_CH0  / TC3_CH0  / EXTINT[2]       |
 * |     12     |                   |  PA20  |D[12]/PCT_X[8]     | *Digital IO / PWM0_CH6  / TCC0_CH6 / EXTINT[4]       |
 * |     13     |                   |  PA15  |D[13]/PCT_X[14]    | *Digital IO / PWM3_CH1  / TC3_CH1                    |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |            | Digital fixed fn  |        |                   |                                                      |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |     14     | INPUT ONLY        |  PB 3  |GLCD[2]            | GLCD BUSY CHECK                                      |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|                                                          
 * |     15     | OUTPUT ONLY       |  PA14  |USB[0]             | USB  : HOST ID                                       |
 * |     16     |                   |  PA21  |RS485[2]           | RW485: Read(low)/Write(high) to RS485 bus            |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |     17     | Input Interrupt   |  PA27  |INT[0]             | EXTINT[15] : Ethernet INT                            |
 * |     18     |                   |  PA28  |INT[1]             | EXTINT[8 ] : GSM WAKE MCU                            |
 * |     19     |                   |  PB22  |INT[2]             | EXTINT[6 ] : LCD INT                                 |
 * |     20     |                   |  PB23  |INT[3]             | EXTINT[7 ] : SW INT                                  |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |            |     SERCOM        |        |                   |                                                      |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |     21     |  Serial0 / GSM    |  PA 4  |GSM[0]             | SERCOM[0]PAD[0] : TX /GSM[0]                         |
 * |     22     |                   |  PA 5  |GSM[1]             | SERCOM[0]PAD[1] : RX /GSM[1]                         |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |     23     |  Serial4 / WIFI   |  PB10  |WIFI[0]            | SERCOM[4]PAD[2] : TX /WIFI[0]                        |
 * |     24     |                   |  PB11  |WIFI[1]            | SERCOM[4]PAD[3] : RX /WIFI[1]                        |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |     25     |  Serial5 / RS485  |  PA22  |RS485[0]           | SERCOM[5]PAD[0] : TX /RS485[0]                       |
 * |     26     |                   |  PA23  |RS485[1]           | SERCOM[5]PAD[1] : RX /RS485[1]                       |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |     27     |        SPI        |  PA16  |MOSI               | SERCOM[1]PAD[0] : MOSI                               |
 * |     28     |                   |  PA17  |SCK                | SERCOM[1]PAD[1] : SCK                                |
 * |     29     |                   |  PA19  |MISO               | SERCOM[1]PAD[3] : MISO                               |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |     30     |    WIRE / I2C     |  PA12  |SDA                | SERCOM[2]PAD[0] : SDA                                |
 * |     31     |                   |  PA13  |SCL                | SERCOM[2]PAD[0] : SCL                                |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |            | **DO NOT CHANGE** |        |                   |                                                      |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |     32     |        USB        |  PA24  |USB/DM             |                                                      |
 * |     33     |                   |  PA25  |USB/DP             |                                                      |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|                                                                 
 * |     34     | Serial Wire Debug |  PA30  |SWCLK              |                                                      |
 * |     35     |                   |  PA31  |SWDIO              |                                                      |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 * |     36     | 32.768KHz Crystal |  PA00  |XIN32              |                                                      |
 * |     37     |                   |  PA01  |XOUT32             |                                                      |
 * +------------+-------------------+--------+-------------------+------------------------------------------------------|
 */


#include "variant.h"
/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[]=
{
  //Analog Current Mode PIN
  { PORTA,  2, PIO_ANALOG ,(PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG)                                 , ADC_Channel0  , NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2   }, 	// D[0]/A[0]/PTC_Y[0]
  { PORTA,  3, PIO_ANALOG ,(PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG)                                 , ADC_Channel1  , NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3   }, 	// D[1]/A[1]/PTC_Y[1]
  { PORTA,  6, PIO_ANALOG ,(PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG)                                 , ADC_Channel6  , NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, 	// D[2]/A[2]/PTC_Y[4]
  { PORTA,  7, PIO_ANALOG ,(PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG)                                 , ADC_Channel7  , NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, 	// D[3]/A[3]/PTC_Y[5]
  { PORTB,  2, PIO_ANALOG ,(PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG)                                 , ADC_Channel10 , NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2   }, 	// D[4]/A[4]/PTC_Y[8]

  //Analog Voltage Mode PIN
  { PORTB,  8, PIO_ANALOG      ,(PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel2  , PWM4_CH0  , TC4_CH0     , EXTERNAL_INT_NONE}, 	// D[5]/A[5]/PTC_Y[14]
  { PORTB,  9, PIO_ANALOG      ,(PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel3  , PWM4_CH1  , TC4_CH1     , EXTERNAL_INT_9   }, 	// D[6]/A[6]/PTC_Y[15]
  { PORTA,  8, PIO_ANALOG      ,(PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel16 , PWM0_CH0  , TCC0_CH0    , EXTERNAL_INT_NMI }, 	// D[7]/A[7]/PTC_X[0]
  { PORTA,  9, PIO_ANALOG      ,(PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG|PIN_ATTR_PWM|PIN_ATTR_TIMER), ADC_Channel17 , PWM0_CH1  , TCC0_CH1    , EXTERNAL_INT_9   }, 	// D[8]/A[8]/PTC_X[1]
  { PORTA, 10, PIO_ANALOG      ,(PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG)                            , ADC_Channel18 , NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_10  }, 	// D[9]/A[9]/PTC_X[2]
  
  //Digital IO pin
  { PORTA, 11, PIO_DIGITAL     ,(PIN_ATTR_DIGITAL)                                            , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_11  }, 	// D[10]/PCT_X[3]
  { PORTA, 18, PIO_DIGITAL     ,(PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER)                , No_ADC_Channel, PWM3_CH0  , TC3_CH0     , EXTERNAL_INT_2   },   // D[11]/PCT_X[6]
  { PORTA, 20, PIO_DIGITAL     ,(PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER_ALT)            , No_ADC_Channel, PWM0_CH6  , TCC0_CH6    , EXTERNAL_INT_4   },   // D[12]/PCT_X[8]
  { PORTA, 15, PIO_DIGITAL     ,(PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER)                , No_ADC_Channel, PWM3_CH1  , TC3_CH1     , EXTERNAL_INT_NONE}, 	// D[13]/PCT_X[14]
  
  //Digital fixed function
  /*INPUT ONLY*/
  { PORTB,  3, PIO_INPUT_PULLUP,(PIN_ATTR_DIGITAL)                                            , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, 	//GLCD[2] : BUSY CHECK
  /*OUTPUT ONLY*/                                                                             
  { PORTA, 14, PIO_OUTPUT      ,(PIN_ATTR_DIGITAL)                                            , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},	//USB[0]  : HOST ID
  { PORTA, 21, PIO_OUTPUT      ,(PIN_ATTR_DIGITAL)                                            , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, 	//RS485[2]: Read(low)/Write(high)
  /*INTTERRUPT*/	
  { PORTA, 27, PIO_INPUT_PULLUP,(PIN_ATTR_EXTINT)                                             , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15  }, 	// INT[0] Ethernet INT
  { PORTA, 28, PIO_INPUT_PULLUP,(PIN_ATTR_EXTINT)                                             , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_8   }, 	// INT[1] GSM WAKE MCU
  { PORTB, 22, PIO_INPUT       ,(PIN_ATTR_EXTINT)                                             , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_6   }, 	// INT[2] LCD INT
  { PORTB, 23, PIO_INPUT       ,(PIN_ATTR_EXTINT)                                             , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_7   }, 	// INT[3] SW INT
   
  //Serial0
  { PORTA,  4, PIO_SERCOM_ALT  ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, 	// SERCOM[0]PAD[0] : TX /GSM[0]
  { PORTA,  5, PIO_SERCOM_ALT  ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE}, 	// SERCOM[0]PAD[1] : RX /GSM[1]
  
  //Serial4
  { PORTB, 10, PIO_SERCOM_ALT  ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},   // SERCOM[4]PAD[2] : TX /WIFI[0]
  { PORTB, 11, PIO_SERCOM_ALT  ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE},   // SERCOM[4]PAD[3] : RX /WIFI[1]

  //Serial5
  { PORTA, 22, PIO_SERCOM_ALT  ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, 	// SERCOM[5]PAD[0] : TX /RS485[0]
  { PORTA, 23, PIO_SERCOM_ALT  ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, 	// SERCOM[5]PAD[1] : RX /RS485[1]

  //SPI  
  { PORTA, 16, PIO_SERCOM      ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, 	// SERCOM[1]PAD[0] : MOSI 
  { PORTA, 17, PIO_SERCOM      ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, 	// SERCOM[1]PAD[1] : SCK  
  { PORTA, 19, PIO_SERCOM      ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, 	// SERCOM[1]PAD[3] : MISO 
  
  //I2C
  { PORTA, 12, PIO_SERCOM      ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SERCOM[2]PAD[0] : SDA 
  { PORTA, 13, PIO_SERCOM      ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SERCOM[2]PAD[0] : SCL 
  
  //USB
  { PORTA, 24, PIO_COM         ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
  { PORTA, 25, PIO_COM         ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP
  
  //SWI                                                                                       
  { PORTA, 30, PIO_COM         ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SWCLK
  { PORTA, 31, PIO_COM         ,(PIN_ATTR_NONE)                                               , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }  // SWDIO

};

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial0( &sercom0, PIN_SERIAL0_RX, PIN_SERIAL0_TX , PAD_SERIAL0_RX, PAD_SERIAL0_TX);
Uart Serial4( &sercom4, PIN_SERIAL4_RX, PIN_SERIAL4_TX , PAD_SERIAL4_RX, PAD_SERIAL4_TX);
Uart Serial5( &sercom5, PIN_SERIAL5_RX, PIN_SERIAL5_TX , PAD_SERIAL5_RX, PAD_SERIAL5_TX);


void SERCOM0_Handler()
{
  Serial0.IrqHandler();
}
void SERCOM4_Handler()
{
  Serial4.IrqHandler();
}
void SERCOM5_Handler()
{
  Serial5.IrqHandler();
}


