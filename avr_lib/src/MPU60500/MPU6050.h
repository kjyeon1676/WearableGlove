
#ifndef MPU6050_H__
#define MPU6050_H__
#include <stdint.h>

extern void mpu6050_getrawdata(int16_t *axraw,int16_t *ayraw,int16_t *azraw,int16_t *gxraw,int16_t *gyraw,int16_t *gzraw);
extern char mpu6050_read(char addr);
extern void mpu6050_write(char addr, char data);

#endif
