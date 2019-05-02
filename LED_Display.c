/*
 * LED_Display.c
 *
 Simple Algorithm (C Embedded, AVR, Atmega32) which shows decrementation on EVB's Kit LED Display when it counts upward
 and incrementation, when it counts reverse.
 I used the switch button -> PORT C
 For LED Display -> Port B for segments and Port D for digits. 
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

int main(void)
{


	 int digit[10]={ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
	 int i;
	 int j=0;

	 DDRB =0xFF;

	 DDRD=0x04;

	 DDRC = DDRC & ~(1<<4) ;
	 PORTC = PORTC | (1<<4);

	while (1)
	{

		if(j<0)
		{
			j=0;
		}

		for(i=j;i<10;i++)
		{
			PORTB= ~ (digit[i]) ;

			_delay_ms(500);

			if((PINC & (1<<4))==0)
			{
				break;
			}
		}

		if(i>9)
		{
			i=9;
		}

		for(j=i;j>=0;j--)
		{
			PORTB= ~ (digit[j]) ;

			_delay_ms(500);

			if((PINC & (1<<4))==0)
			{
				break ;
			}
		}


	}
	return 0;
}

