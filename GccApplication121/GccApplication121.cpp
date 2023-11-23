#include <avr/io.h>
#include <avr/interrupt.h>
int sin[35]={0,51,100,145,184,216,239,252,254,252,239,216,184,145,100,51,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int i;

ISR(TIMER1_COMPA_vect)

{
	OCR2=sin[i];
	i++;
	if (i>16)
	{
		TCCR2=0x49;
		PORTB=(1<<PINB0);
	}
	if (i<16)
	{
		TCCR2=0x69;
		PORTB=PORTB&0x00;
	}
	if (i>32) i=0;
}

int main(void)
{
	PORTD=0x00;
	DDRD=0x80;
	PORTB=0x00;
	DDRB=0x01;
	TCCR1A=0x00;
	TCCR1B=0x09;
	TCNT1=0x00;
	ICR1=0x00;
	OCR1AH=0x13;
	OCR1AL=0xD9;
	OCR1BH=0x00;
	OCR1BL=0x00;

	ASSR=0x00;
	TCCR2=0x69;
	TCNT2=0x00;
	OCR2=0x00;

	TIMSK=0x10;
	sei();
	while(1) 
	{
	}
}