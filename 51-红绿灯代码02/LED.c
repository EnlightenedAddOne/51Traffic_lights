#include <REGX52.H>

extern unsigned char count;
/********************************************
 *
 *		   南北方向
 *
 ********************************************/
void Red1_ON(void){
	P2_0=0;
}
void Red1_OFF(void){
	P2_0=1;
}
void Red1_Turn(void){
	P2_0=~P2_0;
}
void Green1_ON(void){
	P2_1=0;
}
void Green1_OFF(void){
	P2_1=1;
}
void Green1_Turn(void){
	P2_1=~P2_1;
}
void Yellow1_ON(void){
	P2_2=0;
}
void Yellow1_OFF(void){
	P2_2=1;
}
void Yellow1_Turn(void){
	P2_2=~P2_2;
}
void Yellow1_Flash(void){
	if(count%5==0){
		Yellow1_Turn();
	}
}

/********************************************
 *
 *		   东西方向
 *
 ********************************************/

void Red2_ON(void){
	P2_3=0;
}
void Red2_OFF(void){
	P2_3=1;
}
void Red2_Turn(void){
	P2_3=~P2_3;
}
void Green2_ON(void){
	P2_4=0;
}
void Green2_OFF(void){
	P2_4=1;
}
void Green2_Turn(void){
	P2_4=~P2_4;
}
void Yellow2_ON(void){
	P2_5=0;
}
void Yellow2_OFF(void){
	P2_5=1;
}
void Yellow2_Turn(void){
	P2_5=~P2_5;
}
void Yellow2_Flash(void){
	if(count%5==0){
		Yellow2_Turn();
	}
}

