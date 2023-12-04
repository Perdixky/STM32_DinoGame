/*
 * KalmanFliter.c
 *
 *  Created on: Nov 18, 2023
 *      Author: 32937
 */

#include "KalmanFliter.h"
#include "math.h"

#define MAG0MAX 603
#define MAG0MIN -578
#define MAG1MAX 542
#define MAG1MIN -701
#define MAG2MAX 547
#define MAG2MIN -556//磁力计校准数值

//这里使用多个函数来实现一个函数执行一个功能，从而增强代码的可读性

struct Kalman kalmanX, kalmanY, kalmanZ; // 创建卡尔曼实例

int accX, accY, accZ;
int gyroX, gyroY, gyroZ;
int magX, magY, magZ;
double yaw, pitch, roll;

double gyroXangle, gyroYangle, gyroZangle; // Angle calculate using the gyro only 只用陀螺仪计算角度
double compAngleX, compAngleY, compAngleZ; // Calculated angle using a complementary filter  结合电磁计计算角度
double kalAngleX, kalAngleY, kalAngleZ; // Calculated angle using a Kalman filter    用kalman计算角度

double magGain[3];
float magOffset[3] = { (MAG0MAX + MAG0MIN) / 2, (MAG1MAX + MAG1MIN) / 2, (MAG2MAX + MAG2MIN) / 2 };

MPU6050_DataTypdef MPU6050_Data;
HMC5883L_DataTypedef HMC5883_Data;




void   Init(struct Kalman* klm){
	/* We will set the variables like so, these can also be tuned by the user */
    klm->Q_angle = 0.001;
    klm->Q_bias = 0.003;
    klm->R_measure = 0.03;

    klm->angle = 0; // Reset the angle
    klm->bias = 0; // Reset bias

    klm->P[0][0] = 0; // Since we assume that the bias is 0 and we know the starting angle (use setAngle), the error covariance matrix is set like so - see: http://en->wikipedia->org/wiki/Kalman_filter#Example_application->2C_technical
    klm->P[0][1] = 0;
    klm->P[1][0] = 0;
    klm->P[1][1] = 0;
}

// The angle should be in degrees and the rate should be in degrees per second and the delta time in seconds
double getAngle(struct Kalman * klm, double newAngle, double newRate, double dt) {
    // KasBot V2  -  Kalman filter module - http://www->x-firm->com/?page_id=145
    // Modified by Kristian Lauszus
    // See my blog post for more information: http://blog->tkjelectronics->dk/2012/09/a-practical-approach-to-kalman-filter-and-how-to-implement-it

    // Discrete Kalman filter time update equations - Time Update ("Predict")
    // Update xhat - Project the state ahead
    /* Step 1 */
    klm->rate = newRate - klm->bias;
    klm->angle += dt * klm->rate;

    // Update estimation error covariance - Project the error covariance ahead
    /* Step 2 */
    klm->P[0][0] += dt * (dt*klm->P[1][1] - klm->P[0][1] - klm->P[1][0] + klm->Q_angle);
    klm->P[0][1] -= dt * klm->P[1][1];
    klm->P[1][0] -= dt * klm->P[1][1];
    klm->P[1][1] += klm->Q_bias * dt;

    // Discrete Kalman filter measurement update equations - Measurement Update ("Correct")
    // Calculate Kalman gain - Compute the Kalman gain
    /* Step 4 */
    klm->S = klm->P[0][0] + klm->R_measure;
 /* Step 5 */
     klm->K[0] = klm->P[0][0] / klm->S;
     klm->K[1] = klm->P[1][0] / klm->S;

     // Calculate angle and bias - Update estimate with measurement zk (newAngle)
     /* Step 3 */
     klm->y = newAngle - klm->angle;
     /* Step 6 */
     klm->angle += klm->K[0] * klm->y;
     klm->bias += klm->K[1] * klm->y;

     // Calculate estimation error covariance - Update the error covariance
     /* Step 7 */
     klm->P[0][0] -= klm->K[0] * klm->P[0][0];
     klm->P[0][1] -= klm->K[0] * klm->P[0][1];
     klm->P[1][0] -= klm->K[1] * klm->P[0][0];
     klm->P[1][1] -= klm->K[1] * klm->P[0][1];

 return klm->angle;
}

