//#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "ultrasonic.h"
#include "stdio.h"

 int main(void)
 { 
	u8 lcd_id[12];			//���LCD ID�ַ���	
	float temp;
	u8 DisNum[16];
	delay_init(72);	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
 	Ultran_Init();
	LCD_Init();
	POINT_COLOR=RED; 
 	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//��LCD ID��ӡ��lcd_id���顣				 	
	LCD_ShowString(30,10,200,16,16,lcd_id);		//��ʾLCD ID	      					 
while(1)
{

 	Ultra_Ranging(&temp);

	sprintf(DisNum,"Distance(m): %1.3f   ",temp); // 

	LCD_ShowString(30,40,200,16,16,DisNum);	
//	LCD_ShowString(40,40,200,16,16,"m");		//��ʾLCD ��λ	      					 
	delay_ms(500);			


}

}









//int main()
//{
////	float temp;
////	char DisNum[16];
////	SystemInit();
//	delay_init(72);
////	LCD5110_GPIOInit();
//	Ultran_Init();
//    LCD_Init();				//��ʼ��LCD
// 	POINT_COLOR=RED;
//	LCD_ShowString(30,20,200,16,16,"ALIENTEK STM32 ^_^");	
//	LCD_ShowString(30,40,200,16,16,"NE0-6M GPS TEST");	
//	LCD_ShowString(30,60,200,16,16,"ATOM@ALIENTEK");
//	LCD_ShowString(30,80,200,16,16,"KEY0:Upload NMEA Data SW");   	 										   	   
//   	LCD_ShowString(30,100,200,16,16,"NMEA Data Upload:OFF");   
//	while(1)
//	{
////		 u8 x=0;
//		u8 lcd_id[12];			//���LCD ID�ַ���	
//		delay_init(72);	    	 //��ʱ������ʼ��	  
////		uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
////		LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
//	 	LCD_Init();
//		POINT_COLOR=RED; 
//		sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//��LCD ID��ӡ��lcd_id����
////	   	LCD_ShowString(30,120,200,16,16,"NEO-6M Set Done!!");
////			Ultra_Ranging(&temp);
//////	 	LCD_ShowString(30,250,200,16,16,dtbuf);		 
//////		sprintf((char *)dtbuf,"UTC Date:%04d/%02d/%02d   ",gpsx.utc.year,gpsx.utc.month,gpsx.utc.date);	//��ʾUTC����
////
////			LCD_ShowString(30,40,200,24,24,(u8 *)DisNum);	
////			sprintf(DisNum,"Baixu _%1.4f",temp);
////
//////			LCD5110WriteEnStr(0,0,(u8 *)DisNum);			
////			delay_ms(500);			
//	}
//
//}
//
//
//
//
