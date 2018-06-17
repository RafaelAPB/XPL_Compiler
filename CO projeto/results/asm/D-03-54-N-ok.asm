segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
	push	dword 0
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
	push	dword 0
	pop	eax
	cmp	eax, byte 0
	je	near _L5
segment	.rodata
align	4
_L6:
	db	"elsif1", 0
segment	.text
	push	dword $_L6
	call	prints
	add	esp, 4
	jmp	dword _L7
_L5:
	push	dword 0
	pop	eax
	cmp	eax, byte 0
	je	near _L8
segment	.rodata
align	4
_L9:
	db	"elsif2", 0
segment	.text
	push	dword $_L9
	call	prints
	add	esp, 4
	jmp	dword _L10
_L8:
	push	dword 0
	pop	eax
	cmp	eax, byte 0
	je	near _L11
segment	.rodata
align	4
_L12:
	db	"elsif3", 0
segment	.text
	push	dword $_L12
	call	prints
	add	esp, 4
	jmp	dword _L13
_L11:
	push	dword 0
	pop	eax
	cmp	eax, byte 0
	je	near _L14
segment	.rodata
align	4
_L15:
	db	"elsif4", 0
segment	.text
	push	dword $_L15
	call	prints
	add	esp, 4
	jmp	dword _L16
_L14:
segment	.rodata
align	4
_L17:
	db	"OK", 0
segment	.text
	push	dword $_L17
	call	prints
	add	esp, 4
_L16:
_L13:
_L10:
_L7:
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
