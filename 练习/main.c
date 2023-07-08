#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.H"
#include "Matrixkey.h"
int num = 0;
int num1 = 0;
void main()
{
	LCD_Init();
	while(1)
	{
		num = Matrixkey();
		if(num)
		{
			if(num != num1)
			{
				LCD_ShowString(1,1,"                ");
				LCD_ShowString(2,1,"                ");
			}
			if(num<=8)
			{
				num1 = num;
				LCD_ShowNum(1,2*num-1,num,2);
			}
			else
			{
				num1 = num;
				LCD_ShowNum(2,(2*num-1)%16,num,2);
			}
		}
	}
}