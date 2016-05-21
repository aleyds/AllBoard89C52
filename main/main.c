#include "base_type.h"
#include "wdg.h"
#include "display.h"
#include "tools.h"
#include "timer.h"
#include "keyboard.h"
#include "REG51.H"

sbit Led1 = P1^0;
sbit Led2 = P1^ 1;
sbit Led3 = P1^ 2;
sbit Led4 = P1^ 3;

static char g_StartSonser = 0;

static void _InterruptOpen(void)
{
	EA=1;
}

static void _InterruptClose(void)
{
	EA=0;
}

static void _Timer0Callback(void)
{
	if(SONSER_VDET&0x1)//�������ź�Ϊ�ߵ�ƽ
	{
		//TODO:�޵��ת�����Ͽ��̵���ֹͣ�򹤿ذ幩��
	}
}

#if 0
//Project running Main
void main()
{
	KeyBoard_Type _KeyType = _KEYBOARD_T1;
	H_U32 TimerTime = 0;
	//Step1:Interrupt Init 
	_InterruptOpen();
	//Step2:wait check click
	while(1)
	{
		
		if(START_VDET&0x1)//��⿪ʼ�źź�ʼ��⴫�����ź�
		{
			g_StartSonser = 1;
		}
		if(g_StartSonser == 1)
		{
			_KeyType = _KeyBoardScan();
			if(_KeyType != _KEYBOARD_MAX)
			{
				wy_timer_close(_TIMER0);
				TimerTime = 100*_KeyType + 100;
				wy_timer_open(_TIMER0, TimerTime, _Timer0Callback);
			}
		}
		
		
	}
}

#else

//Test Main function
void main()
{
	//wy_wdg_start();
	//wy_led_display(_LED_0, H_TRUE);
	//wy_led_display(_LED_1, H_TRUE);
	//wy_led_display(_LED_2, H_TRUE);
	//_InterruptOpen();
	//wy_timer_open(_TIMER0,10000);
	
	while(1)
	{
		_MatrixKeyTest();
		//wy_delay(1000);
		//Led1=1;
		//wy_led_display(_LED_0, H_FAUSE);
		//wy_delay(1000);
		//wy_SysReset();
		//wy_led_display(_LED_1, H_FAUSE);
		//wy_led_display(_LED_2, H_FAUSE);
	}
}
#endif

