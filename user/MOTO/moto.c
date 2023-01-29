#include "moto.h"
#include "encoder.h"


void delay(unsigned int i)//毫秒延迟
{
	unsigned int temp;
	SysTick->LOAD = 9000*i;
	SysTick->CTRL = 0X01;
	SysTick->VAL = 0;
	do
	{
		temp = SysTick->CTRL;
	}
	while((temp&0x01)&&(!(temp&(1<<16))));
	SysTick->CTRL = 0;
	SysTick->VAL = 0;
}	

int Read_Encoder_test(TIM_TypeDef * TIMX)
{
  int Encoder_TIM;
  Encoder_TIM = TIMX->CNT;
  if (Encoder_TIM>0xefff)Encoder_TIM = Encoder_TIM-0xffff;
	return Encoder_TIM;
}

int PID_SetCompare1()        //pid
{
	  float Kp=3,Ki=0.1;//pid控制系数	
    float cap;	
	  int e=0,e1=0;         //pid偏差 e-本次 e1-上次  e2-上上次  esum-历次误差累计
	  static float PwmControl= 0;
	  int SpeedSet = 50;
	  int speed;
	  int DWheelEncoderNow =0;
	  int DWheelEncoderLast =0;
	  delay(10);
		DWheelEncoderNow += Read_Encoder_test(TIM2);
    speed = (DWheelEncoderNow	- DWheelEncoderLast)*0.5;
		DWheelEncoderLast = DWheelEncoderNow;
    e=SpeedSet-speed;        //误差=设定值-实际转速值
    PwmControl+=Kp *(e-e1)+ Ki*e ;  //控制PWM占空值(1~100)
    e1 = e;
    cap = PwmControl;   	//cap占空比控制范围：(0~1)
		return cap;
	
}

int PID_SetCompare2()        //pid
{
	  float Kp=3,Ki=0.1;//pid控制系数	
    float cap;	
	  int e=0,e1=0;         //pid偏差 e-本次 e1-上次  e2-上上次  esum-历次误差累计
	  static float PwmControl= 0;
	  int SpeedSet = 50;
	  int speed;
	  int DWheelEncoderNow =0;
	  int DWheelEncoderLast =0;
	  delay(10);
		DWheelEncoderNow += Read_Encoder_test(TIM8);
    speed = (DWheelEncoderNow	- DWheelEncoderLast)*0.5;
		DWheelEncoderLast = DWheelEncoderNow;
    e=SpeedSet-speed;        //误差=设定值-实际转速值
    PwmControl+=Kp *(e-e1)+ Ki*e ;  //控制PWM占空值(1~100)
    e1 = e;
    cap = PwmControl;             //cap占空比控制范围：(0~1)
		return cap;
}

int PID_SetCompare3()        //pid
{
	  float Kp=3,Ki=0.1;//pid控制系数	
    float cap;	
	  int e=0,e1=0;         //pid偏差 e-本次 e1-上次  e2-上上次  esum-历次误差累计
	  static float PwmControl= 0;
	  int SpeedSet = 50;
	  int speed;
	  int DWheelEncoderNow =0;
	  int DWheelEncoderLast =0;
	  delay(10);
		DWheelEncoderNow += Read_Encoder_test(TIM4);
    speed = (DWheelEncoderNow	- DWheelEncoderLast)*0.5;
		DWheelEncoderLast = DWheelEncoderNow;
    e=SpeedSet-speed;        //误差=设定值-实际转速值
    PwmControl+=Kp *(e-e1)+ Ki*e ;  //控制PWM占空值(1~100)
    e1 = e;
    cap = PwmControl;             //cap占空比控制范围：(0~1)
		return cap;
}

int PID_SetCompare4()        //pid
{
	  float Kp=3,Ki=0.1;//pid控制系数	
    float cap;	
	  int e=0,e1=0;         //pid偏差 e-本次 e1-上次  e2-上上次  esum-历次误差累计
	  static float PwmControl= 0;
	  int SpeedSet = 50;
	  int speed;
	  int DWheelEncoderNow =0;
	  int DWheelEncoderLast =0;
	  delay(10);
		DWheelEncoderNow += Read_Encoder_test(TIM1);
    speed = (DWheelEncoderNow	- DWheelEncoderLast)*0.5;
		DWheelEncoderLast = DWheelEncoderNow;
    e=SpeedSet-speed;        //误差=设定值-实际转速值
    PwmControl+=Kp *(e-e1)+ Ki*e ;  //控制PWM占空值(1~100)
    e1 = e;
    cap = PwmControl;             //cap占空比控制范围：(0~1)
		return cap;
}



