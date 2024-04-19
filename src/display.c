#include <display.h>

 /*     
 *  Common cathode
 * 
 *      a
 *     +++
 *   +     + `  `
 * f +     + b  
 *   +  g  + 
 *     +++ 
 *   +     +
 * e +     + c
 *   +  d  +
 *     +++
 */   
void writeLED(uint8_t val, uint8_t digit){
    switch (val)
    {
        case 0:
            PORTA &= ~(1 << G);

            PORTA |= (1 << A) | (1 << B) | (1 << C) | (1 << D) | (1 << E) | (1 << F);
            break;
        case 1:
            PORTA &= ~(1 << A);
            PORTA &= ~(1 << D); 
            PORTA &= ~(1 << E); 
            PORTA &= ~(1 << F); 
            PORTA &= ~(1 << G);

            PORTA |= (1 << B) | (1 << C);
            break;
        case 2:
            PORTA &= ~(1 << C); 
            PORTA &= ~(1 << F);

            PORTA |= (1 << A) | (1 << B) | (1 << D) | (1 << E) | (1 << G);
            break;
        case 3:
            PORTA &= ~(1 << E);
            PORTA &= ~(1 << F);

            PORTA |= (1 << A) | (1 << B) | (1 << C) | (1 << D) | (1 << G);
            break;
        case 4:
            PORTA &= ~(1 << A); 
            PORTA &= ~(1 << D); 
            PORTA &= ~(1 << E);

            PORTA |= (1 << B) | (1 << C) | (1 << F) | (1 << G);
            break;
        case 5:
            PORTA &= ~(1 << B);
            PORTA &= ~(1 << E);
            
            PORTA |= (1 << A) | (1 << C) | (1 << D) | (1 << F) | (1 << G); 
            break;
        case 6:
            PORTA &= ~(1 << B);

            PORTA |= (1 << A) | (1 << C) | (1 << D) | (1 << E) | (1 << F) | (1 << G);
            break;
        case 7:
            PORTA &= ~(1 << D); 
            PORTA &= ~(1 << E); 
            PORTA &= ~(1 << F);
            PORTA &= ~(1 << G);

            PORTA |= (1 << A) | (1 << B) | (1 << C);
            break;
        case 8:
            PORTA |= (1 << A) | (1 << B) | (1 << C) | (1 << D) | (1 << E) | (1 << F) | (1 << G);
            break;
        case 9:
            PORTA &= ~(1 << E);
            PORTA |= (1 << A) | (1 << B) | (1 << C) | (1 << D) | (1 << F) | (1 << G);
            break;
    }
    switch (digit)
    {
        case 0:
            PORTB &= ~(1 << ENA_1); 
            PORTB &= ~(1 << ENA_2); 
            PORTB &= ~(1 << ENA_3); 

            PORTB |= (1 << ENA_4);
            break;
        case 1:
            PORTB &= ~(1 << ENA_1); 
            PORTB &= ~(1 << ENA_2); 
            PORTB &= ~(1 << ENA_4); 

            PORTB |= (1 << ENA_3);
            break;
        case 2:
            PORTB &= ~(1 << ENA_1);
            PORTB &= ~(1 << ENA_3);
            PORTB &= ~(1 << ENA_4);

            PORTB |= (1 << ENA_2);
            break;
        case 3:
            PORTB &= ~(1 << ENA_2);
            PORTB &= ~(1 << ENA_3);
            PORTB &= ~(1 << ENA_4);

            PORTB |= (1 << ENA_1);
            break;
    }
}