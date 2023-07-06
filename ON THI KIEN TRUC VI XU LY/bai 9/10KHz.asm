//10KHz->T=10ms->khoang thoi gian cho = 5ms doi vs thach anh 12MHz, 10ms doi vs thach anh 24MHz
org 00h

main:
	mov tmod,#01h

	call loop1
//loop:
//	CPL P1.0
//	ACALL DELAY10mS
//	jmp loop
loop1:
	CPL P1.1
	ACALL DELAY200mS
	jmp loop1

DELAY10mS:
	MOV R0,#10

DELAY1mS:
	MOV TH0,#0F8h  ;65536-2000
	MOV TL0,#3h
	SETB TR0
	JNB TF0,$
	CLR TR0
	CLR TF0
	DJNZ R0,DELAY1mS
 	RET

DELAY200mS:
	MOV R1,#200

DELAY1mS2:
	MOV TH0,#0F8h  ;65536-2000
	MOV TL0,#3h
	SETB TR0
	JNB TF0,$
	CLR TR0
	CLR TF0
	DJNZ R1,DELAY1mS2
 	RET
END