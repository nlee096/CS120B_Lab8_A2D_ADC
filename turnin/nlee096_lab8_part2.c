/*	Author: Nathan Lee
 *  Partner(s) Name: none
 *	Lab Section: 022
 *	Assignment: Lab #8  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *  Demo Link: https://drive.google.com/drive/folders/1ZmkvXxbiqK73Ga4go4d5qrm4s6rgtGir?usp=sharing
 *
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short adc = 0x00;
unsigned char tmpB = 0x00;
unsigned char tmpD = 0x00;

void ADC_init(){
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
    adc = 0x00;
    tmpB = 0x00;
    tmpD = 0x00;
    ADC_init();
    while (1) {
        adc = ADC;
        tmpB = (char)adc;
        tmpD = (char)(adc >> 8);
        PORTB = tmpB;
        PORTD = tmpD;
    }
    return 1;
}
