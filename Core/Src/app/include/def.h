

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "main.h"

/*----------------------- STM32 관련 드라이버 정의 -------------------------*/

/* TIME 함수 정의*/
void delay(uint32_t time_ms);
uint32_t millis(void);

/* GPO 이름 채널 정의*/
// Defult Option
#define USB_PENA 				0
#define DBG_LED 				1
#define LCD_PWR_EN 				2
#define BUZZER 					3
#define O_LED 					4
#define O_FAN 					5

/* GPI 이름 채널 정의*/
// Defult Option
#define USB_PFLT 				6

#define GPIO_MAX_CH 6