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

float copm_current(vlotage1,vlotage2)
{
	float current;
	current=0.02*(vlotage2-vlotage1);
	return current;
}

float copm_power(current,voltage)
{
	float power;
	power=current*voltage;
	return power;
}
