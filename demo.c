/* -*- mode: c -*- */
/* This program is a demo that is supposed to be used with the arduino
   uno r3 microcontroller board.  It switches the output of pin 13
   every second. */

#include <avr/io.h>
#include <stdint.h>

// include delay procedure
#define F_CPU 16000000UL
#include <util/delay.h>

void delaySeconds(int8_t s);
void digitalWrite13(int state);
void initPort13Output(void);

#define HIGH 1
#define LOW 0
 
int main (void)
{
  /* set PORTB for output*/
  initPort13Output();
 
  while (1)
    {
      /* set PORTB.2 high */
      digitalWrite13(HIGH);
 
      /* Wait for 1 second */
      delaySeconds(1);
 
      /* set PORTB.2 low */
      digitalWrite13(LOW);
 
      /* Wait for 1 second*/
      delaySeconds(1);
    }
 
  return 1;
}

void delaySeconds(int8_t s)
/* Pause command execution for s seconds.

   The pause strongly depends on the processor clock.  You have to
   define 'F_CPU' to make this procedure to work correctly, example:
  
   #define F_CPU 16000000UL // 16 Mhz

   :not-portable:
*/
{
  int8_t i = 0;
  for (i = 0; i< s; i++){
    _delay_ms(1000);
  }
}

void digitalWrite13(int state)
/* Write HIGH or LOW to pin 13 of the arduino uno r3 microcontroller
   board. 

   :not-portable:
*/
{
  if (state == HIGHT) {
    PORTB |= _BV(PORTB5);
  } else if (state == LOW) {
    PORTB &= ~_BV(PORTB5);
  };
}

void initPort13Output(void)
/* initialize port 13 of the arduino uno r3 micro controller board
   as a digital output 
   
   :not-portable:
*/
{
  DDRB |= _BV(DDB5);
}
