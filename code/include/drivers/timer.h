#ifndef __TIMER_H___
#define __TIMER_H___
#include "list.h"
typedef void (*TimerCallback)(void);

typedef enum {
	_STATE_INIT,	//初始化状态,不可计数
	_STATE_START, //开始状态，开始计数
	_STATE_STOP, //停止状态，不可计数，计数值清零
	_STATE_PAUSE, //暂停状态，不可计数，计数值不清零
}TimerState_t;

typedef enum{
	_MODE_ONCE,//仅仅执行一次
	_MODE_REPEATED, //重复执行
}TimerMode_t;

typedef struct {
	struct list_head entries;
	H_U32 _TimerID; //定时器标识
	TimerState_t _State; //使用状态
	TimerMode_t _Mode;//使用模式
	H_U32 _TicksInit; //初始计数值
	H_U32 _TicksCount;//计数值
	TimerCallback _Handler;//技术到后的回调函数
}TimerList_T;

void _TimerInit(void);
H_U32 _TimerCreat(TimerList_T *_Timer);
void _TimerStart(H_U32 _TimerID);
void _TimerStop(H_U32 _TimerID);
#endif