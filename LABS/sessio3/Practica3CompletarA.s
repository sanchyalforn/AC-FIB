.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
# Aqui has de introducir el codigo

    movl    $1, %ebx
for:
    cmpl    12(%ebp),%ebx
    jge     fifor
    movl    8(%ebp),%ecx
    movl    (%ecx,%ebx,4),%ecx
    cmpl    %ecx,-4(%ebp)
    jge fiif
    movl %ecx,-4(%ebp)
fiif:
    incl %ebx
    jmp for
fifor:
    movl %ebx, -8(%ebp)
# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
