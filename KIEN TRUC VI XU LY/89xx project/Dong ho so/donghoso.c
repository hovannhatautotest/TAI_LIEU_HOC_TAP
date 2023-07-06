
#include <reg52x2.h>
#define mode P3_0
#define shift P3_1
#define inc P3_2
#define dec P3_3
#define bset P3_4

static unsigned long tran = 0;
int i,j,vtri[4];
int ms,s,min,hour,num[4],settime[4];
int sw_mode,sw_shift,sw_inc,sw_dec,sw_set, chedo,set,pos;
void hien_thi (int number);

void timer1_ISR (void) interrupt 3
{
	tran++;   /* Increment the overflow count */
	if (tran==20000)
	{
	 s++;
	 tran = 0;
	 if (s==60)
		{
		 s=0;
		 min++;
		 if (min==60)
		 	{
				min=0;	
			}			
		}
	}
}


void main(void)
{   

TMOD = ((TMOD & 0x0F) | 0x20);  /* Set Mode (8-bit timer with reload) */
TH1 = 256 - 100;              /* Reload TL1 to count 100 clocks */
TL1 = TH1;
ET1 = 1;                      /* Enable Timer 1 Interrupts */
TR1 = 1;                      /* Start Timer 1 Running */
EA = 1;                       /* Global Interrupt Enable */

//hien_thi(so_dem);
vtri[0] = 8;
vtri[1] = 4;
vtri[2] = 2;
vtri[3] = 1;
set = 0;
for (i=0;i<4;i++) settime[i]=0;
while(1)
{
/*hien thi gio hoac dat gio*/

    num[0] = s%10; //don vi giay
	num[1] = s/10; //hang chuc giay 
	num[2] = min%10;
	num[3] = min/10;

	if (set == 0)
	{
		for (i = 0;i<4;i++)
		{
			for (j=0;j<10;j++)
			{
				P2 = vtri[i];
				hien_thi(num[i]);
			}
		}
	}
	else 
	{
		if(s%2==0)
		{
			for (i = 0;i<4;i++)
			{
				for (j=0;j<10;j++)
				{
					if (i!=pos)
					{
						P2 = vtri[i];
						hien_thi(settime[i]);
					}
				}
			}
		}
		else
		{
			for (i = 0;i<4;i++)
			{
				for (j=0;j<10;j++)
				{
					P2 = vtri[i];
					hien_thi(settime[i]);
				}
			}
		}
	}

/*nut chuyen che do*/
	sw_mode = mode;
    if (sw_mode == 0)
	{ 
		if (chedo == 0) chedo = 0; else chedo = 1;
		while (sw_mode==0)sw_mode = mode;
	}


/*nut dat gio*/
	sw_set = bset;
    if (sw_set == 0)
	{ 
		if (set == 0) 
		{
			set = 1;
			pos = 0;
		}
		else 
		{
			set = 0;
			s = settime[1]*10 + settime[0];
			min = settime[3]*10 + settime[2];
		}
		while (sw_set==0)sw_set = bset;
	}

/*nut dich chuyen vi tri*/
    sw_shift = shift;
	if (sw_shift == 0)
	{ 
		pos++;
		if (pos>4) pos = 0;
		while (sw_shift==0)sw_shift = shift;
	}
	
/*nut tang*/
	sw_inc = inc;
    if (sw_inc == 0)
	{ 	
		settime[pos]++;
		switch (pos)
		{
			case 0: if (settime[0]>9) settime[0]=0;break;	
			case 1: if (settime[1]>5) settime[1]=0;break;
			case 2: if (settime[2]>9) settime[2]=0;break;
			case 3: if (settime[3]>5) settime[3]=0;break;
		}
		while (sw_inc==0)sw_inc = inc;
	}
	
/*nut giam*/
	sw_dec = dec;
    if (sw_dec == 0)
	{ 	
		settime[pos]--;
		switch (pos)
		{
			case 0: if (settime[0]<0) settime[0]=9;break;	
			case 1: if (settime[1]<0) settime[1]=5;break;
			case 2: if (settime[2]<0) settime[2]=9;break;
			case 3: if (settime[3]<0) settime[3]=5;break;
		}
		while (sw_dec==0)sw_dec = dec;
	}				

}

}

void hien_thi (int number)
{
	switch (number)
	{
	 	case 0: P1 = 0x40;break;
		case 1: P1 = 0x79;break;
		case 2: P1 = 0x24;break;
		case 3: P1 = 0x30 ;break;
	 	case 4: P1 = 0x19;break;
		case 5: P1 = 0x12;break;
		case 6: P1 = 0x02;break;
		case 7: P1 = 0x78 ;break;
		case 8: P1 = 0x00;break;
		case 9: P1 = 0x10 ;break;
	}

	P1 = 0xff;
//	P2 = 0;
}