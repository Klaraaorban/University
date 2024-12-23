global main

section .data

a db 1000 dup(0)
i db 3

section .text

main:
mov rax, -1
xor ebx,ebx


mov cl,33
mov [a+3],cl
mov bl, [i]
mov al, [ebx + a]

mov rax,60
xor rdi, rdi
syscall