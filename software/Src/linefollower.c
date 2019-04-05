/*
 * linefollower.c
 *
 *  Created on: 5 Apr 2019
 *      Author: cyprian
 */

#include "linefollower.h"

void LF_Init(LF* lf)
{
	lf->mode = STOP;
	lf->pulse_L = 0;
	lf->pulse_R = 0;
}

LF_STATUS LF_SetPWMPulse(LF* lf, PD_CONTROLLER pd)
{
	if(lf->mode == STOP)
		return LF_ERROR;
	lf->pulse_L = BASE_PWM_PULSE + pd.error_value;
	lf->pulse_R = BASE_PWM_PULSE - pd.error_value;

	return LF_OK;
}

LF_STATUS LF_StartFollowing(LF* lf, uint32_t sensors_tab)
{
	if(sensors_tab != SENSORS_NO_LINE)
	{
		lf->mode = FOLLOW_LINE;
		return LF_OK;
	}
	return LF_ERROR;
}

void LF_Stop(LF* lf)
{
	lf->mode = STOP;
	lf->pulse_L = 0;
	lf->pulse_R = 0;
}
