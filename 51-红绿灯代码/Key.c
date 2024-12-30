#include <REGX52.H>
#include "Delay.h"
#include "LED.h"
#include "Nixie.h"

/*
 * @brief（简介）		获取独立按键键码
 * @param（参数）		无
 * @retval（返回值）	按下的按键键码，范围1~4，无按键按下时返回值为零
 */


extern unsigned char ModeChose;

unsigned char Key()
{
	
	if(P1_0==0){Delay(20);while(P1_0==0);Delay(20);ModeChose=2;}
	if(P1_1==0){Delay(20);while(P1_1==0);Delay(20);ModeChose=3;}
//	if(P1_2==0){Delay(20);while(P1_2==0);Delay(20);ModeChose=4;}
//	if(P1_3==0){Delay(20);while(P1_3==0);Delay(20);ModeChose=5;}
//	if(P3_7==0){Delay(20);while(P3_7==0);Delay(20);ModeChose=4;}
	return ModeChose;
}



//void Time_Adjust(unsigned char *green_Time1,unsigned char *green_Time2,unsigned char qiehuan){
//					
//	if(qiehuan==0){
//		
//		Twonixie1(*green_Time1);
//		Twonixie2(*green_Time1+3);
//		
//		Green1_ON();
//		Red2_ON();
//		
//		Green2_OFF();
//		Red1_OFF();
//		Yellow1_OFF();
//		Yellow2_OFF();
//		
//		if(P1_2==0){
//			Delay(20);while(P1_2==0);Delay(20);
//			*green_Time1--;
//		
//		}
//		if(P1_3==0){			
//			Delay(20);while(P1_3==0);Delay(20);
//			*green_Time1++;		
//		}
//	}	

//	if(qiehuan==1){
//		
//		Twonixie1(*green_Time2);
//		Twonixie2(*green_Time2+3);
//		
//		Green2_ON();
//		Red1_ON();
//		
//		Green1_OFF();
//		Red2_OFF();
//		Yellow1_OFF();
//		Yellow2_OFF();
//		
//		if(P1_2==0){
//		
//			Delay(20);while(P1_2==0);Delay(20);
//			*green_Time2--;
//		
//		}
//		if(P1_3==0){
//			
//			Delay(20);while(P1_3==0);Delay(20);
//			*green_Time2++;
//			
//		}
//	}
//				
//}

