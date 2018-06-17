segment	.data
align	4
global	x:object
x:
	dd	10
segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	push	dword $x
	pop	eax
	push	dword [eax]
	call	printi
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
