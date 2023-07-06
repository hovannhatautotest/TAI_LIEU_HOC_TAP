P1_0 bit 0x90

org 0x00
ajmp main

org 0x1B
ngat_dinh_thoi:
	CPL P1_0
reti

main:
	mov TMOD,#0x20
	mov TH1,#156
	mov TL1,TH1
	setb EA; cho phep ngat toan cuc
	setb ET1; cho phep ngat cua bo dinh thoi
	setb TR1; cho bo dinh thoi 1 hoat dong



end