	.file	"2.64.c"
	.text
	.p2align 4,,15
	.globl	any_odd_one
	.type	any_odd_one, @function
any_odd_one:
.LFB11:
	.cfi_startproc
	xorl	%eax, %eax
	testl	$-1431655766, 4(%esp)
	setne	%al
	ret
	.cfi_endproc
.LFE11:
	.size	any_odd_one, .-any_odd_one
	.ident	"GCC: (GNU) 6.3.0"
	.section	.note.GNU-stack,"",@progbits
