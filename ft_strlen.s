		global	_ft_strlen
		section	.text
_ft_strlen:					;str should be in rdi
	xor		rax, rax
	jmp		while

increment:
	inc		rax

while:
	cmp		BYTE [rdi + rax], 0
	jne		increment

done:
	ret
