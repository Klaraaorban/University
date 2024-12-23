global main

section .data

	n db 0            ; de a avea o variabila pt numarul de repetitii
	cha db 0		  ; variabila pentru caracterul citit
	space db 32       ; ascii pentru space
	newline db 10		;ascii pentru rand nou
	wie_viele_ziffer_numeric db 0    ; de a evita problema de multi thread
	res1 dw 100

	repetiti_erklarung db 'Wie viel Wiederholungen mochten sie?  '       ;explicatii
	caracterul_erklarung db 'Welche Charakter mochten Sie anschauen?  '
	salutare db 'Hallo, diese Programm zeigt eine Charakter n mal(sowohl das Charakter als auch n wird von dem Tastatur eingegeben)'

section .text

newline_function:
	mov rax,1
	mov rdi,1
	mov rsi,newline    			; printeaza un newline pe ecran
	mov rdx,1
	syscall
ret


main:

	xor rax,rax

	call newline_function

		mov rax,1
		mov rdi,1
		mov rsi,salutare   		; printeaza un newline pe ecran
		mov rdx,114
		syscall

	call newline_function

	call newline_function

		mov rax,1
		mov rdi,1     			; da o scurta explicatie pentru inputul de numar de repetitii
		mov rsi,repetiti_erklarung
		mov rdx,38
		syscall

	mov word [res1],0


	do1:
								;read 1 character
			mov rax,0
			mov rdi,0
			mov rsi,n
			mov rdx,1
			syscall
								;check if the given key is a space
			cmp byte [n],' '
			
				je exited1		;if it is a space the reading from keyboard ends
			
								;convert to int
			sub byte [n],'0'
			
								
			mov ax,[res1]		;mul res1 by 10 and add new digit
			mov bx,10
			mul bx
			
			mov bl,[n]
			mov bh,0
			add ax,bx
			
			mov [res1],ax
			
		jmp do1
		
		exited1:				;result will be in res1 after the function ends
								
								
	mov rax,0					;we give an enter
	mov rdi,0
	mov rsi,newline
	mov rdx,1
	syscall	
		
	mov rax,1
	mov rdi,1
	mov rsi,caracterul_erklarung    ; explicatie pt caracterul citit
	mov rdx,41
	syscall


	mov rax,0
	mov rdi,0     				; citeste caracterul de la tastatura
	mov rsi,cha
	mov rdx,1
	syscall

	mov ax, [cha]

	call newline_function

	for_loop:

		mov rax,1
		mov rdi,1
		mov rsi,cha   			; printeaza caracterul pe ecran
		mov rdx,1
		syscall
		
		mov rax,1
		mov rdi,1
		mov rsi,space    		; printeaza un space pe ecran
		mov rdx,1
		syscall
		
		
		mov bx,[res1]
		dec bx	
		mov [res1],bx			; scade 1 din contorul de repetitii
		cmp bx,0
		
		
		mov bl,[res1]
		mov bh,0
		cmp bl,0     			; compara contorul de repetitii cu 0
		
		
	ja for_loop
		
		
	call newline_function
	call newline_function

mov rax,60   				; iesire din program
mov rdi,0
syscall