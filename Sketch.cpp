/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include "Timer.h"
#include "Serial.h"
#include "External.h"
#define _BV(n) (1<<n)

/*End of auto generated code by Atmel studio */

//Beginning of Auto generated function prototypes by Atmel Studio

//End of Auto generated function prototypes by Atmel Studio

void display_column(int led_1, int led_2, int led_3, int led_4, int led_5, int led_6, int led_7);


int main(void){
	 Timer();
	 //Serial_fct();
	 External();
	 while(1){
		
	 }
}

void display_column(int led_1, int led_2, int led_3, int led_4, int led_5, int led_6, int led_7){
	if (led_1 == 1){
		PORTD |= _BV(3);
	}
	else{
		PORTD &= ~_BV(3);
	}

	if (led_2 == 1){
		PORTD |= _BV(4);
	}
	else{
		PORTD &= ~_BV(4);
	}

	if (led_3 == 1){
		PORTD |= _BV(5);
	}
	else{
		PORTD &= ~_BV(5);
	}

	if (led_4 == 1){
		PORTD |= _BV(6);
	}
	else{
		PORTD &= ~_BV(6);
	}

	if (led_5 == 1){
		PORTD |= _BV(7);
	}
	else{
		PORTD &= ~_BV(7);
	}

	if (led_6 == 1){
		PORTB |= _BV(0);
	}
	else{
		PORTB &= ~_BV(0);
	}

	if (led_7 == 1){
		PORTB |= _BV(1);
	}
	else{
		PORTB &= ~_BV(1);
	}
}