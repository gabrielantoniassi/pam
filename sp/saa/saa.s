	.file	"saa.c"
	.abiversion 2
	.section	".text"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 3
.LC2:
	.string	"m/s = %f\n"
	.section	.text.startup,"ax",@progbits
	.align 2
	.p2align 4,,15
	.globl main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
.LCF0:
0:	addis 2,12,.TOC.-.LCF0@ha
	addi 2,2,.TOC.-.LCF0@l
	.localentry	main,.-main
	mflr 0
	stfd 31,-8(1)
	std 0,16(1)
	stdu 1,-128(1)
	.cfi_def_cfa_offset 128
	.cfi_offset 65, 16
	.cfi_offset 63, -8
	li 0,96
	stvx 31,1,0
	.cfi_offset 108, -32
#APP
 # 14 "saa.c" 1
	# primeiro loop
 # 0 "" 2
#NO_APP
	bl clock
	nop
	mtvsrd 63,3
	bl clock
	nop
	mtvsrd 31,3
	xscvsxddp 63,63
	fcfid 31,31
	xssubdp 31,31,63
#APP
 # 26 "saa.c" 1
	# segundo loop
 # 0 "" 2
#NO_APP
	bl clock
	nop
	mtvsrd 63,3
	bl clock
	nop
	addis 9,2,.LC0@toc@ha
	addis 4,2,.LC2@toc@ha
	addi 4,4,.LC2@toc@l
	mtvsrd 0,3
	fneg 1,31
	lfd 12,.LC0@toc@l(9)
	li 3,1
	xscvsxddp 63,63
	fcfid 0,0
	xssubdp 0,0,63
	fsub 31,31,0
	fmadd 1,1,12,0
	fdiv 1,1,31
	mfvsrd 5,1
	bl __printf_chk
	nop
	addi 1,1,128
	.cfi_def_cfa_offset 0
	li 0,-32
	li 3,0
	lvx 31,1,0
	ld 0,16(1)
	lfd 31,-8(1)
	mtlr 0
	.cfi_restore 65
	.cfi_restore 63
	.cfi_restore 108
	blr
	.long 0
	.byte 0,0,2,1,129,0,0,0
	.cfi_endproc
.LFE23:
	.size	main,.-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 3
.LC0:
	.long	0
	.long	1071644672
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.gnu_attribute 4, 1
	.section	.note.GNU-stack,"",@progbits
