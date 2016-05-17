#include "base_type.h"
#include "display.h"
#include "tools.h"

static H_U8 gDigitalTable[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 
							 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};
#define TABLE_LEN		(sizeof(gDigitalTable)/sizeof(gDigitalTable[0]))
//
void wy_digital_display(H_U8 number, H_U8 display, H_U8 point)
{
	H_U8 p = (point == 0)?0:0x80;
	H_U8 TableLen = TABLE_LEN;
	
	//选择对应的数码管显示
	DIG_SELECTA = number&0x1;
	DIG_SELECTB = ((number >> 1)&0x1);
	DIG_SELECTC = ((number >> 2)&0x1);
	
	//开启数码数据显示
	display = display%TableLen;
	P0 = (gDigitalTable[display] | p);
	//关闭显示锁存
}

void wy_digital_hide(H_U8 number)
{
	//选择对应的数码管显示
	DIG_SELECTA = number&0x1;
	DIG_SELECTB = ((number >> 1)&0x1);
	DIG_SELECTC = ((number >> 2)&0x1);
	
	//开启数码数据显示
	P0 = 0x0;
	//关闭显示锁存
}

void _DigitalTest()
{
	H_U8 i = 0;
	for(i = 0; i < 8; i++)
	{
		wy_digital_display(i, i, i);
		wy_delay(2);
		//wy_digital_hide(i);
		//wy_delay(1000);
	}
}