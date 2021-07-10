	.file	"2daray.c"
	.section	.rodata
.LC0:
	.string	"%d "
	.text
	.globl	fun
	.type	fun, @function
fun:
.LFB0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$0, -8(%ebp)
	jmp	.L2
.L5:
	movl	$0, -4(%ebp)
	jmp	.L3
.L4:
	movl	-16(%ebp), %eax
	sall	$3, %eax
	addl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	(%eax,%edx,4), %edx
	movl	$.LC0, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$1, -12(%ebp)
.L3:
	cmpl	$1, 12(%ebp)
	jle	.L4
	movl	$10, (%esp)
	call	putchar
	addl	$1, 16(%ebp)
.L2:
	cmpl	$1, 16(%ebp)
	jle	.L5
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	fun, .-fun
	.globl	main
	.type	main, @function
main:
.LFB1:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$1, -16(%ebp)
	movl	$2, -12(%ebp)
	movl	$3, -8(%ebp)
	movl	$4, -4(%ebp)
	pushl	$2             # pushl internellly decrements esp by 4 bytes 
	pushl	$2
	leal	-16(%ebp), %eax
	push 	%eax
	call	fun
	addl	$12, %esp    # deallocating 12 bytes of stack for actual argmnts
	movl	$0, %eax
	leave
	ret
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
