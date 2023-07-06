;tao khoang thoi gian cho dung bang 1ms doi voi thach anh 12MHz
org 00h

main:
	mov tmod,#01h

loop:
	CPL P1.0
	ACALL DELAY1mS
	jmp loop

DELAY1mS:
	MOV TH0,#0FCh  ;65536-1000
	MOV TL0,#18h
	SETB TR0
	JNB TF0,$
	CLR TR0
	CLR TF0
RET
END
