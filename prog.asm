global main
section .data

num dw 50		; a+b < 2560
num2 dw 100
res1 dw 100
res2 dw 100
n dw 0
len equ 10
c times len db 0
d times len db 0

section .text

main:
;first number given from keyboard --> res1
mov word [res1],0
	do1:
							;read 1 character
		mov rax,0
		mov rdi,0
		mov rsi,num
		mov rdx,1
		syscall
							;check if the given key is a space
		cmp byte [num],' '
		je exited1			;if it is a space the reading from keyboard ends
		
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
	
	exited1:				;result will be in res1 after the function ends

;second number given from keyboard input --> res2
mov word [res2],0
	do2:
	;read 1 character
		mov rax,0
		mov rdi,0
		mov rsi,num2
		mov rdx,1
		syscall
							;check if there is a space
		cmp byte [num2],' '
		je exited2			;if it is a space the reading from keyboard ends
		
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
	
	exited2:				;result will be in res2 after the function ends

							;loading up the parameters with res1, res2
	mov ax,[res1]
	mov bx,[res2]


	add ax, bx
							;add the two numbers
	mov dl, 2
	div dl
							;then divide it by two(calcualte the median)
	mov ah, 0
	
	
	mov [n], ax 			;the median is in ax
							;we are indexing from the back, rsi is the index
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
							;[rsi] = c[i] <- the last actual digit
		mov bx,[n]
		cmp bx,0
		
							;repeat if there are more digits left

	ja do

mov rbx,len
add rbx,c
sub rbx,rsi

							;calculate the length of the given number

mov rax,1
mov rdi,1
inc rsi
mov rdx,rbx
syscall
							;loading the parameters up then writing the result out


mov rax,60
xor rdi,rdi
syscall
