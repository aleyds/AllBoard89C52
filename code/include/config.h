#ifndef __CONFIG_H__
#define __CONFIG_H__

//Platform  Enable
#define P_STC_89C51				(0)
#define P_STC_89C52				(1)
#define P_STC_90C58AD			(2)
#define P_TYPE					(P_STC_89C52)

//Driver Enable
#define TIMER_ENABLE
#define I2C_ENABLE
#define SPI_ENABLE
#define UART_ENABLE
#define RFID_M401C		 //԰־�Ƽ�
#define RFID_MFRC522	 //Nxp RC522 оƬ
#define RFID_THM3010	//�������Ƽ�

//Modules Enable
#define M_KEYBOARD_ENABLE		
#define M_LED_ENABLE
#define M_LCD_ENABLE
#define M_TFT_ENBALE
#define M_RFID_ENABLE


#endif