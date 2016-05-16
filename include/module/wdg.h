#ifndef __WDG_H__
#define __WDG_H__

#define WDG_REGISTER			0xe1
#define WDG_EN						(1<<5)
#define WDG_CLR						(1<<4)
#define WDG_IDLE					(1<<3)

enum{
	_WDG_FREQ2,     	//65.5ms
	_WDG_FREQ4,			//131.0ms
	_WDG_FREQ8,			//262.1ms
	_WDG_FREQ16,		//524.2ms
	_WDG_FREQ32,		//1.0485s
	_WDG_FREQ64,		//2.0971s
	_WDG_FREQ128,		//4.1943s
	_WDG_FREQ256,		//8.3886
};

H_S32 wy_wdg_start(void);

#endif