/*
 * stm32L053R8_buzzer.h
 *
 *  Created on: 26 avr. 2022
 *      Author: teone
 */

#ifndef INC_STM32L053R8_GP2Y0A21_H_
#define INC_STM32L053R8_GP2Y0A21_H_
#include <stm32l053xx.h>

void ADC_init(ADC_TypeDef * adc, uint8_t resolution, uint8_t channel);
int distance(int YY);

#endif /* INC_STM32L053R8_BUZZER_H_ */
