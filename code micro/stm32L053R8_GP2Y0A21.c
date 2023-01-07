/*
 * stm32L053R8_buzzer.c
 *
 *  Created on: 26 avr. 2022
 *      Author: teone
 */
#include <stm32L053R8_GP2Y0A21.h>
#include <stm32l053xx.h>

//ADC_init(ADC1, 12, 0);
/*while((ADC1->ISR& ADC_ISR_EOC)==0);
	  lgADCDR = ADC1->DR;
	  //7+(4095-lgADCDR)/((4095-300)/(80-7)); //4095 parce que resolution du CAN (12bits) | -lgADC parce que le pic est à 7cm
	  //et prend la valeur max (soit 4095) | /52 car la plage de valeur a un pas de 52 car (4095-250)/|7-80|
	  LL_mDelay(200);
	  int disIR = distance(lgADCDR);
	  */

void ADC_init(ADC_TypeDef * adc, uint8_t resolution, uint8_t channel){
	RCC->APB2ENR |= RCC_APB2ENR_ADCEN;
	adc->CFGR2 |=(0b11<<ADC_CFGR2_CKMODE_Pos);
	if((ADC1->CR & ADC_CR_ADEN) != 0)
	{
		ADC1->CR &= ~(uint32_t)ADC_CR_ADEN;
	}
	ADC1->CR |= ADC_CR_ADCAL;
	while((ADC1->CR & ADC_CR_ADCAL)!=0);

	adc->CFGR1 |= (0b1 << ADC_CFGR1_CONT_Pos);
	if (resolution == 12)
	{
		adc->CFGR1 |= (0b00 << ADC_CFGR1_RES_Pos);
	}
	else if (resolution == 10)
	{
		adc->CFGR1 |= (0b01 << ADC_CFGR1_RES_Pos);
	}
	else if (resolution == 8)
	{
		adc->CFGR1 |= (0b10 << ADC_CFGR1_RES_Pos);
	}
	else if (resolution == 6)
	{
		adc->CFGR1 |= (0b11 << ADC_CFGR1_RES_Pos);
	}
	adc->CHSELR |= (0b1 << channel);
	adc->CR |= (0b1 << ADC_CR_ADEN_Pos);
	adc->CR |= (0b1 << ADC_CR_ADSTART_Pos);
}

int distance(int YY){
    if(YY<4095){
        int tab_taille = 17;
        int Yval[]={4095,2900,2000,1600,1300,1100,950,850,800,730,680,660,640,630,620,610,600};
        int Xval[]={5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85};
        int x1=0, y1=0, x2=0, y2=0;
        for(int i=0; i<tab_taille; i++){
            if(YY>=Yval[i]){
                x1 = Xval[i-1];
                x2 = Xval[i];
                y1 = Yval[i-1];
                y2 = Yval[i];
                break;
            }
        }
        if(x1!=0 && x2!=0 && y1!=0 && y2!=0){
            int a = (y1-y2)/(x1-x2);
            int b = y2-a*x2;
            printf("a %d b %d\n",a,b);
            int dist= (YY-b)/a;
            return dist;
        }
    }
	return 0;
}


