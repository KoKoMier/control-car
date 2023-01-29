#include "debug.h"
#include <stdio.h>
#include "moto.h"
#include "pwm.h"
#include "usart.h"
#include "encoder.h"
#include "basic_tim.h"


volatile uint32_t time = 0;	


int main( void )
{   uint8_t ch;
  	BASIC_TIM_Init();
    Encoder_Init();
		USARTx_CFG();
		GPIO_Toggle_INIT();	
		TIM3_CH3_PWM_Init(1000-1, 71,0);
    while( 1 )
    {		
	  	ch = getchar();
			printf("%c\n",ch);
			switch(ch)
			{
			case'W':MotorForward();break;
			case'S':MotorBack();break;
			case'X':MotorStop();break;
			case'A':MotorRight();break;
			case'D':MotorLeft();break;
			case'E':Right();break;
      case'Q':Left();break;
      case'J':LeftForward();break;				
      case'K':RightForward();break;
      case'H':Circuit();break;				
			}	
		
    }
	}	
