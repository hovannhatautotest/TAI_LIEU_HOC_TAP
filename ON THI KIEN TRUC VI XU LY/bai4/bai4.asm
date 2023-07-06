;tao xung co tan so 5kHz do rong 50% 2kHz-> chu ki T = 5ms->muc cao = muc thap = 2500us
org 00h

main:
	mov tmod,#01h

loop:
	CPL P1.0
	ACALL DELAY1mS
	jmp loop

DELAY1mS:
	MOV TH0,#0F6h  ;65536-2500
	MOV TL0,#3Ch
	SETB TR0
	JNB TF0,$
	CLR TR0
	CLR TF0
RET
END
