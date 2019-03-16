#include "stm32f10x.h"
#include "ultrasonic.h"
#include"delay.h"

/********************************************************************************************************************************************
@f_name: void Ultran_Init(void)
@brief:	 超声波硬件模块初始化
@param:	 None
@return: None
*********************************************************************************************************************************************/
void Ultran_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(ULTRA_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Pin =ULTRA_TRIG;       //发送电平引脚
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
 	GPIO_Init(ULTRA_PORT, &GPIO_InitStructure);
	GPIO_ResetBits(ULTRA_PORT,ULTRA_TRIG);

	GPIO_InitStructure.GPIO_Pin =ULTRA_ECHO;		//返回电平引脚
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
 	GPIO_Init(ULTRA_PORT, &GPIO_InitStructure);	
}
/********************************************************************************************************************************************
@f_name: void Ranging(void)
@brief:	 超声波测距，均值5次，实际 测量过程发现测量静态的比较稳定，动态的不稳定，3米范围内比较稳定
@param:	 float *p:测距缓存变量
@return: None
*********************************************************************************************************************************************/
void Ultra_Ranging(float *p)
{
	u8 i;
	u32 j;
	float Ultr_Temp;	
	for(i=0;i<8;i++)
	{
		TRIG_Send=1;
		delay_ms(10);//超声波启动时间理论10us，下次试试2017年10月1日21:28:54
		TRIG_Send=0;
		//ECHO_Reci=0一直等待信号返回,ECHO_Reci=1有信号返回
		while(!ECHO_Reci);
		//算高电平持续时间[高电平持续的时间就是超声波发射到返回的时间]
		while(ECHO_Reci)
		{
			delay_us(5);
			j++;
		}
		Ultr_Temp += 340/2*j*10;//模块最大可测距3m (后面*10可去掉)
		j=0;
		delay_ms(10);//防止发射信号对回响信号的影响
	}
	*p=Ultr_Temp/8/1000000; //取平均值计算距离单位:米	
}
/*	u8 i;
	u32 j;
	float Ultr_Temp;	
	for(i=0;i<10;i++)
	{
		TRIG_Send=1;
		delay_ms(10);
		TRIG_Send=0;
		while(!ECHO_Reci);
		while(ECHO_Reci)
		{
			delay_us(5);
			j++;
		}
		Ultr_Temp += 340/2*j*10;//  模块最大可测距3m 
		j=0;
		delay_ms(10);//防止发射信号对回响信号的影响
	}
	*p=Ultr_Temp/10/1000000; //	
*/
