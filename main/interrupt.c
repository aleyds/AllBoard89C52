#include "base_type.h"
#include "display.h"



void wy_External0(void) interrupt 0
{
	//TODO:外部中断INT0
}


void wy_External1(void) interrupt 2
{
	//TODO:外部中断INT1
}



void wy_uart(void) interrupt 4
{
	//TODO:串口中断
	if(RI)//串口数据接收标志
	{
		RI = 0;//清除标志
		
	}
}



void wy_External2(void) interrupt 6
{
	//TODO:外部中断INT2
}

void wy_External3(void) interrupt 7
{
	//TODO:外部中断INT3
}