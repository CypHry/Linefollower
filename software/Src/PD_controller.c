/*
 * PD_controller.c
 *
 *  Created on: 3 Apr 2019
 *      Author: cyprian
 */

#include "PD_controller.h"

PD_ERROR_TYPE current_error;

PD_STATUS PD_SetError(uint8_t* sensors_tab)
{
	if(*sensors_tab == SENSORS_TAB_L4)	// sensors: 1 0 0 0 0
		current_error = ERROR_l4;
	else if(*sensors_tab == SENSORS_TAB_L3)	// sensors: 1 1 0 0 0
		current_error = ERROR_l3;
	else if(*sensors_tab == SENSORS_TAB_L2)	// sensors: 0 1 0 0 0
		current_error = ERROR_l2;
	else if(*sensors_tab == SENSORS_TAB_L1)	// sensors: 0 1 1 0 0
			current_error = ERROR_l1;
	else if(*sensors_tab == SENSORS_TAB_0)	// sensors: 0 0 1 0 0
			current_error = ERROR_0;
	else if(*sensors_tab == SENSORS_TAB_R1)	// sensors: 0 0 1 1 0
			current_error = ERROR_r1;
	else if(*sensors_tab == SENSORS_TAB_R2)	// sensors: 0 0 0 1 0
			current_error = ERROR_r2;
	else if(*sensors_tab == SENSORS_TAB_R3)	// sensors: 0 0 0 1 1
			current_error = ERROR_r3;
	else if(*sensors_tab == SENSORS_TAB_R4)	// sensors: 0 0 0 0 1
			current_error = ERROR_r4;
	else
		return PD_ERROR;

	return PD_OK;
}
