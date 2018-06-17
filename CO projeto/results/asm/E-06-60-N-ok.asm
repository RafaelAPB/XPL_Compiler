segment	.data
align	4
global	x:object
x:
	dd	1
segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
_L2:
	push	dword $x
	pop	eax
	push	dword [eax]
	push	dword 3
	neg	dword [esp]
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setge	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L3
	push	dword $x
	pop	eax
	push	dword [eax]
	call	printi
	add	esp, 4
	push	dword $x
	pop	eax
	push	dword [eax]
	push	dword 1
	pop	eax
	sub	dword [esp], eax
	push	dword [esp]
	push	dword $x
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	jmp	dword _L2
_L3:
_L1:
	push	dword 0
	pop	eax
	leave
	ret
extern	readi
extern	printi
extern	prints
extern	println
