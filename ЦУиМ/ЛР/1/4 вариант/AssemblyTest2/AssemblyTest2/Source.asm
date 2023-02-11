
.686
.model flat, stdcall
.stack 4096
.data
	;Вычислить M=(Z-X-Y)/2+(X & Y)
	X	dw	17
	Y	dw	5
	Z	dw	44
	M	dw	?
	
.code
	ExitProcess PROTO STDCALL :DWORD
	main:

	mov ax, Z
	sub ax, X
	sub ax, Y

	mov bh, 2
	idiv bh
	xor bh,bh

	mov bx, X
	and bx, Y

	add ax, bx
	mov M, ax

	xor ax,ax
	xor bx,bx
	exit:
Invoke ExitProcess,1
End main