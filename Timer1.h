/*
 * Timer1.h
 *
 * Created: 1/19/2019 3:27:31 PM
 *  Author: Ade
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
#include <avr/io.h>
#define _BV(n) (1<<n)

ISR(TIMER1_COMPA_vect);

void Timer1Setup(){

	TCCR1B |= _BV(WGM12);
	OCR1A = 0xFFFF;		
	TCCR1B |= _BV(CS12) | _BV(CS10);
	TIMSK1 |= _BV(OCIE1A);
		
	sei();
}

ISR(TIMER1_COMPA_vect){
	
}

void Timer1(){
	
	Timer1Setup();
}





#endif /* TIMER1_H_ */