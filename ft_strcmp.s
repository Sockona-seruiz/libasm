		global 	_ft_strcmp
		section .text
_ft_strcmp:
	xor		rax, rax
	xor		rcx, rcx
	jmp		while

while:
	mov		al , [rdi]
	mov		cl , [rsi]
	cmp		al, 0
	je		done
	cmp		al, cl
	jne		done
	inc 	rdi
	inc 	rsi
	jmp		while

done:
	sub		rax, rcx
	ret