/** ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : IAR ARM C Compiler
**     Date/Time   : 2012-09-19, 09:05, # CodeGen: 16
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         TU1_OnCounterRestart       - void TU1_OnCounterRestart(LDD_TUserData *UserDataPtr);
**         I2C2_OnMasterBlockSent     - void I2C2_OnMasterBlockSent(LDD_TUserData *UserDataPtr);
**         I2C2_OnMasterBlockReceived - void I2C2_OnMasterBlockReceived(LDD_TUserData *UserDataPtr);
**         I2C2_OnError               - void I2C2_OnError(LDD_TUserData *UserDataPtr);
**         Cpu_OnNMIINT               - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"


extern volatile bool DataTransmittedFlg;
extern volatile bool DataReceivedFlg;
extern volatile bool LTCDataReceivedFlg;
extern volatile bool LTCDataTransmittedFlg;
extern void Timer_Interrupt_CB(void);


void IO1_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnBlockSent (module Events)
**
**     Component   :  AS1 [Serial_LDD]
**     Description :
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void IO1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/* User includes (#include below this line is not maintained by Processor Expert) */

/*
** ===================================================================
**     Event       :  TU1_OnCounterRestart (module Events)
**
**     Component   :  TU1 [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void TU1_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
  Timer_Interrupt_CB();
}

/*
** ===================================================================
**     Event       :  I2C2_OnMasterBlockSent (module Events)
**
**     Component   :  I2C2 [I2C_LDD]
**     Description :
**         This event is called when I2C in master mode finishes the
**         transmission of the data successfully. This event is not
**         available for the SLAVE mode and if MasterSendBlock is
**         disabled. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2C2_OnMasterBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
  DataTransmittedFlg = TRUE;

}

/*
** ===================================================================
**     Event       :  I2C2_OnMasterBlockReceived (module Events)
**
**     Component   :  I2C2 [I2C_LDD]
**     Description :
**         This event is called when I2C is in master mode and finishes
**         the reception of the data successfully. This event is not
**         available for the SLAVE mode and if MasterReceiveBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2C2_OnMasterBlockReceived(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
  DataReceivedFlg = TRUE;
}

/*
** ===================================================================
**     Event       :  I2C2_OnError (module Events)
**
**     Component   :  I2C2 [I2C_LDD]
**     Description :
**         This event is called when an error (e.g. Arbitration lost)
**         occurs. The errors can be read with GetError method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2C2_OnError(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
**     Description :
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the <NMI
**         interrrupt> property is set to 'Enabled'.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Function    : uart_putchar
**
**     Description :
**         This function sends one character to the desired UART port.
**         It was written to patch a CodeWarrior bug with the printf
**         function.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ch              - Character to be sent to the UART
**         uart_port_num   - Specifies which UART to send the 
**         					 character to.   
**                           
**     Returns     : Nothing
** ===================================================================
*/
void uart_putchar (int uart_port_num, char ch)
{
	if (uart_port_num == 0)
	{
      /* Wait until space is available in the FIFO */
      while(!(UART0_S1 & UART_S1_TDRE_MASK));
    
      /* Send the character */
      UART0_D = (uint8)ch;
	}
	else if (uart_port_num == 1)
	{
	  /* Wait until space is available in the FIFO */
	  while(!(UART1_S1 & UART_S1_TDRE_MASK));
	   
	  /* Send the character */
	  UART1_D = (uint8)ch;
	}
	else
	{
	  /* Wait until space is available in the FIFO */
	  while(!(UART2_S1 & UART_S1_TDRE_MASK));
	  
	  /* Send the character */
	  UART2_D = (uint8)ch;
	}
 }

/*
** ===================================================================
**     Function    : uart_getchar
**
**     Description :
**         This function gets one character to the desired UART port.
**         It was written to patch a CodeWarrior bug with the getchar
**         function.
**     Parameters  :
**         NAME            - DESCRIPTION
**         uart_port_num   - Specifies which UART to get the 
**         					 character from.   
**                           
**     Returns     : character (UARTx_D)
** ===================================================================
*/
char uart_getchar (int uart_port_num)
{
	if (uart_port_num == 0)
	{
      /* Wait until space is available in the FIFO */
      while(!(UART0_S1 & UART_S1_RDRF_MASK));
    
      /* Send the character */
      return (uint8)UART0_D;
	}
	else if (uart_port_num == 1)
	{
	  /* Wait until space is available in the FIFO */
	  while(!(UART1_S1 & UART_S1_RDRF_MASK));
	   
	  /* Send the character */
	  return (uint8)UART1_D;
	}
	else
	{
	  /* Wait until space is available in the FIFO */
	  while(!(UART2_S1 & UART_S1_RDRF_MASK));
	  
	  /* Send the character */
	  return (uint8)UART2_D;
	}
 }
/*
** ===================================================================
**     Event       :  out_I2C_OnMasterBlockSent (module Events)
**
**     Component   :  out_I2C [I2C_LDD]
*/
/*!
**     @brief
**         This event is called when I2C in master mode finishes the
**         transmission of the data successfully. This event is not
**         available for the SLAVE mode and if MasterSendBlock is
**         disabled. 
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void out_I2C_OnMasterBlockSent(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
	 LTCDataTransmittedFlg = TRUE;
}

/*
** ===================================================================
**     Event       :  out_I2C_OnMasterBlockReceived (module Events)
**
**     Component   :  out_I2C [I2C_LDD]
*/
/*!
**     @brief
**         This event is called when I2C is in master mode and finishes
**         the reception of the data successfully. This event is not
**         available for the SLAVE mode and if MasterReceiveBlock is
**         disabled.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
*/
/* ===================================================================*/
void out_I2C_OnMasterBlockReceived(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
	LTCDataReceivedFlg=TRUE;
}

/*
** ===================================================================
**     Event       :  AD1_OnEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called after the measurement (which consists
**         of <1 or more conversions>) is/are finished.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AD1_OnEnd(void)
{
  /* Write your code here ... */
	extern volatile bool ADC_koniec;
	ADC_koniec = TRUE;
}

/*
** ===================================================================
**     Event       :  AD1_OnCalibrationEnd (module Events)
**
**     Component   :  AD1 [ADC]
**     Description :
**         This event is called when the calibration has been finished.
**         User should check if the calibration pass or fail by
**         Calibration status method./nThis event is enabled only if
**         the <Interrupt service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AD1_OnCalibrationEnd(void)
{
	
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/

