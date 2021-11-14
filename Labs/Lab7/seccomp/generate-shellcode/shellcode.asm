BITS 32
	push ebp
	mov ebp, esp
	xor eax, eax
	mov al, 3
	xor ebx, ebx
	mov bl, 3
	mov ecx, [ebp + 8]
	xor edx, edx
	mov dl, 1
	int 0x80
	mov al, 4
	mov bl, 4
	int 0x80
	leave
	ret
