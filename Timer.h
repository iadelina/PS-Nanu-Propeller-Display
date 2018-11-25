/*
 * Timer.h
 *
 * Created: 11/25/2018 6:39:03 PM
 *  Author: Ade
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>

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
	PORTD ^= 0xFC;
	PORTB ^= 0x1F;
}

void Timer(){
	DDRD=0xFC;//B11111100;
	DDRB=0x1F;//B11111;
	TimerSetup();
}




#endif /* TIMER_H_ */