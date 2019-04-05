/*
 * linefollower.h
 *
 *  Created on: 5 Apr 2019
 *      Author: cyprian
 */

#ifndef __LINEFOLLOWER_H
#define __LINEFOLLOWER_H

#include "PD_controller.h"

#define BASE_PWM_PULSE 		0x7530// 30000 max: 0xFFFF

typedef struct
{
	uint32_t pulse_L;
	uint32_t pulse_R;
} LF;

void LF_Init(LF* lf);
void LF_Stop(LF* lf);
void LF_SetPWMPulse(LF* lf, PD_CONTROLLER pd);

#endif /* __LINEFOLLOWER_h */
