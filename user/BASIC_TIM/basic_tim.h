#ifndef __BASIC_TIM_H
#define __BASIC_TIM_H


#include "ch32f20x.h"



#define            BASIC_TIM                   TIM6
#define            BASIC_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            BASIC_TIM_CLK               RCC_APB1Periph_TIM6
#define            BASIC_TIM_Period            (1000-1)
#define            BASIC_TIM_Prescaler         71
#define            BASIC_TIM_IRQ               TIM6_IRQn
#define            BASIC_TIM_IRQHandler        TIM6_IRQHandler




void BASIC_TIM_Init(void);
static void BASIC_TIM_NVIC_Config(void);

#endif	
