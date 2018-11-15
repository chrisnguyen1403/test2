/*
  Exercise 2: This exercise is to pulse the LED on digital pin 3 at a frequency of 1Hz (1s). 
  You will need to utilise Exercise 1 code and integrate a Timer module to control the pulse rate
  For this exercise you cannot use the Arduino standard library. 
  Code written by:
          Member 1 SID xxxxxxxx
          Member 2 SID xxxxxxxx
          Member 3 SID xxxxxxxx
  Version: x.xx 
  Date: xx/xx/xxxx
*/

#include <avr/io.h> /*Include the standard library required for programming the avr microprocessor*/

/* 
  This exercise is an addon to the Exercise 1 code, it would be a good idea to copy the exercise 1
  code into this exercise. Then you will need to refer to the data sheet for the Timer modules.
  You can choose between 8-bit Timer0 and Timer2, or the 16-bit Timer1. You will need to read the
  modes of operations for this scenario I would recommended normal mode.
  Then you will need to calculate the configuration values. 
*/
#define out 1
int counter = 0;
void setup() {
  
  DDRD |= out<<DDD3;
  DDRD |= out<<DDD2;
  DDRD |= out<<DDD4;
  TCCR0A=~(1<<WGM01)&~(1<<WGM00);
  TCCR0B|=(1<<CS02);
  TCCR0B&=~(1<<CS01);
  TCCR0B|=(1<<CS00);
  PORTD = 0;
  TCNT0 = 0;
  
  
      /*
      Use this equation to figure out how many clock ticks required for your period based
      your desired time: TimerCountsRequired=[ (clockI/Ospeed / Prescaler) * Desiredtime ] - 1
      Hint: The clockI/O speed is the same as the internal clock
      Hint: An 8-bit Timer has a maximum size of 255 ticks, a 16-bit Timer has a max size 65535
    */
    /*<-------- Here, set Timer control register A for Normal mode.*/
    /*<-------- Here, set control register B for the prescaler values.*/

}

void loop() {
  if ((TIFR0&(1<<TOV0)==1))
  {
    counter++;
    TIFR0&=~(1<<TOV0);
    
  PORTD ^= 1<<PORTD3;
  }
  if (counter==10)
  { 
    counter=0;
  }
}
    /*
      In this section you have to have a condition that check the amount of counter ticks
      that has passed. You can do this by checking the Counter Value Register which is an
      8 bit register reflecting the current counter value 
      Hint use if condition -> TCNTx>=TimerCountsRequired
      
      If using 8-bit timer consider using running through more than one counter cycle as the 
      
      If this condition you will need to toggle the LED pin at the end of the desired 
      period. Hint: To toggle a bit you can use ^=(1<<*insert register bit*)
      Don't forget to reset the counter value register.
    */
      



