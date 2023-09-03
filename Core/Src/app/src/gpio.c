#include "gpio.h"

/* GPIO MODE 정의*/
#define      _DEF_INPUT               0
#define      _DEF_INPUT_PULLUP        1
#define      _DEF_INPUT_PULLDOWN      2
#define      _DEF_OUTPUT              3
#define      _DEF_OUTPUT_PULLUP       4
#define      _DEF_OUTPUT_PULLDOWN     5

/*GPIO PULL 정의*/
#define      _DEF_LOW                 0
#define      _DEF_HIGH                1

 /* GPO 의 PORT,PIN,STATE 값관련 TABLE*/
  typedef struct
  {
    GPIO_TypeDef     *port;
    uint32_t         pin;
    uint8_t          mode;
    bool             init_value;
    GPIO_PinState    on;
    GPIO_PinState    off;

  }gpio_tbl_t;

  /* 사용할 GPO의 PORT,PIN, STATE값을 TABLE에 정의*/
   gpio_tbl_t  gpio_tbl[GPIO_MAX_CH] =
       {
    		   /*--------------- GPO Table Setting Value-----------------------------*/
    	   {USB_PENA_GPIO_Port,	  USB_PENA_Pin, 	_DEF_OUTPUT_PULLDOWN, _DEF_LOW,  GPIO_PIN_RESET, GPIO_PIN_SET  },
           {DBG_LED_GPIO_Port,    DBG_LED_Pin,    	_DEF_OUTPUT_PULLUP,   _DEF_HIGH, GPIO_PIN_SET,   GPIO_PIN_RESET},
           {BUZZER_GPIO_Port,     BUZZER_Pin,     	_DEF_OUTPUT_PULLDOWN, _DEF_LOW,  GPIO_PIN_SET,   GPIO_PIN_RESET},
           {O_LED_GPIO_Port,      O_LED_Pin,      	_DEF_OUTPUT_PULLUP,   _DEF_HIGH, GPIO_PIN_SET,   GPIO_PIN_RESET},
           {O_FAN_GPIO_Port,  	  O_FAN_Pin,     	_DEF_OUTPUT_PULLUP,   _DEF_HIGH, GPIO_PIN_SET,   GPIO_PIN_RESET},
		      /*--------------- GPI Table Setting Value-----------------------------*/
		   {USB_PFLT_GPIO_Port,	  USB_PFLT_Pin,   	_DEF_INPUT_PULLDOWN,  false,     GPIO_PIN_SET,   GPIO_PIN_RESET},
       };

bool gpioInit(void)
{
    bool ret = true;

	for (int i=0; i<GPIO_MAX_CH; i++)
	  {
		  gpioPinMode(i, gpio_tbl[i].mode);
		  gpioPinWrite(i, gpio_tbl[i].init_value);
	  }

#ifdef _USE_CLI
   cliAdd("GPIO", cliGpio);
#endif

	return ret;
}

bool gpioPinMode(uint8_t ch, uint8_t mode)
{
	bool ret = true;

	  GPIO_InitTypeDef GPIO_InitStruct = {0};

	  switch(mode)
	  {
	  case _DEF_INPUT:
		  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		  GPIO_InitStruct.Pull = GPIO_NOPULL;
		  break;

	  case _DEF_INPUT_PULLUP:
		  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		  GPIO_InitStruct.Pull = GPIO_PULLUP;
		  break;

	  case _DEF_INPUT_PULLDOWN:
		  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
		  break;

	  case _DEF_OUTPUT:
		  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		  GPIO_InitStruct.Pull = GPIO_NOPULL;
		  break;

	  case _DEF_OUTPUT_PULLUP:
		  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		  GPIO_InitStruct.Pull = GPIO_PULLUP;
		  break;

	  case _DEF_OUTPUT_PULLDOWN:
		  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
		  break;
	  }

	  GPIO_InitStruct.Pin = gpio_tbl[ch].pin;
	  HAL_GPIO_Init(gpio_tbl[ch].port, &GPIO_InitStruct);

	return ret;
}

void gpioPinWrite(uint8_t ch, bool value)
{
	if(ch >= GPIO_MAX_CH)
	{
		return ;
	}

	if(value == true)
	{
		HAL_GPIO_WritePin(gpio_tbl[ch].port, gpio_tbl[ch].pin, gpio_tbl[ch].on);
	}
	else
	{
		HAL_GPIO_WritePin(gpio_tbl[ch].port, gpio_tbl[ch].pin, gpio_tbl[ch].off);
	}
}

bool gpiRede(uint8_t ch)
{
	bool ret = false;

	if(ch >= GPIO_MAX_CH)
	{
		return false;
	}

	if (HAL_GPIO_ReadPin(gpio_tbl[ch].port, gpio_tbl[ch].pin) == gpio_tbl[ch].on)
	{
		ret = true;
	}

	return ret;
}

void gpoOn(uint8_t ch) 
{
	 if(ch >= GPIO_MAX_CH) return;
	 HAL_GPIO_WritePin(gpio_tbl[ch].port, gpio_tbl[ch].pin, gpio_tbl[ch].on);
}

void gpoOff(uint8_t ch)
{
    if (ch >= GPIO_MAX_CH) return;
	HAL_GPIO_WritePin(gpio_tbl[ch].port, gpio_tbl[ch].pin, gpio_tbl[ch].off);
}

void gpoToggle(uint8_t ch)
{
	if (ch >= GPIO_MAX_CH) return;
	HAL_GPIO_TogglePin(gpio_tbl[ch].port, gpio_tbl[ch].pin);
}
