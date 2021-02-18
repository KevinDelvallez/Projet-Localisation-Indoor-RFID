/*
 * MPU9250.h
 *
 *  Created on: 28 janv. 2021
 *      Author: ayoub
 */

#ifndef APP_INC_MPU9250_H_
#define APP_INC_MPU9250_H_

#include "main.h"


// Public functions

void BSP_MPU9250_Init();

#define READ_FLAG 0x80
#define MPU9250_ADDRESS 0x68
#define AK8963_ADDRESS 0x0C
#define WHO_AM_I_MPU9250 0x75

// Registers 0 to 2 – Gyroscope Self-Test Registers (Reset value: 0x00)

#define MPUREG_XG_OFFS_TC 			0x00	// #0
#define MPUREG_YG_OFFS_TC 			0x01	// #1
#define MPUREG_ZG_OFFS_TC 			0x02	// #2


#define MPUREG_X_FINE_GAIN 			0x03
#define MPUREG_Y_FINE_GAIN 			0x04
#define MPUREG_Z_FINE_GAIN 			0x05

#define MPUREG_XA_OFFS_H 			0x06
#define MPUREG_XA_OFFS_L 			0x07
#define MPUREG_YA_OFFS_H 			0x08
#define MPUREG_YA_OFFS_L 			0x09
#define MPUREG_ZA_OFFS_H 			0x0A
#define MPUREG_ZA_OFFS_L 			0x0B

#define MPUREG_PRODUCT_ID 			0x0C

// Registers 13 to 15 – Accelerometer Self-Test Registers (Reset value: 0x00)

#define MPUREG_SELF_TEST_X 			0x0D	// #13
#define MPUREG_SELF_TEST_Y 			0x0E	// #14
#define MPUREG_SELF_TEST_Z 			0x0F	// #15


#define MPUREG_SELF_TEST_A 			0x10

// Registers 19 to 24 – Gyro Offset Registers (Reset value: 0x00)

#define MPUREG_XG_OFFS_USRH 		0x13	// #19
#define MPUREG_XG_OFFS_USRL 		0x14	// #20
#define MPUREG_YG_OFFS_USRH 		0x15	// #21
#define MPUREG_YG_OFFS_USRL 		0x16	// #22
#define MPUREG_ZG_OFFS_USRH 		0x17	// #23
#define MPUREG_ZG_OFFS_USRL 		0x18	// #24

// Register 25 – Sample Rate Divider (Reset value: 0x00)

#define MPUREG_SMPLRT_DIV 			0x19	// #25

// Register 26 – Configuration -> FIFO_MODE, EXT_FSYNC_SET, DLPF_CFG

#define MPUREG_CONFIG 				0x1A	// #26

#define BITS_DLPF_CFG_0  			0x00
#define BITS_DLPF_CFG_1         	0x01
#define BITS_DLPF_CFG_2          	0x02
#define BITS_DLPF_CFG_3          	0x03
#define BITS_DLPF_CFG_4         	0x04
#define BITS_DLPF_CFG_5          	0x05
#define BITS_DLPF_CFG_6           	0x06
#define BITS_DLPF_CFG_7 			0x07

// Register 27 – Gyroscope Configuration (Reset value: 0x00)

#define MPUREG_GYRO_CONFIG 			0x1B	// #27

#define BITS_FS_250DPS              0x00
#define BITS_FS_500DPS              0x08
#define BITS_FS_1000DPS             0x10
#define BITS_FS_2000DPS             0x18

#define BITS_GYRO_NODLP				0x03

// Register 28-29 - Accelerometer Configuration

#define MPUREG_ACCEL_CONFIG 		0x1C	// #28

#define BITS_FS_2G                  0x00
#define BITS_FS_4G                  0x08
#define BITS_FS_8G                  0x10
#define BITS_FS_16G                 0x18
#define BITS_FS_MASK                0x18

#define MPUREG_ACCEL_CONFIG_2      	0x1D	// #29

#define BIT_ACCL_NODLP				0x08

