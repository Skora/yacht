
#include "LTC2945.h"

uint8_t LtcOutData[2] ={0x2A, 0x01};                // Inicjacja buforu wyjciowego 

volatile bool LTCDataReceivedFlg=FALSE;
volatile bool LTCDataTransmittedFlg=FALSE;

LTC2945 ltc2945;
LDD_TError Error;

LDD_TDeviceData *Myout_I2CPtr;






/*****************************************************************************
* Inicjacja I2C dla  MMA845x
******************************************************************************/
void LTC2945_Init(void)
{

  /* Configure I2C BUS devic - Write Operation */
  Error = out_I2C_MasterSendBlock(Myout_I2CPtr, &LtcOutData, 2, LDD_I2C_NO_SEND_STOP); /* Send LtcOutData (4 bytes) on the I2C bus and generates a stop condition to end transmission */
  while (!LTCDataTransmittedFlg); 
  LTCDataTransmittedFlg = FALSE;
  
  LtcOutData[0] = LTC2945_DIVICE_ADDR; 

  Error = out_I2C_MasterSendBlock(Myout_I2CPtr, &LtcOutData, 1, LDD_I2C_NO_SEND_STOP);
  while (!LTCDataTransmittedFlg);  
  LTCDataTransmittedFlg = FALSE;
  
  Error = out_I2C_MasterReceiveBlock(Myout_I2CPtr, &ltc2945.id, 1, LDD_I2C_SEND_STOP);
  while (!LTCDataReceivedFlg);
  LTCDataReceivedFlg = FALSE;
}

/**************************************************************************//*!
*    polling
******************************************************************************/
void LTC2945_Poll(void)
{

	LtcOutData[0] = LTC2945_DIVICE_ADDR; //device dares with R/W st to 0
	Error = out_I2C_MasterSendBlock(Myout_I2CPtr, &LtcOutData, 1, LDD_I2C_NO_SEND_STOP); 
	while (!LTCDataTransmittedFlg); 
	LTCDataTransmittedFlg = FALSE;
	LtcOutData[0] = CURRENT_MSB; //choosing the register form witch read
	Error = out_I2C_MasterSendBlock(Myout_I2CPtr, &LtcOutData, 1, LDD_I2C_NO_SEND_STOP); // Send LtcOutData 4 bytes) on the I2C bus 
	while (!LTCDataTransmittedFlg); 
	LTCDataTransmittedFlg = FALSE;
	LtcOutData[0] = LTC2945_DIVICE_ADDR+1; //device dares with R/W st to 1
	Error = out_I2C_MasterSendBlock(Myout_I2CPtr, &LtcOutData, 1, LDD_I2C_NO_SEND_STOP); 
	while (!LTCDataTransmittedFlg);
	LTCDataTransmittedFlg = FALSE;
	Error = out_I2C_MasterReceiveBlock(Myout_I2CPtr, &LtcInData, 2, LDD_I2C_SEND_STOP);  //getting whole  current here 
	while (!LTCDataReceivedFlg);
	LTCDataReceivedFlg = FALSE;  

	ltc2945.current= LtcInData[1] | (LtcInData[0] << 8);

}
