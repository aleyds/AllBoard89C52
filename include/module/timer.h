#ifndef __TIMER_H___
#define __TIMER_H___
typedef enum{
	_TIMER0,
	_TIMER1,
	_TIMER2,
}_TimerType_e;

typedef void (*TimerCallback)(void);

H_U32 wy_timer_open(_TimerType_e type, H_U32 time,TimerCallback call);
H_U32 wy_timer_close(_TimerType_e type);

#endif