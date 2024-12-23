global main
section .data

; a+b < 2560

num dw 50
num2 dw 100
res1 dw 100
res2 dw 100
n dw 0
len equ 10
c times len db 0
d times len db 0

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
	;result will be in res2 after the function ends


	mov ax,[res1]
	mov bx,[res2]


	add ax, bx
	;osszeadom a ket szamot
	mov dl, 2
	div dl
	;elosztom kettovel... cuz duhhh
	mov ah, 0
	
	
	mov [n], ax ;ax-ben az atlag
;indexeles hatulrol, rsi index
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
;[rsi] = c[i] <- a legutolso aktualis szamjegy
		mov bx,[n]
		cmp bx,0
		
;ha meg vannak szamjegyek ismetel

	ja do

mov rbx,len
add rbx,c
sub rbx,rsi

;kiszamolom a letrejott szamnak a hosszat

mov rax,1
mov rdi,1
inc rsi
mov rdx,rbx
syscall
;parameterek feltoltese + kiir


mov rax,60
xor rdi,rdi
syscall
