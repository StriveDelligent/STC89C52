#include "Delay.h"
#include <REGX52.H>
static int key = 0;
int Matrixkey()
{
	P1 = 0xf0;
	if(P1 != 0xf0)
	{
		delay(20);
		if(P1!=0xf0)
		{
			P1=0xf0;           //检测行
			switch(P1)
			{
				case 0x70: key = 1;break;
				case 0xb0: key = 2;break;
				case 0xd0: key = 3;break;
				case 0xe0: key = 4;break;
			}
			P1 = 0x0f;
			switch(P1)           //检测列
			{
				case 0x07: key = 4*(key - 1)+1;break;
				case 0x0b: key = 4*(key - 1)+2;break;
				case 0x0d: key = 4*(key - 1)+3;break;
				case 0x0e: key = 4*(key - 1)+4;break;
			}
		}
		while(P1 != 0x0f);         //等待松手
	}
	return key;
}
