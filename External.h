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

#include <avr/io.h>
#include <avr/interrupt.h>

float time_for_one_rot = 0;
float time_for_one_degree = 0;
byte last_IN_st;
unsigned long counter_for_high_state, current_count;
volatile uint16_t sequence = 1;
volatile uint8_t sequence_index = 0;

void External_interrupt_Setup(void){
	EICRA |= _BV(ISC00) | _BV(ISC01);  //interrupt on rising edge
	EIMSK |= _BV(INT0); //enable interrupt on INT0
	sei();
}

ISR(INT0_vect){
	sequence = TCNT1/72;
	TCNT1=0;
	OCR0A = sequence;
	sequence_index=0;
}

void External(void){
	DDRD &= ~_BV(2);
	PORTD |= _BV(2);

	External_interrupt_Setup();
}



#endif /* EXTERNAL_H_ */