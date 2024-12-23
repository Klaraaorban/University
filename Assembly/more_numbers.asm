global main

section .data
num dw 100
num2 dw 50
res1 dw 100
res2 dw 100

c dw '5'
d dw '6'
sum dw '5'
section .text

main:
;counting result
mov word [res1],0
	do1:
	;read 1 character
		mov rax,0
		mov rdi,0
		mov rsi,num
		mov rdx,1
		syscall
	;check if space
		cmp byte [num],' '
		je exited1
		
	;convert to int
		sub byte [num],'0'
		
	;mul res1 by 10 and add new digit
	
		mov ax,[res1]
		mov bx,10
		mul bx
		
		mov bl,[num]
		mov bh,0
		add ax,bx
		
		mov [res1],ax
		
	jmp do1
	
	exited1:
	;result will be in res1 after the function ends
	ret

;counting result2
mov word [res2],0
	do2:
	;read 1 character
		mov rax,0
		mov rdi,0
		mov rsi,num2
		mov rdx,1
		syscall
	;check if space
		cmp byte [num2],' '
		je exited2
		
	;convert to int
		sub byte [num2],'0'
		
	;mul res1 by 10 and add new digit
	
		mov ax,[res2]
		mov bx,10
		mul bx
		
		mov bl,[num2]
		mov bh,0
		add ax,bx
		
		mov [res2],ax
		
	jmp do2
	
	exited2:
	;result will be in res1 after the function ends
	ret
	
xor rax,rax
mov ax,[res1]
mov bx,[res2]
add ax,bx
add ax,'0'
mov [sum],ax


mov rax,1
mov rdi,1
mov rsi,sum
mov rdx,1
syscall


mov rax,60
mov rdi,0
syscall
