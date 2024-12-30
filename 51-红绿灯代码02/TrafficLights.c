#include "LED.h"
#include "Nixie.h"
#include "Delay.h"

extern unsigned char Num;
unsigned char Yellow_Time=3;

void Countdown(unsigned char Green_Time1,unsigned char Green_Time2){
	
	if(Num<Green_Time1)
	{
		//1������̵�
		Twonixie1(Green_Time1-Num);
				
		Twonixie2(Green_Time1+Yellow_Time-Num);//2���
	}
	else if(Num>=Green_Time1&&Num<(Green_Time1+Yellow_Time))
	{
		//1����ĻƵƱ�Ϊ���		
		Twonixie1((Green_Time1+Yellow_Time)-Num);//1�Ƶ�
		//2����ĺ�Ʊ�Ϊ�̵�
		Twonixie2(Green_Time1+Yellow_Time-Num);//2���
		
	}
	if(Num>=(Green_Time1+Yellow_Time)&&Num<(Green_Time2+Green_Time1+Yellow_Time))
	{
		Twonixie1((Green_Time1+Yellow_Time+Green_Time2+Yellow_Time)-Num);//1���
		Twonixie2((Green_Time2+Yellow_Time+Green_Time1)-Num);//2�̵�
			
	}
	if(Num>=(Green_Time1+Yellow_Time+Green_Time2)&&Num<(Green_Time1+Yellow_Time*2+Green_Time2))
	{
		//2������̵Ʊ�Ϊ���
		
		//1����ĺ�Ʊ�Ϊ�̵�
		Twonixie1((Green_Time1+Yellow_Time*2+Green_Time2)-Num);//1���
		
		Twonixie2((Green_Time1+Yellow_Time*2+Green_Time2)-Num);//2�Ƶ�
		
	}
}



void DayMode(unsigned char Green_Time1,unsigned char Green_Time2){

	if((Num-1)==0){
		//��ʼ��1����Ϊ�̵ƣ�2����Ϊ���
		Green1_ON();
		Green2_OFF();
		Red2_ON();
		Red1_OFF();
		
		Yellow1_OFF();
		Yellow2_OFF();

	}

	if(Green_Time1<=Num&&Num<= (Green_Time1+Yellow_Time)){
		//1������̵Ʊ�Ϊ�Ƶ�
		Green1_OFF();
		Yellow1_Flash();
	}
	
	if(Num==(Green_Time1+Yellow_Time))
	{
		//1����ĻƵƱ�Ϊ���
		Yellow1_OFF();
		Red1_ON();
		//2����ĺ�Ʊ�Ϊ�̵�
		Red2_OFF();
		Green2_ON();
		
	}
	
	if((Green_Time1+Yellow_Time+Green_Time2)<=Num&&Num<= (Green_Time1+Yellow_Time+Green_Time2+Yellow_Time)){
		
		//2������̵Ʊ�Ϊ�Ƶ�
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

// 1������
void Long_Green1(void){
	Num=0;
	Green1_ON();
	Red2_ON();	
	
	Red1_OFF();
	Green2_OFF();
	Yellow2_OFF();
	Yellow1_OFF();
}

// 2������
void Long_Green2(void){
	Num=0;
	Green2_ON();
	Red1_ON();	
	
	Red2_OFF();
	Green1_OFF();
	Yellow2_OFF();
	Yellow1_OFF();
}



