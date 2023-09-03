#include "def.h"

bool gpioInit(void);
bool gpioPinMode(uint8_t ch, uint8_t mode);
void gpioPinWrite(uint8_t ch, bool value);
bool gpiRede(uint8_t ch);
void gpoOn(uint8_t ch);
void gpoOff(uint8_t ch);
void gpoToggle(uint8_t ch);


