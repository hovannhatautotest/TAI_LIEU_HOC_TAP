#include <reg52x2.h>
#define DVI P3_1
#define CHUC P3_0
#define tang P1_1
#define giam P1_0

//delay(int time);

hien_thi(int number);

void main(void)
{   int phim_tang, phim_giam,sodem,d_vi,hang_chuc,i;

sodem = 0;

while(1)
{
	phim_tang = tang;
	if(phim_tang == 0)
	{
		sodem++;
		if (sodem ==100) sodem=99;
		while (phim_tang == 0) phim_tang = tang;
	}
	phim_giam = giam; //lay tu P1_0
	if(phim_giam == 0)
	{
		sodem--;
		if (sodem<0) sodem=0;
	//	while (phim_giam == 0) phim_giam = giam;
	}
	
	hang_chuc = sodem/10;
	d_vi = sodem - (hang_chuc*10);	//d_vi = so_dem%10
	//hang_tram = sodem/100;
	//hang_chuc = (sodem - (100*hang_tram))/10;
	//d_vi =
	for (i=1;i<100;i++)
	{
		DVI = 1;
		CHUC = 0;
		hien_thi(d_vi);
	}
	for (i=1;i<100;i++)
	{
		CHUC = 1;
		DVI = 0;
		hien_thi(hang_chuc);
	}

}

}

hien_thi (int number)
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

//delay(int time)
//{
//    int k,l;
//    for(k=1;k<time;k++)
//    for(l=1;l<time;l++);
//}
