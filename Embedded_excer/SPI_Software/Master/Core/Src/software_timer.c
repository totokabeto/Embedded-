/*
 * software_timer.c
 *
 *  Created on: Jul 26, 2023
 *      Author: Admin
 */

#include "software_timer.h"
int timer_counter1 = 0;
int timer_counter2 = 0;
int timer_counter3 = 0;

int timer_flag1 = 0;
int timer_flag2 = 0;
int timer_flag3 = 0;

void SetTimer1(int duration){
	timer_counter1 = duration;
	timer_flag1 = 0;
	}
void SetTimer2(int duration){
	timer_counter2 = duration;
	timer_flag2 = 0;
	}
void TimerRun(){
	if(timer_counter1){
		timer_counter1--;
	}
	if(timer_counter1 <= 0 ){
		timer_flag1 = 1;
	}
	if(timer_counter2){
		timer_counter2--;
		}
	if(timer_counter2 <= 0 ){
		timer_flag2 = 1;
		}
	if(timer_counter3){
		timer_counter3--;
	}
	if(timer_counter3 <= 0){
		timer_flag3 = 1;
	}
}
