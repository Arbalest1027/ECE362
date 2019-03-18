	.syntax unified
	.cpu cortex-m0
	.fpu softvfp
	.thumb


main:
	movs r0, #0
mainloop:
	adds r0,r0,#1
	b	mainloop
