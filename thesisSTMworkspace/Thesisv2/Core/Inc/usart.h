/* USER CODE BEGIN Header */

#define DMA_RX_BUFFER_SIZE 50
#define UART_BUFFER_SIZE 50

/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USART_H__
#define __USART_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern UART_HandleTypeDef huart1;

extern UART_HandleTypeDef huart2;

/* USER CODE BEGIN Private defines */
typedef struct
{
	  UART_HandleTypeDef huart;

	  uint8_t DMA_RX_Buffer[DMA_RX_BUFFER_SIZE];
	  uint8_t UART_Buffer[UART_BUFFER_SIZE];

	  uint16_t *UartBufferHead;
	  uint16_t *UartBufferTail;
	  uint8_t  *UartBufferLines;
}DMA_UART_TypeDef;

/* USER CODE END Private defines */

void MX_USART1_UART_Init(void);
void MX_USART2_UART_Init(void);

/* USER CODE BEGIN Prototypes */


/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

