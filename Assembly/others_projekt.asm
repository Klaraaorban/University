global main

section .data
n db 0
cha db 0
space db 32
newline db 10
repetiti_erklarung db 'Wie viel Wiederholungen mochten sie?'
caracterul_erklarung db 'Welche Charakter mochten Sie anschauen?'
res dw 100
section .text




user_inputs:
mov word [res],0
do1:
							;read 1 character
		mov rax,0
		mov rdi,0
		mov rsi,n
		mov rdx,1
		syscall
							;check if the given key is a space
		cmp byte [n], ' '
		je exited1			;if it is a space the reading from keyboard ends
		
							;convert to int
		sub byte [n],'0'
		
							;mul res1 by 10 and add new digit
	
		mov al,[res]
		mov bx,10
		mul bx
		
		mov bl,[n]
		mov bh,0
		add ax,bx
		
		mov [res],ax
		
	jmp do1
	
	exited1:
		
ret


main:

xor rax,rax

mov rax,1
mov rdi,1     ; da o scurta explicatie
mov rsi,repetiti_erklarung
mov rdx,36
syscall


call user_inputs ;apelam inputurile cu o functie

mov rax,1
		mov rdi,1
		mov rsi,caracterul_erklarung    ; explicatie pt caracterul citit
		mov rdx,39
		syscall
		
		mov rax,0
		mov rdi,0
		mov rsi,cha
		mov rdx,1
		syscall


for_loop:

	mov rax,1
	mov rdi,1
	mov rsi,cha   ; printeaza caracterul pe ecran
	mov rdx,1
	syscall
	
	mov rax,1
	mov rdi,1
	mov rsi,space    ; printeaza un space pe ecran
	mov rdx,1
	syscall
	
	
	mov bl,[res]
	dec bl         ; scade 1 din contorul de repetitii
	mov [res],bl
	
	mov bl,[res]
	cmp bl,0     ; compara contorul de repetitii cu 0
	ja for_loop
	
	
mov rax,1
mov rdi,1
mov rsi,newline    ; printeaza un newline pe ecran
mov rdx,1
syscall

mov rax,60   ; iesire din program
mov rdi,0
syscall
