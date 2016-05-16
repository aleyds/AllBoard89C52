
#include "keyboard.h"
#include "platform.h"

static KeyBoard_Type _KeyBoardScan(void)
{
	KeyBoard_Type _KeyType = _KEYBOARD_MAX;
	
	if(KEYBOARD_T1&0x1)
	{
		_KeyType = _KEYBOARD_T1;
	}else if(KEYBOARD_T2&0x1)
	{
		_KeyType = _KEYBOARD_T2;
	}else if(KEYBOARD_T3&0x1)
	{
		_KeyType = _KEYBOARD_T3;
	}else if(KEYBOARD_T4&0x1)
	{
		_KeyType = _KEYBOARD_T4;
	}else if(KEYBOARD_T5&0x1)
	{
		_KeyType = _KEYBOARD_T5;
	}else if(KEYBOARD_T6&0x1)
	{
		_KeyType = _KEYBOARD_T6;
	}else if(KEYBOARD_T7&0x1)
	{
		_KeyType = _KEYBOARD_T7;
	}else if(KEYBOARD_T8&0x1)
	{
		_KeyType = _KEYBOARD_T8;
	}else if(KEYBOARD_T9&0x1)
	{
		_KeyType = _KEYBOARD_T9;
	}else if(KEYBOARD_T10&0x1)
	{
		_KeyType = _KEYBOARD_T10;
	}else if(KEYBOARD_T11&0x1)
	{
		_KeyType = _KEYBOARD_T11;
	}else if(KEYBOARD_T12&0x1)
	{
		_KeyType = _KEYBOARD_T12;
	}else if(KEYBOARD_T13&0x1)
	{
		_KeyType = _KEYBOARD_T13;
	}else if(KEYBOARD_T14&0x1)
	{
		_KeyType = _KEYBOARD_T14;
	}else if(KEYBOARD_T15&0x1)
	{
		_KeyType = _KEYBOARD_T15;
	}
	return _KeyType;
}


