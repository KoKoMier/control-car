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
		
		//���ڳ�ʼ������
    USART_Init( USART3, &USART_InitStructure );
	
		//ʹ�ܴ��ڽ����ж�
    USART_ITConfig( USART3, USART_IT_RXNE ,ENABLE);   //EXNE�������ݼĴ����ǿ�


    USART_Cmd( USART3, ENABLE );
//  USART_Cmd( USART3, ENABLE );
}

//����һ���ֽ�
void Usart_SendByte(USART_TypeDef *pUSARTx,uint8_t data)
{
	USART_SendData(pUSARTx, data);
	while(USART_GetFlagStatus(pUSARTx,  USART_FLAG_TXE) ==RESET);
}
//���������ֽڵ�����
void Usart_Sendhalf(USART_TypeDef *pUSARTx,uint8_t data)
{
	uint8_t temp_h,temp_1;
	
	temp_h = (data&0xff00) >>8;  //ȡ�߰�λд���ַ
	temp_1 = (data&0xff);     //ȡ�Ͱ�λд��ߵ�ַ��
	//0x1234&0xff����� 1&0 =0 1&1 =1 ���� 0x1234ֻ�ܱ����Ͱ�λ���� 0000000000110100 Ҳ���� 0x34
	USART_SendData(pUSARTx, temp_h);
	while(USART_GetFlagStatus(pUSARTx,  USART_FLAG_TXE) ==RESET);
	
	USART_SendData(pUSARTx, temp_1);
	while(USART_GetFlagStatus(pUSARTx,  USART_FLAG_TXE) ==RESET);
}

//����8λ������
void Usart_Senddarray(USART_TypeDef *pUSARTx,uint8_t *array, uint8_t num)
{
	uint8_t i;
	for(i=0;i<num;i++)
	{
		Usart_SendByte(pUSARTx, array[i] );    //������*array++
	}
		while(USART_GetFlagStatus(pUSARTx,  USART_FLAG_TC) ==RESET);
}

//�����ַ���
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
