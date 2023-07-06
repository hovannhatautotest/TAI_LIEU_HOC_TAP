#include <reg52x2.h>
#define hang P2
#define cot P3


void main(void)
{   int i,k;
	int gt_hang[8], gt_cot[8];

//for(i = 1;i<9;i++) gt_cot[i] = 2^(i-1);

gt_cot[1] = 1;
gt_cot[2] = 2;
gt_cot[3] = 4;
gt_cot[4] = 8;
gt_cot[5] = 16;
gt_cot[6] = 32;
gt_cot[7] = 64;
gt_cot[8] = 128;

gt_hang[1]= 0xfc; //11111100
gt_hang[2]= 0xfc;
gt_hang[3]= 0xfc;
gt_hang[4]= 0x00;
gt_hang[5]= 0x00;
gt_hang[6]= 0xfc;
gt_hang[7]= 0xfc;
gt_hang[8]= 0xfc;


while(1)
{
	for (i=1;i<9;i++)
	{
	 	for(k=0;k<10;k++)
		{
		 	cot = gt_cot[i];
			hang = gt_hang[i];
		}
	}
}

}
