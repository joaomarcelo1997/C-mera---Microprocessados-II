/*
 *  pulso.c
 *
 *  Created on: 16 de ago de 2016
 *      Author: Juliana
 */
#include <msp430.h>

/** This function produces a pulse 0n P1.2
     corresponding to SI */

void pulso(void)
 { P1DIR|= BIT2;
   P1OUT &= ~BIT2;
   __delay_cycles(1);
   P1OUT |= BIT2;
   __delay_cycles(1); //Signal period
   P1OUT &= ~BIT2;
   __delay_cycles(1);
 }


