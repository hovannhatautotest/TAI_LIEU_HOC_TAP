
org 0x00
ajmp main


org 0x30
main:
	mov P2,#0
	mov R1,#7
	main_loop:
		mov A,#1
		loop:
		mov	B,#2
		mul AB
		mov R0,A
		dec R0
		mov P2,R0
		;acall delay
		djnz R1,loop
	ajmp main_loop

delay:
mov R0,#10
mov R1,#10
loop0:
loop1:
	nop
	nop
	nop
	djnz R0,loop1
djnz R1,loop0
ret
end