void MotorForward(void)
{	
		GPIO_SetBits(GPIOA,GPIO_Pin_4);
		GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		GPIO_SetBits(GPIOA,GPIO_Pin_10);
		GPIO_ResetBits(GPIOA,GPIO_Pin_11);
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		GPIO_ResetBits(GPIOB,GPIO_Pin_2);
		GPIO_SetBits(GPIOB,GPIO_Pin_13);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);

  	TIM_SetCompare1(TIM3,600);
  	TIM_SetCompare2(TIM3,600);
	  TIM_SetCompare3(TIM3,600);
	  TIM_SetCompare4(TIM3,600);
	  
}

void MotorBack(void)
{
 	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	GPIO_SetBits(GPIOA,GPIO_Pin_5);
	GPIO_ResetBits(GPIOA,GPIO_Pin_10);
	GPIO_SetBits(GPIOA GPIO_Pin_11);
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	GPIO_SetBits(GPIOB,GPIO_Pin_2);
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	
	
	TIM_SetCompare1(TIM3,600);
	TIM_SetCompare2(TIM3,600);
	TIM_SetCompare3(TIM3,600);
	TIM_SetCompare4(TIM3,600);

}

void MotorStop(void)
{
  TIM_SetCompare1(TIM3,0);
	TIM_SetCompare2(TIM3,0);
	TIM_SetCompare3(TIM3,0);
	TIM_SetCompare4(TIM3,0);
}

void MotorRight(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	GPIO_SetBits(GPIOA,GPIO_Pin_10);
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	GPIO_ResetBits(GPIOB,GPIO_Pin_2);
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	
	TIM_SetCompare1(TIM3,900);
	TIM_SetCompare2(TIM3,900);
	TIM_SetCompare3(TIM3,900);
	TIM_SetCompare4(TIM3,600);
}

void MotorLeft(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	GPIO_SetBits(GPIOA,GPIO_Pin_10);
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	GPIO_ResetBits(GPIOB,GPIO_Pin_2);
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	
	TIM_SetCompare1(TIM3,600);
	TIM_SetCompare2(TIM3,900);
	TIM_SetCompare3(TIM3,600);
	TIM_SetCompare4(TIM3,900);
}

void Left(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_4);
	GPIO_SetBits(GPIOA,GPIO_Pin_5);//1号后退
	GPIO_SetBits(GPIOA,GPIO_Pin_10);
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);//2号前进
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	GPIO_ResetBits(GPIOB,GPIO_Pin_2);//3号前进
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	GPIO_SetBits(GPIOB,GPIO_Pin_5);//4号后退
	
	TIM_SetCompare1(TIM3,600);
	TIM_SetCompare2(TIM3,600);
	TIM_SetCompare3(TIM3,600);
	TIM_SetCompare4(TIM3,600);
}


void Right(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);//1号
	GPIO_ResetBits(GPIOA,GPIO_Pin_10);
	GPIO_SetBits(GPIOA,GPIO_Pin_11);//2号
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	GPIO_SetBits(GPIOB,GPIO_Pin_2);//3号
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);//4号
	
	TIM_SetCompare1(TIM3,600);
	TIM_SetCompare2(TIM3,600);
	TIM_SetCompare3(TIM3,600);
	TIM_SetCompare4(TIM3,600);
}

void LeftForward(void)
{
  GPIO_SetBits(GPIOA,GPIO_Pin_4);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	GPIO_SetBits(GPIOA,GPIO_Pin_10);
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	GPIO_ResetBits(GPIOB,GPIO_Pin_2);
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	
	TIM_SetCompare1(TIM3,0);
	TIM_SetCompare2(TIM3,600);
	TIM_SetCompare3(TIM3,600);
	TIM_SetCompare4(TIM3,0);
}

void RightForward(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	GPIO_SetBits(GPIOA,GPIO_Pin_10);
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	GPIO_ResetBits(GPIOB,GPIO_Pin_2);
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	
	TIM_SetCompare1(TIM3,600);
	TIM_SetCompare2(TIM3,0);
	TIM_SetCompare3(TIM3,0);
	TIM_SetCompare4(TIM3,600);
}

void Circuit(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	GPIO_SetBits(GPIOA,GPIO_Pin_10);
	GPIO_ResetBits(GPIOA,GPIO_Pin_11);
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	GPIO_SetBits(GPIOB,GPIO_Pin_2);
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	
	TIM_SetCompare1(TIM3,600);
	TIM_SetCompare2(TIM3,600);
	TIM_SetCompare3(TIM3,600);
	TIM_SetCompare4(TIM3,600);
}

void GPIO_Toggle_INIT( void )
{
   GPIO_InitTypeDef  GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE );
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_10|GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( GPIOA, &GPIO_InitStructure );
	 
	  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE );
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_2|GPIO_Pin_13|GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( GPIOB, &GPIO_InitStructure );
		

		
}
