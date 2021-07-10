	.file	"aray.c"
	.section	.rodata
.LC0:
	.string	"%d %d"
	.text
	.globl	fun
	.type	fun, @function
fun:
.LFB0:
	pushl	%ebp
	movl	%esp, %ebp
	addl	$4, 8(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %ecx
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	$.LC0, %eax
	pushl   %ecx
	pushl	%edx
	pushl	%eax
	call	printf
	addl	$12, %esp
	leave
	ret

.LFE0:
	.size	fun, .-fun
	.globl	main
	.type	main, @function
main:
.LFB1:

	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$1, -8(%ebp)
	movl	$20, -4(%ebp)
	leal	-8(%ebp), %eax
	pushl 	%eax
	call	fun
	addl	$4, %esp
	movl	$0, %eax
	leave
	ret

	
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
