#include "stm32f10x.h"
#include "ultrasonic.h"
#include"delay.h"

/********************************************************************************************************************************************
@f_name: void Ultran_Init(void)
@brief:	 ������Ӳ��ģ���ʼ��
@param:	 None
@return: None
*********************************************************************************************************************************************/
void Ultran_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
 	RCC_APB2PeriphClockCmd(ULTRA_CLK, ENABLE);

	GPIO_InitStructure.GPIO_Pin =ULTRA_TRIG;       //���͵�ƽ����
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//�������
 	GPIO_Init(ULTRA_PORT, &GPIO_InitStructure);
	GPIO_ResetBits(ULTRA_PORT,ULTRA_TRIG);

	GPIO_InitStructure.GPIO_Pin =ULTRA_ECHO;		//���ص�ƽ����
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
 	GPIO_Init(ULTRA_PORT, &GPIO_InitStructure);	
}
/********************************************************************************************************************************************
@f_name: void Ranging(void)
@brief:	 ��������࣬��ֵ5�Σ�ʵ�� �������̷��ֲ�����̬�ıȽ��ȶ�����̬�Ĳ��ȶ���3�׷�Χ�ڱȽ��ȶ�
@param:	 float *p:��໺�����
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
		delay_ms(10);//����������ʱ������10us���´�����2017��10��1��21:28:54
		TRIG_Send=0;
		//ECHO_Reci=0һֱ�ȴ��źŷ���,ECHO_Reci=1���źŷ���
		while(!ECHO_Reci);
		//��ߵ�ƽ����ʱ��[�ߵ�ƽ������ʱ����ǳ��������䵽���ص�ʱ��]
		while(ECHO_Reci)
		{
			delay_us(5);
			j++;
		}
		Ultr_Temp += 340/2*j*10;//ģ�����ɲ��3m (����*10��ȥ��)
		j=0;
		delay_ms(10);//��ֹ�����źŶԻ����źŵ�Ӱ��
	}
	*p=Ultr_Temp/8/1000000; //ȡƽ��ֵ������뵥λ:��	
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
		Ultr_Temp += 340/2*j*10;//  ģ�����ɲ��3m 
		j=0;
		delay_ms(10);//��ֹ�����źŶԻ����źŵ�Ӱ��
	}
	*p=Ultr_Temp/10/1000000; //	
*/
