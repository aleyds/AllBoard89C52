#include"base_type.h"
#include "timer.h"

//不同晶振定时1ms初始不同，根据具体使用进行配置
#define TIMER0TH		0x1C //1ms  晶振11.0592MHz 0x1C   晶振16MHz 0x1A   晶振12MHz 0x1C
#define TIMER0TL		0x66 //1ms  晶振11.0592MHz 0x66	晶振16MHz 0xCB	 晶振12MHz 0x18

static LIST_HEAD(g_TimerList);

//定期器0  作为通用定时器  工作方式0
void _Timer0IRQHandler(void) interrupt 1
{
	TimerList_T *_pPos;
	TH0=TIMER0TH; 
	TL0=TIMER0TL;
	
	list_for_each_entry(_pPos, &g_TimerList, entries, TimerList_T)
	{
		if(_pPos != H_NULL)
		{
			if(_pPos->_State == _STATE_START)
			{
				if(_pPos->_TicksCount == 0)//计数时间到，溢出
				{
					_pPos->_TicksCount = _pPos->_TicksInit;//计数重新赋值
					_pPos->_Handler();//调用溢出处理函数
					if(_pPos->_Mode == _MODE_ONCE)//只执行一次的定时器，释放资源
					{
						_pPos->_State = _STATE_INIT;
					}
				}
			}else if(_pPos->_State == _STATE_STOP)
			{
				_pPos->_TicksCount = _pPos->_TicksInit;//计数重新赋值
			}
			
		}
	}
}

void _TimerInit(void)
{
	//定时器T0为常用定时器
	TR0 = 0;//先关闭定时器0
	TMOD |= 0x00;//定时器工作在方式0
	TH0 = TIMER0TH; //设置定时器0初值 5ms
	TL0 = TIMER0TL;
	ET0=1;//开启定时器0中断
	TR0=1;//开启定时器0
}

H_U32 _TimerCreat(TimerList_T *_Timer)
{
	list_add_tail(&_Timer->entries, &g_TimerList);
	return _Timer->_TimerID;
}

void _TimerStart(H_U32 _TimerID)
{
	TimerList_T *_pPos;
	list_for_each_entry(_pPos, &g_TimerList, entries, TimerList_T)
	{
		if(_pPos != H_NULL)
		{
			if(_TimerID == _pPos->_TimerID)
			{
				_pPos->_State = _STATE_START;
				return;
			}
		}
	}
}

void _TimerStop(H_U32 _TimerID)
{
	TimerList_T *_pPos;
	list_for_each_entry(_pPos, &g_TimerList, entries, TimerList_T)
	{
		if(_pPos != H_NULL)
		{
			if(_TimerID == _pPos->_TimerID)
			{
				_pPos->_State = _STATE_STOP;
				return;
			}
		}
	}
}


