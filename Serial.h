/*
 * Serial.h
 *
 * Created: 12/29/2018 1:27:14 PM
 *  Author: Ade
 */ 


#ifndef SERIAL_H_
#define SERIAL_H_
#define CALCUBRR 115199

#include <avr/io.h>
#define _BV(n) (1<<n)


void USART_Init(void){
	UBRR0H = (CALCUBRR >> 8);
	UBRR0L = CALCUBRR;

	UCSR0B |= _BV(RXCIE0);
	UCSR0B |= _BV(RXEN0) | _BV(TXEN0);
	UCSR0C |= _BV(UCSZ01) | _BV(UCSZ00);

	sei();
}

void USART_transmit(unsigned char data){
	while(!(UCSR0A & _BV(UDRE0)))
	;
	UDR0 = data;
}

unsigned int USART_receive(){
	while(!(UCSR0A & _BV(RXC0)))
	;
	return UDR0;
}

//void USART_putstring(char *str){
//	while(*str != 0x00){
//		USART_transmit(*str);
//		str++;
//	}
//}

int leds_shift[7] = {3, 4, 5, 6, 7, 0, 1};
ISR(USART_RX_vect){
	
	unsigned int recievedInt = USART_receive();
	int i = 0;
	for (i = 0; i < recievedInt; i++){
		if (leds_shift[i] == 0 || leds_shift[i] == 1)
		PORTB |= _BV(leds_shift[i]);
		else
		PORTD |= _BV(leds_shift[i]);
	}
}

void Serial_fct(void){
	DDRD |= _BV(3) | _BV(4) | _BV(5) | _BV(6) | _BV(7);
	DDRB |= _BV(0) | _BV(1);
	USART_Init();
}

#endif /* SERIAL_H_ */