/*
 * Timer.h
 *
 * Created: 11/25/2018 6:39:03 PM
 *  Author: Ade
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include "External.h"
#define _BV(n) (1<<n)

ISR(TIMER0_COMPA_vect);

void TimerSetup(){
	TCCR0A |= _BV(WGM01);
	//OCR0A = 0xFF;
	TCCR0B |= _BV(CS02) | _BV(CS00);
	TIMSK0 |= _BV(OCIE0A);

	sei();
}

ISR(TIMER0_COMPA_vect){
	// the index part and shit
	//PORTD ^= _BV(3) ^ _BV(4) ^ _BV(5) ^ _BV(6) ^ _BV(7);
	//PORTB ^= _BV(0) ^ _BV(1);
	
	switch(sequence_index){
		//P
		case 0:
		display_column(1, 1, 1, 1, 1, 1, 1);
		break;
		case 1:
		display_column(1, 0, 0, 1, 0, 0, 0);
		break;
		case 2:
		display_column(1, 0, 0, 1, 0, 0, 0);
		break;
		case 3:
		display_column(0, 1, 1, 0, 0, 0, 0);
		break;
		case 4:
		display_column(0, 0, 0, 0, 0, 0, 0);
		break;
		//S
		case 5:
		display_column(0, 1, 1, 0, 0, 0, 1);
		break;
		case 6:
		display_column(1, 0, 0, 1, 0, 0, 1);
		break;
		case 7:
		display_column(1, 0, 0, 1, 0, 0, 1);
		break;
		case 8:
		display_column(1, 0, 0, 1, 0, 0, 1);
		break;
		case 9:
		display_column(1, 0, 0, 0, 1, 1, 0);
		break;
		// 3 empty sequences
		case 10:
		display_column(0, 0, 0, 0, 0, 0, 0);
		break;
		case 11:
		display_column(0, 0, 0, 0, 0, 0, 0);
		break;
		case 12:
		display_column(0, 0, 0, 0, 0, 0, 0);
		break;
		//digit 2
		case 13:
		display_column(0, 1, 0, 0, 0, 1, 1);
		break;
		case 14:
		display_column(1, 0, 0, 0, 1, 0, 1);
		break;
		case 15:
		display_column(1, 0, 0, 0, 1, 0, 1);
		break;
		case 16:
		display_column(1, 0, 0, 1, 0, 0, 1);
		break;
		case 17:
		display_column(0, 1, 1, 0, 0, 0, 1);
		break;
		// 2 empty sequences
		case 18:
		display_column(0, 0, 0, 0, 0, 0, 0);
		break;
		case 19:
		display_column(0, 0, 0, 0, 0, 0, 0);
		break;
		//digit 0
		case 20:
		display_column(0, 1, 1, 1, 1, 1, 0);
		break;
		case 21:
		display_column(1, 0, 0, 0, 0, 0, 1);
		break;
		case 22:
		display_column(1, 0, 0, 0, 0, 0, 1);
		break;
		case 23:
		display_column(1, 0, 0, 0, 0, 0, 1);
		break;
		case 24:
		display_column(0, 1, 1, 1, 1, 1, 0);
		break;
		// 2 empty sequences
		case 25:
		display_column(0, 0, 0, 0, 0, 0, 0);
		break;
		case 26:
		display_column(0, 0, 0, 0, 0, 0, 0);
		break;
		// digit 1
		case 27:
		display_column(0, 0, 1, 0, 0, 0, 1);
		break;
		case 28:
		display_column(0, 1, 0, 0, 0, 0, 1);
		break;
		case 29:
		display_column(1, 1, 1, 1, 1, 1, 1);
		break;
		case 30:
		display_column(0, 0, 0, 0, 0, 0, 1);
		break;
		case 31:
		display_column(0, 0, 0, 0, 0, 0, 1);
		break;
		// 2 empty sequences
		case 32:
		display_column(0, 0, 0, 0, 0, 0, 0);
		break;
		case 33:
		display_column(0, 0, 0, 0, 0, 0, 0);
		break;
		// digit 9
		case 34:
		display_column(0, 1, 1, 0, 0, 0, 1);
		break;
		case 35:
		display_column(1, 0, 0, 1, 0, 0, 1);
		break;
		case 36:
		display_column(1, 0, 0, 1, 0, 0, 1);
		break;
		case 37:
		display_column(1, 0, 0, 1, 0, 0, 1);
		break;
		case 38:
		display_column(0, 1, 1, 1, 1, 1, 0);
		break;
	}
	sequence_index++;
	sequence_index = sequence_index % 72;
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

void Timer(){
	External();
	DDRD |= _BV(3) | _BV(4) | _BV(5) | _BV(6) | _BV(7);
	DDRB |= _BV(0) | _BV(1);
	
	TimerSetup();
}


#endif /* TIMER_H_ */