/*
 * stm32L053R8_HC-SR04.h
 *
 *  Created on: 6 mai 2022
 *      Author: teone
 */

#ifndef INC_STM32L053R8_HC_SR04_H_
#define INC_STM32L053R8_HC_SR04_H_
#include <stm32l053xx.h>

#endif /* INC_STM32L053R8_HC_SR04_H_ */

struct sHCSR04{
	GPIO_TypeDef* portTrig;
	int pinTrig;
	GPIO_TypeDef* portEcho;
	int pinEcho;
}; typedef struct sHCSR04* HCSR04;

void initUS(HCSR04 ultrason);
int captUS(HCSR04 ultrason);
