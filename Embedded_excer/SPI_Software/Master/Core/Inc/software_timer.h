/*
 * software_timer.h
 *
 *  Created on: Jul 26, 2023
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag1;
extern int timer_flag2;
extern int timer_flag3;

void TimerRun();
void SetTimer1(int duration);
void SetTimer2(int duration);
void SetTimer3(int duration);


#endif /* INC_SOFTWARE_TIMER_H_ */
