/*
 * Timer.h
 *
 * Created: 11/25/2018 6:39:03 PM
 *  Author: Ade
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
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
	
	PORTD ^= _BV(3) ^ _BV(4) ^ _BV(5) ^ _BV(6) ^ _BV(7);
	PORTB ^= _BV(0) ^ _BV(1);
}

void Timer(){
	  	
	DDRD |= _BV(3) | _BV(4) | _BV(5) | _BV(6) | _BV(7);
	DDRB |= _BV(0) | _BV(1);
	
	TimerSetup();
}


#endif /* TIMER_H_ */