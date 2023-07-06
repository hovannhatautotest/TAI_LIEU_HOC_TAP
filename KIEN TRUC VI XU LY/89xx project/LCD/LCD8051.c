																																		#include <REGX51.H>

#define LCD_RS P2_0
#define LCD_RW P2_1
#define LCD_EN P2_2
#define LCD_D0 P3_0
#define LCD_D1 P3_1
#define LCD_D2 P3_2
#define LCD_D3 P3_3
#define LCD_D4 P3_4
#define LCD_D5 P3_5
#define LCD_D6 P3_6
#define LCD_D7 P3_7

void delay_us (unsigned int t){
	unsigned int i;
	for (i=0;i<t;i++);
}

void delay_ms(unsigned int t){
	unsigned int i,j;
	for (i=0;i<t;i++)
	for (j=0;j<125;j++);
}

void delay (long time){
	while (time--);
}

/********chuong trinh giao tiep LCD 16x2 8bit**********/
void LCD_Enable (void){
	LCD_EN = 1;
	delay_us(3);
	LCD_EN = 0;
	delay_us(50);
}

//ham gui 8 bit du lieu ra LCD
void LCD_Send8Bit (unsigned char Data){
	LCD_D0 = Data & 0x01;
	LCD_D1 = (Data>>1)&1;
	LCD_D2 = (Data>>2)&1;
	LCD_D3 = (Data>>3)&1;
	LCD_D4 = (Data>>4)&1;
	LCD_D5 = (Data>>5)&1;
	LCD_D6 = (Data>>6)&1;
	LCD_D7 = (Data>>7)&1;
}

//Ham gui 1 tap lenh cho LCD
void LCD_SendCommand(unsigned char command){
	LCD_Send8Bit(command >>8);/* Gui 4 bit cao */
	LCD_Enable();
	LCD_Send8Bit(command);/* Gui 4 bit thap */
	LCD_Enable();
	
}

//Ham xoa man hinh LCD//
void LCD_Clear(){
	LCD_SendCommand(0x01);
	delay_us(10);
}

//Ham khoi tao LCD
void LCD_Init(){
	LCD_Send8Bit(0x00);    //turn on LCD
	delay(20);
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_Send8Bit(0x03);    //function setting//
	LCD_Enable();
    delay_ms(5);
    LCD_Enable();
    delay_us(100);
    LCD_Enable();
    LCD_Send8Bit(0x02);	  //di chuyen con tro ve dau man hnh
    LCD_Enable();
    LCD_SendCommand( 0x38 ); //lua chon che do 8 bit
    LCD_SendCommand( 0x0c);  // bat hien thi va tat con tro di
    LCD_SendCommand( 0x06 );
    LCD_SendCommand(0x01);
}
void LCD_Gotoxy(unsigned char x, unsigned char y){
        unsigned char address;
        if(!y)address=(0x80+x);
        else address=(0xc0+x);
        delay_us(1000);
        LCD_SendCommand(address);
        delay_us(50);
}
void LCD_PutChar(unsigned char Data){
        LCD_RS=1;
        LCD_SendCommand(Data);
        LCD_RS=0 ;
}
void LCD_Puts(char *s){
        while (*s){
                LCD_PutChar(*s);
                s++;
        }
}

void main(){
	LCD_Init();
	delay_ms(20);
	LCD_Puts("Hello");
	delay_ms(1000);
	LCD_Clear();
	LCD_Gotoxy(0,0);
	LCD_Puts("HO VAN NHAT");
	delay_ms(1000);
	LCD_Gotoxy(0,0);
	LCD_Puts("19T1051013");
	LCD_Clear();
	LCD_Gotoxy(0,0);
	LCD_Puts("KTVXL");
	//LCD_Puts(" Cerato Forte");
	while(1){};
}
