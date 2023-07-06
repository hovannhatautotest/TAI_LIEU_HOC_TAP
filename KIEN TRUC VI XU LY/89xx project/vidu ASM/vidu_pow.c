#include <reg52x2.h>


void delay(int x);
int luythua(int a,int b);
void main()
{int m,k,x; 				
 	P2=0x00;
	k=40;
	while(1)
	{
	
	P2=0x00;
	for(x=0;x<8;x++)
	{
		P2=luythua(2,x)-1;
		delay(k);  
	}
	P2 = 0x00;
	for(x=0;x<8;x++)
	{
		P2=luythua(2,x);
		delay(k);  
	}
	 
	m = 0;
	for(x=7;x>-1;x--)
	{
		
		m=m+luythua(2,x);
		P2 = m;
		delay(k);  
	}

	}
}

void delay(int x)
{int j,y;
for(y=0;y<x;y++) for(j=0;j<x;j++);

}

int luythua(int a, int b)
{int tam,x;
 x=1;
 for (tam=1;tam<=b;tam++) x=x*a;
 return(x);
} 

