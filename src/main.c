#include <Arduino.h>
#include <pinConfig.h>
#include <avr/io.h>
#include <display.h>

// 0 - FALLING EDGE
// 1 - RISSING EDGE
#define RISSIN_FALLING_EDGE 0
#define AB 0

void initPins(){

  DDRB |= (1 << ENA_1) | (1 << ENA_2) | (1 << ENA_3) | (1 << ENA_4);
  DDRA |= (1 << A) | (1 << B) | (1 << C) | (1 << D) | (1 << E) | (1 << F) | (1 << G); 
  DDRB &= ~(1 << SH1);
  DDRA &= ~(1 << SH2);
}



int main(){
  init();
  initPins();
  int16_t i = 0;
  char numb [4] = {0, 0, 0,0};
  uint32_t timer = 0;
  uint8_t counter = 0;
  uint8_t digit = 0;
  int16_t oldi = 0;
  bool flag1 = false;
  bool flag2 = false;
  int16_t n = 1;
  

  uint8_t val = read_gray_code_from_encoder();

  while(1){
     
      


    //if(i <= 0){
      // for(int i = 0; i < 4; i++){
      //   numb[i] = 0;
      // }
      //n *= -1;
    //}
    #if(AB)
    uint8_t val_tmp = read_gray_code_from_encoder();

        if(val != val_tmp) 
        { 
          if((val==3 && val_tmp==1) || (val==0 && val_tmp==2) ) 
          { 
          i++; 
          } 
          else if((val==2 && val_tmp==0) || (val==1 && val_tmp==3)) 
          { 
          i--; 
          }
          val = val_tmp; 
        } 
    #else
      #if(RISSIN_FALLING_EDGE)
      if ((PINB & 0b01000000 ) && !flag1){
        i = i + n ;
        flag1 = true;
      }
      else if( !(PINB & 0b01000000) && flag1 ){
        flag1 = false;
      }
      if((PINA & 0b10000000 ) && !flag2){
        i = i - n ;
        flag2 = true;
      }
      else if( !(PINA & 0b10000000) && flag2 ){
        flag2 = false;
      }
    
    #else
      if (!(PINB & 0b01000000 ) && !flag1){
        i = i + n ;
        flag1 = true;
      }
      else if( PINB & 0b01000000 && flag1 ){
        flag1 = false;
      }
      if(!(PINA & 0b10000000 ) && !flag2){
        i = i - n ;
        flag2 = true;
      }
      else if( PINA & 0b10000000 && flag2 ){
        flag2 = false;
      }
    
    #endif
    #endif
    
    if(i != oldi){
      int16_t tmp = abs(i);
      if(tmp < 10){
        numb[1] = 0;
      }
      if(tmp < 100){
        numb[2] = 0;
      }
      while(tmp){
        numb[counter] = tmp % 10;
        tmp /= 10;
        counter++;
      }
      oldi = i;
      counter = 0;
    }
    if (millis() - timer >= 5) { 
      writeLED(numb[digit], digit);
      digit++;
      if(digit > 3){
        digit = 0;
      }
      timer = millis();
    }
  }
}

