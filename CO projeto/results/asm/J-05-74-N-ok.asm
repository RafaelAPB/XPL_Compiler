segment	.text
align	4
pi:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	push	dword 314
	push	dword [esp]
segment	.data
align	4
pi:
	dd	0
segment	.text
	push	dword $pi
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
_L1:
	push	dword 0
	pop	eax
	leave
	ret
extern	readi
extern	printi
extern	prints
extern	println
segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
