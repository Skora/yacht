/*
 * adc_data.h
 *
 *  Created on: Jan 22, 2016
 *      Author: Skóra
 */

#ifndef ADC_DATA_H_
#define ADC_DATA_H_



#endif /* ADC_DATA_H_ */


float vlotage_scaling(uint16_t adc_results);
float copm_current(float vlotage1, float vlotage2);
float copm_power(float current,float voltage);
