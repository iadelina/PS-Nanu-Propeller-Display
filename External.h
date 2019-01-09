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

float time_for_one_rot = 0;
float time_for_one_degree = 0;
byte last_IN_st;
unsigned long counter_for_high_state, current_count;

void External_interrupt_Setup(void){
	EICRA |= _BV(ISC00) | _BV(ISC01);  //interrupt on rising edge
	EIMSK |= _BV(INT0); //enable interrupt on INT0
	sei();
}

ISR(INT0_vect){
	//here goes the hall sensor detection
	current_count = micros();
	if(PIND & _BV(2)){
		if(last_IN_st == 0){
			last_IN_st = 1;
			counter_for_high_state = current_count;
		}
	}
	else{
		if(last_IN_st == 1){
			time_for_one_rot = current_count - counter_for_high_state;
			time_for_one_degree = time_for_one_rot/360.0;
		}
	}
}

void External(void){
	DDRD |= _BV(2);
	
	External_interrupt_Setup();
}


#endif /* EXTERNAL_H_ */