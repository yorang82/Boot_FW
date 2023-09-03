#include "app.h"    


void apInit(void)
{
    gpioInit();
}

void apMain(void)
{
    uint32_t pre_time;

    gpoOn(BUZZER);
	delay(500);
	gpoOff(BUZZER);

	while(1)
	{
		// non block time
		if (millis()-pre_time >= 1000)
		{
			pre_time = millis();

			gpoToggle(DBG_LED);
		}
    }    
}