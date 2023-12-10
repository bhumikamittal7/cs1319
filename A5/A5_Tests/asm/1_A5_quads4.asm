	.file	"testASM.nc"
	.text	
	.globl	sum
	.type	sum, @function
sum: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$52, %rsp
	movq	%rdi, -20(%rbp)
	movl	$0, %eax
	movl 	%eax, -24(%rbp)
	movl	-20(%rbp), %eax
	cmpl	-24(%rbp), %eax
	je .L2
	jmp .L3
	jmp .L3
.L2: 
	movl	-20(%rbp), %eax
	jmp .L3
.L3: 
	movl	$1, %eax
	movl 	%eax, -32(%rbp)
	movl 	-20(%rbp), %eax
	movl 	-32(%rbp), %edx
	subl 	%edx, %eax
	movl 	%eax, -36(%rbp)
	movl 	-36(%rbp), %eax
	movq 	-36(%rbp), %rdi
	call	sum
	movl	%eax, -40(%rbp)
	movl 	-40(%rbp), %eax
	movl 	-20(%rbp), %edx
	addl 	%edx, %eax
	movl 	%eax, -44(%rbp)
	movl	-44(%rbp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	sum, .-sum
	.globl	main
	.type	main, @function
main: 
.LFB1:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$48, %rsp

	movl	$10, %eax
	movl 	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl 	%eax, -24(%rbp)
