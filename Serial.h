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

	UCSR0A &= ~_BV(U2X0);
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

unsigned char USART_receive(){
	while(!(UCSR0A & _BV(UDRE0)))
	;
	return UDR0;
}

void USART_putstring(char *str){
	while(*str != 0x00){
		USART_transmit(*str);
		str++;
	}
}

ISR(USART_RX_vect){
	//PORTD ^= 0xFC;
	//PORTB ^= 0x1F;

	//unsigned char recievedChar = USART_receive();
	 //if (recievedChar == 'H') {
		 PORTD |= _BV(128);
		 USART_putstring("LED ENABLED\n");
	// }
	 //else if (recievedChar == 'L'){	
	//	PORTB ^= _BV(128);
	//	USART_putstring("LED DISABLED\n");			
	//}
}

void Serial_fct(void){
	DDRD = _BV(128); // 0x80;
	USART_Init();
}

#endif /* SERIAL_H_ */