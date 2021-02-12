	.file	"pdro.c"
	.abiversion 2
	.section	".text"
	.section	.rodata
	.align 3
.LC2:
	.string	"ts = %f\n"
	.align 3
.LC3:
	.string	"tm = %f\n"
	.align 3
.LC4:
	.string	"tl = %f\n"
	.align 3
.LC5:
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
	stdu 1,-272(1)
	.cfi_def_cfa_offset 272
	.cfi_offset 65, 16
	.cfi_offset 31, -8
	mr 31,1
	.cfi_def_cfa_register 31
	ld 9,-28688(13)
	std 9,248(31)
	li 9,0
	lis 9,0x3b9a
	ori 9,9,0xca00
	stw 9,100(31)
	addis 9,2,.LC0@toc@ha
	addi 9,9,.LC0@toc@l
	lfd 0,0(9)
	stfd 0,104(31)
	addis 9,2,.LC1@toc@ha
	addi 9,9,.LC1@toc@l
	lfd 0,0(9)
	stfd 0,112(31)
	addis 9,2,.LC1@toc@ha
	addi 9,9,.LC1@toc@l
	lfd 0,0(9)
	stfd 0,200(31)
	addis 9,2,.LC1@toc@ha
	addi 9,9,.LC1@toc@l
	lfd 0,0(9)
	stfd 0,208(31)
	addis 9,2,.LC0@toc@ha
	addi 9,9,.LC0@toc@l
	lfd 0,0(9)
	stfd 0,216(31)
	addis 9,2,.LC0@toc@ha
	addi 9,9,.LC0@toc@l
	lfd 0,0(9)
	stfd 0,224(31)
	li 9,-56
	addi 10,31,256
	lxvd2x 0,10,9
	xxpermdi 0,0,0,2
	xxpermdi 0,0,0,2
	li 9,-96
	addi 10,31,256
	stxvd2x 0,10,9
	li 9,-40
	addi 10,31,256
	lxvd2x 0,10,9
	xxpermdi 0,0,0,2
	xxpermdi 0,0,0,2
	li 9,-80
	addi 10,31,256
	stxvd2x 0,10,9
	bl clock
	nop
	std 3,120(31)
#APP
 # 22 "pdro.c" 1
	# soma
 # 0 "" 2
#NO_APP
	li 9,0
	stw 9,96(31)
	b .L2
.L3:
	li 9,-96
	addi 10,31,256
	lxvd2x 0,10,9
	xxpermdi 12,0,0,2
	li 9,-80
	addi 10,31,256
	lxvd2x 0,10,9
	xxpermdi 0,0,0,2
	xvadddp 12,12,0
	li 9,-96
	addi 10,31,256
	lxvd2x 0,10,9
	xxpermdi 0,0,0,2
	xvadddp 0,12,0
	li 9,-24
	xxpermdi 0,0,0,2
	addi 10,31,256
	stxvd2x 0,10,9
	lwz 9,96(31)
	addi 9,9,1
	stw 9,96(31)
.L2:
	lwz 10,96(31)
	lwz 9,100(31)
	cmpw 0,10,9
	blt 0,.L3
	bl clock
	nop
	std 3,128(31)
	addi 9,31,128
	lxsdx 32,0,9
	xscvsxddp 12,32
	addi 9,31,120
	lxsdx 32,0,9
	xscvsxddp 0,32
	fsub 0,12,0
	stfd 0,136(31)
	ld 9,136(31)
	lfd 0,136(31)
	mr 4,9
	fmr 1,0
	addis 3,2,.LC2@toc@ha
	addi 3,3,.LC2@toc@l
	bl printf
	nop
	bl clock
	nop
	std 3,120(31)
#APP
 # 30 "pdro.c" 1
	# mul
 # 0 "" 2
#NO_APP
	li 9,0
	stw 9,96(31)
	b .L4
.L5:
	li 9,-96
	addi 10,31,256
	lxvd2x 0,10,9
	xxpermdi 12,0,0,2
	li 9,-80
	addi 10,31,256
	lxvd2x 0,10,9
	xxpermdi 0,0,0,2
	xvmuldp 0,12,0
	li 9,-24
	xxpermdi 0,0,0,2
	addi 10,31,256
	stxvd2x 0,10,9
	lwz 9,96(31)
	addi 9,9,1
	stw 9,96(31)
.L4:
	lwz 10,96(31)
	lwz 9,100(31)
	cmpw 0,10,9
	blt 0,.L5
	bl clock
	nop
	std 3,128(31)
	addi 9,31,128
	lxsdx 32,0,9
	xscvsxddp 12,32
	addi 9,31,120
	lxsdx 32,0,9
	xscvsxddp 0,32
	fsub 0,12,0
	stfd 0,144(31)
	ld 9,144(31)
	lfd 0,144(31)
	mr 4,9
	fmr 1,0
	addis 3,2,.LC3@toc@ha
	addi 3,3,.LC3@toc@l
	bl printf
	nop
	bl clock
	nop
	std 3,120(31)
#APP
 # 38 "pdro.c" 1
	# loop vazio
 # 0 "" 2
#NO_APP
	li 9,0
	stw 9,96(31)
	b .L6
.L7:
	li 9,-96
	addi 10,31,256
	lxvd2x 0,10,9
	xxpermdi 0,0,0,2
	li 9,-24
	xxpermdi 0,0,0,2
	addi 10,31,256
	stxvd2x 0,10,9
	lwz 9,96(31)
	addi 9,9,1
	stw 9,96(31)
.L6:
	lwz 10,96(31)
	lwz 9,100(31)
	cmpw 0,10,9
	blt 0,.L7
	bl clock
	nop
	std 3,128(31)
	addi 9,31,128
	lxsdx 32,0,9
	xscvsxddp 12,32
	addi 9,31,120
	lxsdx 32,0,9
	xscvsxddp 0,32
	fsub 0,12,0
	stfd 0,152(31)
	ld 9,152(31)
	lfd 0,152(31)
	mr 4,9
	fmr 1,0
	addis 3,2,.LC4@toc@ha
	addi 3,3,.LC4@toc@l
	bl printf
	nop
#APP
 # 45 "pdro.c" 1
	# printando
 # 0 "" 2
#NO_APP
	lfd 12,144(31)
	lfd 0,152(31)
	fsub 12,12,0
	lfd 11,136(31)
	lfd 0,152(31)
	fsub 0,11,0
	fdiv 0,12,0
	mfvsrd 9,0
	mr 8,9
	mr 10,9
	mr 9,8
	mtvsrd 0,10
	mr 4,9
	fmr 1,0
	addis 3,2,.LC5@toc@ha
	addi 3,3,.LC5@toc@l
	bl printf
	nop
#APP
 # 47 "pdro.c" 1
	# final
 # 0 "" 2
#NO_APP
	li 9,0
	ld 10,248(31)
	ld 8,-28688(13)
	xor. 10,10,8
	li 8,0
	beq 0,.L9
	bl __stack_chk_fail
	nop
.L9:
	mr 3,9
	addi 1,31,272
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
