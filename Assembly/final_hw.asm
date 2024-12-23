global main

section .data

; a+b < 2560

a dw 200
b dw 500
n dw 0
len equ 10
c times len db 0

section .text

main:
	mov ax,[a]
	mov bx, [b]


	add ax, bx
	;ax - ben az osszeg

	mov [n], ax
	mov rsi, c+len-1

	do:
		xor rax,rax
		mov ax,[n]
		mov bl,10
		div bl
		add ah,'0'
		mov [rsi],ah
		dec rsi
		mov ah,0
		mov [n],ax


		mov bx,[n]
		cmp bx,0

	ja do

mov rbx,len
add rbx,c
sub rbx,rsi


mov rax,1
mov rdi,1
inc rsi
mov rdx,rbx
syscall

mov rax,60
xor rdi,rdi
syscall
