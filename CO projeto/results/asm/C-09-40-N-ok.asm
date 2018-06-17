segment	.data
align	4
global	x:object
x:
	dd	10
segment	.data
align	4
global	y:object
y:
	dd	3
segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	push	dword $y
	pop	eax
	push	dword [eax]
	push	dword $x
	pop	eax
	push	dword [eax]
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
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
