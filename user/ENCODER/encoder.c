#include "encoder.h"


void Encoder_Init1(void)
	{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
		
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_Period = 65535;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI12, TIM_ICPolarity_BothEdge, TIM_ICPolarity_BothEdge);
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_ICFilter = 6;// ‰»Î≤∂ªÒ¬À≤®
	TIM_ICInit(TIM2, &TIM_ICInitStructure);
	TIM_SetCounter(TIM2,0);
	TIM_Cmd(TIM2, ENABLE); 
}

void Encoder_Init2(void)
	{
	 GPIO_InitTypeDef GPIO_InitStructure;  
 TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure; 
 TIM_ICInitTypeDef TIM_ICInitStructure;
 
 
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8,ENABLE);
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
 GPIO_Init(GPIOC,&GPIO_InitStructure);
 
 TIM_DeInit(TIM1);
 TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
 TIM_TimeBaseStructure.TIM_Period = 65535;
 TIM_TimeBaseStructure.TIM_Prescaler = 0; 
 TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
 TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
 TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
 TIM_ARRPreloadConfig(TIM8, ENABLE);
 TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure);
 
 TIM_EncoderInterfaceConfig(TIM8, TIM_EncoderMode_TI12,TIM_ICPolarity_BothEdge, TIM_ICPolarity_BothEdge);
 TIM_ICStructInit(&TIM_ICInitStructure);  
 TIM_ICInitStructure.TIM_ICFilter = 6;//ICx_FILTER; 
 TIM_ICInit(TIM8, &TIM_ICInitStructure);
 TIM_ClearFlag(TIM8, TIM_FLAG_Update); 
 TIM_SetCounter(TIM8, 0);
 TIM_Cmd(TIM8, ENABLE);
	
	
}
	

void Encoder_Init3(void)
	{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
		
	TIM_TimeBaseStructure.TIM_Prescaler = 0;
	TIM_TimeBaseStructure.TIM_Period = 65535;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	TIM_EncoderInterfaceConfig(TIM4, TIM_EncoderMode_TI12, TIM_ICPolarity_BothEdge, TIM_ICPolarity_BothEdge);
	TIM_ICStructInit(&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_ICFilter = 6;// ‰»Î≤∂ªÒ¬À≤®
	TIM_ICInit(TIM4, &TIM_ICInitStructure);
	TIM_SetCounter(TIM4,0);
	TIM_Cmd(TIM4, ENABLE); 
}


void Encoder_Init4(void)
	{

 GPIO_InitTypeDef GPIO_InitStructure;  
 TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure; 
 TIM_ICInitTypeDef TIM_ICInitStructure;
 
 
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1,ENABLE);
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_8;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
 GPIO_Init(GPIOA,&GPIO_InitStructure);
 
 TIM_DeInit(TIM1);
 TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
 TIM_TimeBaseStructure.TIM_Period = 65535;
 TIM_TimeBaseStructure.TIM_Prescaler = 0; 
 TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
 TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
 TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
 TIM_ARRPreloadConfig(TIM1, ENABLE);
 TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);
 
 TIM_EncoderInterfaceConfig(TIM1, TIM_EncoderMode_TI12,TIM_ICPolarity_BothEdge, TIM_ICPolarity_BothEdge);
 TIM_ICStructInit(&TIM_ICInitStructure);  
 TIM_ICInitStructure.TIM_ICFilter = 6;//ICx_FILTER; 
 TIM_ICInit(TIM1, &TIM_ICInitStructure);
 TIM_ClearFlag(TIM1, TIM_FLAG_Update); 
 TIM_SetCounter(TIM1, 0);
 TIM_Cmd(TIM1, ENABLE);

}
	

void Encoder_Init(void)
{
    Encoder_Init1();
    Encoder_Init2();
  	Encoder_Init3();
	  Encoder_Init4();
}


