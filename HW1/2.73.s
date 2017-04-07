	.file	"2.73.c"
	.text
	.p2align 4,,15
	.globl	saturating_add
	.type	saturating_add, @function
saturating_add:
.LFB11:
	.cfi_startproc
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	movl	12(%esp), %ebx
	movl	16(%esp), %ecx
	movl	%ebx, %edx
	movl	%ecx, %esi
	leal	(%ebx,%ecx), %eax
	notl	%edx
	notl	%esi
	shrl	$31, %ebx
	shrl	$31, %esi
	shrl	$31, %edx
	shrl	$31, %ecx
	andl	%esi, %edx
	movl	%eax, %esi
	shrl	$31, %esi
	andl	%esi, %edx
	testb	%cl, %bl
	je	.L2
	testl	%eax, %eax
	jns	.L10
.L2:
	testb	%dl, %dl
	movl	$2147483647, %edx
	cmovne	%edx, %eax
	popl	%ebx
	.cfi_remember_state
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	.cfi_restore_state
	movl	$-2147483648, %eax
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE11:
	.size	saturating_add, .-saturating_add
	.ident	"GCC: (GNU) 6.3.0"
	.section	.note.GNU-stack,"",@progbits
