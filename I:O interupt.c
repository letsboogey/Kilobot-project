#include <avr/io.h>
#include <avr/interrupt.h>

// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows
ISR(TIMER0_COMPA_vect)
{
    
    static int counterio=0;
    static int countersys=0;
    counterio++;
    
    if(counterio==4)
    {
        countersys++;
        counterio=0;
        //whatever code to run
    }
    
    if(countersys==1000){
        countersys=0;
        //whatever code to run
        
    }
}

int main(void)
{
    // set up timer with no prescaler
    TCCR0B |= (1 << CS00)&&(1<<WGM02);
    
    // initialize counter
    TCNT0 = 0;
    
    OCR0A=200;
    
    // enable compare timer interrupt
    TIMSK0 = (1 << OCIE0A);
    
    // enable global interrupts
    sei();
    
    for(;;){
        
    }
    
    
    
}