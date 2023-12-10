	.file	"testASM.nc"
	.comm	a,4,4
	.text	
	.globl	func
	.type	func, @function
func: 
.LFB0:
	.cfi_startproc
	pushq 	%rbp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movq 	%rsp, %rbp
	.cfi_def_cfa_register 5
	subq	$28, %rsp
	movq	%rdi, -20(%rbp)
	movq	%rsi, -16(%rbp)
	.ident		"Bhumika's Compiler LOL - pls pls reach here"