// Register 30 – Low Power Accelerometer ODR Control

#define MPUREG_LP_ACCEL_ODR        	0x1E	// #30

// Register 31 – Wake-on Motion Threshold

#define MPUREG_MOT_THR             	0x1F	// #31

// Register 35 – FIFO Enable (Reset value: 0x00)

#define MPUREG_FIFO_EN             	0x23	// #35

#define BITS_FIFO_TEMP				0x80
#define BITS_FIFO_XYZGYRO			0x70
#define BITS_FIFO_XYZACCL			0x08
#define BITS_FIFO_SLV2				0x04
#define BITS_FIFO_SLV1				0x02
#define BITS_FIFO_SLV0				0x01

// Register 36 – I2C Master Control (Reset value: 0x00)

#define MPUREG_I2C_MST_CTRL        	0x24	// #36

// Registers 37 to 39 – I2C Slave 0 Control

#define MPUREG_I2C_SLV0_ADDR       	0x25	// #37
#define MPUREG_I2C_SLV0_REG        	0x26	// #38
#define MPUREG_I2C_SLV0_CTRL       	0x27	// #39

// Registers 40 to 42 – I2C Slave 1 Control

#define MPUREG_I2C_SLV1_ADDR       	0x28	// #40
#define MPUREG_I2C_SLV1_REG        	0x29	// #41
#define MPUREG_I2C_SLV1_CTRL       	0x2A	// #42

// Registers 43 to 45 – I2C Slave 2 Control

#define MPUREG_I2C_SLV2_ADDR       	0x2B	// #43
#define MPUREG_I2C_SLV2_REG        	0x2C	// #44
#define MPUREG_I2C_SLV2_CTRL       	0x2D	// #45

// Registers 46 to 48 – I2C Slave 3 Control

#define MPUREG_I2C_SLV3_ADDR       	0x2E	// #46
#define MPUREG_I2C_SLV3_REG        	0x2F	// #47
#define MPUREG_I2C_SLV3_CTRL       	0x30	// #48

// Registers 49 to 53 – I2C Slave 4 Control

#define MPUREG_I2C_SLV4_ADDR       	0x31	// #49
#define MPUREG_I2C_SLV4_REG        	0x32	// #50
#define MPUREG_I2C_SLV4_DO         	0x33	// #51
#define MPUREG_I2C_SLV4_CTRL       	0x34	// #52
#define MPUREG_I2C_SLV4_DI         	0x35	// #53

// Register 54 – I2C Master Status ((Reset value: 0x00)

#define MPUREG_I2C_MST_STATUS      	0x36	// #54

// Register 55 – INT Pin / Bypass Enable Configuration

#define MPUREG_INT_PIN_CFG 			0x37	// #55

// Register 56 – Interrupt Enable

#define MPUREG_INT_ENABLE 			0x38	// #56

#define BIT_INT_FIFO_OVERFLOW_EN	0x10
#define BIT_INT_RAW_RDY_EN			0x01

// Register 58 – Interrupt Status

#define MPUREG_INT_STATUS			0x3A	// #58

// Registers 59 to 64 – Accelerometer Measurements

#define MPUREG_ACCEL_XOUT_H 		0x3B	// #59
#define MPUREG_ACCEL_XOUT_L 		0x3C	// #60
#define MPUREG_ACCEL_YOUT_H 		0x3D	// #61
#define MPUREG_ACCEL_YOUT_L 		0x3E	// #62
#define MPUREG_ACCEL_ZOUT_H 		0x3F	// #63
#define MPUREG_ACCEL_ZOUT_L 		0x40	// #64

// Registers 65 and 66 – Temperature Measurement

#define MPUREG_TEMP_OUT_H 			0x41	// #65
#define MPUREG_TEMP_OUT_L 			0x42	// #66

// Registers 67 to 72 – Gyroscope Measurements

