/*
 * linefollower.c
 *
 *  Created on: 5 Apr 2019
 *      Author: cyprian
 */

#include "linefollower.h"

void LF_Init(LF* lf)
{
	//AIN1/2 BIN1/2?
	lf->pulse_L = 0;
	lf->pulse_R = 0;
}

void LF_SetPWMPulse(LF* lf, PD_CONTROLLER pd)
{
	lf->pulse_L = BASE_PWM_PULSE + pd.output_value;
	lf->pulse_R = BASE_PWM_PULSE - pd.output_value;
}


void LF_Stop(LF* lf)
{
	lf->pulse_L = 0;
	lf->pulse_R = 0;
}
