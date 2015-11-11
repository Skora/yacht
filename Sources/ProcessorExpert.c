/** ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : IAR ARM C Compiler
**     Date/Time   : 2012-08-27, 15:21, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "I2C2.h"
#include "IO1.h"
#include "WAIT1.h"
#include "LED1.h"
#include "LEDpin1.h"
#include "BitIoLdd1.h"
#include "TU1.h"
#include "CsIO1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "stdio.h"
#include "AS5040.h"
#include "mma8453.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
extern AS5040data as5040data;
extern MMA845X mma845x;


LDD_TDeviceData *MyI2CPtr;
LDD_TDeviceData *MyTimerPtr;


int main(void)
{

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  // Inicjacja I2C
  MyI2CPtr = I2C2_Init(NULL);
 
  // Inicjacja Timera
  MyTimerPtr = TU1_Init(NULL);

  
    // Inicjacja Akcelerometru MMA855X
  MMA845X_Init();
  AS5040_Init();
  
  for(;;)
  {
//	  i++;
//	 WAIT1_WaitOSms(1);
//	 if(i%25==0)
//	 LED1_Neg();
	 AS5040_data_parser();
	 MMA845X_Poll();



	printf("tilt =  %d  ang_pos =  %d", mma845x.y, as5040data.ang_position);
	printf("\n");

  }
  
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