void setAngle(struct Kalman* klm, double newAngle) { klm->angle = newAngle; } // Used to set angle, this should be set as the starting angle
double getRate(struct Kalman* klm) { return klm->rate; } // Return the unbiased rate

/* These are used to tune the Kalman filter */
void setQangle(struct Kalman* klm, double newQ_angle) { klm->Q_angle = newQ_angle; }
void setQbias(struct Kalman* klm, double newQ_bias) { klm->Q_bias = newQ_bias; }
void setRmeasure(struct Kalman* klm, double newR_measure) { klm->R_measure = newR_measure; }

double getQangle(struct Kalman* klm) { return klm->Q_angle; }
double getQbias(struct Kalman* klm) { return klm->Q_bias; }
double getRmeasure(struct Kalman* klm) { return klm->R_measure; }





void update()
{
	MPU6050_Data = MPU6050_GetData(&hi2c1);
	HMC5883_Data = HMC5883L_GetData(&hi2c3);
	accX = MPU6050_Data.AccX;
	accY = MPU6050_Data.AccY;
	accZ = MPU6050_Data.AccZ;
	gyroX = MPU6050_Data.GyroX;
	gyroY = MPU6050_Data.GyroY;
	gyroZ = MPU6050_Data.GyroZ;
	magX = HMC5883_Data.MagX;
	magY = HMC5883_Data.MagY;
	magZ = HMC5883_Data.MagZ;
}

void updatePitchRoll() {
     // Source: http://www.freescale.com/files/sensors/doc/app_note/AN3461.pdf eq. 25 and eq. 26
     // atan2 outputs the value of -π to π (radians) - see http://en.wikipedia.org/wiki/Atan2
     // It is then converted from radians to degrees
     #ifdef RESTRICT_PITCH // Eq. 25 and 26
     roll = atan2(accY,accZ) * RAD_TO_DEG;
     pitch = atan(-accX / sqrt(accY * accY + accZ * accZ)) * RAD_TO_DEG;
     #else // Eq. 28 and 29
     roll = atan(accY / sqrt(accX * accX + accZ * accZ)) * RAD_TO_DEG;
     pitch = atan2(-accX, accZ) * RAD_TO_DEG;
     #endif
}

void updateYaw() { // See: http://www.freescale.com/files/sensors/doc/app_note/AN4248.pdf
     double rollAngle,pitchAngle,Bfy,Bfx;

     magX *= -1; // Invert axis - this it done here, as it should be done after the calibration
     magZ *= -1;

     magX *= magGain[0];
     magY *= magGain[1];
     magZ *= magGain[2];

     magX -= magOffset[0];
     magY -= magOffset[1];
     magZ -= magOffset[2];


     rollAngle  = kalAngleX * DEG_TO_RAD;
     pitchAngle = kalAngleY * DEG_TO_RAD;

     Bfy = magZ * sin(rollAngle) - magY * cos(rollAngle);
     Bfx = magX * cos(pitchAngle) + magY * sin(pitchAngle) * sin(rollAngle) + magZ * sin(pitchAngle) * cos(rollAngle);
     yaw = atan2(-Bfy, Bfx) * RAD_TO_DEG;

     yaw *= -1;
 }

void InitAll()
{
	MPU6050_INIT(&hi2c1);
	HMC5883L_INIT(&hi2c3);
    /* Set Kalman and gyro starting angle */
	update();
    updatePitchRoll();
    updateYaw();

    setAngle(&kalmanX,roll); // First set roll starting angle
    gyroXangle = roll;
    compAngleX = roll;

    setAngle(&kalmanY,pitch); // Then pitch
    gyroYangle = pitch;
    compAngleY = pitch;

    setAngle(&kalmanZ,yaw); // And finally yaw
    gyroZangle = yaw;
    compAngleZ = yaw;

//    timer = micros; // Initialize the timer
}


