#include "usart.h"

void USARTx_CFG( void )
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0}; 
    USART_InitTypeDef USART_InitStructure = {0};


    RCC_APB1PeriphClockCmd( RCC_APB1Periph_USART3 , ENABLE );
    RCC_APB2PeriphClockCmd(  RCC_APB2Periph_GPIOB, ENABLE );

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;      
    GPIO_Init( GPIOB, &GPIO_InitStructure );
		
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;      
    GPIO_Init( GPIOB, &GPIO_InitStructure );


    USART_InitStructure.USART_BaudRate = 9600;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
		
		//串口初始化设置
    USART_Init( USART3, &USART_InitStructure );
	
		//使能串口接受中断
    USART_ITConfig( USART3, USART_IT_RXNE ,ENABLE);   //EXNE接受数据寄存器非空


    USART_Cmd( USART3, ENABLE );
//  USART_Cmd( USART3, ENABLE );
}

//发送一个字节
void Usart_SendByte(USART_TypeDef *pUSARTx,uint8_t data)
{
	USART_SendData(pUSARTx, data);
	while(USART_GetFlagStatus(pUSARTx,  USART_FLAG_TXE) ==RESET);
}
//发送两个字节的数据
void Usart_Sendhalf(USART_TypeDef *pUSARTx,uint8_t data)
{
	uint8_t temp_h,temp_1;
	
	temp_h = (data&0xff00) >>8;  //取高八位写入地址
	temp_1 = (data&0xff);     //取低八位写入高地址中
	//0x1234&0xff与操作 1&0 =0 1&1 =1 这样 0x1234只能保留低八位的数 0000000000110100 也就是 0x34
	USART_SendData(pUSARTx, temp_h);
	while(USART_GetFlagStatus(pUSARTx,  USART_FLAG_TXE) ==RESET);
	
	USART_SendData(pUSARTx, temp_1);
	while(USART_GetFlagStatus(pUSARTx,  USART_FLAG_TXE) ==RESET);
}

//发送8位的数组
void Usart_Senddarray(USART_TypeDef *pUSARTx,uint8_t *array, uint8_t num)
{
	uint8_t i;
	for(i=0;i<num;i++)
	{
		Usart_SendByte(pUSARTx, array[i] );    //或者是*array++
	}
		while(USART_GetFlagStatus(pUSARTx,  USART_FLAG_TC) ==RESET);
}

//发送字符串
void Usart_Sendstr(USART_TypeDef *pUSARTx,uint8_t *str)
{
	uint8_t i = 0;
	do
	{
		
	USART_SendData(pUSARTx,*(str+i));
	while(USART_GetFlagStatus(pUSARTx,  USART_FLAG_TC) ==RESET);
	i++ ;
	}while(*(str+i) != '\0');
	while(USART_GetFlagStatus(pUSARTx,  USART_FLAG_TC) ==RESET);

}
