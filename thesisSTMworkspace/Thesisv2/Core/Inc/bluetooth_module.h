

#ifndef INC_BLUETOOTH_MODULE_H_
#define INC_BLUETOOTH_MODULE_H_

#include <stdbool.h>

#define BUFF_LEN 100

extern bool bt_editMode;

extern volatile char bluetooth_RX1_buffer[BUFF_LEN];
extern volatile char bluetooth_TX_buffer[BUFF_LEN];



void enable_BluetoothEditMode(bool *check_status);
void check_Bluetooth();
void check_bluetooth_BaudRate();
void check_bluetooth_Name();
void check_bluetooth_Password();
void UART_BluetoothHandler();
void set_bluetooth_Name();
void set_bluetooth_BaudRate();
void set_BaudRate();

#endif /* INC_BLUETOOTH_MODULE_H_ */

