	.file	"simples.c"
	.abiversion 2
	.section	".text"
	.align 2
	.type	__ppc_get_timebase, @function
__ppc_get_timebase:
.LFB0:
	.cfi_startproc
	std 31,-8(1)
	stdu 1,-48(1)
	.cfi_def_cfa_offset 48
	.cfi_offset 31, -8
	mr 31,1
	.cfi_def_cfa_register 31
	mfspr 9,268
	mr 3,9
	addi 1,31,48
	.cfi_def_cfa 1, 0
	ld 31,-8(1)
	blr
	.long 0
	.byte 0,0,0,0,128,1,0,1
	.cfi_endproc
.LFE0:
	.size	__ppc_get_timebase,.-__ppc_get_timebase
	.section	.rodata
	.align 3
.LC4:
	.string	"ts = %f\n"
	.align 3
.LC5:
	.string	"tm = %f\n"
	.align 3
.LC6:
	.string	"m/s = %f\n"
	.align 3
.LC7:
	.string	"soh pro compilador nao remover: %f %f %f %f\n"
	.section	".text"
	.align 2
	.globl main
	.type	main, @function
main:
.LFB9:
	.cfi_startproc
.LCF1:
0:	addis 2,12,.TOC.-.LCF1@ha
	addi 2,2,.TOC.-.LCF1@l
	.localentry	main,.-main
	mflr 0
	std 0,16(1)
	std 31,-8(1)
	stdu 1,-256(1)
	.cfi_def_cfa_offset 256
	.cfi_offset 65, 16
	.cfi_offset 31, -8
	mr 31,1
	.cfi_def_cfa_register 31
	ld 9,-28688(13)
	std 9,232(31)
	li 9,0
	addis 9,2,.LC0@toc@ha
	addi 9,9,.LC0@toc@l
	lfd 0,0(9)
	stfd 0,168(31)
	addis 9,2,.LC1@toc@ha
	addi 9,9,.LC1@toc@l
	lfd 0,0(9)
	stfd 0,176(31)
	addis 9,2,.LC2@toc@ha
	addi 9,9,.LC2@toc@l
	lfd 0,0(9)
	stfd 0,184(31)
	addis 9,2,.LC3@toc@ha
	addi 9,9,.LC3@toc@l
	lfd 0,0(9)
	stfd 0,192(31)
	li 9,-72
	addi 10,31,240
	lxvd2x 0,10,9
	xxpermdi 0,0,0,2
	xxpermdi 0,0,0,2
	li 9,-112
	addi 10,31,240
	stxvd2x 0,10,9
	li 9,-56
	addi 10,31,240
	lxvd2x 0,10,9
	xxpermdi 0,0,0,2
	xxpermdi 0,0,0,2
	li 9,-96
	addi 10,31,240
	stxvd2x 0,10,9
#APP
 # 21 "simples.c" 1
	# soma
 # 0 "" 2
#NO_APP
	bl __ppc_get_timebase
	mr 9,3
	std 9,96(31)
	li 9,-112
	addi 10,31,240
	lxvd2x 0,10,9
	xxpermdi 12,0,0,2
	li 9,-96
	addi 10,31,240
	lxvd2x 0,10,9
	xxpermdi 0,0,0,2
	xvadddp 0,12,0
	li 9,-40
	xxpermdi 0,0,0,2
	addi 10,31,240
	stxvd2x 0,10,9
	bl __ppc_get_timebase
	mr 9,3
	std 9,104(31)
	addi 9,31,104
	lxsdx 32,0,9
	xscvsxddp 12,32
	addi 9,31,96
	lxsdx 32,0,9
	xscvsxddp 0,32
	fsub 0,12,0
	stfd 0,112(31)
	ld 9,112(31)
	lfd 0,112(31)
	mr 4,9
	fmr 1,0
	addis 3,2,.LC4@toc@ha
	addi 3,3,.LC4@toc@l
	bl printf
	nop
#APP
 # 28 "simples.c" 1
	# mul
 # 0 "" 2
#NO_APP
	bl __ppc_get_timebase
	mr 9,3
	std 9,96(31)
	li 9,-112
	addi 10,31,240
	lxvd2x 0,10,9
	xxpermdi 12,0,0,2
	li 9,-96
	addi 10,31,240
	lxvd2x 0,10,9
	xxpermdi 0,0,0,2
	xvmuldp 0,12,0
	li 9,-24
	xxpermdi 0,0,0,2
	addi 10,31,240
	stxvd2x 0,10,9
	bl __ppc_get_timebase
	mr 9,3
	std 9,104(31)
	addi 9,31,104
	lxsdx 32,0,9
	xscvsxddp 12,32
	addi 9,31,96
	lxsdx 32,0,9
	xscvsxddp 0,32
	fsub 0,12,0
	stfd 0,120(31)
	ld 9,120(31)
	lfd 0,120(31)
	mr 4,9
	fmr 1,0
	addis 3,2,.LC5@toc@ha
	addi 3,3,.LC5@toc@l
	bl printf
	nop
#APP
 # 35 "simples.c" 1
	# printando
 # 0 "" 2
#NO_APP
	lfd 12,120(31)
	lfd 0,112(31)
	fdiv 0,12,0
	mfvsrd 9,0
	mr 8,9
	mr 10,9
	mr 9,8
	mtvsrd 0,10
	mr 4,9
	fmr 1,0
	addis 3,2,.LC6@toc@ha
	addi 3,3,.LC6@toc@l
	bl printf
	nop
	lfd 0,200(31)
	lfd 12,208(31)
	lfd 11,216(31)
	lfd 10,224(31)
	mfvsrd 9,10
	mr 10,9
	mr 7,10
	mtvsrd 10,9
	mfvsrd 9,11
	mr 10,9
	mr 8,10
	mtvsrd 11,9
	mfvsrd 9,12
	mr 10,9
	mtvsrd 12,9
	mfvsrd 9,0
	mr 5,9
	mr 6,9
	mr 9,5
	mtvsrd 0,6
	fmr 4,10
	mr 6,8
	fmr 3,11
	mr 5,10
	fmr 2,12
	mr 4,9
	fmr 1,0
	addis 3,2,.LC7@toc@ha
	addi 3,3,.LC7@toc@l
	bl printf
	nop
#APP
 # 38 "simples.c" 1
	# final
 # 0 "" 2
#NO_APP
	li 9,0
	ld 10,232(31)
	ld 8,-28688(13)
	xor. 10,10,8
	li 8,0
	beq 0,.L5
	bl __stack_chk_fail
	nop
.L5:
	mr 3,9
	addi 1,31,256
	.cfi_def_cfa 1, 0
	ld 0,16(1)
	mtlr 0
	ld 31,-8(1)
	blr
	.long 0
	.byte 0,0,0,1,128,1,0,1
	.cfi_endproc
.LFE9:
	.size	main,.-main
	.section	.rodata
	.align 3
.LC0:
	.long	858993459
	.long	1072902963
	.align 3
.LC1:
	.long	1717986918
	.long	1073112678
	.align 3
.LC2:
	.long	3435973837
	.long	1072745676
	.align 3
.LC3:
	.long	1374389535
	.long	1072766648
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.gnu_attribute 4, 1
	.section	.note.GNU-stack,"",@progbits
