#include <REGX52.H>
#include "Delay.h"
#include "Timer.h"
#include "TrafficLights.h"
#include "Nixie.h"
#include "Key.h"
#include "LED.h"

unsigned char Green_Time1=30,Green_Time2=30;
 

unsigned char count=0,Num=0,ldelay=0,choseMode=0;
unsigned char ModeChose =1,qiehuan=0;



void main(){
	
	TimerInit();

	while(1){

		
		if(P3_7==0){Delay(20);while(P3_7==0);Delay(20);qiehuan=!qiehuan;ldelay=1;}
		if(ldelay==1){
			Num=0;

			if(qiehuan==0){
				
				Twonixie1(Green_Time1);
				Twonixie2(Green_Time1+3);
				
				Green1_ON();
				Red2_ON();
				
				Green2_OFF();
				Red1_OFF();
				Yellow1_OFF();
				Yellow2_OFF();
				
				
			}	

			if(qiehuan==1){
				
				Twonixie1(Green_Time2+3);
				Twonixie2(Green_Time2);
				
				Green2_ON();
				Red1_ON();
				
				Green1_OFF();
				Red2_OFF();
				Yellow1_OFF();
				Yellow2_OFF();
				
				
			}
				
		}
		else if(ldelay==0){
			Countdown(Green_Time1,Green_Time2);
		}		
	}	
}


timer () interrupt 1{
	ModeChose=Key();
	count++;
	if(count==20)
	{
		count=0;
		Num++;	
		
	}
	switch(ModeChose){
		case 1:
			DayMode(Green_Time1,Green_Time2);
			break;
		case 0:NightMode();
			break;
		case 2:Long_Green1();
			break;
		case 3:Long_Green2();
			break;
	}

	TH0=15536/256;
	TL0=15536%256;
}


Green_time333() interrupt 0{	
	if(P3_2==0){
		if(qiehuan==0){
			Green_Time1++;	
		}
		if(qiehuan==1){
			Green_Time2++;	
		}
	}	
}


Green_time222() interrupt 2{	
	if(P3_3==0){
		if(qiehuan==0){
			Green_Time1--;	
		}
		if(qiehuan==1){
			Green_Time2--;	
		}		
	}	
}
