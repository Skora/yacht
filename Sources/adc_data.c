/*
 * adc_data.c
 *
 *  Created on: Jan 22, 2016
 *      Author: Skóra
 */


float vlotage_scaling(adc_results)
{
	float voltage;
	voltage=adc_results*3.3/65536;
	return voltage;
}
