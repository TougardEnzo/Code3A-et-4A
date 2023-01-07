/*
 * stm32L053R8_HC-SR04.c
 *
 *  Created on: 6 mai 2022
 *      Author: teone
 */
#include <stm32L053R8_HC-SR04.h>

void initUS(HCSR04 ultrason){
	uint8_t nb_port=(uint32_t)((uint32_t *)ultrason->portEcho - IOPPERIPH_BASE)/ (uint32_t)0x400;
	RCC->IOPENR|=1<<nb_port;
	nb_port=(uint32_t)((uint32_t *)ultrason->portTrig - IOPPERIPH_BASE)/ (uint32_t)0x400;
	RCC->IOPENR|=1<<nb_port;

	ultrason->portTrig->MODER&=~(0b11<<(ultrason->pinTrig*2));
	ultrason->portTrig->MODER|=(0b01<<(ultrason->pinTrig*2));

	ultrason->portEcho->MODER&=~(0b11<<(ultrason->pinEcho*2));
	ultrason->portEcho->MODER|=(0b00<<(ultrason->pinEcho*2));
}
int captUS(HCSR04 ultrason){//LL_Init1msTick(16000); pour transformer les millisecondes en microsecondes
	int distance = 0;
	ultrason->portTrig->ODR |=(1<<ultrason->pinTrig);
	LL_mDelay(10);
	ultrason->portTrig->ODR &=~(1<<ultrason->pinTrig);
	while(!(ultrason->portEcho->IDR &(1<<ultrason->pinEcho)));
	while((ultrason->portEcho->IDR &(1<<ultrason->pinEcho))){
	   distance ++;
	   LL_mDelay(58);
	}
	return distance;
}



