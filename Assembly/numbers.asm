global main
section .data
m db 12
n db 0
o db 0
new db 10
section .text

main:

mov ax,[m]
mov bl,10
div bl

add al,'0'
mov [n],al
add ah,'0'
mov [o],ah

mov rax,1
mov rdi,1
mov rsi,new
mov rdx,1
syscall

mov rax,1
mov rdi,1
mov rsi,o
mov rdx,1
syscall

mov rax,60
xor rdi,rdi
syscall
