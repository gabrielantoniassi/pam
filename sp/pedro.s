	.file	"pedro.c"
	.abiversion 2
	.section	".text"
	.section	.rodata
	.align 3
.LC2:
	.string	"m/s = %f\n"
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
	mflr 0
	std 0,16(1)
	std 31,-8(1)
	stdu 1,-176(1)
	.cfi_def_cfa_offset 176
	.cfi_offset 65, 16
	.cfi_offset 31, -8
	mr 31,1
	.cfi_def_cfa_register 31
	addis 9,2,.LC0@toc@ha
	addi 9,9,.LC0@toc@l
	lfd 0,0(9)
	stfd 0,104(31)
	addis 9,2,.LC1@toc@ha
	addi 9,9,.LC1@toc@l
	lfd 0,0(9)
	stfd 0,112(31)
	bl clock
	nop
	std 3,120(31)
#APP
 # 10 "pedro.c" 1
	# soma
 # 0 "" 2
#NO_APP
	lfd 12,104(31)
	lfd 0,112(31)
	fadd 0,12,0
	stfd 0,128(31)
	bl clock
	nop
	std 3,136(31)
	addi 9,31,136
	lxsdx 32,0,9
	xscvsxddp 12,32
	addi 9,31,120
	lxsdx 32,0,9
	xscvsxddp 0,32
	fsub 0,12,0
	stfd 0,144(31)
	bl clock
	nop
	std 3,120(31)
#APP
 # 16 "pedro.c" 1
	# mul
 # 0 "" 2
#NO_APP
	lfd 12,104(31)
	lfd 0,112(31)
	fmul 0,12,0
	stfd 0,128(31)
	bl clock
	nop
	std 3,136(31)
	addi 9,31,136
	lxsdx 32,0,9
	xscvsxddp 12,32
	addi 9,31,120
	lxsdx 32,0,9
	xscvsxddp 0,32
	fsub 0,12,0
	stfd 0,152(31)
#APP
 # 21 "pedro.c" 1
	# print
 # 0 "" 2
#NO_APP
	lfd 12,152(31)
	lfd 0,144(31)
	fdiv 0,12,0
	mfvsrd 9,0
	mr 8,9
	mr 10,9
	mr 9,8
	mtvsrd 0,10
	mr 4,9
	fmr 1,0
	addis 3,2,.LC2@toc@ha
	addi 3,3,.LC2@toc@l
	bl printf
	nop
#APP
 # 23 "pedro.c" 1
	# end
 # 0 "" 2
#NO_APP
	li 9,0
	mr 3,9
	addi 1,31,176
	.cfi_def_cfa 1, 0
	ld 0,16(1)
	mtlr 0
	ld 31,-8(1)
	blr
	.long 0
	.byte 0,0,0,1,128,1,0,1
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
	.gnu_attribute 4, 1
	.section	.note.GNU-stack,"",@progbits
