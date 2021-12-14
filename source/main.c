
/*  Author: Nathan Lee
 *  Partner(s) Name: none
 *  Lab Section: 022
 *  Assignment: Lab #8  Exercise #4
 *  Exercise Description: [optional - include for your own benefit]
 *
 *  I acknowledge all content contained herein, excluding template or example
 *  code, is my own original work.
 *
 *  Demo Link: https://drive.google.com/drive/folders/1yaO9mZ5sHd7-OFao06M3UosnniTslnqU?usp=sharing
 *
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned short adc = 0x00;
unsigned char tmpB = 0xFF;
const unsigned short max = 0x39F;


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
    tmpB = 0xFF;
    //tmpD = 0x00;
    ADC_init();
    while (1) {
        adc = ADC;
        if(adc >= max){
            tmpB = 0xFF;
        }
        else if(adc >= ((7*max)/8)){
            tmpB = 0xFF >>1;
        }
        else if(adc >= ((6*max)/8)){
            tmpB = 0xFF >>2;
        }
        else if(adc >= ((5*max)/8)){
            tmpB = 0xFF >> 3;
        }
        else if(adc >= (max/2)){
            tmpB = 0x0F;
        }
        else if(adc >= ((3*max)/8)){
            tmpB = 0x0F >>1;
        }
        else if(adc >= ((2*max)/8)){
            tmpB = 0x0F >>2;
        }
        else if(adc >= ((1*max)/8)){
            tmpB = 0x0F >>3;
        }
        else{
            tmpB = 0x00;
        }
        //tmpB = (char)adc;
        //tmpD = (char)(adc >> 8);
        PORTB = tmpB;
        //PORTD = tmpD;
    }
    return 1;
}
