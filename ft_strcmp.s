		global 	_ft_strcmp
		section .text
_ft_strcmp:
	xor		rax, rax		;rdi arg[0] rsi arg[1]
	xor		r8, r8
	dec		r8
	jmp		while

notequal:
	jl		retneg
	jnl		retpos
	jmp		retzero

while:
	inc		r8
	mov		al , BYTE[rdi + r8]
	mov		bl , BYTE[rsi + r8]
	cmp		al, bl
	jne		notequal
	cmp		al, 0
	je		retzero
	cmp		bl, 0
	je		retzero
	cmp		al, bl
	je		while

	jmp		notequal

retpos:
	mov		rax, 1
	ret

retneg:
	mov		rax, -1
	ret

retzero:
	mov		rax, 0
	ret