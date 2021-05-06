		global	_ft_list_size
		section	.text
_ft_list_size:
	xor		rax, rax

while:
	cmp		rdi, 0
	jz		done
	inc		rax
	mov		rdi, [rdi + 8]
	jmp		while

done:
	ret