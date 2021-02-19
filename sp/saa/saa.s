	.file	"saa.c"
	.abiversion 2
	.section	".text"
	.section	.rodata
	.align 3
.LC5:
	.string	"m/s = %f\n"
	.align 3
.LC6:
	.string	"soh pro compilador nao tirar: %f %f %f\n"
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
	stdu 1,-208(1)
	.cfi_def_cfa_offset 208
	.cfi_offset 65, 16
	.cfi_offset 31, -8
	mr 31,1
	.cfi_def_cfa_register 31
	lis 9,0x1dcd
	ori 9,9,0x6500
	stw 9,108(31)
	addis 9,2,.LC0@toc@ha
	addi 9,9,.LC0@toc@l
	lfd 0,0(9)
	stfd 0,136(31)
	addis 9,2,.LC1@toc@ha
	addi 9,9,.LC1@toc@l
	lfd 0,0(9)
	stfd 0,128(31)
	xxlxor 0,0,0
	stfd 0,120(31)
#APP
 # 14 "saa.c" 1
	# primeiro loop
 # 0 "" 2
#NO_APP
	bl clock
	nop
	std 3,144(31)
	li 9,0
	stw 9,104(31)
	b .L2
.L3:
	lfd 12,136(31)
	lfd 0,128(31)
	fmul 12,12,0
	addis 9,2,.LC2@toc@ha
	addi 9,9,.LC2@toc@l
	lfd 11,0(9)
	lfd 0,128(31)
	fsub 0,11,0
	fmul 0,12,0
	stfd 0,128(31)
	lfd 12,120(31)
	lfd 0,128(31)
	fadd 0,12,0
	stfd 0,120(31)
	lwz 9,104(31)
	addi 9,9,1
	stw 9,104(31)
.L2:
	lwz 10,104(31)
	lwz 9,108(31)
	cmpw 0,10,9
	blt 0,.L3
	bl clock
	nop
	std 3,152(31)
	addi 9,31,152
	lxsdx 32,0,9
	xscvsxddp 12,32
	addi 9,31,144
	lxsdx 32,0,9
	xscvsxddp 0,32
	fsub 0,12,0
	stfd 0,160(31)
	addis 9,2,.LC3@toc@ha
	addi 9,9,.LC3@toc@l
	lfd 0,0(9)
	stfd 0,112(31)
	lfd 12,112(31)
	lfd 0,128(31)
	fadd 12,12,0
	addis 9,2,.LC4@toc@ha
	addi 9,9,.LC4@toc@l
	lfd 0,0(9)
	fdiv 0,12,0
	stfd 0,112(31)
#APP
 # 26 "saa.c" 1
	# segundo loop
 # 0 "" 2
#NO_APP
	bl clock
	nop
	std 3,144(31)
	li 9,0
	stw 9,104(31)
	b .L4
.L5:
	lfd 12,136(31)
	lfd 0,112(31)
	fmul 12,12,0
	addis 9,2,.LC2@toc@ha
	addi 9,9,.LC2@toc@l
	lfd 11,0(9)
	lfd 0,112(31)
	fsub 0,11,0
	fmul 0,12,0
	stfd 0,112(31)
	lwz 9,104(31)
	addi 9,9,1
	stw 9,104(31)
.L4:
	lwz 10,104(31)
	lwz 9,108(31)
	cmpw 0,10,9
	blt 0,.L5
	bl clock
	nop
	std 3,152(31)
	addi 9,31,152
	lxsdx 32,0,9
	xscvsxddp 12,32
	addi 9,31,144
	lxsdx 32,0,9
	xscvsxddp 0,32
	fsub 0,12,0
	stfd 0,168(31)
	lfd 12,160(31)
	lfd 0,168(31)
	fsub 0,12,0
	stfd 0,176(31)
	lfd 12,160(31)
	addis 9,2,.LC4@toc@ha
	addi 9,9,.LC4@toc@l
	lfd 0,0(9)
	fdiv 0,12,0
	lfd 12,168(31)
	fsub 0,12,0
	stfd 0,184(31)
	lfd 12,184(31)
	lfd 0,176(31)
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
	ld 8,112(31)
	lfd 11,112(31)
	ld 10,120(31)
	lfd 12,120(31)
	ld 9,128(31)
	lfd 0,128(31)
	mr 6,8
	fmr 3,11
	mr 5,10
	fmr 2,12
	mr 4,9
	fmr 1,0
	addis 3,2,.LC6@toc@ha
	addi 3,3,.LC6@toc@l
	bl printf
	nop
	li 9,0
	mr 3,9
	addi 1,31,208
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
	.long	1889785610
	.long	1074596413
	.align 3
.LC1:
	.long	3264175145
	.long	1070344437
	.align 3
.LC2:
	.long	0
	.long	1072693248
	.align 3
.LC3:
	.long	858993459
	.long	1069757235
	.align 3
.LC4:
	.long	0
	.long	1073741824
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.gnu_attribute 4, 1
	.section	.note.GNU-stack,"",@progbits
