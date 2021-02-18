/*
 * SPI.c
 *
 *  Created on: 28 janv. 2021
 *      Author: ayoub
 */

#include "main.h"


void BSP_SPI2_Common_Init()
{
	// SPI_SCK  -> PB13 (AF5)
	// SPI_MISO -> PB14 (AF5)
	// SPI_MOSI -> PB15 (AF5)

	// Enable GPIOB clock
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN;

	// Configure PB13, PB14, PB15 as AF mode
	GPIOB->MODER &= ~(GPIO_MODER_MODER13 | GPIO_MODER_MODER14 | GPIO_MODER_MODER15);
	GPIOB->MODER |= (0x02 <<26U) |(0x02 <<28U) |(0x02 <<30U);

	// Connect to SPI2 (AF5)
	GPIOB->AFR[1] &= ~(0xFFF00000);
	GPIOB->AFR[1] |=  (0x55500000);

	// Enable SPI2 Clock
	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;

	// Configure SPI
	// Default config -> Full-duplex, 8-bit, no CRC, MSB first,...
	SPI2->CR1 = 0x0000;
	SPI2->CR2 = 0x0000;

	// Set the baudrate to 84MHz /128
	SPI2->CR1 |= 0x06 <<3;

	// Set as master (SSI must be high)
	SPI2->CR1 |= SPI_CR1_MSTR | SPI_CR1_SSI;

	// Set software management of NSS
	SPI2->CR1 |= SPI_CR1_SSM;

	// Enable SPI2
	SPI2->CR1 |= SPI_CR1_SPE;
}

/*
 * SPI CS Pins for MPU9250 - ADXL343 - BMA280
 */

void BSP_SPI2_CSPins_Init()
{
	// PC3 -> MPU9250

	// Enable GPIOC clock
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
	// Configure the CS pin (PC3)
	GPIOC->MODER  &= ~(GPIO_MODER_MODER3);	// PC3 as output
	GPIOC->MODER  |=  (0x01 <<6U) | (0x01 <<8U) | (0x01 <<10U);
	GPIOC->OTYPER &= ~(GPIO_OTYPER_OT_3);		// Push-pull
	GPIOC->PUPDR  &= ~(GPIO_PUPDR_PUPDR3);	// No Pull resistor
	GPIOC->OSPEEDR |= (0x03 <<6U);						// High-speed

	// Reset all CS high
	GPIOC->ODR |= (uint32_t)0x00000008U ;
}