#define MPUREG_GYRO_XOUT_H 			0x43	// #67
#define MPUREG_GYRO_XOUT_L 			0x44	// #68
#define MPUREG_GYRO_YOUT_H 			0x45	// #69
#define MPUREG_GYRO_YOUT_L 			0x46	// #70
#define MPUREG_GYRO_ZOUT_H 			0x47	// #71
#define MPUREG_GYRO_ZOUT_L 			0x48	// #72

// Registers 73 to 96 – External Sensor Data

#define MPUREG_EXT_SENS_DATA_00    	0x49	// #73
#define MPUREG_EXT_SENS_DATA_01    	0x4A	// #74
#define MPUREG_EXT_SENS_DATA_02    	0x4B	// #75
#define MPUREG_EXT_SENS_DATA_03    	0x4C	// #76
#define MPUREG_EXT_SENS_DATA_04    	0x4D	// #77
#define MPUREG_EXT_SENS_DATA_05    	0x4E	// #78
#define MPUREG_EXT_SENS_DATA_06    	0x4F	// #79
#define MPUREG_EXT_SENS_DATA_07    	0x50	// #80
#define MPUREG_EXT_SENS_DATA_08    	0x51	// #81
#define MPUREG_EXT_SENS_DATA_09    	0x52	// #82
#define MPUREG_EXT_SENS_DATA_10    	0x53	// #83
#define MPUREG_EXT_SENS_DATA_11    	0x54	// #84
#define MPUREG_EXT_SENS_DATA_12    	0x55	// #85
#define MPUREG_EXT_SENS_DATA_13    	0x56	// #86
#define MPUREG_EXT_SENS_DATA_14    	0x57	// #87
#define MPUREG_EXT_SENS_DATA_15    	0x58	// #88
#define MPUREG_EXT_SENS_DATA_16    	0x59	// #89
#define MPUREG_EXT_SENS_DATA_17    	0x5A	// #90
#define MPUREG_EXT_SENS_DATA_18    	0x5B	// #91
#define MPUREG_EXT_SENS_DATA_19    	0x5C	// #92
#define MPUREG_EXT_SENS_DATA_20    	0x5D	// #93
#define MPUREG_EXT_SENS_DATA_21    	0x5E	// #94
#define MPUREG_EXT_SENS_DATA_22    	0x5F	// #95
#define MPUREG_EXT_SENS_DATA_23    	0x60	// #96

// Registers 99 to 102 – I2C Slaves Data Out

#define MPUREG_I2C_SLV0_DO         	0x63	// #99
#define MPUREG_I2C_SLV1_DO         	0x64	// #100
#define MPUREG_I2C_SLV2_DO         	0x65	// #101
#define MPUREG_I2C_SLV3_DO         	0x66	// #102

// Register 103 – I2C Master Delay Control (Reset value: 0x00)

#define MPUREG_I2C_MST_DELAY_CTRL  	0x67	// #103

// Register 104 – Signal Path Reset

#define MPUREG_SIGNAL_PATH_RESET   	0x68	// #104

// Register 105 – Accelerometer Interrupt Control (Reset value: 0x00)

#define MPUREG_MOT_DETECT_CTRL     	0x69	// #105

// Register 106 – User Control

#define MPUREG_USER_CTRL 			0x6A	// #106

#define BIT_FIFO_EN					0x40
#define I2C_IF_DIS					0x10
#define FIFO_RST					0x04

// Register 107 and 108 – Power Management

#define MPUREG_PWR_MGMT_1 			0x6B	// #107

#define BIT_CLKSEL_AUTO				0x01
#define BIT_SLEEP 					0x40
#define BIT_H_RESET 				0x80

#define MPUREG_PWR_MGMT_2 			0x6C	// #108

#define BITS_ALL_ON					0x00

#define MPUREG_BANK_SEL 			0x6D
#define MPUREG_MEM_START_ADDR 		0x6E
#define MPUREG_MEM_R_W 				0x6F
#define MPUREG_DMP_CFG_1 			0x70
#define MPUREG_DMP_CFG_2 			0x71

// Register 114 and 115 – FIFO Count Registers (Reset value: 0x00)

