segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 12
	push	dword 1
	lea	eax, [ebp+-8]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
_L2:
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 3
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L4
	push	dword 1
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
_L5:
	lea	eax, [ebp+-4]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 6
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L7
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	push	dword 2
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	edx
	push	dword 0
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L8
	jmp	dword _L7
	jmp	dword _L9
_L8:
	lea	eax, [ebp+-4]
	push	eax
	pop	eax
	push	dword [eax]
	call	printi
	add	esp, 4
_L9:
_L6:
	push	dword 1
	push	dword [esp]
	lea	eax, [ebp+-4]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	add	dword [esp], eax
	lea	eax, [ebp+-4]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	jmp	dword _L5
_L7:
_L3:
	push	dword 1
	push	dword [esp]
	lea	eax, [ebp+-8]
	push	eax
	pop	eax
	push	dword [eax]
	pop	eax
	add	dword [esp], eax
	lea	eax, [ebp+-8]
	push	eax
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	jmp	dword _L2
_L4:
_L1:
	push	dword 0
	pop	eax
	leave
	ret
extern	readi
extern	printi
extern	prints
extern	println