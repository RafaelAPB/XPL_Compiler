segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 4
segment	.rodata
align	4
_L2:
	db	"X", 32, 10, 32, "Y", 32, 10, 32, "Z", 32, 10, 0
segment	.text
	push	dword $_L2
	call	prints
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
