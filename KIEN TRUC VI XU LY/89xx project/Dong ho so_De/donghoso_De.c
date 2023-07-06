/**************************************************************************************************
	DESIGNED BY:Pham Van De --DHKH--dien tu vien thong k32
	MO TA: DONG HO SU DUNG TIMER
	KET NOI PHAN CUNG: DATA LED 7 DOAN = P0
						P2 QUET LED 7 DOAN; SU DUNG 6 LED 7 DOAN GIO : PHUT : GIAY 
						 led 7segment chung anode
						 Dieu chinh gio -phut -giay bang cach thay doi code ko dung phim nhan
	THACH ANH: 12MHZ 
	VI DIEU KHIEN: AT89C51 	
	Contact: depham90@gmail.com
	thoi gian hoan thanh:26/4/2011
/************KHAI BAO THU VIEN, DINH NGHIA********************************************************/
#include <REGX51.H>		
/************KHAI BAO BIEN, MANG...***************************************************************/
unsigned char led7_data[10] = {0x40,0x79,0x24,0x30,0x19,0x12,0x2,0x78,0x0,0x10};	   // lan luot tu 0 den 9
unsigned char gio,phut,giay;
unsigned char time, i,index,dem;
		int            j,k;
							 
sbit    tang_giay=P3^2;
sbit 	tang_phut=P3^1;
sbit	tang_gio=P3^0;
/************KHAI BAO HAM, CHUONG TRINH CON*******************************************************/
	// Chuong trinh khoi tao main
void set_main(void);
	// Chuong trinh cai dat timer 1 va 0 
void setup_timer(void);
//   chuong trinh dieu chinh gio-phut-giay khi tang hoac giam
 void Fix_time(void);
 void Keypad(void) ;// Kiem tra phim nhan.
 void delay(int lap); // ham tre

 
/************CAC CHUONG TRINH CON*****************************************************************/
/*void delay(int lap)	 // tao ham tre cho khi nhan phim nhan de dieu chinh thoi gian
{  for(j=0;j<lap;j++)
	  for(k=0;k<0;k++)
		  {};
}	
void bip(void)	   // tieng bip phat ra moi khi nhan phim nhan
{
for(i=0;x<100;x++)
{
loa=1;
delay(10);
loa=0;
delay(10);
}
}	
*/	// Chuong trinh khoi tao main
void set_main(void)
{
	P1=0x00;
	P0=0x00;
	P2=0x00;
	P3=0xff;
}
	// Setup timer 0 va timer 1 
void setup_timer(void)
{
	TMOD=0x11; // timer 0 che do 1 va timer 1 che do 1: 16bit ko autoreload
	TH0=-1000/256;		//thoi gian quet led								   
	TL0=-1000%256;
	TH1=0x3C;  // HIGH(-50000)
	TL1=0xB0;//	LOW (-50000)    
	ET1=1;	 //su dung bo ngat 1
	ET0=1;	  // su dung bo ngat 0
	EA=1;	  // cho phep su dung ngat con EA=0 thi cam ngat
	TF0=0;	  //khoi tao co tran cua timer 0
	TF1=0;	  // khoi tao co tran cua timer 1
	TR0=1;	  // bat dau chay  TIMER 0		   
	TR1=1;	  // bat dau chay TIMER 1
}
	//ngat timer 1 chay dong ho
void T1_ISR(void) interrupt 3
{
	TR1=0;	  // 
	TF1=0;	  // nap lai gia tri cho thanh ghi 
	TH1=0x3C; // HIGH(-50000)
	TL1=0xB0; //	 LOW (-50000)
	time++;		  // Tao vong lap 20 lan
	if(time==20)// 20x50000us = 1s 
	{
	time=0;
	giay++;
		if(giay==60)
		{
		giay=0;
		phut++;
		}
		if(phut==60)
		{
		phut=0;
		gio++;
		}
		if(gio==24)
		gio=0;
	}
	TR1=1;		   //cho chay lai TIMER 1
}
	// ngat timer 0 de quet led
void T0_ISR(void) interrupt 1
{
	TR0=0;
	TF0=0;
	TH0=-1000/256; // Nap lai gia tri cho thanh ghi 
	TL0=-1000%256;
	
	index--;  // de ta quet tu led don vi giay toi led hang chuc cua gio
	if(index==1)
			{	P0=0xff;				  // chu y la phai dong nay rat quan trong do ko thoi la nhay loan so luon
			P0=led7_data[gio/10];		  // hien thi gio >>hang chuc
			P2=0x01;					  // cho led nay hien thi
			index=7;					  // khoi tao lai vong lap de quet led
		}
	
	if(index==2)
	
		{	P0=0xff;					  // phai co
			P0=led7_data[gio%10];		  // hien thi gio>>> don vi
			P2=0x02;					  // cho led nay hien thi
		}

	if(index==3)
										   // phai co
		{	P0=0xff;
			P0=led7_data[phut/10];		   // hien thi phut>> hang chuc
			P2=0x04;					   // cho led nay hien thi
		}

	if(index==4)
		{												   
			P0=0xff;						//phai co
			P0=led7_data[phut%10];			// hien thi phut >> don vi
			P2=0x08;						// cho led nay hien thi
		}
	
	if(index==5)
	 
		{	P0=0xff;						// phai co
			P0=led7_data[giay/10];			// hien thi giay>> hang chuc
			P2=0x10; 						// cho led nay hien thi
		}
	
	if(index==6)
	
		{	P0=0xff;						// phai co
			P0=led7_data[giay%10];			//hien thi giay >>>hang don vi
			P2=0x20;						// cho led nay hien thi
			 
			
																   
		}
		TR0=1;								//cho chay lai TIMER O
}

 

 
/************CHUONG TRINH CHINH*******************************************************************/
void main()
{ 

{	set_main();
	time=dem=0;
	index=7;	
	
	setup_timer();
	
 }
 
  while(1)  // TAO VONG LAP VO HAN
  {	  if(tang_gio==0){gio++;if(gio==24)gio=0;}while(tang_gio==0);  
if(tang_phut==0){phut++;if(phut==60)phut=0;}  while(tang_phut==0); 
if(tang_giay==0){giay++;if(giay==60)giay=0;}while(tang_giay==0); 	
 	
  }
}	