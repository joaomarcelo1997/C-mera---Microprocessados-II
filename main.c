#include <msp430.h>


// Functions
void adc_control();
#include "adc_confg.h"
#include "clock.h"
#include "pulso.h"


// Variables and arrays
int adc[24] = {0};
int media = 0;
int caractere[16]={0};
int soma = 0;
int x; // Counter number of pixels
int y; // Counter number of characteres

void main()
{   // Stop watchdog timer
	WDTCTL = WDTPW + WDTHOLD;

	// ADC settings
	adc_confg();

	// Set the pins referring to the clock signal to be sent to P1.4(Clk)
	clock ();



    while(1)
	{
    	// Value corresponds to amounts of characters showing on LCD: This case 16 characters
		for(y=0;y<=15;y++){

		// Pulse equivalent to SI (Start)

		pulso();
		 // Integrator reset period
		__delay_cycles(18);

		/**Function responsible for the start of the conversion of the values applied
		   to the Analog input. Stores the values converted into vector adc */
		adc_control();

		pulso();

		soma=0;
		     // Maximum limit equal to the number of pixels: This case 24 pixels
			for(x=0;x<=23;x++)
			{
			// Performs the sum of the converted pixels at the time
			  soma=soma+adc[x];
		    }

		      media=soma/24;

		     //  display();

		     // Shows corresponding values to each character
		      caractere[y]=media;

	  }
  }
}

void adc_control()
{
    ADC10CTL0 &= ~ENC;				// Conversion disabled
    while (ADC10CTL1 & BUSY);		// Wait if ADC10 busy
    ADC10SA = (int)adc;				// Transfers data to the array
    ADC10CTL0 |= ENC + ADC10SC;		// Enable Conversion and start

}
