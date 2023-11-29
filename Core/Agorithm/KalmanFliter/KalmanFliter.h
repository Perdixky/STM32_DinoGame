/*
 * KalmanFliter.h
 *
 *  Created on: Nov 18, 2023
 *      Author: 32937
 */

#ifndef AGORITHM_KALMANFLITER_KALMANFLITER_H_
#define AGORITHM_KALMANFLITER_KALMANFLITER_H_

#include "HMC5883L.h"
#include "MPU6050.h"

extern double yaw, pitch, roll;

void Kalman_Loop(double dt);//此函数放在循环中，参数为中断间隔（单位s)




//#define RAD_TO_DEG (360/PI/2) // 弧度转角度的转换率
//#define DEG_TO_RAD (2*PI/360) // 角度转弧度的转换率
#define RAD_TO_DEG 57.295779513082320876798154814105  // 弧度转角度的转换率
#define DEG_TO_RAD 0.01745329251994329576923690768489 // 角度转弧度的转换率

#define RESTRICT_PITCH//限定roll角度为±90°

/* Copyright (C) 2012 Kristian Lauszus, TKJ Electronics-> All rights reserved->

  This software may be distributed and modified under the terms of the GNU
  General Public License version 2 (GPL2) as published by the Free Software
  Foundation and appearing in the file GPL2->TXT included in the packaging of
  this file-> Please note that GPL2 Section 2[b] requires that all works based
  on this software must also be made publicly available under the terms of
  the GPL2 ("Copyleft")->

  Contact information
  -------------------

  Kristian Lauszus, TKJ Electronics
  Web      :  http://www->tkjelectronics->com
  e-mail   :  kristianl@tkjelectronics->com
  */

struct Kalman {
    /* Kalman filter variables */
    double Q_angle; // Process noise variance for the accelerometer
    double Q_bias; // Process noise variance for the gyro bias
    double R_measure; // Measurement noise variance - this is actually the variance of the measurement noise

    double angle; // The angle calculated by the Kalman filter - part of the 2x1 state vector
    double bias; // The gyro bias calculated by the Kalman filter - part of the 2x1 state vector
    double rate; // Unbiased rate calculated from the rate and the calculated bias - you have to call getAngle to update the rate

    double P[2][2]; // Error covariance matrix - This is a 2x2 matrix
    double K[2]; // Kalman gain - This is a 2x1 vector
    double y; // Angle difference
    double S; // Estimate error
};


#endif /* AGORITHM_KALMANFLITER_KALMANFLITER_H_ */
