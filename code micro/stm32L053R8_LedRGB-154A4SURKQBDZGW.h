#include "stm32l053xx.h"

typedef struct
{
	GPIO_TypeDef * gpioPortR;
	uint8_t pinR;
	GPIO_TypeDef * gpioPortG;
	uint8_t pinG;
	GPIO_TypeDef * gpioPortB;
	uint8_t pinB;

}LED_TypeDef;

void Led_init(LED_TypeDef *led, GPIO_TypeDef * portR, uint8_t pnR, GPIO_TypeDef * portG, uint8_t pnG, GPIO_TypeDef * portB, uint8_t pnB);

void LedR_turnOn(LED_TypeDef *led);
void LedR_turnOff(LED_TypeDef *led);
void LedR_toggle(LED_TypeDef *led);

void LedG_turnOn(LED_TypeDef *led);
void LedG_turnOff(LED_TypeDef *led);
void LedG_toggle(LED_TypeDef *led);

void LedB_turnOn(LED_TypeDef *led);
void LedB_turnOff(LED_TypeDef *led);
void LedB_toggle(LED_TypeDef *led);

int* Led_state(LED_TypeDef *led);
