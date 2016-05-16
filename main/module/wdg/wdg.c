#include "base_type.h"
#include "wdg.h"

sfr WDG_CONTR=WDG_REGISTER;

H_S32 wy_wdg_start(void)
{
		WDG_CONTR=(WDG_EN|WDG_CLR|_WDG_FREQ128);
		return 0;
}
