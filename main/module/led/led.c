#include "base_type.h"
#include "tools.h"
#include "display.h"

H_S32 wy_led_display(LedType_e type, H_BOOL on)
{
	H_U8 st = (on == 0)?1:0;
	switch(type)
	{
		case _LED_0:
			DIS_LED0=st;
			break;
		case _LED_1:
			DIS_LED1=st;
			break;
		case _LED_2:
			DIS_LED2=st;
			break;
		case _LED_3:
			DIS_LED3=st;
			break;
		case _LED_4:
			DIS_LED4=st;
			break;
		case _LED_5:
			DIS_LED5=st;
			break;
		case _LED_6:
			DIS_LED6=st;
			break;
		case _LED_7:
			DIS_LED7=st;
			break;
		default:
			break;
	}
	return H_SUCCESS;
}

void _LEDTest(void)
{
	H_U32 i = 0;
	for(i = 0; i < _LED_MAX; i++)
	{
		wy_led_display(i, H_TRUE);
		wy_delay(1000);
		wy_led_display(i, H_FAUSE);
	}
}