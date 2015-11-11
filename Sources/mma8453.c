
#include "mma8453.h"

uint8_t OutData[2] ={0x2A, 0x01};                // Inicjacja buforu wyjciowego 

volatile bool DataReceivedFlg=FALSE;
volatile bool DataTransmittedFlg=FALSE;

MMA845X mma845x;
LDD_TError Error;

LDD_TDeviceData *MyI2CPtr;
LDD_TDeviceData *MyTimerPtr;

volatile bool DataTransmittedFlg;
volatile bool DataReceivedFlg;


static MMA845_STATE measuring = IDLE;
static MMA845_STATE measuring_last = RECEIVE;




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
