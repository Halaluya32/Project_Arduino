#include <PCF8574.h>

PCF8574 IO0,IO1;
uint8_t i=0;

void INT1_ISR(void)
{
  if(IO1.bit_in(0)==0)i=0; 
}

void setup() {
  // put your setup code here, to run once:
  IO0.init(0,false);
  IO1.init(1,false);
  pinMode(D1,INPUT);
  attachInterrupt(D1, INT1_ISR , FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  IO0.port_out(i++);delay(100); 
}
