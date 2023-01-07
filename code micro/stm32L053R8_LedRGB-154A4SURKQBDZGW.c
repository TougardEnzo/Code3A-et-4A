#include <stm32L053R8_LedRGB-154A4SURKQBDZGW.h>

void Led_init(LED_TypeDef *led, GPIO_TypeDef * portR, uint8_t pnR, GPIO_TypeDef * portG, uint8_t pnG, GPIO_TypeDef * portB, uint8_t pnB){

	led->gpioPortR=portR;
	led->pinR=pnR;
	led->gpioPortG=portG;
	led->pinG=pnG;
	led->gpioPortB=portB;
	led->pinB=pnB;
	//Activation de l'horloge sur le port en question
	//determiner le numero du port 0--> GPIOA, 1-->GPIOB, etc.
	//puis activation de l'hologe
	uint8_t nb_port;
	nb_port=(uint32_t)((uint32_t *)led->gpioPortR - IOPPERIPH_BASE)/ (uint32_t)0x400;
	RCC->IOPENR|=1<<nb_port;
	nb_port=(uint32_t)((uint32_t *)led->gpioPortG - IOPPERIPH_BASE)/ (uint32_t)0x400;
	RCC->IOPENR|=1<<nb_port;
	nb_port=(uint32_t)((uint32_t *)led->gpioPortB - IOPPERIPH_BASE)/ (uint32_t)0x400;
	RCC->IOPENR|=1<<nb_port;

	//configuration de la pin en sortie
	led->gpioPortR->MODER&=~(0b11<<2*led->pinR);
	led->gpioPortR->MODER|=(0b01<<2*led->pinR);
	led->gpioPortG->MODER&=~(0b11<<2*led->pinG);
	led->gpioPortG->MODER|=(0b01<<2*led->pinG);
	led->gpioPortB->MODER&=~(0b11<<2*led->pinB);
	led->gpioPortB->MODER|=(0b01<<2*led->pinB);
}

void LedG_turnOn(LED_TypeDef *led){
	led->gpioPortG->ODR |= (1<<led->pinG);
}
void LedG_turnOff(LED_TypeDef *led){
	led->gpioPortG->ODR &= ~(1<<led->pinG);
}
void LedG_toggle(LED_TypeDef *led){
	led->gpioPortG->ODR ^=(1<<led->pinG);
}

void LedB_turnOn(LED_TypeDef *led){
	led->gpioPortB->ODR |= (1<<led->pinB);
}
void LedB_turnOff(LED_TypeDef *led){
	led->gpioPortB->ODR &=~(1<<led->pinB);
}
void LedB_toggle(LED_TypeDef *led){
	led->gpioPortB->ODR ^=(1<<led->pinB);
}

void LedR_turnOn(LED_TypeDef *led){
	led->gpioPortR->ODR |= (1<<led->pinR);
}
void LedR_turnOff(LED_TypeDef *led){
	led->gpioPortR->ODR &=~(1<<led->pinR);
}
void LedR_toggle(LED_TypeDef *led){
	led->gpioPortR->ODR ^=(1<<led->pinR);
}

int* Led_state(LED_TypeDef *led){
	int led_state[3]={-1,-1,-1};
	if(led->gpioPortR->IDR & (1<<led->pinR)) led_state[0]=1;
	else led_state[0]=0;
	if(led->gpioPortG->IDR & (1<<led->pinG)) led_state[1]=1;
	else led_state[1]=0;
	if(led->gpioPortB->IDR & (1<<led->pinB)) led_state[2]=1;
	else led_state[2]=0;
	return led_state;
}
