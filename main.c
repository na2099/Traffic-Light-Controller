//Nabeel Azard, 101152007

#include <stdio.h>
#include <stdint.h>
#include "msp.h"
#define GREEN 0
#define YELLOW 1
#define  RED 2

int traffic_light = GREEN;
void TA0_N_IRQHandler(void) {

	static int ticks = 0;
	ticks++;

	//clear interrupt flag
	TA0CTL &= (uint16_t)(~(1<<0));

	if ((ticks == 5) && (traffic_light == GREEN)){
		ticks = 0;
		traffic_light = YELLOW;
	}
	if ((ticks == 1) && (traffic_light == YELLOW)){
		ticks = 0;
		traffic_light = RED;
	}
	if ((ticks == 3) && (traffic_light == RED)){
		ticks = 0;
		traffic_light = GREEN;
	}
}

int main(void) {
    // insert code here...
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; // Watchdog timer disabled.   
	P2SEL0 &= (uint8_t) (~((1<<2) | (1<<1) | (1<<0)));
	P2SEL1 &= (uint8_t) (~((1<<2) | (1<<1) | (1<<0)));
	P2DIR |= (uint8_t) (((1<<2) | (1<<1) | (1<<0)));
	P2OUT &= ~(uint8_t) (((1<<2) | (1<<1) | (1<<0)));
  
    

	// Timer config
  TA0CTL &= (uint16_t)(~((1<<5) | (1<<4))); //stop timer
	TA0CTL |= (uint16_t) ((1<<2)); // reset the timer
	//TA0CTL &= (uint16_t)(~((1<<8) | (1<<9))); // choosing clk source
	TA0CTL |= (uint16_t)((1<<8)); // choosing clk source
  TA0CTL &= (uint16_t)(~(1<<0)); //clear interrupt flag
  TA0CCR0 = (uint16_t)(32767); //Assuming clock is at default frequecy 3Mhz, is configured 1s
  TA0CTL |= (uint16_t)((1<<1)); //interrupt enable
  TA0CTL |= (uint16_t)((1<<4)); //up mode (count to CCR0)
    
  //configuration NVIC TIMER

  NVIC_SetPriority(TA0_N_IRQn, 2);
  NVIC_ClearPendingIRQ(TA0_N_IRQn);
  NVIC_EnableIRQ(TA0_N_IRQn);
    
  //Globally enable interrupts in CPU
  __ASM("CPSIE I");
    
	
	
	while(1){
		if (traffic_light == GREEN){
			P2OUT &= (uint8_t)(~((1<<0)|(1<<1)|(1<<2))); // clear the color
			P2OUT |= (uint8_t)((1<<1)); // change to green
		}
		else if (traffic_light == YELLOW){
			P2OUT &= (uint8_t)(~((1<<0)|(1<<1)|(1<<2))); // clear the color
			P2OUT |= (uint8_t)((1<<0)|(1<<1)); // change yellow
		}

		else if (traffic_light == RED){
			P2OUT &= (uint8_t)(~((1<<0)|(1<<1)|(1<<2))); // clear the color
			P2OUT |= (uint8_t)((1<<0)); // change red
		}

		else{
			continue;
		}
	
	}
    return 0;
}


		
