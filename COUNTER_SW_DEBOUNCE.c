/*
 * COUNTER_SW_DEBOUNCE.c
 *
	Simple Algorithm (C Embedded, AVR, Atmega32) which shows incrementation on EVB's Kit LED Display while 
	the switch button is pressed + DEBOUNCE. 
 * 
 */
#include<avr/io.h>
#include<stdint.h>

#include <util/delay.h>
#define F_CPU 16000000

#define ZERO 0x3f
#define ONE 0x06
#define TWO 0x5b
#define THREE 0x4f
#define FOUR 0x66
#define FIVE 0x6d
#define SIX 0x7d
#define SEVEN 0x07
#define EIGHT 0x7f
#define NINE 0x6f


#define SWITCHED (PINC & (1<<4))
#define DEBOUNCE_PER 30
#define TRUE 1
#define FALSE 0

uint8_t RELEASED=TRUE;
uint8_t PRESSED =FALSE;

int state=0;


void IO_init(void)
{
	 DDRB =0xFF; //segments => OUTPUT

	 DDRD=0x04; //last two digits => OUTPUT

	 DDRC = DDRC & ~(1<<4) ; // INPUT (0) => ACTIVATE PULL-UP
	 PORTC = PORTC | (1<<4); // OUTPUT


}

int Debounce_Function(void)
{
	static uint8_t debounce_cnt;
	if((SWITCHED==0) &&(RELEASED==TRUE))
	{
		debounce_cnt++;
		if(debounce_cnt >DEBOUNCE_PER)
		{

				RELEASED = FALSE;
				PRESSED = TRUE;
				state=1;

		}

	}
	else
	{
		if((SWITCHED ==(1<<4)) && (PRESSED==FALSE))

		RELEASED =TRUE;
		PRESSED= FALSE;
		debounce_cnt=0;
		state=0;

	}

	return state;

}

int main(void)
{




	 int digit[10]={ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT,NINE};
	 int counter=0;
	 int counter_new=1;

	 IO_init();

	 PORTB= ~(digit[0]);

	while (1)
	{

		PORTB= ~(digit[counter]);
			if(Debounce_Function()==1)
			{
				counter++;
			}

	}

	return 0;
}
