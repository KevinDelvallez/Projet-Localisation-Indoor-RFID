#include "stm32f0xx.h"
#include "main.h"
#include <math.h>
#include <string.h>
// Clock initialisation
static void SystemClock_Config(void);

#define NB_TAG 9
#define size_table 19

char TabstrID[NB_TAG][size_table]={
	"e2002075810D01540300EBD2",
	"000000000000024113F33DAE",
	"300833B2DDD9014000000000",
	"CAFE09B20000300000001800",
	"E20031C227034771119C2D1C",
	"300833B2DDD9014000000000",
	"E20068060000000000000000",
	"E2003074210C012624301D04",
	"300833B2DDD9014000000000"
};

// FreeRTOS tasks
void vTask1         (void *pvParameters);
void vTask2         (void *pvParameters);
void Task_Write         (void *pvParameters);
#define taille 100
typedef uint8_t command_message_t[taille];
// Kernel Objects
xQueueHandle	xComQueue;
xSemaphoreHandle xSEM_DMA_TC;
xSemaphoreHandle xSem_UART_TC;
uint8_t	 Tx_dma_buffer_lecteur[100];
//20C0008011AA5541000B7B9

unsigned char inventory_with_report[19] = {0x02,0x00,0x0C,0x00,0x00,0x00,0x08,0x00,0x11,0xAA,0x55,0x00,0x04,0X01,0x00,0x00,0x00,0xB7,0xB9};//inventory with report
uint8_t	mpu_data[6];


// Main program
int main()
{

	//configue systèm clock(HSE)
	SystemClock_Config();

	// Initialize LED pin
	BSP_LED_Init();

	// Initialize Debug Console
	BSP_Console_Init();

	BSP_PB_Init();
	/*
	  // Start Trace Recording
    vTraceEnable(TRC_START);

    // Create Semaphore object
    xSem_UART_TC = xSemaphoreCreateBinary();

     // Give a nice name to the Semaphore in the trace recorder
      vTraceSetSemaphoreName(xSem_UART_TC, "xSem_UART_TC");

     // Create Semaphore object
     xSEM_DMA_TC = xSemaphoreCreateBinary();

     // Give a nice name to the Semaphore in the trace recorder
     vTraceSetSemaphoreName(xSEM_DMA_TC, "xSEM_DMA_TC");

     // Create Queue to hold console messages
     xComQueue = xQueueCreate(10, sizeof(command_message_t *));

     // Give a nice name to the Queue in the trace recorder
     vTraceSetQueueName(xComQueue, "xComQueue");

     // Create Tasks
     xTaskCreate(vTask1, "Task_1", 256, NULL, 3, NULL);
     xTaskCreate(vTask2, "Task_2", 256, NULL, 2, NULL);
     xTaskCreate(Task_Write,"Task_Write", 256, NULL, 1, NULL);

     // Start the Scheduler
     vTaskStartScheduler();
	 */


	my_printf("\r\n Console Ready \r\n");
	my_printf("SYSCLK = %d Hz\r\n", SystemCoreClock);
	BSP_I2C1_Init();
	BSP_MPU9250_Init();

	while(1)
	{
		// Read Accl Gyro data from IMU
		   BSP_I2C1_Read(MPU9250_ADDRESS,MPUREG_ACCEL_XOUT_H, mpu_data, 6);
			 //BSP_I2C1_Read(AK8963_ADDRESS,MPUREG_I2C_SLV0_CTRL,  mpu_data, 6);
			raw_ax = ((uint8_t)mpu_data[0]<<8) | (uint8_t)mpu_data[1];
			raw_ay = ((uint8_t)mpu_data[2]<<8) | (uint8_t)mpu_data[3];
			raw_az = ((uint8_t)mpu_data[4]<<8) | (uint8_t)mpu_data[5];

			// Scale Accelerometers
			imu_ax =  raw_ax * MPU9250A_2g;
			imu_ay =  raw_ay * MPU9250A_2g;
			imu_az =  raw_az * MPU9250A_2g;

			imu_ax_si =  imu_ax * 9.81f;
		    imu_ay_si =  imu_ay * 9.81f;
			imu_az_si =  imu_az * 9.81f;

			raw_gx = ((int16_t)mpu_data[8]<<8)  | (int16_t)mpu_data[9];
			raw_gy = ((int16_t)mpu_data[10]<<8) | (int16_t)mpu_data[11];
			raw_gz = ((int16_t)mpu_data[12]<<8) | (int16_t)mpu_data[13];

			// Scale Gyros with offset cancellation
			imu_gx = -(raw_gx + 60) * MPU9250G_500dps;
			imu_gy = -(raw_gy + 20) * MPU9250G_500dps;
			imu_gz = -(raw_gz + 40) * MPU9250G_500dps;

			// Read Magnetometer data from IMU
			BSP_I2C1_Read(AK8963_ADDRESS,MPUREG_EXT_SENS_DATA_00, mpu_data, 7);

			raw_mx =  ((int16_t)mpu_data[1]<<8) | (int16_t)mpu_data[0];
			raw_my =  ((int16_t)mpu_data[3]<<8) | (int16_t)mpu_data[2];
			raw_mz =  ((int16_t)mpu_data[5]<<8) | (int16_t)mpu_data[4];

			// Scale Magnetometers
			imu_mx = raw_mx * MPU9250M_4800uT;
			imu_my = raw_my * MPU9250M_4800uT;
			imu_mz = raw_mz * MPU9250M_4800uT;

		     //GET MPU9250 DEVICE ID (Default Value : 0x71)
		    my_printf("MPU9250 ADDRESS = 0x%02x%d\r\n",BSP_I2C1_Read( MPU9250_ADDRESS, 0x75 ,0,1));
		    //GET MAGNETOMETER AK8963 DEVICE ID
		    my_printf("AK8963 ADDRESS = 0x%02x%d\r\n",BSP_I2C1_Read( AK8963_ADDRESS, 0x00,0,1));

		    my_printf("\r\n x= %6d, y= %6d ,z= %6d \r\n", raw_ax , raw_ay ,raw_az );

}
}
void vTask1 (void *pvParameters)
{
	//command_message_t  message;
	//command_message_t    *pm;
    while(1){

        // Send message to the Console Queue
    	//pm = &message;
    	//xQueueSendToBack(xComQueue, &pm, 0);
        //vTaskDelay(100);
    }
}

