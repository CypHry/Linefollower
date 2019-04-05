#ifndef __PD_CONTROLLER_H
#define __PD_CONTROLLER_H

#include "stdint.h"

#define SENSORS_TAB_L4 		0x10 // 00010000
#define SENSORS_TAB_L3 		0x18 // 00011000
#define SENSORS_TAB_L2 		0x08 // 00001000
#define SENSORS_TAB_L1 		0x0C // 00001100
#define SENSORS_TAB_0 		0x04 // 00000100
#define SENSORS_TAB_R1 		0x06 // 00000110
#define SENSORS_TAB_R2 		0x02 // 00000010
#define SENSORS_TAB_R3 		0x03 // 00000011
#define SENSORS_TAB_R4 		0x01 // 00000001
#define SENSORS_NO_LINE   	0x00 // 00000000
#define SENSORS_LINE		0x1F // 00011111


#define Kp					200.0 // tbc
#define Kd  				0.0   // tbc

#define BASE_PWM_PULSE 		0x7530// 30000 max: 0xFFFF


typedef enum
{
	PD_OK,
	PD_ERROR
} PD_STATUS;

typedef enum
{
	ERROR_L4 = -4, 	// sensors: 1 0 0 0 0
	ERROR_L3 = -3, 	// sensors: 1 1 0 0 0
	ERROR_L2 = -2, 	// sensors: 0 1 0 0 0
	ERROR_L1 = -1, 	// sensors: 0 1 1 0 0
	ERROR_0  =  0, 	// sensors: 0 0 1 0 0
	ERROR_R1 =  1, 	// sensors: 0 0 1 1 0
	ERROR_R2 =  2, 	// sensors: 0 0 0 1 0
	ERROR_R3 =  3,  // sensors: 0 0 0 1 1
	ERROR_R4 =  4 	// sensors: 0 0 0 0 1
} PD_ERROR_TYPE;

typedef struct
{
	PD_ERROR_TYPE current_error;
	PD_ERROR_TYPE previous_error;
	uint32_t error_value;
} PD_CONTROLLER;

void PD_Init(PD_CONTROLLER* pd);
PD_STATUS PD_SetError(PD_CONTROLLER* pd, uint8_t* sensors_tab);
void PD_CallculateErrorValue(PD_CONTROLLER* pd);


#endif //__PD_CONTROLLER_H
