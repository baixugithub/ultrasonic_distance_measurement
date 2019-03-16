#ifndef _ultrasonic_H
#define _ultrasonic_H
#include"sys.h"



//------------------------------------------------------------ÒÆÖ²ÐÞ¸ÄÇø-----------------------------------------------------------------------

#define ULTRA_PORT	GPIOA
#define ULTRA_CLK       RCC_APB2Periph_GPIOA
#define ULTRA_TRIG			GPIO_Pin_6
#define ULTRA_ECHO			GPIO_Pin_7

#define TRIG_Send  PAout(6)
#define ECHO_Reci  PAin(7)


//---------------------------------------------------------------------------------------------------------------------------------------------
void Ultran_Init(void);
void Ultra_Ranging(float *p);




#endif

