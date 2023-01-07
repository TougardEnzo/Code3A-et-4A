/*
 * stm32L053R8_buzzer.c
 *
 *  Created on: 26 avr. 2022
 *      Author: teone
 */
#include <stm32L053R8_buzzer.h>
#include <stm32l053xx.h>

/*
  set_freq(GPIOC, 7, frequency[i], 16000000);
  if(!(GPIOC->IDR &(1<<13))) i++;
  i++;
  if(i==11) i=0;
  if(GPIOC->IDR &(1<<7)) Led_turnOn(&led);
  else Led_turnOff(&led);
  LL_mDelay(1000);
 */

PWM_pin set_PWM(GPIO_TypeDef * port, uint8_t pin)
{
	PWM_pin pinPWM;
	pinPWM.pin = pin;
	pinPWM.port = port;
	if(port==GPIOA)
	{
		if(pin==0)
		{
			pinPWM.timer = TIM2;
			pinPWM.channel = 1;
			pinPWM.af = 2;
		}
		else if(pin==1)
		{
			pinPWM.timer = TIM2;
			pinPWM.channel = 2;
			pinPWM.af = 2;
		}
		else if(pin==2)
		{
			pinPWM.timer = TIM2;
			pinPWM.channel = 3;
			pinPWM.af = 2;
		}
		else if(pin==3)
		{
			pinPWM.timer = TIM2;
			pinPWM.channel = 4;
			pinPWM.af = 2;
		}
		else if(pin==5)
		{
			pinPWM.timer = TIM2;
			pinPWM.channel = 1;
			pinPWM.af = 5;
		}
		else if(pin==6)
		{
			pinPWM.timer = TIM22;
			pinPWM.channel = 1;
			pinPWM.af = 5;
		}
		else if(pin==7)
		{
			pinPWM.timer = TIM22;
			pinPWM.channel = 2;
			pinPWM.af = 5;
		}
		else if(pin==15)
		{
			pinPWM.timer = TIM2;
			pinPWM.channel = 1;
			pinPWM.af = 5;
		}
	}
	else if(port==GPIOB)
	{
		if(pin==3){
			pinPWM.timer = TIM2;
			pinPWM.channel = 2;
			pinPWM.af = 2;
		}
		else if(pin==4)
		{
			pinPWM.timer = TIM22;
			pinPWM.channel = 1;
			pinPWM.af = 4;
		}
		else if(pin==5)
		{
			pinPWM.timer = TIM22;
			pinPWM.channel = 2;
			pinPWM.af = 5;
		}
		else if(pin==10)
		{
			pinPWM.timer = TIM2;
			pinPWM.channel = 3;
			pinPWM.af = 2;
		}
		else if(pin==11)
		{
			pinPWM.timer = TIM2;
			pinPWM.channel = 4;
			pinPWM.af = 2;
		}
		else if(pin==13)
		{
			pinPWM.timer = TIM21;
			pinPWM.channel = 1;
			pinPWM.af = 6;
		}
		else if(pin==14)
		{
			pinPWM.timer = TIM21;
			pinPWM.channel = 6;
		}
	}
	if(port==GPIOC)
	{
		if(pin==6){
			pinPWM.timer = TIM22;
			pinPWM.channel = 1;
			pinPWM.af = 0;
		}
		else if(pin==7)
		{
			pinPWM.timer = TIM22;
			pinPWM.channel = 2;
			pinPWM.af = 0;
		}
	}
	return pinPWM;
}


void set_freq(PWM_pin pinPWM, float frequency, uint32_t HCLKFrenquency)
{
	if((HCLKFrenquency/frequency-1) >= 65535){
	  pinPWM.timer->PSC = 0;
	  pinPWM.timer->ARR = (HCLKFrenquency/frequency*1000)-1;
	}
	else{
	  pinPWM.timer->PSC = 0;
	  pinPWM.timer->ARR = HCLKFrenquency/frequency-1;
	}
	pinPWM.timer->CCR1 = (pinPWM.timer->ARR+1)*0.05;
}

PWM_pin buzzer_init(GPIO_TypeDef * port, uint8_t pin, uint32_t HCLKFrenquency)
{//pin should be a PWM pin
	uint8_t nb_port;
	nb_port=(uint32_t)((uint32_t *)pin - IOPPERIPH_BASE)/ (uint32_t)0x400;
	RCC->IOPENR|=1<<nb_port;
	PWM_pin pinPWM;
	pinPWM = set_PWM(port, pin);
	AlternateFunction_setup(port, pinPWM.pin, pinPWM.af); // Pin PWM
	PWM_setup(pinPWM.timer, pinPWM.channel, HCLKFrenquency, 0,0.05);
	return pinPWM;
}

void AlternateFunction_setup(GPIO_TypeDef * port, uint8_t pin, uint8_t af)
{
	uint32_t nb_port =(uint32_t)((uint32_t *)port - IOPPERIPH_BASE)/ (uint32_t)0x400;
	RCC->IOPENR|=1<<nb_port;
	// activer l’alternate function en question
	port->MODER&=~(0b11 << 2*pin);
	port->MODER|=(0b10 << 2*pin);
	//activer l’alternate function en question
	if(pin >= 0 && pin <= 7)
	{
		port->AFR[0] |=(af<<pin*4);
	}
	else if(pin >= 8 && pin <= 15)
	{
		port->AFR[1] |=(af<<pin*4);
	}
}

void PWM_setup(TIM_TypeDef * timer, uint8_t canal, uint32_t HCLKFrenquency, uint32_t PWMFrequency, float duty_cycle)
{
	if(timer == TIM2)
	{
		// activation de l’horloge pour le timer 2
		RCC->APB1ENR|= RCC_APB1ENR_TIM2EN;
	}
	else if(timer == TIM21)
	{
		// activation de l’horloge pour le timer 21
		RCC->APB2ENR|= RCC_APB2ENR_TIM21EN;
	}
	else if(timer == TIM22)
	{//CORRECTE NORMALEMENT
		// activation de l’horloge pour le timer 22
		RCC->APB2ENR|= RCC_APB2ENR_TIM22EN;
	}
	// configurer les registres de comptage et de comparaison
	//configuration des ARR
	if((HCLKFrenquency/PWMFrequency-1) >= 65535)
	{
		timer->PSC = 999;
		timer->ARR = (HCLKFrenquency/PWMFrequency*1000)-1;
	}
	else
	{
		timer->ARR = HCLKFrenquency/PWMFrequency-1;
	}
	if(canal == 1)
	{
		//configuration en mode PWM mode1 sur le canal 1
		timer->CCMR1 &= ~TIM_CCMR1_OC1M_0;
		timer->CCMR1 |= TIM_CCMR1_OC1M_1| TIM_CCMR1_OC1M_2;
		//activer la sortie du signal PWM sur le canal en question
		//activation du canal1
		timer->CCER |= TIM_CCER_CC1E;
		//configuration des CCR
		timer->CCR1 = (timer->ARR+1)*duty_cycle; //CCR du canal 1 du timer 2
	}
	else 
	{
		//configuration en mode PWM mode1 sur le canal 2
		timer->CCMR1 &= ~TIM_CCMR1_OC2M_0;
		timer->CCMR1 |= TIM_CCMR1_OC2M_1| TIM_CCMR1_OC2M_2;
		//activation de la sortie PWM sur le canal 2
		timer->CCER |= TIM_CCER_CC2E;
		//configuration des CCR
		timer->CCR2 = (timer->ARR+1)*duty_cycle; //CCR du canal 2 du timer 2
	}
	// Lancement du timer 2
	timer->CR1 |= TIM_CR1_CEN_Msk;
}



