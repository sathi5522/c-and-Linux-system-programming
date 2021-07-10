add:
	pushl %ebp
	movl %esp,%ebp
	movl -8(%ebp),%eax
	addl -12(%ebp),%eax
	popl %ebp
	ret
main:
	pushl %ebp
	movl %esp,%ebp
	subl $12,%esp
	movl $10,-12(%ebp)
	movl $20,-8(%ebp)
	pushl -8(%ebp)
	pushl -12(%ebp)
	call add
	movl %eax,-4(%ebp)
	addl $8,%esp
	leave
	ret
