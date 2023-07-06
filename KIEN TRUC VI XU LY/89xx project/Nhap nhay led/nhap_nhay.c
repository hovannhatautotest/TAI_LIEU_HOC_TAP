#include <reg52x2.h>
int luythua(a,b);
void delay(int time);

void main()
{int i,x,t;
	t = 1000;
    while(1)
    {
		P2 = 0;
		for (i=0;i<8;i++) {P2 = luythua(2,i);delay(t);}	 //dich sang trai
		for (i=7;i>0;i--) {P2 = luythua(2,i);delay(t);}
/*		delay(t);
		x = 0;
		//den sang dan trai qua phai
		for(i=0;i<9;i++)
		{
			P1 = luythua(2,i)-1;
			delay(t);
		}
		//den tat dan tu trai qua phai
	
		for(i=0;i<9;i++)
		{
			P1 = 256 - luythua(2,i);
			delay(t);
		}

		P1 = 0;
		delay(t);
		//den sang dan tu phai qua trai			
		for(i=0;i<8;i++)
		{
			x = x+luythua(2,7-i);
			P1 = x;
			delay(t);
		}
		//den tat dan tu phai qua trai
		for(i=0;i<8;i++)
		{
			P1 = 256/luythua(2,i)-1;
			delay(t);
		}
		*/
    }

}

void delay(int time)
{int i;
    for(i=0;i<time;i++);

}

int luythua(a,b)
{int x,k;
	x = 1;
	for(k=0;k<b;k++) x=x*a;
	return(x);
}