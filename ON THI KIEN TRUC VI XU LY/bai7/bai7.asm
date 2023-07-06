

		ORG 00H
			MOV DPTR,#MALED
		reset:
			mov R0,#9
		main:
			MOV A,R0
			MOVC A,@A+DPTR
			MOV P0,A
			jb P2.7,$
			jnb P2.7,$
			dec R0
			CJNE R0,#0,main
			jmp reset

		MALED:
			DB 01H,0F9H,0A4H,0B0H,99H,92H,82H,0F8H,80H,010H
		
END