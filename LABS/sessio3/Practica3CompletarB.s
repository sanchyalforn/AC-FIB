.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo

    movl $0, -4(%ebp)
    movl $0, -8(%ebp)

for1:
    cmpl $3, -8(%ebp)
    jge endfor
    movl $0, -12(%ebp)
for2:
    cmpl $3, -12(%ebp)
    jge endfor2
    movl -8(%ebp),%eax
    imull $12, %eax
    movl -12(%ebp),%ebx
    imull $4, %ebx
    addl %ebx, %eax
    movl %eax, %ecx
    addl 8(%ebp), %ecx
    movl (%ecx), %ecx
    addl %ecx, -4(%ebp)
    movl 12(%ebp), %ecx
    addl %ecx, -12(%ebp)
    jmp for2
endfor2:
    movl 12(%ebp), %ecx
    addl %ecx, -8(%ebp)
    jmp for1
endfor:

    

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret
