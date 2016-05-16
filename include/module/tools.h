#ifndef __TOOLS_H__
#define __TOOLS_H__

typedef struct MainMessage{
	H_U16 msg_type;
	H_U16 msg_code;
	H_U32 param1;
	H_U32 param2;
}MainMessage_t,*pMainMessage_t;

void wy_delay(H_U32 ms);
void wy_SysReset(void);
#endif