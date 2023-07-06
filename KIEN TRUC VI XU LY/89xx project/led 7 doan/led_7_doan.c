#include <reg52x2.h>

//void delay(int time);

void hien_thi(int number);

void main(void)
{	int i,j,button1,button2;
	j = 0;
	
	while (1)
	{	
		button1 = P3_0;
		button2 = P3_1;
		if (button1==0)
		{
		 	j++;
			if (j==10) j=0;
			while (button1 == 0) button1 = P3_0;
		}
	 	
		if (button2==0)
		{
		 	j--;
			if (j<0) j=9;
			while (button2 == 0) button2 = P3_1;
		}
	 	hien_thi(j);
	}
}

void hien_thi (int number)
{
	switch (number)
	{
	 	case 0: P2 = 0x40;break;
		case 1: P2 = 0x79;break;
		case 2: P2 = 0x24;break;
		case 3: P2 = 0x30 ;break;
	 	case 4: P2 = 0x19;break;
		case 5: P2 = 0x12;break;
		case 6: P2 = 0x02;break;
		case 7: P2 = 0x78 ;break;
		case 8: P2 = 0x00;break;
		case 9: P2 = 0x10 ;break;
	}
	P2 = 0xff;
}
 
/*
void delay(int time)
{
    int k,l;
    for(k=1;k<time;k++)
    for(l=1;l<time;l++);
}
*/