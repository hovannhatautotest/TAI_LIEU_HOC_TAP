;khoang thoi gian cho dung bang 1ms doi voi thach anh 24MHz
org 00h

main:
	mov tmod,#01h

loop:
	CPL P1.0
	ACALL DELAY1mS
	jmp loop

DELAY1mS:
	MOV TH0,#0F8h  ;65536-2000
	MOV TL0,#30h
	SETB TR0
	JNB TF0,$
	CLR TR0
	CLR TF0
RET


END
