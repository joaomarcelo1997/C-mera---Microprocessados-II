/*
 * adc_confg.C
 *
 *  Created on: 16 de ago de 2016
 *      Author: Juliana
 */

#include <msp430.h>

#define conversao 0x18


void adc_confg()
{
	ADC10CTL1 = CONSEQ_2 + INCH_0 + ADC10DIV_4;			// Repeat single channel, A0 , ADC10 clock divider:/5
	ADC10CTL0 = ADC10SHT_2 + MSC + ADC10ON;	            // Sample & Hold Time:16xADC10CLKs, multiple sample and conversion , ADC10 ON
	ADC10DTC1 = conversao;								// 24 conversions
	ADC10AE0 |= BIT1;									// P1.0 Analog input enabled
}
