#include <REGX52.H>
#include "Delay.h"
//共阳不带小数点0-F段码为：
unsigned char Digital_tube[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};


void nixie1(unsigned char location,unsigned char  number) {
	switch (location) {
		case 11:
			P1_5 = 0;
			P1_4 = 1;
			P1_6 = 0;
			P1_7 = 0;
			break;
		case 12:
			P1_5 = 1;
			P1_4 = 0;
			P1_6 = 0;
			P1_7 = 0;			
			break;
			
		case 21:
			P1_4 = 0;
			P1_5 = 0;
			P1_6 = 0;
			P1_7 = 1;
			break;
		case 22:
			P1_4 = 0;
			P1_5 = 0;
			P1_6 = 1;
			P1_7 = 0;	
			break;	
	}
	P0 = Digital_tube[number];
	Delay(1);
	P0=0xff;
}

void Twonixie1(unsigned char  number){
	nixie1(11,number%10);
	nixie1(12,number/10);
}

//void nixie2(unsigned char location,unsigned char  number) {
//	switch (location) {
//		case 1:
//			P3_6 = 0;
//			P3_7 = 1;
//			break;
//		case 2:
//			P3_6 = 1;
//			P3_7 = 0;	
//			break;	
//	}
//	P0 = Digital_tube[number];
//	Delay(1);
//	P1=0xff;
//}

void Twonixie2(unsigned char  number){
	nixie1(21,number%10);
	nixie1(22,number/10);
}
