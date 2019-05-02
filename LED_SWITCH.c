/*
 * LED_SWITCH.c
 *

 */
#include<avr/io.h>
#include<stdint.h>
#include <util/delay.h>
#define F_CPU 16000000
int main(void)
{

	 int i;
	 int j=0;

	 DDRA = 0xFF;



	while (1)
	{



		DDRC = DDRC & ~(1<<5) ; // Make pin 5 of port C as a input
		PORTC = PORTC | (1<<5);


		for(i=j;i<8;i++)
		{


			PORTA = (PORTA & 0) | ~( 1 << i ) ;

			_delay_ms(250);

			 if(( PINC & (1<<5))==0 )
			 {
				 	break;
			 }

		}

		 for(j=i;j>=0;j--)
		 {

			PORTA = (PORTA & 0) | ~( 1 << j ) ;

			_delay_ms(250);



			 if(( PINC & (1<<5))==0 ) //if PIN5 of port C is high
			 {
					break;
			 }

		 }

	}
	return 0;
}

