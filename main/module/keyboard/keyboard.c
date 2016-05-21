#include "base_type.h"
#include "tools.h"
#include "keyboard.h"
#include "platform.h"
#include "display.h"

#define KEYBOARD_INIT	(0xff)
//Line 0 Key
#define _VALUE_KEY0		(0xee)
#define _VALUE_KEY1		(0xde)
#define _VALUE_KEY2		(0xbe)
#define _VALUE_KEY3		(0x7e)
//Line 1 Key
#define _VALUE_KEY4		(0xed)
#define _VALUE_KEY5		(0xdd)
#define _VALUE_KEY6		(0xbd)
#define _VALUE_KEY7		(0x7d)
//Line 2 Key
#define _VALUE_KEY8		(0xeb)
#define _VALUE_KEY9		(0xdb)
#define _VALUE_KEYA		(0xbb)
#define _VALUE_KEYB		(0x7b)
//Line 3 Key
#define _VALUE_KEYC		(0xe7)
#define _VALUE_KEYD		(0xd7)
#define _VALUE_KEYE		(0xb7)
#define _VALUE_KEYF		(0x77)

/*矩阵键盘扫描*/
static H_BOOL __MatrixKeyRelease(void)
{
	H_U8 TmpKey = 0;
	H_U32 TimeOut = 500;
	TmpKey = P3;
	while(((TmpKey&0xf0) != 0xf0) && (TimeOut > 0))
	{
		TmpKey=P3;
		wy_delay(1);
		TimeOut--;
	}
	if(TimeOut > 0)
		return H_TRUE;
	else 
		return	H_FAUSE;
}

static KeyBoard_Type __MatrixScanLine(H_U8 line)
{
	KeyBoard_Type _KeyType = _KEYBOARD_MAX;
	H_U8 TmpKey = 0;
	line=(line > 3)?0:line;
	if(line == 0)
	{
		P3 = 0xfe;
	}else
	{
		P3=((~(0x1 << line)))&0xff;
	}
	
	TmpKey = P3;
	TmpKey = TmpKey&0xf0;
	if(TmpKey != 0xf0)
	{
		wy_delay(10);//延时10ms 去抖动,从新获取P3口值
		TmpKey = P3;
		TmpKey = TmpKey&0xf0;
		if(TmpKey != 0xf0)
		{
			TmpKey = P3;
			switch(TmpKey)
			{
				case _VALUE_KEY0:
					_KeyType = _KEYBOARD_T1;
					break;
				case _VALUE_KEY1:
					_KeyType = _KEYBOARD_T2;
					break;
				case _VALUE_KEY2:
					_KeyType = _KEYBOARD_T3;
					break;
				case _VALUE_KEY3:
					_KeyType = _KEYBOARD_T4;
					break;
				case _VALUE_KEY4:
					_KeyType = _KEYBOARD_T5;
					break;
				case _VALUE_KEY5:
					_KeyType = _KEYBOARD_T6;
					break;
				case _VALUE_KEY6:
					_KeyType = _KEYBOARD_T7;
					break;
				case _VALUE_KEY7:
					_KeyType = _KEYBOARD_T8;
					break;
				case _VALUE_KEY8:
					_KeyType = _KEYBOARD_T9;
					break;
				case _VALUE_KEY9:
					_KeyType = _KEYBOARD_T10;
					break;
				case _VALUE_KEYA:
					_KeyType = _KEYBOARD_T11;
					break;
				case _VALUE_KEYB:
					_KeyType = _KEYBOARD_T12;
					break;
				case _VALUE_KEYC:
					_KeyType = _KEYBOARD_T13;
					break;
				case _VALUE_KEYD:
					_KeyType = _KEYBOARD_T14;
					break;
				case _VALUE_KEYE:
					_KeyType = _KEYBOARD_T15;
					break;
				case _VALUE_KEYF:
					_KeyType = _KEYBOARD_T16;
					break;
				default:
					break;
			}
		}
	}
	if(__MatrixKeyRelease())
	{
		return _KeyType;
	}else
	{
		return _KEYBOARD_MAX;
	}
	
}

static KeyBoard_Type _KeyBoardMatrix(void)
{
	KeyBoard_Type _KeyType = _KEYBOARD_MAX;
	
	_KeyType = __MatrixScanLine(0);
	if(_KeyType == _KEYBOARD_MAX)
	{
		_KeyType = __MatrixScanLine(1);
		if(_KeyType == _KEYBOARD_MAX)
		{
			_KeyType = __MatrixScanLine(2);
			if(_KeyType == _KEYBOARD_MAX)
			{
				_KeyType = __MatrixScanLine(3);
			}
		}
	}
	return _KeyType;
}

/*独立键盘扫描*/
static KeyBoard_Type _KeyBoardIndie(void)
{
	
}

void _MatrixKeyTest(void)
{
	KeyBoard_Type _KeyType = _KeyBoardMatrix();
	if(_KeyType < _KEYBOARD_MAX)
	{
		wy_digital_display(0, _KeyType, 0);
		//wy_delay(1000);
	}
	
	
}


