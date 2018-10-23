
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

void setup() {
  DDRD=0xFC;//B11111100;
  DDRB=0x1F;//B11111;
  TimerSetup();
}
ISR(TIMER1_COMPA_vect){
  PORTD ^= 0xFC;   
  PORTB ^= 0x1F;  
}

void loop() { 
  
}
