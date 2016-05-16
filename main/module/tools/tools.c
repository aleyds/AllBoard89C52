#include"base_type.h"
#include "platform.h"
#include "tools.h"

void wy_delay(H_U32 ms)
{
	H_U32 i = 0;
	H_U32 j = 0;
	for(i = ms; i> 0; i--)
	{
		for(j = 110; j > 0; j--)
		{
			
		}
	}
}

void wy_SysReset(void)
{
	ISP_CONTR = 0x20;
}

