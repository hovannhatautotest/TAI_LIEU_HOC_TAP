org 0x00
ajmp main
org 0x30
main:
	mov SCON,#0x52
	mov TMOD,#0x20
	mov TH1,#253
	mov TL1,TH1
	;setb EA; cho phep ngat toan cuc
	;setb ET1; cho phep ngat cua bo dinh thoi
	setb TR1; cho bo dinh thoi 1 hoat dong
	setb REN; cho phep bo UART nhan du lieu
	;wait_r: 
	;	jnb RI,wait_r
	;	clr RI
	main_loop:
		wait_r: 
		jnb RI,wait_r
		clr RI
		mov A,SBUF
		wait_w:
		jnb TI,wait_w
		clr TI
		mov SBUF,A
	sjmp main_loop
end