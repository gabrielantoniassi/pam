	.file	"sem_tempo.c"
	.abiversion 2
	.section	".text"
	.align 2
	.globl main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
.LCF0:
0:	addis 2,12,.TOC.-.LCF0@ha
	addi 2,2,.TOC.-.LCF0@l
	.localentry	main,.-main
	std 31,-8(1)
	stdu 1,-80(1)
	.cfi_def_cfa_offset 80
	.cfi_offset 31, -8
	mr 31,1
	.cfi_def_cfa_register 31
	addis 9,2,.LC0@toc@ha
	addi 9,9,.LC0@toc@l
	lfd 0,0(9)
	stfd 0,40(31)
	addis 9,2,.LC1@toc@ha
	addi 9,9,.LC1@toc@l
	lfd 0,0(9)
	stfd 0,48(31)
#APP
 # 9 "sem_tempo.c" 1
	# soma
 # 0 "" 2
#NO_APP
	lfd 12,40(31)
	lfd 0,48(31)
	fadd 0,12,0
	stfd 0,56(31)
#APP
 # 12 "sem_tempo.c" 1
	# mul
 # 0 "" 2
#NO_APP
	lfd 12,40(31)
	lfd 0,48(31)
	fmul 0,12,0
	stfd 0,56(31)
#APP
 # 15 "sem_tempo.c" 1
	# print
 # 0 "" 2
 # 17 "sem_tempo.c" 1
	# end
 # 0 "" 2
#NO_APP
	li 9,0
	mr 3,9
	addi 1,31,80
	.cfi_def_cfa 1, 0
	ld 31,-8(1)
	blr
	.long 0
	.byte 0,0,0,0,128,1,0,1
	.cfi_endproc
.LFE0:
	.size	main,.-main
	.section	.rodata
	.align 3
.LC0:
	.long	3229815407
	.long	1074340298
	.align 3
.LC1:
	.long	2755651017
	.long	1074118367
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
