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
#include "ProcessorExpert.h"
#include "AS5040.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
volatile bool DataReceivedFlg = FALSE;
volatile bool DataTransmittedFlg = FALSE;

uint8_t OutData[2] = {0x2A, 0x01};                // Inicjacja buforu wyjciowego 
uint8_t InData[MMA845X_BUFFER_SIZE];
LDD_TError Error;

LDD_TDeviceData *MyI2CPtr;
LDD_TDeviceData *MyTimerPtr;

MMA845X mma845x;
int16_t mma845_tmp;
extern AS5040data as5040data;

volatile bool DataTransmittedFlg;
volatile bool DataReceivedFlg;

static MMA845_STATE measuring = IDLE;
static MMA845_STATE measuring_last = RECEIVE;

uint16_t data;

/**************************************************************************//*!
* Funkcja obs³uga przerwania Timera
******************************************************************************/
void Timer_Interrupt_CB(void)
{
  if(measuring == IDLE)
  {
    if(measuring_last == TRANSMIT)
      measuring = RECEIVE; 
    else if(measuring_last == RECEIVE)
      measuring = TRANSMIT;
  }
}

/*****************************************************************************
* Inicjacja I2C dla  MMA845x
******************************************************************************/
void MMA845X_Init(void)
{
  /* Configure I2C BUS device(e.g. RTC) - Write Operation */
  Error = I2C2_MasterSendBlock(MyI2CPtr, &OutData, 2, LDD_I2C_NO_SEND_STOP); /* Send OutData (4 bytes) on the I2C bus and generates a stop condition to end transmission */
  while (!DataTransmittedFlg); 
  DataTransmittedFlg = FALSE;
  
  OutData[0] = MMA845X_DEVICE_ID; 

  Error = I2C2_MasterSendBlock(MyI2CPtr, &OutData, 1, LDD_I2C_NO_SEND_STOP);
  while (!DataTransmittedFlg);  
  DataTransmittedFlg = FALSE;
  
  Error = I2C2_MasterReceiveBlock(MyI2CPtr, &mma845x.id, 1, LDD_I2C_SEND_STOP);
  while (!DataReceivedFlg);
  DataReceivedFlg = FALSE;
}

/**************************************************************************//*!
*   MMA845x polling
******************************************************************************/
void MMA845X_Poll(void)
{
    if(measuring == TRANSMIT)
    {
      measuring = IDLE;
      measuring_last = TRANSMIT;
       
      OutData[0] = MMA845X_CFG_VALUE;
      Error = I2C2_MasterSendBlock(MyI2CPtr, &OutData, 1, LDD_I2C_NO_SEND_STOP); /* Send OutData (4 bytes) on the I2C bus and generates a stop condition to end transmission */
      while (!DataTransmittedFlg); 
      DataTransmittedFlg = FALSE;   
    }
    else if(measuring == RECEIVE)
    {
      measuring = IDLE;
      measuring_last = RECEIVE;
      Error = I2C2_MasterReceiveBlock(MyI2CPtr, &InData, MMA845X_BUFFER_SIZE, LDD_I2C_SEND_STOP);
      while (!DataReceivedFlg);
      DataReceivedFlg = FALSE;  

      mma845_tmp = InData[1] | (InData[0] << 8);
      mma845x.x = (mma845_tmp / MMA845X_DIVIDER);

      mma845_tmp = InData[3] | (InData[2] << 8);
      mma845x.y = (mma845_tmp / MMA845X_DIVIDER);

      mma845_tmp = InData[5] | (InData[4] << 8);     
      mma845x.z = (mma845_tmp / MMA845X_DIVIDER);   

      //printf("%d", mma845x.y);
      //printf("\n");
    }
}



int main(void)

{
	int i,data;
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
//    data=AS5040_Data_read();

//    printf("data =  %x", data);
//    printf("\n");
//    printf("ocf =  %d", as5040data.ocf);
//    printf("\n");
//    printf("cof =  %d", as5040data.cof);
//    printf("\n");
//    printf("lin =  %d", as5040data.lin);
//    printf("\n");
//    printf("MAGdec =  %d", as5040data.MAG_dec);
//    printf("\n");
//    printf("MAGinc =  %d", as5040data.MAG_inc);
//    printf("\n");
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
