/*
 * adc_control.c
 *
 *  Created on: 16 de ago de 2016
 *      Author: Juliana
 */
#include <msp430.h>

// Set the pins referring to the clock signal to be sent to P1.4(Clk)

void clock (void){
	P1SEL |= BIT4;  //SMCLK signal output
	P1DIR |= BIT4;
}


