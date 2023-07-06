#include <reg52x2.h>

#define mode P3_0
#define shift P3_1
#define inc P3_2
#define dec P3_3
#define bset P3_4

int vtri[4], so[10], min[2], sec[2];

void hien_gio();
void hien_dat_gio();


void main(){


bit mode_sw,shift_sw,inc_sw,dec_sw,bset_sw;
bit cur_mode = 1;

	while (1){
		if (cur_mode == 1) hien_gio();
		else hien_dat_gio;
	
		bset_sw = bset;
		if bset == 0
		{
		 	cur_mode = ~cur_mode;
			while (bset_sw == 0) bset_sw = bset;
		}
	}
}

void hien_gio(){

}

void hien_dat_gio{

}
