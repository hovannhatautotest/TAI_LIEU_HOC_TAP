chuc BIT 0xB0
dvi BIT 0xB1

org 0x00
ajmp main

org 0x30
main:
	mov A,#17
	mov B,#10
	DIV AB
	
	;main_loop:
		mov R0,#128
		mov R1,#128
		lap1:
		setb chuc
		clr dvi
		acall hienthi
		djnz R0,lap1
		lap2:
		clr chuc
		setb dvi
		mov A,B
		acall hienthi
		djnz R1,lap2		
	sjmp main

hienthi:
    CJNE A,#0,so_1
    MOV P2,#0x40
    AJMP ket_thuc
    so_1:
    CJNE A,#1,so_2
    MOV P2,#0x79
    AJMP ket_thuc
    so_2:
    CJNE A,#2,so_3
    MOV P2,#0x24
    AJMP ket_thuc
    so_3:
    CJNE A,#3,so_4
    MOV P2,#0x30
    AJMP ket_thuc
    so_4:
    CJNE A,#4,so_5
    MOV P2,#0x19
    AJMP ket_thuc
    so_5:
    CJNE A,#5,so_6
    MOV P2,#0x12
    AJMP ket_thuc
    so_6:
    CJNE A,#6,so_7
    MOV P2,#0x02
    AJMP ket_thuc
    so_7:
    CJNE A,#7,so_8
    MOV P2,#0x78
    AJMP ket_thuc
    so_8:
    CJNE A,#8,so_9
    MOV P2,#0x00
    AJMP ket_thuc
    so_9:
    CJNE A,#9,ket_thuc
    MOV P2,#0x10
    ket_thuc:
RET

end  