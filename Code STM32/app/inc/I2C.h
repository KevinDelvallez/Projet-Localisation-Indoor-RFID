/*
 * I2C.h
 *
 *  Created on: 28 janv. 2021
 *      Author: ayoub
 */

#ifndef APP_INC_I2C_H_
#define APP_INC_I2C_H_
#include "main.h"
uint8_t	BSP_I2C1_Read( uint8_t device_address,
                       uint8_t register_address,
                       uint8_t *buffer,
                       uint8_t nbytes );

uint8_t	BSP_I2C1_Write( uint8_t device_address,
                        uint8_t register_address,
                        uint8_t buffer, uint8_t nbytes );
uint8_t wait_for_flags();
void BSP_I2C1_Init();
void BSP_I2C2_Init();
#endif /* APP_INC_I2C_H_ */
