/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f0xx.h"
#include "stm32f072b_discovery.h"
#include <string.h>

#define UART_MES_BUF 20

UART_HandleTypeDef uart2;
UART_HandleTypeDef uart3;
uint8_t Received[UART_MES_BUF];

void GPIOInit();
void UARTInit();

void sendString(UART_HandleTypeDef *uart, char* s) {
//	HAL_UART_Transmit_IT(uart, (uint8_t*) s, strlen(s));
	HAL_UART_Transmit_IT(uart, (uint8_t*) s, UART_MES_BUF);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *uart) {

	if (uart->Instance == USART2) {
//		sendString(&uart2, "Dostalem - UART2\r\n");
		sendString(&uart2, (char*)Received);
		HAL_UART_Receive_IT(&uart2, Received, UART_MES_BUF); // Ponowne nasluchiwania
	} else if (uart->Instance == USART3) {
		sendString(&uart3, "Dostalem - UART3\r\n");
		HAL_UART_Receive_IT(&uart3, Received, UART_MES_BUF); // Ponowne nasluchiwania
	}

}

int main(void)
{
	SystemCoreClock = 8000000; // taktowanie 8Mhz
	HAL_Init();

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_USART2_CLK_ENABLE();
	__HAL_RCC_USART3_CLK_ENABLE();

	GPIOInit();
	UARTInit();

	HAL_UART_Receive_IT(&uart2, Received, UART_MES_BUF);
	HAL_UART_Receive_IT(&uart3, Received, UART_MES_BUF);

	for(;;) {

	}
}
void GPIOInit() {
	GPIO_InitTypeDef gpio;

	/*Linia TX dla UART2*/
	gpio.Mode = GPIO_MODE_AF_PP;
	gpio.Alternate = GPIO_AF1_USART2;
	gpio.Pin = GPIO_PIN_14;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &gpio);

	/*Linia RX dla UART2*/
	gpio.Pin = GPIO_PIN_15;
	gpio.Mode = GPIO_MODE_AF_OD;
	HAL_GPIO_Init(GPIOA, &gpio);

	/*Linia TX dla UART3*/
	gpio.Pin = GPIO_PIN_10;
	gpio.Alternate = GPIO_AF4_USART3;
	gpio.Mode = GPIO_MODE_AF_PP;
	HAL_GPIO_Init(GPIOB, &gpio);

	/*Linia RX dla UART3*/
	gpio.Pin = GPIO_PIN_11;
	gpio.Mode = GPIO_MODE_AF_OD;
	HAL_GPIO_Init(GPIOB, &gpio);

	/*Pomocnicza dioda LED*/
	gpio.Pin = GPIO_PIN_7;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOC, &gpio);
}
void UARTInit(){
	/*Inicjalizacja UART2 handle*/
	uart2.Instance = USART2;
	uart2.Init.BaudRate = 115200;
	uart2.Init.WordLength = USART_WORDLENGTH_8B;
	uart2.Init.Parity = USART_PARITY_NONE;
	uart2.Init.StopBits = UART_STOPBITS_1;
	uart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart2.Init.OverSampling = UART_OVERSAMPLING_16;
	uart2.Init.Mode = UART_MODE_TX_RX;
	HAL_UART_Init(&uart2);

	/*Inicjalizacja UART3 handle*/
	uart3.Instance = USART3;
	uart3.Init.BaudRate = 115200;
	uart3.Init.WordLength = USART_WORDLENGTH_8B;
	uart3.Init.Parity = USART_PARITY_NONE;
	uart3.Init.StopBits = UART_STOPBITS_1;
	uart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart3.Init.OverSampling = UART_OVERSAMPLING_16;
	uart3.Init.Mode = UART_MODE_TX_RX;
	HAL_UART_Init(&uart3);

	/* Konfiguracja przerwania dla UART2 */
	HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART2_IRQn);

	/*Konfiguracja przerwania dla UART3*/
	HAL_NVIC_SetPriority(USART3_4_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART3_4_IRQn);
}
