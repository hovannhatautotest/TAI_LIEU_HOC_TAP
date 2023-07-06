#include <reg52x2.h>
#define hoatdong P1_0
#define n1 P0_0
#define n2 P0_1
#define n3 P0_2
#define n4 P0_3
#define button P3_7
#define baodong P3_0

void main(void)
{int phim_hd, nut_n1,nut_n2,nut_n3,nut_n4, nut_button;
int dem1,temp;
baodong = 0;	
while(1)
{	
	temp = 0;
	phim_hd = hoatdong;
	if(phim_hd == 0)
	{
		temp = 1;
		baodong = 0;
		while(phim_hd == 0) phim_hd = hoatdong;
	}
	while (temp==1) 
	{
	 	nut_button = button;
		if (nut_button == 1) baodong = 1;
		//kiem tra ma phim
		nut_n1 = n1;
		nut_n2 = n2;
		nut_n3 = n3;
		nut_n4 = n4;
		if (nut_n1 == 0)
		{
		 	if (dem1==0) dem1 = 1; else dem1=0;
			while(nut_n1 == 0) nut_n1 = n1;	
		}
		if (nut_n2 == 0)
		{
		 	if (dem1==1) dem1 = 2; else dem1=0;
			while(nut_n2 == 0) nut_n2 = n2;	
		}
		if (nut_n3 == 0)
		{
		 	if (dem1==2) dem1 = 3; else dem1=0;
			while(nut_n3 == 0) nut_n3 = n3;	
		}
		if (nut_n4 == 0)
		{
		 	if (dem1==3) dem1 = 4; else dem1=0;
			while(nut_n4 == 0) nut_n4 = n4;	
		}
		if (dem1 ==4) {baodong = 0; temp=0;}
		
	}

}	

}
