	.file	"testof.c"
	.text
	.p2align 4,,15
	.globl	testofv
	.type	testofv, @function
testofv:
.LFB0:
	.cfi_startproc
	movabsq	$9223372036854775807, %rax
	addq	%rdi, %rax
	cmpq	%rax, %rdi
	setg	%al
	ret
	.cfi_endproc
.LFE0:
	.size	testofv, .-testofv
	.ident	"GCC: (GNU) 6.3.0"
	.section	.note.GNU-stack,"",@progbits
