#ifndef __USART_H
#define __USART_H

#include "ch32f20x.h"


void USARTx_CFG( void );
void Usart_SendByte(USART_TypeDef *pUSARTx,uint8_t data);
void Usart_Sendhalf(USART_TypeDef *pUSARTx,uint8_t data);
void Usart_Senddarray(USART_TypeDef *pUSARTx,uint8_t *array, uint8_t num);
void Usart_Sendstr(USART_TypeDef *pUSARTx,uint8_t *str);


#endif
