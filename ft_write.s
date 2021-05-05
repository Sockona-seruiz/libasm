		global	_ft_write
		section	.text
_ft_write:			;write(rdi, rsi, rdx)
	push	rdi
	push	rsi
	push	rdx
	mov		r8, rdx
	mov		rax, 0x02000004
	syscall
	jc		error
	pop		rdi
	pop		rsi
	pop		rdx
	mov		rax, r8
	ret

error:
	pop		rdi
	pop		rsi
	pop		rdx
	mov		rax, -1
	ret