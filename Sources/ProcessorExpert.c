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
#include "out_I2C.h"
#include "AD1.h"
#include "AdcLdd1.h"
#include "IO1.h"
#include "WAIT1.h"
#include "LEDgreen.h"
#include "LEDpin1.h"
#include "BitIoLdd1.h"
#include "LEDred.h"
#include "LEDpin2.h"
#include "BitIoLdd2.h"
#include "out_I2C.h"
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
#include "LTC2945.h"
#include "adc_data.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
extern AS5040data as5040data;
extern MMA845X mma845x;
extern LTC2945 ltc2945;


LDD_TDeviceData *MyI2CPtr;
LDD_TDeviceData *MyTimerPtr;
LDD_TDeviceData *Myout_I2CPtr;



static uint16_t ADC_value[AD1_CHANNEL_COUNT];
volatile bool ADC_koniec;
float Voltage;
float Current;
float Power;

int volt;
int powe;
int curr;

int main(void)
{

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization. 
	 *                    ***/
	LEDred_Off();
	LEDgreen_Off();
	// Inicjacja I2C
	MyI2CPtr = I2C2_Init(NULL); //mma88453
	Myout_I2CPtr = out_I2C_Init(NULL); //LTC2945
	// Inicjacja Timera (for I2C)
	MyTimerPtr = TU1_Init(NULL);


	// Inicjacja Akcelerometru MMA855X
	MMA845X_Init();
	//LTC2945_Init();
	AS5040_Init();
	(void)AD1_Measure(TRUE);
	

	for(;;)
	{

		AS5040_data_parser();
		MMA845X_Poll();
		//LTC2945_Poll();
//		if (ADC_koniec){
//		(void)AD1_GetValue16(&ADC_value[0]);
//		ADC_koniec=FALSE;
//		(void)AD1_Measure(TRUE);
//		}
		
		
//		Voltage=vlotage_scaling(ADC_value[1]);
//		Current=copm_current(vlotage_scaling(ADC_value[0]),Voltage);
//		Power=copm_current(Current,Voltage);
//		
//		volt=Voltage*1000;
//		curr=Current*1000;
//		powe=Power*1000;
		

		if(as5040data.Erorr){
			LEDgreen_Off();
			LEDred_On();
			printf("%d,%d \n", 0xffff,mma845x.y);
			printf("\n");
		}
		else{
			LEDgreen_On();
			LEDred_Off();
			printf("%d,%d \n", as5040data.ang_position,mma845x.y);
			printf("\n");
		}


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
