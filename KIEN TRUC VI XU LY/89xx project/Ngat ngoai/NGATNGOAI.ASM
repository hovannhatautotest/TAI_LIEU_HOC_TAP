P1_1 bit 0x91


org 0x00
ajmp main_m

org 0x03
ajmp ngat_ngoai

org 0x13
 ngat_ngoai_1:
   mov P1,#255
   reti

org 0x30
main_m:
setb EA
setb EX0
setb EX1
;setb IT0
main:
mov P1,#0x00
acall delay
mov P1,#0x01
acall delay
mov P1,#0x03
acall delay
mov P1,#0x07
acall delay
mov P1,#15
acall delay
mov P1,#31
acall delay
mov P1,#63
acall delay
mov P1,#127
acall delay
mov P1,#255
acall delay
ajmp main

;Chuong trinh phuc vu ngat
ngat_ngoai:
mov P1,#0x00
acall delay
mov P1,#0x01
acall delay
mov P1,#0x02
acall delay
mov P1,#0x04
acall delay
mov P1,#0x08
acall delay
mov P1,#16
acall delay
mov P1,#32
acall delay
mov P1,#64
acall delay
mov P1,#128
acall delay
reti

;Chuong trinh con
delay:
mov R1,#255
MOV R0,#100
lap1:
lap: 
	nop
	nop
	nop
	djnz R1,lap
djnz R0,lap1
ret

;Ket thuc chuong trinh
end 