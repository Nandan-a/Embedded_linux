	.file	"fork_race_solution_with_wait.c"
	.text
	.globl	count
	.data
	.align 4
	.type	count, @object
	.size	count, 4
count:
	.long	10
	.section	.rodata
.LC0:
	.string	"Child process is created "
.LC1:
	.string	"Count in child block: %d\n"
.LC2:
	.string	"parent process block"
.LC3:
	.string	"Count in parent block: %d\n"
.LC4:
	.string	"ret val parent : %d\n"
.LC5:
	.string	"child is not created \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	call	fork@PLT
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jne	.L2
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	movl	count(%rip), %eax
	addl	$2, %eax
	movl	%eax, count(%rip)
	movl	count(%rip), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L3
.L2:
	cmpl	$0, -4(%rbp)
	jle	.L4
	movl	$0, %edi
	call	wait@PLT
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movl	count(%rip), %eax
	addl	$5, %eax
	movl	%eax, count(%rip)
	movl	count(%rip), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L3
.L4:
	leaq	.LC5(%rip), %rdi
	call	perror@PLT
.L3:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
