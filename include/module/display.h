#ifndef __LED_H__
#define __LED_H__

typedef enum{
	_LED_0,
	_LED_1,
	_LED_2,
	_LED_3,
	_LED_4,
	_LED_5,
	_LED_6,
	_LED_7,
	_LED_MAX,
}LedType_e;

H_S32 wy_led_display(LedType_e type, H_BOOL on);
void _LEDTest(void);
void _DigitalTest();
#endif