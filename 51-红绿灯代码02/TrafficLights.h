#ifndef __TRAFFIC_LIGHTS_H__
#define __TRAFFIC_LIGHTS_H__

void TrafficLightInit(void);
void NightMode(void);

void DayMode(unsigned char Green_Time1,unsigned char Green_Time2);

void Countdown(unsigned char Green_Time1,unsigned char Green_Time2);

void Long_Green1(void);
void Long_Green2(void);

void Time_Adjust1(void);
void Time_Adjust2(void);
#endif

