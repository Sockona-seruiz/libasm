		global	_ft_write
		extern	___error
		section	.text
_ft_write:			;write(rdi, rsi, rdx)
	push	rax
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
	pop		rdi
	ret

error:
	push	rax
	call	___error
	pop		rdi
	mov		[rax], rdi
	pop		rdi
	pop		rsi
	pop		rdx
	pop		rax
	mov		rax, -1
	ret