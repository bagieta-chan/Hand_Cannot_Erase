#include "bluetooth_module.h"
#include "main.h"
#include "usart.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define BAUD_RATE 9600
#define TIME_OF_BREAK 50

volatile char bluetooth_TX_buffer[BUFF_LEN];
volatile char bluetooth_RX1_buffer[BUFF_LEN] = "";

char password[]= "1234";

char command_end[] = "\r\n";
char command_AT[] = "AT";
char command_password[] = "PSWD";
char command_module_name[] = "NIGGER_BLUETOOTH";
char command_name[] = "NAME";
char command_baud_rate[] = "UART";

char module_version[] = "VERSION";
char factory_settings[] = "ORGL";
char result_command[BUFF_LEN];

static char baud_rate[] = "";

bool bt_editMode = false;

void enable_BluetoothEditMode(bool* check_status)
{
	if(!*check_status)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, SET);
		HAL_Delay(TIME_OF_BREAK);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, RESET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
	}

}

void check_Bluetooth()
{

	memset(bluetooth_TX_buffer,0, BUFF_LEN);
	memset(result_command, 0, BUFF_LEN);

	sprintf(result_command, "%s%s", command_AT, command_end);
	sprintf(bluetooth_TX_buffer, "%s", result_command);

	if(*bluetooth_TX_buffer != '\0')
	{
		__disable_irq();
		HAL_UART_Transmit_DMA(&huart1, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);

		while(!(USART2->SR & USART_SR_TC)){}

		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);

		while(!(USART1->SR & USART_SR_TC)){}

		__enable_irq();
		memset(bluetooth_TX_buffer,0, BUFF_LEN);


		HAL_UART_Receive_DMA(&huart1, (uint8_t *)bluetooth_RX1_buffer, BUFF_LEN);


	}

}

void check_bluetooth_Name()
{


	memset(bluetooth_TX_buffer,0, BUFF_LEN);
	memset(result_command, 0, BUFF_LEN);

	sprintf(result_command, "%s+%s?%s", command_AT, command_name, command_end);
	sprintf(bluetooth_TX_buffer, "%s", result_command);

	if(*bluetooth_TX_buffer != '\0')
	{
		__disable_irq();
		HAL_UART_Transmit_DMA(&huart1, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);
		__enable_irq();
		while(!(USART2->SR & USART_SR_TC)){}
		__disable_irq();
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);
		__enable_irq();
		while(!(USART1->SR & USART_SR_TC)){}


		memset(bluetooth_TX_buffer,0, BUFF_LEN);


		HAL_UART_Receive_DMA(&huart1, (uint8_t *)bluetooth_RX1_buffer, BUFF_LEN);


	}

}

void check_bluetooth_BaudRate()
{
	memset(bluetooth_TX_buffer,0, BUFF_LEN);
	memset(result_command, 0, BUFF_LEN);

	sprintf(result_command, "%s+%s?%s", command_AT, command_baud_rate, command_end);
	sprintf(bluetooth_TX_buffer, "%s", result_command);

	if(*bluetooth_TX_buffer != '\0')
	{
		__disable_irq();
		HAL_UART_Transmit_DMA(&huart1, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);

		while(!(USART2->SR & USART_SR_TC)){}

		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);

		while(!(USART1->SR & USART_SR_TC)){}

		__enable_irq();
		memset(bluetooth_TX_buffer,0, BUFF_LEN);


		HAL_UART_Receive_DMA(&huart1, (uint8_t *)bluetooth_RX1_buffer, BUFF_LEN);


	}
}

void check_bluetooth_Password()
{
	memset(bluetooth_TX_buffer,0, BUFF_LEN);
	memset(result_command, 0, BUFF_LEN);

	sprintf(result_command, "%s+%s?%s", command_AT, command_password, command_end);
	sprintf(bluetooth_TX_buffer, "%s", result_command);

	if(*bluetooth_TX_buffer != '\0')
	{
		__disable_irq();
		HAL_UART_Transmit_DMA(&huart1, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);

		while(!(USART2->SR & USART_SR_TC)){}

		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);

		while(!(USART1->SR & USART_SR_TC)){}

		__enable_irq();
		memset(bluetooth_TX_buffer,0, BUFF_LEN);


		HAL_UART_Receive_DMA(&huart1, (uint8_t *)bluetooth_RX1_buffer, BUFF_LEN);


	}
}

void set_bluetooth_Name()
{

	__disable_irq();
	memset(bluetooth_TX_buffer,0, BUFF_LEN);
	memset(result_command, 0, BUFF_LEN);

	sprintf(result_command, "%s+%s=%s%s", command_AT, command_name, command_module_name, command_end);
	sprintf(bluetooth_TX_buffer, "%s", result_command);
	__enable_irq();


	if(*bluetooth_TX_buffer != '\0')
	{

		HAL_UART_Transmit_DMA(&huart1, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);

		while(!(USART2->SR & USART_SR_TC)){}

		USART2->SR &=~ USART_SR_TC;

		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);

		while(!(USART1->SR & USART_SR_TC)){}

		USART2->SR &=~ USART_SR_TC;


		memset(bluetooth_RX1_buffer,0, BUFF_LEN);

		char confirm = "OK\r\n";
		char* tmp = NULL;

		while(1)
		{
			__disable_irq();
			HAL_UART_Receive_DMA(&huart1, (uint8_t *)bluetooth_RX1_buffer, BUFF_LEN);
			__enable_irq();

			tmp = (char*)bluetooth_RX1_buffer;

			for(int i = 0; i< BUFF_LEN; i++)
			{
				if(*(tmp + i) != 0)
				{
					tmp = tmp + i;
					break;
				}
			}


			if(strstr(tmp, confirm) != NULL)
			{
				memset(bluetooth_RX1_buffer,0, BUFF_LEN);
				break;
			}
			else
			{
				HAL_UART_Transmit_DMA(&huart1, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);
				HAL_UART_Transmit_DMA(&huart2, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);

				memset(bluetooth_RX1_buffer,0, BUFF_LEN);
				HAL_Delay(1000);
			}
		}

		memset(bluetooth_TX_buffer,0, BUFF_LEN);

	}


}

void set_BaudRate(int rate)
{
	itoa(rate, baud_rate, 10);
}

void set_bluetooth_BaudRate()
{
	__disable_irq();
	memset(bluetooth_TX_buffer,0, BUFF_LEN);
	memset(bluetooth_RX1_buffer,0, BUFF_LEN);
	memset(result_command, 0, BUFF_LEN);

	sprintf(bluetooth_TX_buffer, "%s+%s?", command_AT, command_baud_rate);

	set_BaudRate(BAUD_RATE);
	__enable_irq();



	if(*bluetooth_TX_buffer != '\0')
	{
		HAL_UART_Receive_IT(&huart1, (uint8_t *)bluetooth_RX1_buffer, BUFF_LEN);
		HAL_UART_Transmit_DMA(&huart2, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);

		while(!(USART2->SR & USART_SR_TC)){}

		HAL_UART_Transmit_DMA(&huart1, (uint8_t *)bluetooth_TX_buffer, BUFF_LEN);

		while(!(USART1->SR & USART_SR_TC)){}

		memset(bluetooth_TX_buffer,0, BUFF_LEN);
	}


}


