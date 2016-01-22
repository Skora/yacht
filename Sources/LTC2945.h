

#ifndef LTC2945_H_
#define LTC2945_H_

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "out_I2C.h"




typedef struct
{
	int16_t current;
	int16_t voltage;
	int32_t power;
	int8_t id;
}LTC2945;




// DEVICIE ADRESS DEFINITION
//#define ADR1_LOW  //addr choosing soldering pads
//#define ADR0_LOW
// a6|a5|a4|a3|a3|a1|a0|R/W    //R/W bit set to 0 - R
//#if defined(ADR1_LOW) && defined(ADR0_LOW)
	#define LTC2945_DIVICE_ADDR 0x6F 
//#endif
#if defined(ADR1_HIGH) && defined(ADR0_LOW)
	#define LTC2945_DIVICE_ADDR 0xCE  
#endif
#if defined(ADR1_LOW) && defined(ADR0_HIGH)
	#define LTC2945_DIVICE_ADDR 0xD8  
#endif
#if defined(ADR1_HIGH) && defined(ADR0_HIGH)
	#define LTC2945_DIVICE_ADDR 0xD2  
#endif

//data registers form LTC2945
#define CURRENT_LSB 0x15
#define CURRENT_MSB 0x14  
#define VOLTAGE_MSB 0x1E
#define VOLTAGE_LSB 0x1F
#define POWER_MSB1 0x1E
#define POWER_MSB2 0x1E
#define POWER_LSB 0x1F



#define LTC_BUFFER_SIZE     0x07



uint8_t LtcInData[LTC_BUFFER_SIZE];




void LTC2945_Init();
void LTC2945_Poll();


#endif

