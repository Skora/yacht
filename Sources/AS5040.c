
#include "AS5040.h"

AS5040data as5040data;

void AS5040_Init()
{
	/*SETING UP PORTS FOR SSI COMUNICATION*/
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;  //Seting clock for all PORTs lines
		
	/*INPUT PORTS*/
	PORTE_PCR4 = PORT_PCR_MUX(1); //Data In PTE3
	/*OUTPUT PORTS*/
	PORTE_PCR2 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;   
	PORTE_PCR3 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;   
	PORTE_PCR5 = PORT_PCR_MUX(1) | PORT_PCR_DSE_MASK;   
	GPIOE_PDDR = AS5040_CLK_LOC|AS5040_CS_LOC|AS5040_PRG_LOC;
	
	
	/*Initialization of AS540*/
	AS5040_CS_LOW ;
	AS5040_PRG_LOW;
	AS5040_CLK_HIGH;			// set to logic high, thus the chip starts already measuring

}

uint16_t AS5040_Data_read()
{
	uint16_t i, data;
	
	AS5040_CS_HIGH;
	WAIT1_Waitus(2);
	AS5040_CS_LOW;
	AS5040_CLK_LOW;
	
	data = 0;

	for (i = 0; i < 16; i++)
	{
		AS5040_CLK_HIGH;
		WAIT1_Waitus(1);
		AS5040_CLK_LOW;							// conversion after falling edge CS

		data = data << 1;						// shift bits in target variable one to the left
		if (AS5040_DI_IS_HIGH) // read port bit
		{
			data |=0x01; 						// set new bit in 16 bit variable
		}
		WAIT1_Waitus(1);
	}
	AS5040_CS_HIGH;					//end of aqusition

	return data;
}


	
/*Data Parser (to implement in aplication)*/
void AS5040_data_parser()
{
	uint16_t data;
	data=AS5040_Data_read();
	if(data & 0x0020)
		as5040data.ocf=1;
	else
		as5040data.ocf=0;

	if(data & 0x0010)
		as5040data.cof=1;
	else
		as5040data.cof=0;
	if(data & 0x0008)
		as5040data.lin=1;
	else
		as5040data.lin=0;
	if(data & 0x0004)
		as5040data.MAG_inc=1;
	else
		as5040data.MAG_inc=0;
	if(data & 0x0002)
		as5040data.MAG_dec=1;
	else
		as5040data.MAG_dec=0;
	if(data & 0x0001)
		as5040data.even_parity=1;
	else
		as5040data.even_parity=0;
	
	/* data ERROR evaluation*/ 
	if((as5040data.MAG_inc & as5040data.MAG_inc)|
								(!as5040data.ocf)|
									(as5040data.cof)|
										(as5040data.lin)){
		as5040data.Erorr=1;
	}
	else{
		as5040data.Erorr=0;
		as5040data.ang_position=(data>>6);
	}
	
	

}

