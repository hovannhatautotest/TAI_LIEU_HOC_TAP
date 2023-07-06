org 00h
	MOV DPTR,#maled
RESET:
	MOV R0,#0
MAIN:
	CALL HIENTHI1
	JMP RESET
HIENTHI1:
	MOV A,R0
	MOV B,#10
	DIV AB
	MOVC A,@A+DPTR
	MOV P0,A
	SETB P2.5
	CLR P2.6
	CALL Delay
	CLR P2.5
	MOV A,B
	MOVC A,@A+DPTR
	MOV P0,A
	SETB P2.6
	CLR P2.5
	CALL Delay
	CLR P2.6
	CALL Delay
	INC R0
	CJNE R0,#60,MAIN
ret


Delay:
	mov r1,#10
lap1:
	mov r2,#10
lap2:
	mov r3,#150
	djnz r3,$
	djnz r2,lap2
	djnz r1,lap1
ret
maled:
	DB 0C0H,0F9H,0A4H,0B0H,99H,92H,82H,0F8H,80H,90H
end