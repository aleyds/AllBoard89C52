#include "base_type.h"
#include "led.h"

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
		default:
			break;
	}
	return H_SUCCESS;
}