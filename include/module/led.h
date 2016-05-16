#ifndef __LED_H__
#define __LED_H__

typedef enum{
	_LED_0,
	_LED_1,
	_LED_2,
}LedType_e;

H_S32 wy_led_display(LedType_e type, H_BOOL on);
#endif