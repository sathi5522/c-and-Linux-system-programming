	.file	"oval.c"
	.section	.rodata
.LC0:
	.string	"enter any character"
.LC1:
	.string	"%c"
.LC2:
	.string	"it is a oval"
.LC3:
	.string	"it is not a oval"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	$.LC0, (%esp)
	call	puts
	movl	$.LC1, %eax
	leal	31(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__isoc99_scanf
	movzbl	31(%esp), %eax
	movsbl	%al, %eax
	subl	$97, %eax
	cmpl	$20, %eax
	ja	.L2
	movl	.L8(,%eax,4), %eax
	jmp	*%eax
	.section	.rodata
	.align 4
	.align 4
.L8:
	.long	.L3
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L4
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L5
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L6
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L2
	.long	.L7
	.text
.L3:
	movl	$.LC2, %eax
	movl	%eax, (%esp)
	call	printf
	jmp	.L9
.L4:
	movl	$.LC2, %eax
	movl	%eax, (%esp)
	call	printf
	jmp	.L9
.L5:
	movl	$.LC2, %eax
	movl	%eax, (%esp)
	call	printf
	jmp	.L9
.L6:
	movl	$.LC2, %eax
	movl	%eax, (%esp)
	call	printf
	jmp	.L9
.L7:
	movl	$.LC2, %eax
	movl	%eax, (%esp)
	call	printf
	jmp	.L9
.L2:
	movl	$.LC3, %eax
	movl	%eax, (%esp)
	call	printf
.L9:
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
