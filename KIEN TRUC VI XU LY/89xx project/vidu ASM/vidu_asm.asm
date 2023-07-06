;sbit led1
org 0x00
ajmp main


org 0x30
main:
	mov P2,#0x00
	main_loop:
		mov P2,#1
	    acall delay
		mov P2,#3
		acall delay
		mov P2,#7
	    acall delay
		mov P2,#15
		acall delay
		mov P2,#31
	    acall delay
		mov P2,#63
		acall delay
		mov P2,#127
	    acall delay
		mov P2,#255
		acall delay
	sjmp main_loop

delay:
mov R0,#10
mov R1,#70
loop0:
loop1:
	nop
	nop
	nop
	djnz R0,loop1
djnz R1,loop0
ret
end