#include "timers.h"
#include "main.h"
#include "accelerometre.h"
#include "tim.h"
#include "usart.h"
#include "bluetooth_module.h"


static volatile float tim3_freq = 0;


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	if(htim->Instance == TIM2 )
	{
		  accel_ReadAccel(&acc_device);
		  accel_ReadGyro(&acc_device);
     	  accel_IntegrateGyro(&acc_device, tim3_freq);
		  accel_GetAngles(&acc_device);

	}

	else if(htim->Instance == TIM3)
	{

		char* temp = NULL;
		int i =0;

		for(i; i<BUFF_LEN; i++)
		{
			if(bluetooth_RX1_buffer[i] != 0)
			{
				temp = &bluetooth_RX1_buffer[i];
				break;
			}
			else if(i == BUFF_LEN - 1 && bluetooth_RX1_buffer[i] == 0)
				return;
		}

			__disable_irq();
			HAL_UART_Transmit_DMA(&huart2, (uint8_t*)temp, BUFF_LEN - i);
			__enable_irq();

			while(!(USART2->SR & USART_SR_TC)){

					}

			memset(bluetooth_RX1_buffer,0, BUFF_LEN);
			HAL_UART_Receive_DMA(&huart1, bluetooth_RX1_buffer, BUFF_LEN);


		}



}

void calculate_Tim2Period()
{
	tim3_freq = (float)(HAL_RCC_GetPCLK1Freq()/((htim2.Init.Prescaler + 1) * (htim2.Init.Period + 1)));
}
