#include "basic_tim.h" 


static void BASIC_TIM_NVIC_Config(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);		
    NVIC_InitStructure.NVIC_IRQChannel = BASIC_TIM_IRQ ;	
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	 
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;	
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

static void BASIC_TIM_Mode_Config(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    BASIC_TIM_APBxClock_FUN(BASIC_TIM_CLK, ENABLE);
    TIM_TimeBaseStructure.TIM_Period = BASIC_TIM_Period;	
    TIM_TimeBaseStructure.TIM_Prescaler= BASIC_TIM_Prescaler;
    TIM_TimeBaseInit(BASIC_TIM, &TIM_TimeBaseStructure);		
    TIM_ClearFlag(BASIC_TIM, TIM_FLAG_Update);  
    TIM_ITConfig(BASIC_TIM,TIM_IT_Update,ENABLE);		
    TIM_Cmd(BASIC_TIM, ENABLE);	
}

void BASIC_TIM_Init(void)
{
	BASIC_TIM_NVIC_Config();
	BASIC_TIM_Mode_Config();
}
/*********************************************END OF FILE**********************/
