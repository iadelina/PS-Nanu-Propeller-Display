/*
 * External.h
 *
 * Created: 1/2/2019 6:56:05 PM
 *  Author: Ade
 */ 


#ifndef EXTERNAL_H_
#define EXTERNAL_H_
#define _BV(n) (1<<n)

#include <avr/io.h>
#include <avr/interrupt.h>


void External_interrupt_Setup(void){
	EICRA |= _BV(ISC00) | _BV(ISC01);  //interrupt on rising edge
	EIMSK |= _BV(INT0); //enable interrupt on INT0
	sei();
}

ISR(INT0_vect){
	//here goes the hall sensor detection

}

void External(void){
	DDRD |= _BV(2);
	
	External_interrupt_Setup();
}


#endif /* EXTERNAL_H_ */