void Kalman_Loop(double dt)
{
    double gyroXrate,gyroYrate,gyroZrate;
    /* Update all the IMU values */
    MPU6050_Data = MPU6050_GetData(&hi2c1);
    HMC5883_Data = HMC5883L_GetData(&hi2c3);

//    timer = micros;
//    if(dt<0)dt+=(1<<20);    //时间是周期性的，有可能当前时间小于上次时间，因为这个周期远大于两次积分时间，所以最多相差1<<20

    /* Roll and pitch estimation */
    updatePitchRoll();             //用采集的加速计的值计算roll和pitch的值，换算关系：2^16/250=131.072LSB/(°/S)
    gyroXrate = gyroX / 131.072;     // Convert to deg/s    把陀螺仪的角加速度按照当初设定的量程转换为°/s
    gyroYrate = gyroY / 131.072;     // Convert to deg/s

    #ifdef RESTRICT_PITCH        //如果上面有#define RESTRICT_PITCH就采用这种方法计算，防止出现-180和180之间的跳跃
    // This fixes the transition problem when the accelerometer angle jumps between -180 and 180 degrees
    if ((roll < -90 && kalAngleX > 90) || (roll > 90 && kalAngleX < -90)) {
        setAngle(&kalmanX,roll);
        compAngleX = roll;
        kalAngleX = roll;
        gyroXangle = roll;
    } else
    kalAngleX = getAngle(&kalmanX, roll, gyroXrate, dt); // Calculate the angle using a Kalman filter

    if (fabs(kalAngleX) > 90)
        gyroYrate = -gyroYrate; // Invert rate, so it fits the restricted accelerometer reading
    kalAngleY = getAngle(&kalmanY,pitch, gyroYrate, dt);
    #else
    // This fixes the transition problem when the accelerometer angle jumps between -180 and 180 degrees
    if ((pitch < -90 && kalAngleY > 90) || (pitch > 90 && kalAngleY < -90)) {
        kalmanY.setAngle(pitch);
        compAngleY = pitch;
        kalAngleY = pitch;
        gyroYangle = pitch;
    } else
    kalAngleY = getAngle(&kalmanY, pitch, gyroYrate, dt); // Calculate the angle using a Kalman filter

    if (abs(kalAngleY) > 90)
        gyroXrate = -gyroXrate; // Invert rate, so it fits the restricted accelerometer reading
    kalAngleX = getAngle(&kalmanX, roll, gyroXrate, dt); // Calculate the angle using a Kalman filter
    #endif


    /* Yaw estimation */
    updateYaw();
    gyroZrate = gyroZ / 131.072; // Convert to deg/s
    // This fixes the transition problem when the yaw angle jumps between -180 and 180 degrees
    if ((yaw < -90 && kalAngleZ > 90) || (yaw > 90 && kalAngleZ < -90)) {
        setAngle(&kalmanZ,yaw);
        compAngleZ = yaw;
        kalAngleZ = yaw;
        gyroZangle = yaw;
    } else
    kalAngleZ = getAngle(&kalmanZ, yaw, gyroZrate, dt); // Calculate the angle using a Kalman filter


    /* Estimate angles using gyro only */
    gyroXangle += gyroXrate * dt; // Calculate gyro angle without any filter
    gyroYangle += gyroYrate * dt;
    gyroZangle += gyroZrate * dt;
    //gyroXangle += kalmanX.getRate() * dt; // Calculate gyro angle using the unbiased rate from the Kalman filter
    //gyroYangle += kalmanY.getRate() * dt;
    //gyroZangle += kalmanZ.getRate() * dt;

    /* Estimate angles using complimentary filter 互补滤波算法*/
    compAngleX = 0.93 * (compAngleX + gyroXrate * dt) + 0.07 * roll; // Calculate the angle using a Complimentary filter
    compAngleY = 0.93 * (compAngleY + gyroYrate * dt) + 0.07 * pitch;
    compAngleZ = 0.93 * (compAngleZ + gyroZrate * dt) + 0.07 * yaw;

    // Reset the gyro angles when they has drifted too much
    if (gyroXangle < -180 || gyroXangle > 180)
        gyroXangle = kalAngleX;
    if (gyroYangle < -180 || gyroYangle > 180)
        gyroYangle = kalAngleY;
    if (gyroZangle < -180 || gyroZangle > 180)
        gyroZangle = kalAngleZ;
}
