	.file	"No0521_2.c"
	.section	.rodata
.LC0:
	.string	"(C2)+(4F) = %X(16) %d(10) "
.LC1:
	.string	"(C2)-(4F) = %X(16) %d(10) "
.LC2:
	.string	"(C2)OR(4F) = %X(16) %d(10) "
.LC3:
	.string	"(C2)AND(4F) = %X(16) %d(10) "
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$52, %esp
	movl	$194, -28(%ebp)
	movl	$79, -24(%ebp)
	movl	-24(%ebp), %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -20(%ebp)
	movl	-24(%ebp), %edx
	movl	-28(%ebp), %eax
	subl	%edx, %eax
	movl	%eax, -16(%ebp)
	movl	-24(%ebp), %edx
	movl	-28(%ebp), %eax
	orl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	-24(%ebp), %edx
	movl	-28(%ebp), %eax
	andl	%edx, %eax
	movl	%eax, -8(%ebp)
	movl	$10, (%esp)
	call	putchar
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	cto2
	movl	$10, (%esp)
	call	putchar
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	cto2
	movl	$10, (%esp)
	call	putchar
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	cto2
	movl	$10, (%esp)
	call	putchar
	movl	-8(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	movl	-8(%ebp), %eax
	movl	%eax, (%esp)
	call	cto2
	movl	$10, (%esp)
	call	putchar
	movl	$0, %eax
	addl	$52, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (Debian 4.3.2-1.1) 4.3.2"
	.section	.note.GNU-stack,"",@progbits