void vTask2 (void *pvParameters)
{
	// Set priority level 1 for DMA1_Channel4 interrupts
	NVIC_SetPriority(USART1_IRQn,configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY + 1);

	// Enable DMA1_Channel4 interrupts
	NVIC_EnableIRQ(USART1_IRQn);

	portBASE_TYPE	xStatus;

	uint8_t i = 0;
	char table[100];

	command_message_t message;
	command_message_t *pm;


	 while(1){

		 xStatus = xSemaphoreTake(xSem_UART_TC,portMAX_DELAY);
		 i = 0;
		 if(xStatus == pdPASS){
			 while((USART1->ISR & USART_ISR_RXNE) == USART_ISR_RXNE){
				 table[i] = USART1->RDR;
				 i++;
			 }
		 }

		 i = 0;
		 while(table[i] != '\0'){
			 message[i] = table[i];
			 i++;
		 }

		 pm = &message;

		 xQueueSendToBack(xComQueue,&pm,0);

		 vTaskDelay(200);
	 }
}
void Task_Write (void *pvParameters)
{
	// Set priority level 1 for DMA1_Channel4 interrupts
	NVIC_SetPriority(DMA1_Channel4_5_6_7_IRQn,configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY + 1);

	// Enable DMA1_Channel4 interrupts
	NVIC_EnableIRQ(DMA1_Channel4_5_6_7_IRQn);
	uint8_t i = 0;
	while(1)
	{

		for(i = 0;i<size_table;i++){
			Tx_dma_buffer_lecteur[i] = inventory_with_report[i];
		}

		DMA1_Channel7->CNDTR = size_table;

		// Enable DMA TC interrupt
		DMA1_Channel7->CCR |= DMA_CCR_TCIE;

		// Enable DMA1 Channel 4
		DMA1_Channel7->CCR |= DMA_CCR_EN;

		// Enable USART2 DMA Request on TX
		USART4->CR3 |= USART_CR3_DMAT;

		//This is where the semaphore
		xSemaphoreTake(xSEM_DMA_TC,portMAX_DELAY);

		// Disable USART2 DMA Request on TX
		 USART4->CR3 &= ~USART_CR3_DMAT;

		// Disable DMA1 Channel 4
		DMA1_Channel7->CCR &= ~DMA_CCR_EN;

		vTaskDelay(200);
	}
}


