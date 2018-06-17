segment	.text
align	4
global	f:function
f:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	dd	3
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	lea	eax, [ebp+-4]
	push	eax
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
segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
