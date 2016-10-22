/*
hmc5883l lib sample

copyright (c) Davide Gironi, 2016

Released under GPLv3.
Please refer to LICENSE file for licensing information.

*/


#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>

//#define F_CPU 16000000UL
#include <util/delay.h>
#include "math.h"

#include "hmc5883l/hmc5883l.h"
#include "mpu6050/mpu6050.h"

#define MAGN_DOCALIBRATION 0 //enable or disable magnetometer calibration
#define magncal_getrawdata(mxraw, myraw, mzraw) hmc5883l_getrawdata(mxraw, myraw, mzraw); //set the function that return magnetometer raw values
#include "magn_docalibration.h"

#include "uart/uart.h"

#define DIV 128


//KF
typedef struct {
	double q; //process noise covariance
	double r; //measurement noise covariance
	double x; //value
	double p; //estimation error covariance
	double k; //kalman gain
} kalman_state;


kalman_state kalman_init(double q, double r, double p, double intial_value)
{
	kalman_state result;
	result.q = q;
	result.r = r;
	result.p = p;
	result.x = intial_value;

	return result;
}

void kalman_update(kalman_state* state, double measurement)


	//prediction update
	//omit x = x

	state->p = state->p + state->q;

	//measurement update
	state->k = state->p / (state->p + state->r);
	state->x = state->x + state->k * (measurement - state->x);
	state->p = (1 - state->k) * state->p;
}


//KF

void adc_init(void)
{

	ADMUX = 0x40;

	ADCSRA = 0x87;

	DDRF = 0x00;
}

int adc_get(int8_t ad_port)
{
	ADMUX |= ad_port;
	ADCSRA = (1 << ADEN) | (1 << ADSC) | (7 << ADPS0);

	_delay_ms(10);

	while (!(ADCSRA&(1 << ADIF)));

	ADMUX = 0x40;

	return ADC;

}


int main(void) {

int count=0;

	int16_t mxraw = 0;
	int16_t myraw = 0;
	int16_t mzraw = 0;
	double mx,my,mz;
	double ax,ay,az,gx,gy,gz;
	//int16_t ax, ay, az, gx, gy, gz;

	int16_t finger[8];

	int16_t packet[17];

	char itmp[10];

	int i = 0;//loop index 

	kalman_state kf[16];
	for (i = 0; i < 16; i++)
	{
		//kf[i] = kalman_init(0.00001, 0.005, 1, 0);//filter initializing
		if(i<7)
		kf[i]=kalman_init(0.001,0.005,1,0);
		kf[i] = kalman_init(0.001, 0.05, 1, 0);
	}


	//initializing uart 115200 baud rate.
	uart_init(8, 8);

	//init interrupt
	sei();

	//init hmc5883
	hmc5883l_init();

	//init mpu6050
	mpu6050_init();

	//init adc
	adc_init();

#if MAGN_DOCALIBRATION  == 1
	magncal_docalibrationclient(uart_putc, uart_getc);
#endif




	packet[0] = (int16_t)0x7FFF;
	for (;;) {



		//magnetic seneors
//		hmc5883l_getrawdata(&mxraw, &myraw, &mzraw);

		hmc5883l_getdata(&mx, &my, &mz);

		//gyro, accelerate sensors
//		mpu6050_getRawData(&ax, &ay, &az, &gx, &gy, &gz);
		mpu6050_getConvData(&ax, &ay, &az, &gx, &gy, &gz);
		
	//	mpu6050_updateQuaternion();
	//	mpu6050_getRollPitchYaw(&ax,&ay,&az);
	//	gx+=32; gy-=12;
	//	ax /= DIV; ay /= DIV; az /= DIV; 
	//	gx /= DIV; gy /= DIV; gz /= DIV;

		//adc covert(finger flex,pressure)
		for (i = 0; i < 7; i++)
		{
			packet[i+1] = adc_get(i);
		//	if(i==4||i==5)
			{
		//	packet[i+1]-=160;
			}
		//	packet[i+1]*=3;
		//	_delay_ms(100);
		}





		//Ä®¸¸ ÇÊÅÍ

		/*
		itoa(mxraw, itmp, 10); uart1_puts(itmp); uart1_putc(' ');
		itoa(myraw, itmp, 10); uart1_puts(itmp); uart1_putc(' ');
		itoa(mzraw, itmp, 10); uart1_puts(itmp); uart1_putc(' ');
		itoa(ax,itmp,10); uart1_puts(itmp); uart1_putc(' ');
		itoa(ay,itmp,10); uart1_puts(itmp); uart1_putc(' ');
		itoa(az,itmp,10); uart1_puts(itmp); uart1_putc(' ');
		itoa(gx,itmp,10); uart1_puts(itmp); uart1_putc(' ');
		itoa(gy,itmp,10); uart1_puts(itmp); uart1_putc(' ');
		itoa(gz,itmp,10); uart1_puts(itmp); uart1_putc(' ');

		for(i=0;i<7;i++)
		{
		itoa(finger[i],itmp,10); uart1_puts(itmp); uart1_putc(' ');
		}
		*/

		//uart1_puts("\r\n");

		packet[8] = mxraw;
		packet[9] = myraw;
		packet[10] = mzraw;
		packet[8] = (int16_t)(mx*100);
		packet[9] = (int16_t)(my*100);
		packet[10] = (int16_t)(mz*100);

		packet[11] = (int16_t)(ax*10000);
		packet[12] = (int16_t)(ay*10000);
		packet[13] = (int16_t)(az*10000);

		packet[14] = (int16_t)(gx*100);
		packet[15] = (int16_t)(gy*100);
		packet[16] = (int16_t)(gz*100);

		for (i = 1; i < 17; i++)
		{


		//	if(packetb[i]-packet[i]>-8&&packetb[i]-packet[i]<8)
		//	packet[i]=packetb[i];
			//if (i > 7)
			{
				kalman_update(&kf[i-1], (double)packet[i]);
				packet[i] = (int16_t)kf[i-1].x;
			}	
				if (packet[i] == (int16_t)32767)
					packet[i] = (int16_t)32766;

		}

	//	packet[i]=(int16_t)0x7374;
		uart_puts_len((char*)packet, 34);
		   // _delay_ms(100);
	}

}
