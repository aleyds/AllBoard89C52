#include "base_type.h"
#include "uart.h"
#include "timer.h"
#include "REG51.H"

sbit Led1 = P1^0;
sbit Led2 = P1^ 1;
sbit Led3 = P1^ 2;
sbit Led4 = P1^ 3;

static char g_StartSonser = 0;

static void _SystemInit(void)
{
	EA=1;
}

static void _Timer0Callback(void)
{
	hs_printf("Timer0 Callback\n\r");
}

static void TimerTest(void)
{
	static TimerList_T _TimerComm;
	_TimerComm._TimerID =0;
	_TimerComm._State = _STATE_INIT;
	_TimerComm._Mode = _MODE_REPEATED;
	_TimerComm._TicksInit = 1000;//1s
	_TimerComm._Handler = _Timer0Callback;
	_TimerCreat(&_TimerComm);
	_TimerStart(_TimerComm._TimerID);
}

//Test Main function
void main()
{
	_SystemInit();
	//Uart Init
	_UartOpen();
	//Timer Init
	_TimerInit();
	
	TimerTest();
	
	while(1)
	{
		
	}
}

