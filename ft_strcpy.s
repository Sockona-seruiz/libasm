		global 	_ft_strcpy
		section .text
_ft_strcpy:
	xor		rax, rax		;rdi arg[0] rsi arg[1]
	xor		r8, r8
	dec		r8
	jmp		while

while:
	inc		r8
	mov		al , BYTE[rsi + r8]
	cmp		al, 0
	je		done
	mov		BYTE [rdi + r8], al
	jmp		while

done:
	mov		BYTE [rdi + r8], 0
	mov		rax, rdi
	ret