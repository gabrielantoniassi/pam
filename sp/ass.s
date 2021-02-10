	.file	"ass.c"
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
#APP
 # 4 "ass.c" 1
	# double a;
 # 0 "" 2
 # 6 "ass.c" 1
	# a = 1;
 # 0 "" 2
#NO_APP
	addis 9,2,.LC0@toc@ha
	addi 9,9,.LC0@toc@l
	lfd 0,0(9)
	stfd 0,40(31)
#APP
 # 8 "ass.c" 1
	# doubel b;
 # 0 "" 2
 # 10 "ass.c" 1
	# b = a
 # 0 "" 2
#NO_APP
	lfd 0,40(31)
	stfd 0,48(31)
#APP
 # 12 "ass.c" 1
	# double c;
 # 0 "" 2
 # 14 "ass.c" 1
	# comeca o asm:
 # 0 "" 2
#NO_APP
	ld 9,40(31)
#APP
 # 15 "ass.c" 1
	stfd 9, 9
 # 0 "" 2
#NO_APP
	std 9,56(31)
#APP
 # 18 "ass.c" 1
	# fim
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
	.long	0
	.long	1072693248
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
