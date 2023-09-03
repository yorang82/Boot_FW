#include "utils.h"
// #include "uart.h"




void delay(uint32_t time_ms)
{
	HAL_Delay(time_ms);
}

uint32_t millis(void)
{
	return HAL_GetTick();
}


/*------ printf 사용시 UART 포트로 출력 하는 함수 ------*/
// int __io_putchar(int ch)
// {
// 	uartWrite(DBUG_UART, (uint8_t *)&ch, 1);
// 	//uartWrite(LCD_UART, (uint8_t *)&ch, 1);

// 	return 1;
// }