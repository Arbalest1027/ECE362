/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f0xx.h"
#include "stm32f0308_discovery.h"
			

int main(void)
{
	 // The Reset and Clock Control port has an Enable Register for the
	 // Advanced Hardware Bus
	 int *rcc_ahrenb = (int *)0x40021014;
	 // General Purpose I/O port C's Mode register
	 int *gpioc_moder = (int *)0x48000800;
	 // General Purpose I/O port C's Output Data Register
	 int *gpioc_odr = (int *)0x48000814;
	 register int i asm ("r6"); // Put the i variable in a register.
	 *rcc_ahrenb |= 0x00080000; // Enable the clock to the GPIOC
	 *gpioc_moder |= 0x00040000; // Configure PC9 (Green LED) as output
	 *gpioc_moder |= 0x00010000; // Configure PC8 (Blue LED) as output
	 for(;;) {
	 *gpioc_odr = 1<<8; // Turn on only PC8 (Blue LED)
	 for(i=0;i<1148000;i++) { ; } // Wait a sec.
	 *gpioc_odr = 1<<9; // Turn on only PC9 (Green LED)
	 for(i=1148000; i != 0; i--) { ; } // Wait a sec.
	 }
}
