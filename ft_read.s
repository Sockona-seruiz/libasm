		global	_ft_read
		section	.text
_ft_read:			;read(rdi, rsi, rdx)
	push	rdi
	push	rsi
	push	rdx
	mov		r8, rdx
	mov		rax, 0x02000003
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