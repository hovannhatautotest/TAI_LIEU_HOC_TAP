#include <reg52x2.h>
#include <math.h>

void delay(int x);

void main()
{int k; 				
	
	k=40;
	while(1)
	{
		P2 = 0;delay(k);
	 	P2 = 1;delay(k);
		P2 = 3;delay(k);
		P2 = 7;delay(k);
		P2 = 15;delay(k);
		P2 = 31;delay(k);
		P2 = 63;delay(k);
		P2 = 127;delay(k);
		P2 = 255;delay(k);
	}
}

void delay(int x)
{int j,y;
for(y=0;y<x;y++) for(j=0;j<x;j++);

}

