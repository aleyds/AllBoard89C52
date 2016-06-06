#include"base_type.h"
#include "timer.h"

//��ͬ����ʱ1ms��ʼ��ͬ�����ݾ���ʹ�ý�������
#define TIMER0TH		0x1C //1ms  ����11.0592MHz 0x1C   ����16MHz 0x1A   ����12MHz 0x1C
#define TIMER0TL		0x66 //1ms  ����11.0592MHz 0x66	����16MHz 0xCB	 ����12MHz 0x18

static LIST_HEAD(g_TimerList);

//������0  ��Ϊͨ�ö�ʱ��  ������ʽ0
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
				if(_pPos->_TicksCount == 0)//����ʱ�䵽�����
				{
					_pPos->_TicksCount = _pPos->_TicksInit;//�������¸�ֵ
					_pPos->_Handler();//�������������
					if(_pPos->_Mode == _MODE_ONCE)//ִֻ��һ�εĶ�ʱ�����ͷ���Դ
					{
						_pPos->_State = _STATE_INIT;
					}
				}
			}else if(_pPos->_State == _STATE_STOP)
			{
				_pPos->_TicksCount = _pPos->_TicksInit;//�������¸�ֵ
			}
			
		}
	}
}

void _TimerInit(void)
{
	//��ʱ��T0Ϊ���ö�ʱ��
	TR0 = 0;//�ȹرն�ʱ��0
	TMOD |= 0x00;//��ʱ�������ڷ�ʽ0
	TH0 = TIMER0TH; //���ö�ʱ��0��ֵ 5ms
	TL0 = TIMER0TL;
	ET0=1;//������ʱ��0�ж�
	TR0=1;//������ʱ��0
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


