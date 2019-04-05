/*
 * PD_controller.c
 *
 *  Created on: 3 Apr 2019
 *      Author: cyprian
 */

#include "PD_controller.h"

void PD_Init(PD_CONTROLLER* pd)
{
	pd->current_error = ERROR_0;
	pd->previous_error = ERROR_0;
	pd->error_value = 0;
}

PD_STATUS PD_SetError(PD_CONTROLLER* pd, uint8_t* sensors_tab)
{
	pd->previous_error = pd->current_error;

	if(*sensors_tab == SENSORS_TAB_L4 || *sensors_tab == SENSORS_LINE)	// sensors: 1 0 0 0 0
		pd->current_error = ERROR_L4;
	else if(*sensors_tab == SENSORS_TAB_L3)	// sensors: 1 1 0 0 0
		pd->current_error = ERROR_L3;
	else if(*sensors_tab == SENSORS_TAB_L2)	// sensors: 0 1 0 0 0
		pd->current_error = ERROR_L2;
	else if(*sensors_tab == SENSORS_TAB_L1)	// sensors: 0 1 1 0 0
		pd->current_error = ERROR_L1;
	else if(*sensors_tab == SENSORS_TAB_0)	// sensors: 0 0 1 0 0
		pd->current_error = ERROR_0;
	else if(*sensors_tab == SENSORS_TAB_R1)	// sensors: 0 0 1 1 0
		pd->current_error = ERROR_R1;
	else if(*sensors_tab == SENSORS_TAB_R2)	// sensors: 0 0 0 1 0
		pd->current_error = ERROR_R2;
	else if(*sensors_tab == SENSORS_TAB_R3)	// sensors: 0 0 0 1 1
		pd->current_error = ERROR_R3;
	else if(*sensors_tab == SENSORS_TAB_R4)	// sensors: 0 0 0 0 1
		pd->current_error = ERROR_R4;
	else
		return PD_ERROR;

	return PD_OK;
}


void PD_CallculateErrorValue(PD_CONTROLLER* pd)
{
	uint32_t P = pd->current_error;
	uint32_t D = pd->current_error - pd->previous_error;

	pd->error_value = Kp*P + Kd*D;
}





