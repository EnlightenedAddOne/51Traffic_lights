#include <REGX52.H>

void TimerInit(void){
	TMOD=0x01;
	TH0=15536/256;
	TL0=15536%256;
	TR0=1;
	ET0=1;
	
	IT0=1;
	EX0=1;
	
	
//	TH1=15536/256;
//	TL1=15536%256;
//	TR1=1;
//	ET1=1;
	
	EA=1;	
}
