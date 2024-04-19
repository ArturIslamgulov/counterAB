#include <pinConfig.h>
#include <avr/io.h>



uint8_t read_gray_code_from_encoder(void ) 
{ 
 uint8_t val=0; 

  if(!bit_is_clear(PINB, SH1)) 
	val |= (1<<1); 

  if(!bit_is_clear(PINA, SH2)) 
	val |= (1<<0); 

  return val; 
}