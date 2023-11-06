

#ifndef INC_DMA_UART_H_
#define INC_DMA_UART_H_

#include "main.h"

#define DMA_RX_BUFFER_SIZE 50
#define UART_BUFFER_SIZE 50

typedef struct
{
	  UART_HandleTypeDef* huart; // UART handler

	  uint8_t DMA_RX_Buffer[DMA_RX_BUFFER_SIZE]; // DMA direct buffer
	  uint8_t UART_Buffer[UART_BUFFER_SIZE]; // UART working circular buffer

	  uint16_t UartBufferHead;
	  uint16_t UartBufferTail;
	  uint8_t UartBufferLines;

}DMA_UARTHandle;

void DMA_UART_Init(DMA_UARTHandle *dmauart, UART_HandleTypeDef *huart);
void DMA_UART_UARTIrqHandler(DMA_UARTHandle *dmauart);
void DMA_UART_DMAIrqHandler(DMA_UARTHandle *dmauart);

#endif /* INC_DMA_UART_H_ */
