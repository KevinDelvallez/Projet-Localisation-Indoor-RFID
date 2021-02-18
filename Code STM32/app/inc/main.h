

#include "delay.h"
#include "bsp.h"
#include "stm32f0xx_it.h"
#include "stm32f0xx.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "queue.h"
#include "event_groups.h"
#include "stream_buffer.h"
#include "MPU9250.h"
#include "SPI.h"
#include "I2C.h"
#ifndef APP_INC_MAIN_H_
#define APP_INC_MAIN_H_

/*
 * printf() and sprintf() from printf-stdarg.c
 */

int my_printf	(const char *format, ...);
int my_sprintf	(char *out, const char *format, ...);
int16_t		raw_ax, raw_ay, raw_az;
int16_t		raw_gx, raw_gy, raw_gz;
int16_t		raw_mx, raw_my, raw_mz;

int16_t		imu_temp;

float		imu_ax, imu_ay, imu_az;
float 		imu_gx, imu_gy, imu_gz;
float 		imu_mx, imu_my, imu_mz;
float		imu_ax_si, imu_ay_si, imu_az_si;

#endif /* APP_INC_MAIN_H_ */
