org 0000h
	
MAIN:
	mov P1,#11111111B
	call Delay
	mov P1,#00000000B
	call Delay
	jmp main
	
Delay:
	mov r1,#5
lap1:
	mov r2,#200
lap2:
	mov r3,#200
	djnz r3,$
	djnz r2,lap2
	djnz r1,lap1
ret
end