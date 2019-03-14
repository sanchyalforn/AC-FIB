 .text
	.align 4
	.globl Asignar
	.type Asignar,@function
Asignar:

	#pos = 24%ebp
	#X = 12%ebp
	#v[] = 8+%ebp
	#S1: c (1) ; k (4) ; *m (8)

	pushl %ebp
	movl %esp, %ebp
	
	#v[pos]	
	movl 8(%ebp), %eax #&v[]
	imul $12, 24(%ebp), %edx#v[pos]

	#v[pos].c = X.c
	movl 12(%ebp), %ecx #X.c
	movb %ecx,(%edx, %eax) #v[pos].c = X.c

	#v[pos].k = X.k
	movl 16(%ebp), %ecx #X.k
	movil %ecx, 4(%edx, %eax)
	
	#v[pos].m = X.m
	movl 20(%ebp), %ecx
	movil %ecx, 8(%edx, %eax) 

	movl %ebp, %esp
	popl %ebp