#define MPUREG_FIFO_COUNTH 			0x72	// #114
#define MPUREG_FIFO_COUNTL 			0x73	// #115

// Register 116 – FIFO Read Write

#define MPUREG_FIFO_R_W			 	0x74	// #116

// Register 117 – Who Am I

#define MPUREG_WHOAMI 				0x75	// #117

// Registers 119, 120, 122, 123, 125, 126 Accelerometer Offset Registers

#define MPUREG_XA_OFFSET_H         	0x77	// #119
#define MPUREG_XA_OFFSET_L         	0x78	// #120
#define MPUREG_YA_OFFSET_H         	0x7A	// #121
#define MPUREG_YA_OFFSET_L         	0x7B	// #122
#define MPUREG_ZA_OFFSET_H         	0x7D	// #123
#define MPUREG_ZA_OFFSET_L         	0x7E	// #124

// Configuration bits mpu9250

#define BITS_CLKSEL 				0x07
#define MPU_CLK_SEL_PLLGYROX 		0x01
#define MPU_CLK_SEL_PLLGYROZ 		0x03
#define MPU_EXT_SYNC_GYROX 			0x02

#define BITS_DLPF_CFG_MASK          0x07

#define BIT_INT_ANYRD_2CLEAR        0x10
#define BIT_RAW_RDY_EN              0x01
#define BIT_I2C_IF_DIS              0x10

// AK8963 Reg In MPU9250

#define AK8963_I2C_ADDR             0x0c	//0x18
#define AK8963_Device_ID            0x48

// Read-only Reg

#define AK8963_WIA                  0x00
#define AK8963_INFO                 0x01
#define AK8963_ST1                  0x02
#define AK8963_HXL                  0x03
#define AK8963_HXH                  0x04
#define AK8963_HYL                  0x05
#define AK8963_HYH                  0x06
#define AK8963_HZL                  0x07
#define AK8963_HZH                  0x08
#define AK8963_ST2                  0x09

// Write/Read Reg

#define AK8963_CNTL1                0x0A
#define AK8963_CNTL2                0x0B
#define AK8963_ASTC                 0x0C
#define AK8963_TS1                  0x0D
#define AK8963_TS2                  0x0E
#define AK8963_I2CDIS               0x0F

// Read-only Reg ( ROM )

#define AK8963_ASAX                 0x10
#define AK8963_ASAY                 0x11
#define AK8963_ASAZ                 0x12

// Sensitivity

#define MPU9250A_2g       ((float)0.000061035156f) // 0.000061035156 g/LSB
#define MPU9250A_4g       ((float)0.000122070312f) // 0.000122070312 g/LSB
#define MPU9250A_8g       ((float)0.000244140625f) // 0.000244140625 g/LSB
#define MPU9250A_16g      ((float)0.000488281250f) // 0.000488281250 g/LSB

// Degres
//#define MPU9250G_250dps   ((float)0.007633587786f) // 0.007633587786 dps/LSB
//#define MPU9250G_500dps   ((float)0.015267175572f) // 0.015267175572 dps/LSB
//#define MPU9250G_1000dps  ((float)0.030487804878f) // 0.030487804878 dps/LSB
//#define MPU9250G_2000dps  ((float)0.060975609756f) // 0.060975609756 dps/LSB

// Radians
#define MPU9250G_250dps   ((float)0.000133158055f) // 0.007633587786 dps/LSB
#define MPU9250G_500dps   ((float)0.000266316109f) // 0.015267175572 dps/LSB
#define MPU9250G_1000dps  ((float)0.000532632218f) // 0.030487804878 dps/LSB
#define MPU9250G_2000dps  ((float)0.001065264436f) // 0.060975609756 dps/LSB

#define MPU9250M_4800uT   ((float)0.6f)            // 0.6 uT/LSB

#define MPU9250T_85degC   ((float)0.002995177763f) // 0.002995177763 degC/LSB

#define Magnetometer_Sensitivity_Scale_Factor ((float)0.15f)


#endif /* APP_INC_MPU9250_H_ */
