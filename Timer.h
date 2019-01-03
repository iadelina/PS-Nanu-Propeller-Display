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

ISR(TIMER1_COMPA_vect);

void TimerSetup(){
	cli();
	TCCR1A = 0;
	TCCR1B = 0;
	TCCR1B |= _BV(CS12) | _BV(CS10);
	TCCR1B |= _BV(WGM12);
	TIMSK1 |= _BV(OCIE1A);
	OCR1A = 14999;
	sei();
}

ISR(TIMER1_COMPA_vect){
	//PORTD ^= 0xFC;
	//PORTB ^= 0x1F;

	PORTD ^= _BV(2) ^ _BV(3) ^ _BV(4) ^ _BV(5) ^ _BV(6) ^ _BV(7);
	PORTB ^= _BV(0) ^ _BV(1) ^ _BV(2) ^ _BV(3) ^ _BV(4);
}

void Timer(){
	//DDRD=0xFC;//B11111100;	             
	//DDRB=0x1F;//B11111;     
	
	DDRD |= _BV(2) | _BV(3) | _BV(4) | _BV(5) | _BV(6) | _BV(7);
	DDRB |= _BV(0) | _BV(1) | _BV(2) | _BV(3) | _BV(4);
	
	TimerSetup();
}


#endif /* TIMER_H_ */