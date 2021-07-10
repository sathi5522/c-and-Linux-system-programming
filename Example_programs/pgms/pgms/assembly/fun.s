	.file	"fun.c"
	.text
	.globl	fun
	.type	fun, @function
fun:
.LFB0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	8(%ebp), %edx
	addl	%edx, %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
.LFE0:
	.size	fun, .-fun
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$12, %esp
	movl	$10, -12(%ebp)
	movl	$20, -8(%ebp)
	pushl	-8(%ebp)
	pushl	-12(%ebp)
	call	fun
	pushl 	-4(%ebp)
	movl	$.LC0, %eax
	pushl 	%eax
	call	printf
	leave
	ret
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