/*
 * 	Clock configuration for the Nucleo STM32F072RB board
 * 	HSE input Bypass Mode	-> 8MHz
 * 	SYSCLK, AHB, APB1 	-> 48MHz
 */

static void SystemClock_Config()
{
	uint32_t	HSE_Status;
	uint32_t	PLL_Status;
	uint32_t	SW_Status;
	uint32_t	timeout = 0;

	timeout = 1000000;

	// Start HSE in Bypass Mode
	RCC->CR |= RCC_CR_HSEBYP;
	RCC->CR |= RCC_CR_HSEON;

	// Wait until HSE is ready
	do
	{
		HSE_Status = RCC->CR & RCC_CR_HSERDY_Msk;
		timeout--;
	} while ((HSE_Status == 0) && (timeout > 0));

	// Select HSE as PLL input source
	RCC->CFGR &= ~RCC_CFGR_PLLSRC_Msk;
	RCC->CFGR |= (0x02 <<RCC_CFGR_PLLSRC_Pos);

	// Set PLL PREDIV to /1
	RCC->CFGR2 = 0x00000000;

	// Set PLL MUL to x6
	RCC->CFGR &= ~RCC_CFGR_PLLMUL_Msk;
	RCC->CFGR |= (0x04 <<RCC_CFGR_PLLMUL_Pos);

	// Enable the main PLL
	RCC-> CR |= RCC_CR_PLLON;

	// Wait until PLL is ready
	do
	{
		PLL_Status = RCC->CR & RCC_CR_PLLRDY_Msk;
		timeout--;
	} while ((PLL_Status == 0) && (timeout > 0));

	// Set AHB prescaler to /1
	RCC->CFGR &= ~RCC_CFGR_HPRE_Msk;
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

	//Set APB1 prescaler to /1
	RCC->CFGR &= ~RCC_CFGR_PPRE_Msk;
	RCC->CFGR |= RCC_CFGR_PPRE_DIV1;

	// Enable FLASH Prefetch Buffer and set Flash Latency (required for high speed)
	FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY;

	/* --- Until this point, MCU was still clocked by HSI at 8MHz ---*/
	/* --- Switching to PLL at 48MHz Now!  Fasten your seat belt! ---*/

	// Select the main PLL as system clock source
	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_PLL;

	// Wait until PLL becomes main switch input
	do
	{
		SW_Status = (RCC->CFGR & RCC_CFGR_SWS_Msk);
		timeout--;
	} while ((SW_Status != RCC_CFGR_SWS_PLL) && (timeout > 0));

	/* --- Here we go ! ---*/

	/*--- Use PA8 as MCO output at 48/16 = 3MHz ---*/

	// Set MCO source as SYSCLK (48MHz)
	RCC->CFGR &= ~RCC_CFGR_MCO_Msk;
	RCC->CFGR |=  RCC_CFGR_MCOSEL_SYSCLK;

	// Set MCO prescaler to /16 -> 3MHz
	RCC->CFGR &= ~RCC_CFGR_MCOPRE_Msk;
	RCC->CFGR |=  RCC_CFGR_MCOPRE_DIV16;

	// Enable GPIOA clock
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

	// Configure PA8 as Alternate function
	GPIOA->MODER &= ~GPIO_MODER_MODER8_Msk;
	GPIOA->MODER |= (0x02 <<GPIO_MODER_MODER8_Pos);

	// Set to AF0 (MCO output)
	GPIOA->AFR[1] &= ~(0x0000000F);
	GPIOA->AFR[1] |=  (0x00000000);

	// Update SystemCoreClock global variable
	SystemCoreClockUpdate();
}
