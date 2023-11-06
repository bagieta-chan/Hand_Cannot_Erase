

#ifndef INC_ACCELEROMETRE_H_
#define INC_ACCELEROMETRE_H_

#include "main.h"

typedef struct accel{
	volatile int16_t accel_X_OG;
	volatile int16_t accel_Y_OG;
	volatile int16_t accel_Z_OG;

	volatile int16_t gyro_X_OG;
	volatile int16_t gyro_Y_OG;
	volatile int16_t gyro_Z_OG;

	volatile float accel_X_proc;
	volatile float accel_Y_proc;
	volatile float accel_Z_proc;

	volatile float gyro_X_proc;
	volatile float gyro_Y_proc;
	volatile float gyro_Z_proc;

	volatile float gyro_X_held;
	volatile float gyro_Y_held;
	volatile float gyro_Z_held;

	volatile float gyro_X_fproc;
	volatile float gyro_Y_fproc;
	volatile float gyro_Z_fproc;

	volatile float rollAngle;
	volatile float pitchAngle;
	volatile float yawAngle;
}Accel;

extern Accel acc_device;

void accel_Init(void);
void get_Dividers();
void accel_ReadAccel(Accel *device);
void accel_ReadGyro(Accel *device);
void accel_GetAngles(Accel *device);
void accel_IntegrateGyro(Accel *device, float elapsedFreq);

#endif /* INC_ACCELEROMETRE_H_ */
