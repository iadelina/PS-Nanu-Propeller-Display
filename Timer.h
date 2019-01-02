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
	TCCR1B |= (1 << CS12) | (1 << CS10);
	TCCR1B |= (1<<WGM12);
	TIMSK1 |= (1 << OCIE1A);
	OCR1A = 14999;
	sei();
}

ISR(TIMER1_COMPA_vect){
	//PORTD ^= 0xFC;
	//PORTB ^= 0x1F;

	PORTD ^= _BV(3);
	PORTD ^= _BV(4);
	PORTD ^= _BV(5);
	PORTD ^= _BV(6);
	PORTD ^= _BV(7);
	PORTD ^= _BV(8);

	PORTB ^= _BV(1);
	PORTB ^= _BV(2);
	PORTB ^= _BV(3);
	PORTB ^= _BV(4);
	PORTB ^= _BV(5);
}

void Timer(){
	//DDRD=0xFC;//B11111100;	             
	//DDRB=0x1F;//B11111;     
	
	DDRD |= _BV(3);
	DDRD |= _BV(4);
	DDRD |= _BV(5);
	DDRD |= _BV(6);
	DDRD |= _BV(7);
	DDRD |= _BV(8);

	DDRB |= _BV(1);
	DDRB |= _BV(2);
	DDRB |= _BV(3);
	DDRB |= _BV(4);
	DDRB |= _BV(5);
	
	TimerSetup();
}


#endif /* TIMER_H_ */