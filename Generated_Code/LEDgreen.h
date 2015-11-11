/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : LEDgreen.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : LED
**     Version     : Component 01.054, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-11-11, 15:28, # CodeGen: 16
**     Abstract    :
**          This component implements a universal driver for a single LED.
**     Settings    :
**          Component name                                 : LEDgreen
**          Turned On with initialization                  : no
**          HW Interface                                   : 
**            On/Off                                       : Enabled
**              Pin                                        : LEDpin
**            PWM                                          : Disabled
**            High Value means ON                          : no
**          Shell                                          : Disabled
**     Contents    :
**         Init       - void LEDgreen_Init(void);
**         Deinit     - void LEDgreen_Deinit(void);
**         On         - void LEDgreen_On(void);
**         Off        - void LEDgreen_Off(void);
**         Neg        - void LEDgreen_Neg(void);
**         Get        - byte LEDgreen_Get(void);
**         Put        - void LEDgreen_Put(byte val);
**         SetRatio16 - void LEDgreen_SetRatio16(word ratio);
**
**     License   :  Open Source (LGPL)
**     Copyright : (c) Copyright Erich Styger, 2012, all rights reserved.
**     Web: http://mcuoneclipse.com
**     This an open source software implementing an LED driver using Processor Expert.
**     This is a free software and is opened for education, research and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file LEDgreen.h
** @version 01.00
** @brief
**          This component implements a universal driver for a single LED.
*/         
/*!
**  @addtogroup LEDgreen_module LEDgreen module documentation
**  @{
*/         

#ifndef __LEDgreen_H
#define __LEDgreen_H

/* MODULE LEDgreen. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "LEDpin1.h"

#include "Cpu.h"

#define LEDgreen_ClrVal()    LEDpin1_ClrVal() /* put the pin on low level */
#define LEDgreen_SetVal()    LEDpin1_SetVal() /* put the pin on high level */
#define LEDgreen_SetInput()  LEDpin1_SetInput() /* use the pin as input pin */
#define LEDgreen_SetOutput() LEDpin1_SetOutput() /* use the pin as output pin */

#define LEDgreen_PARSE_COMMAND_ENABLED  0 /* set to 1 if method ParseCommand() is present, 0 otherwise */


#define LEDgreen_On() LEDpin1_ClrVal()
/*
** ===================================================================
**     Method      :  LEDgreen_On (component LED)
**     Description :
**         This turns the LED on.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDgreen_Off() LEDpin1_SetVal()
/*
** ===================================================================
**     Method      :  LEDgreen_Off (component LED)
**     Description :
**         This turns the LED off.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDgreen_Neg() LEDpin1_NegVal()
/*
** ===================================================================
**     Method      :  LEDgreen_Neg (component LED)
**     Description :
**         This negates/toggles the LED
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDgreen_Get() (!(LEDpin1_GetVal()))
/*
** ===================================================================
**     Method      :  LEDgreen_Get (component LED)
**     Description :
**         This returns logical 1 in case the LED is on, 0 otherwise.
**     Parameters  : None
**     Returns     :
**         ---             - Status of the LED (on or off)
** ===================================================================
*/

#define LEDgreen_Init() LEDgreen_Off()
/*
** ===================================================================
**     Method      :  LEDgreen_Init (component LED)
**     Description :
**         Performs the LED driver initialization.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define LEDgreen_Put(val)  ((val) ? LEDgreen_On() : LEDgreen_Off())
/*
** ===================================================================
**     Method      :  LEDgreen_Put (component LED)
**     Description :
**         Turns the LED on or off.
**     Parameters  :
**         NAME            - DESCRIPTION
**         val             - value to define if the LED has to be on or
**                           off.
**     Returns     : Nothing
** ===================================================================
*/

void LEDgreen_Deinit(void);
/*
** ===================================================================
**     Method      :  LEDgreen_Deinit (component LED)
**     Description :
**         Deinitializes the driver
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void LEDgreen_SetRatio16(word ratio);
/*
** ===================================================================
**     Method      :  LEDgreen_SetRatio16 (component LED)
**     Description :
**         Method to specify the duty cycle. If using a PWM pin, this
**         means the duty cycle is set. For On/off pins, values smaller
**         0x7FFF means off, while values greater means on.
**     Parameters  :
**         NAME            - DESCRIPTION
**         ratio           - Ratio value, where 0 means 'off' and
**                           0xffff means 'on'
**     Returns     : Nothing
** ===================================================================
*/

/* END LEDgreen. */

#endif
/* ifndef __LEDgreen_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/