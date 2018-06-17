segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	push	dword 2
	pop	eax
	cmp	eax, byte 0
	je	near _L2
segment	.rodata
align	4
_L3:
	db	"KO", 0
segment	.text
	push	dword $_L3
	call	prints
	add	esp, 4
	jmp	dword _L4
_L2:
segment	.rodata
align	4
_L5:
	db	"OK", 0
segment	.text
	push	dword $_L5
	call	prints
	add	esp, 4
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
