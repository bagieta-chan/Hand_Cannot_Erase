/*
 * kalman.h
 *
 *  Created on: Sep 30, 2023
 *      Author: Aleksy
 */

#ifndef INC_KALMAN_H_
#define INC_KALMAN_H_

#include "main.h"

typedef struct {
   float Q_angle;
   float Q_bias;
   float R_measure;
   float angle;
   float bias;
   float P[2][2];
} Kalman_t;

float Kalman_getAngle(Kalman_t *Kalman,float newAngle,float newRate,float dt);

#endif /* INC_KALMAN_H_ */
