global main
section .data
n db 123
c db 0
space db 32
new_line db 10
section .text

main:
do:
xor rax,rax
mov al,[n]
mov bl,10
div bl
add ah,'0'
mov [c],ah
mov [n],al


mov rax,1
mov rdi,1
mov rsi,c
mov rdx,1
syscall

mov rax,1
mov rdi,1
mov rsi,space
mov rdx,1
syscall

mov bl,[n]
cmp bl,0
ja do

mov rax,1
mov rdi,1
mov rsi,new_line
mov rdx,1
syscall

mov rax,60
mov rdi,0
syscall
