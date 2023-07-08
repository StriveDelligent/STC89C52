void delay(unsigned int time)		//@12.000MHz
{
	unsigned char data i, j;
	while(time--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}

