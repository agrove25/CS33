	.file	"2.73-redo.c"
	.text
	.p2align 4,,15
	.globl	saturating_add
	.type	saturating_add, @function
saturating_add:
.LFB11:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %edx
	movl	%edx, %ebx
	addl	12(%esp), %ebx
	seto	%cl
	testl	%edx, %edx
	js	.L10
	testb	%cl, %cl
	movl	$2147483647, %eax
	je	.L10
.L4:
	shrl	$31, %edx
	testb	%dl, %dl
	je	.L1
	testb	%cl, %cl
	movl	$-2147483648, %edx
	cmovne	%edx, %eax
.L1:
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	.cfi_restore_state
	movl	%ebx, %eax
	jmp	.L4
	.cfi_endproc
.LFE11:
	.size	saturating_add, .-saturating_add
	.ident	"GCC: (GNU) 6.3.0"
	.section	.note.GNU-stack,"",@progbits
