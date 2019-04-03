#ifndef __PD_CONTROLLER_H
#define __PD_CONTROLLER_H

#include "stdint.h"

#define SENSORS_TAB_L4 	0x10 // 00010000
#define SENSORS_TAB_L3 	0x18 // 00011000
#define SENSORS_TAB_L2 	0x08 // 00001000
#define SENSORS_TAB_L1 	0x0C // 00001100
#define SENSORS_TAB_0 	0x04 // 00000100
#define SENSORS_TAB_R1 	0x06 // 00000110
#define SENSORS_TAB_R2 	0x02 // 00000010
#define SENSORS_TAB_R3 	0x03 // 00000011
#define SENSORS_TAB_R4 	0x01 // 00000001


typedef enum
{
	PD_OK,
	PD_ERROR
} PD_STATUS;

typedef enum
{
	ERROR_l4, 	// sensors: 1 0 0 0 0
	ERROR_l3, 	// sensors: 1 1 0 0 0
	ERROR_l2, 	// sensors: 0 1 0 0 0
	ERROR_l1, 	// sensors: 0 1 1 0 0
	ERROR_0, 	// sensors: 0 0 1 0 0
	ERROR_r1, 	// sensors: 0 0 1 1 0
	ERROR_r2, 	// sensors: 0 0 0 1 0
	ERROR_r3,  	// sensors: 0 0 0 1 1
	ERROR_r4 	// sensors: 0 0 0 0 1
} PD_ERROR_TYPE; // not sure i need that yet

PD_STATUS PD_SetError(uint8_t* sensors_tab); // not sure i need that yet

#endif //__PD_CONTROLLER_H
