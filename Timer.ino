
void TimerSetup(){
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TCCR1B |= (1<<WGM12);
  TIMSK1 |= (1 << OCIE1A);
  OCR1A = 7812;
  sei();
}

void setup() {
  DDRD=B11111100;
  DDRB=B11111;
  TimerSetup();
}
ISR(TIMER1_COMPA_vect){
  PORTD=B11111100;   
  PORTB=B11111;  
}

void loop() { 
  
}
