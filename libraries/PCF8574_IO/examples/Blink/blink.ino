#include <Arduino.h>
#include <Wire.h>
#include <PCF8574_IO.h>

void setup() {
	// put your setup code here, to run once:
	exp_init();
}


void loop() {
	// put your main code here, to run repeatedly:
	EXP_IO[0].pin_out(0,HIGH);
	delay(100);
	EXP_IO[0].pin_out(0,LOW);
	delay(100);
}