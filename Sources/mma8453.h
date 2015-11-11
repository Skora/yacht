

#ifndef MMA8453_H_
#define MMA8453_H_

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "I2C2.h"


typedef struct
{
	int16_t x;
	int16_t y;
	int16_t z;
	int8_t id;
}MMA845X;


typedef enum
{
	IDLE,  
	TRANSMIT,
	RECEIVE
}MMA845_STATE;



#define MMA845X_DIVIDER         0x04
#define MMA845X_BUFFER_SIZE     0x06
#define MMA845X_CFG_VALUE       0x01
#define MMA845X_DEVICE_ID       0x0D


uint8_t InData[MMA845X_BUFFER_SIZE];
int16_t mma845_tmp;


void Timer_Interrupt_CB();
void MMA845X_Init();
void MMA845X_Poll();


#endif /* MMA8453*/

