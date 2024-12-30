#include "LED.h"
#include "Nixie.h"
#include "Delay.h"

extern unsigned char Num;
unsigned char Yellow_Time=3;

void Countdown(unsigned char Green_Time1,unsigned char Green_Time2){
	
	if(Num<Green_Time1)
	{
		//1方向的绿灯
		Twonixie1(Green_Time1-Num);
				
		Twonixie2(Green_Time1+Yellow_Time-Num);//2红灯
	}
	else if(Num>=Green_Time1&&Num<(Green_Time1+Yellow_Time))
	{
		//1方向的黄灯变为红灯		
		Twonixie1((Green_Time1+Yellow_Time)-Num);//1黄灯
		//2方向的红灯变为绿灯
		Twonixie2(Green_Time1+Yellow_Time-Num);//2红灯
		
	}
	if(Num>=(Green_Time1+Yellow_Time)&&Num<(Green_Time2+Green_Time1+Yellow_Time))
	{
		Twonixie1((Green_Time1+Yellow_Time+Green_Time2+Yellow_Time)-Num);//1红灯
		Twonixie2((Green_Time2+Yellow_Time+Green_Time1)-Num);//2绿灯
			
	}
	if(Num>=(Green_Time1+Yellow_Time+Green_Time2)&&Num<(Green_Time1+Yellow_Time*2+Green_Time2))
	{
		//2方向的绿灯变为红灯
		
		//1方向的红灯变为绿灯
		Twonixie1((Green_Time1+Yellow_Time*2+Green_Time2)-Num);//1红灯
		
		Twonixie2((Green_Time1+Yellow_Time*2+Green_Time2)-Num);//2黄灯
		
	}
}



void DayMode(unsigned char Green_Time1,unsigned char Green_Time2){

	if((Num-1)==0){
		//初始化1方向为绿灯，2方向为红灯
		Green1_ON();
		Green2_OFF();
		Red2_ON();
		Red1_OFF();
		
		Yellow1_OFF();
		Yellow2_OFF();

	}

	if(Green_Time1<=Num&&Num<= (Green_Time1+Yellow_Time)){
		//1方向的绿灯变为黄灯
		Green1_OFF();
		Yellow1_Flash();
	}
	
	if(Num==(Green_Time1+Yellow_Time))
	{
		//1方向的黄灯变为红灯
		Yellow1_OFF();
		Red1_ON();
		//2方向的红灯变为绿灯
		Red2_OFF();
		Green2_ON();
		
	}
	
	if((Green_Time1+Yellow_Time+Green_Time2)<=Num&&Num<= (Green_Time1+Yellow_Time+Green_Time2+Yellow_Time)){
		
		//2方向的绿灯变为黄灯
		Green2_OFF();
		Yellow2_Flash();
	}
	
	if(Num==(Green_Time1+Yellow_Time+Green_Time2+Yellow_Time))
	{		
		Num =0;
	}
}


void NightMode(void){
	Num=0;
	Red1_OFF();
	Red2_OFF();
	Green1_OFF();
	Green2_OFF();
	Yellow2_Flash();
	Yellow1_Flash();
}

// 1方向常绿
void Long_Green1(void){
	Num=0;
	Green1_ON();
	Red2_ON();	
	
	Red1_OFF();
	Green2_OFF();
	Yellow2_OFF();
	Yellow1_OFF();
}

// 2方向常绿
void Long_Green2(void){
	Num=0;
	Green2_ON();
	Red1_ON();	
	
	Red2_OFF();
	Green1_OFF();
	Yellow2_OFF();
	Yellow1_OFF();
}



