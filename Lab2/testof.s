	.file	"testof.c"
	.text
	.p2align 4,,15
	.globl	testofv
	.type	testofv, @function
testofv:
.LFB0:
	.cfi_startproc
	cmpq	$-19, %rdi
	setl	%al
	ret
	.cfi_endproc
.LFE0:
	.size	testofv, .-testofv
	.ident	"GCC: (GNU) 6.3.0"
	.section	.note.GNU-stack,"",@progbits
