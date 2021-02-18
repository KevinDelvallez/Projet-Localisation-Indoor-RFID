/*
 * MPU9250.c
 *
 *  Created on: 28 janv. 2021
 *      Author: ayoub
 */
#include "MPU9250.h"


void BSP_MPU9250_Init()
{
	// MPU9250 Basic init

	BSP_I2C1_Write(MPU9250_ADDRESS,MPUREG_PWR_MGMT_1,0x00,6);			// Reset Device
	delay_ms(1);
	BSP_I2C1_Write(MPU9250_ADDRESS,MPUREG_USER_CTRL, I2C_IF_DIS, 6);			// Disable I2C slave mode
	delay_ms(1);
	BSP_I2C1_Write(MPU9250_ADDRESS,MPUREG_PWR_MGMT_1, BIT_CLKSEL_AUTO, 6);		// Auto-select clock source
	delay_ms(1);
	BSP_I2C1_Write(MPU9250_ADDRESS,MPUREG_PWR_MGMT_2, BITS_ALL_ON, 6);			// Enable all Acc & Gyro sensors
	delay_ms(1);

	// Setup Low-pass filters for Gyros and Temperature sensor
	BSP_I2C1_Write(MPU9250_ADDRESS,MPUREG_CONFIG, BITS_DLPF_CFG_3, 6);			// DLPF_CFG is set to 0 (41Hz Gyros, 42Hz Temp)
	delay_ms(1);

	// Setup Full Scales & filters
	BSP_I2C1_Write(MPU9250_ADDRESS,MPUREG_GYRO_CONFIG, BITS_FS_500DPS, 6);		// Set Gyro to +-500dps and use DLPF as above
	delay_ms(1);
	BSP_I2C1_Write(MPU9250_ADDRESS,MPUREG_ACCEL_CONFIG, BITS_FS_2G, 6);			// Set Accl to +-2G
	delay_ms(1);
	BSP_I2C1_Write(MPU9250_ADDRESS,MPUREG_ACCEL_CONFIG_2, BITS_DLPF_CFG_3, 6);	// Set Accl datarate to 1kHz, enable LPF, BW 41Hz
	delay_ms(1);

	// Setup Interrupts
	BSP_I2C1_Write(MPU9250_ADDRESS,MPUREG_SMPLRT_DIV, 9, 6);						// Sample rate is 100Hz (10ms)
	delay_ms(1);
	BSP_I2C1_Write(MPU9250_ADDRESS,MPUREG_INT_ENABLE, BIT_INT_RAW_RDY_EN, 6);	// Setup interrupt when raw data is ready
	delay_ms(1);

	// Setup for Magnetometer

	BSP_I2C1_Write(AK8963_ADDRESS,MPUREG_USER_CTRL, 0x02, 6);					// I2C Master Reset
	delay_ms(1);
	BSP_I2C1_Write(AK8963_ADDRESS,MPUREG_USER_CTRL, 0x20, 6);					// I2C Master Mode Enable
	delay_ms(1);

	BSP_I2C1_Write(AK8963_ADDRESS,MPUREG_I2C_MST_CTRL, 0x0D, 6);				// I2C Master at 400KHz
	delay_ms(1);

	BSP_I2C1_Write(AK8963_ADDRESS,MPUREG_I2C_SLV0_ADDR, AK8963_I2C_ADDR, 6);	// Set Slave0 address to AK8963 adress
	delay_ms(1);

	BSP_I2C1_Write(AK8963_ADDRESS,MPUREG_I2C_SLV0_REG, AK8963_CNTL2, 6);		// I2C slave 0 register address from where to begin data transfer
	delay_ms(1);
	BSP_I2C1_Write(AK8963_ADDRESS,MPUREG_I2C_SLV0_DO, 0x01, 6);					// Reset AK8963
	delay_ms(1);
	BSP_I2C1_Write(AK8963_ADDRESS,MPUREG_I2C_SLV0_CTRL, 0x81, 6);				// Enable I2C and set 1 byte
	delay_ms(1);

	BSP_I2C1_Write(AK8963_ADDRESS,MPUREG_I2C_SLV0_REG, AK8963_CNTL1, 6);		// I2C slave 0 register address from where to begin data transfer
	delay_ms(1);
	BSP_I2C1_Write(AK8963_ADDRESS,MPUREG_I2C_SLV0_DO, 0x12,6);					// Register value to continuous measurement in 16bit
	delay_ms(1);
	BSP_I2C1_Write(AK8963_ADDRESS,MPUREG_I2C_SLV0_CTRL, 0x81,6);				// Enable I2C and set 1 byte
	delay_ms(1);

	// Continuously read 7 bytes from Magnetometers
	BSP_I2C1_Write(AK8963_ADDRESS,MPUREG_I2C_SLV0_ADDR, AK8963_I2C_ADDR|READ_FLAG, 6);
	delay_ms(1);
	BSP_I2C1_Write(AK8963_ADDRESS,MPUREG_I2C_SLV0_REG,  AK8963_HXL, 6);
	delay_ms(1);
	BSP_I2C1_Write(AK8963_ADDRESS,MPUREG_I2C_SLV0_CTRL,  0x87, 6);
	delay_ms(1);
}




