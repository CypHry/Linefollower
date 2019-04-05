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

typedef enum
{
	FOLLOW_LINE,
	STOP
} LF_MODE;

typedef enum
{
	LF_OK,
	LF_ERROR
} LF_STATUS;

typedef struct
{
	LF_MODE mode;
	uint32_t pulse_L;
	uint32_t pulse_R;
} LF;

void LF_Init(LF* lf);
LF_STATUS LF_StartFollowing(LF* lf);
void LF_Stop(LF* lf);
LF_STATUS LF_SetPWMPulse(LF* lf, PD_CONTROLLER pd);

#endif /* __LINEFOLLOWER_h */
