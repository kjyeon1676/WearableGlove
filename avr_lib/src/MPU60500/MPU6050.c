#include "MPU6050.h"
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>



char mpu6050_read(char addr)
{
 unsigned char data; // data넣을 변수 

  TWCR=0xA4; // S

  while((TWCR&0x80)==0x00); //통신대기 

  while((TWSR&0xF8)!=0x08); //신호대기 

  TWDR=0xD0; // AD+W

  TWCR=0x84; // 전송 
  
  while((TWCR&0x80)==0x00); //통신대기 

  while((TWSR&0xF8)!=0x18); //ACK

  TWDR=addr; // RA

  TWCR=0x84; //전송 
  
  while((TWCR&0x80)==0x00); //통신대기 

  while((TWSR&0xF8)!=0x28); //ACK

  TWCR=0xA4; // RS 

  while((TWCR&0x80)==0x00); //통신대기

  while((TWSR&0xF8)!=0x10); //ACK

  TWDR=0xD1; // AD+R 

  TWCR=0x84; //전송  

  while((TWCR&0x80)==0x00); //통신대기

  while((TWSR&0xF8)!=0x40); // ACK 

  TWCR=0x84;//전송    

  while((TWCR&0x80)==0x00); //통신대기

  while((TWSR&0xF8)!=0x58); //ACK

  data=TWDR; 

  TWCR=0x94; // P

  return data; 
}

void mpu6050_write(char addr, char data)
{ 
 TWCR=0xA4; // S 

  while((TWCR&0x80)==0x00); // 전송 대기

  while((TWSR&0xF8)!=0x08); //신호 대기 

   

  TWDR=0xD0; // AD+W저장 

  TWCR=0x84; // 전송 

 

  while((TWCR&0x80)==0x00); //전송대기 

  while((TWSR&0xF8)!=0x18); //ACK대기

  TWDR=addr; // RA

  TWCR=0x84; // 전송  

  

  while((TWCR&0x80)==0x00); 

  while((TWSR&0xF8)!=0x28); // ACK

  TWDR=data; // DATA 

  TWCR=0x84; // 전송  

  

  while((TWCR&0x80)==0x00); 

  while((TWSR&0xF8)!=0x28); // ACK 

  TWCR|=0x94; // P
}


void mpu6050_getrawdata(int16_t *axraw,int16_t *ayraw,int16_t *azraw,int16_t *gxraw,int16_t *gyraw,int16_t *gzraw)
{

char buffer[12];
    buffer[0] = mpu6050_read(0x3B);
    buffer[1] = mpu6050_read(0x3C);
    buffer[2] = mpu6050_read(0x3D);
    buffer[3] = mpu6050_read(0x3E);
    buffer[4] = mpu6050_read(0x3F);
    buffer[5] = mpu6050_read(0x40);
     
    buffer[6] = mpu6050_read(0x43);
    buffer[7] = mpu6050_read(0x44);
    buffer[8] = mpu6050_read(0x45);
    buffer[9] = mpu6050_read(0x46);
    buffer[10] = mpu6050_read(0x47);
    buffer[11] = mpu6050_read(0x48);
     
    *axraw = (int)buffer[0] << 8 | (int)buffer[1];
    *ayraw = (int)buffer[2] << 8 | (int)buffer[3];
    *azraw = (int)buffer[4] << 8 | (int)buffer[5];
    *gxraw = (int)buffer[6] << 8 | (int)buffer[7];
    *gyraw = (int)buffer[8] << 8 | (int)buffer[9];
    *gzraw = (int)buffer[10] << 8 | (int)buffer[11];
}
