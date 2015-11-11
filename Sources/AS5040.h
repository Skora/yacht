

#ifndef AS5040_H_
#define AS5040_H_

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "WAIT1.h"

typedef struct
{
    int16_t ang_position;
    bool ocf;
    bool cof;
    bool lin;
    bool MAG_inc;
    bool MAG_dec;
    bool even_parity;
    bool Erorr;
}AS5040data;

#define AS5040_CLK_LOC		((uint32_t)(1<<3)) 		//chaosing pin number
#define AS5040_DI_LOC		((uint32_t)(1<<4))		//docelowo PTE2-5
#define AS5040_PRG_LOC		((uint32_t)(1<<5))
#define AS5040_CS_LOC		((uint32_t)(1<<2))



#define AS5040_CLK_HIGH			GPIOE_PSOR = AS5040_CLK_LOC
#define AS5040_CLK_LOW			GPIOE_PCOR = AS5040_CLK_LOC
#define AS5040_CLK_TOGGLE		GPIOE_PTOR = AS5040_CLK_LOC

#define AS5040_CS_HIGH			GPIOE_PSOR = AS5040_CS_LOC
#define AS5040_CS_LOW			GPIOE_PCOR = AS5040_CS_LOC
#define AS5040_CS_TOGGLE		GPIOE_PTOR = AS5040_CS_LOC

#define AS5040_PRG_HIGH			GPIOE_PSOR = AAS5040_PRG_LOC
#define AS5040_PRG_LOW			GPIOE_PCOR = AS5040_PRG_LOC
#define AS5040_PRG_TOGGLE		GPIOE_PTOR = AS5040_PRG_LOC

#define AS5040_DI_IS_HIGH	((GPIOE_PDIR&AS5040_DI_LOC)>0)		//DATA INPUT FORM AS5040 is high or low


void AS5040_Init();
uint16_t AS5040_data_read();
void AS5040_data_parser();



#endif /* AS5040*/

