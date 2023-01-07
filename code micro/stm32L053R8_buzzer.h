/*
 * stm32L053R8_buzzer.h
 *
 *  Created on: 26 avr. 2022
 *      Author: teone
 */

#ifndef INC_STM32L053R8_BUZZER_H_
#define INC_STM32L053R8_BUZZER_H_
#include <stm32l053xx.h>

typedef struct PWM_pin_Mode{
	TIM_TypeDef * timer;
	uint8_t channel;
	uint8_t af;
	uint8_t pin;
	GPIO_TypeDef * port;
} PWM_pin;

PWM_pin set_PWM(GPIO_TypeDef * port, uint8_t pin);
void PWM_setup(TIM_TypeDef * timer, uint8_t canal, uint32_t HCLKFrenquency, uint32_t PWMFrequency, float duty_cycle);
void AlternateFunction_setup(GPIO_TypeDef * port, uint8_t pin, uint8_t af);
PWM_pin buzzer_init(GPIO_TypeDef * port, uint8_t pin, uint32_t HCLKFrenquency);//pin should be a PWM pin
void set_freq(PWM_pin pinPWM, float frequency, uint32_t HCLKFrenquency);

#endif /* INC_STM32L053R8_BUZZER_H_ */
