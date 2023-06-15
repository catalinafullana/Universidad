/*---------------------------------------------------------------------
**	Catalina Fullana Mora
**  Fichero:
**    fun_asm.c  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 4
**
**-------------------------------------------------------------------*/
/*
.global guardar
.global eucl_dist
.extern main
.extern i_sqrt
.extern mul
*/

.extern guardar
.extern eucl_dist
.extern main
.global i_sqrt
.global mul
.extern _stack
.data
.bss

.text
/*
eucl_dist:
	addi sp, sp, -28		// PRÓLOGO
	sw ra, 24(sp)
	sw s0, 20(sp)
	sw s1, 16(sp)
	sw s2, 12(sp)
	sw s3, 8(sp)
	sw s4, 4(sp)
	sw s5, 0(sp)

	mv s0, a0				// wi en s0
	mv s1, a1				// s1=a1
	li s2, 0     			// acc=0
	li s3, 0   				// i=0

	for:
		bge s3, s1, efor 	// si cond. contraria salta al efor
		mv a0, s0			// a0 = s0
		slli t0, s3, 2   	// desplazamiento
		add t1, s0, t0		//
		lw t2, 0(t1)		//

		mv a0, t2			// a0 = wi
		mv a1, a0			// a1 = wi

		call mul			// jump a mul
							// a0 pasa a ser mul
		add s2, s2, a0		// acc (s2) += mul(a0)
		addi s3, s3, 1		// i++
		j for
	efor:
	mv a0, s2				// a0=acc -- colocamos valor en a0 para el retorno
	lw ra, 24(sp)			// EPÍLOGO
	lw s0, 20(sp)
	lw s1, 16(sp)
	lw s2, 12(sp)
	lw s3, 8(sp)
	lw s4, 4(sp)
	lw s5, 0(sp)
	addi sp, sp, 28



guardar:
	sb a0, 0(a1)			//guardamos en a0 para devolverlo -- usar sb!
	ret
*/

mul:
	addi sp, sp, -28		// PRÓLOGO
	sw ra, 24(sp)
	sw s0, 20(sp)
	sw s1, 16(sp)
	sw s2, 12(sp)
	sw s3, 8(sp)
	sw s4, 4(sp)
	sw s5, 0(sp)

	//a=a0, b =a1
	li s4, 0	//res=s4
	li s1, 0	//sign=s1
	mv s2, a0	//s2=a
	mv s3, a1	//s3=b
	if:
		blt zero, s2, while	//condicion
		addi s1, zero, 1
		sub s2, zero, s2 //a=-a
	while:
		bge zero, s2, if2	//condicion -- error
		add s4, s4, s3
		addi s2, s2, -1
		j while
	if2:
		bge	zero, s1, else	//condicion
		sub a0, zero, s4	//colocar -res en a0
		j end_else
	else:

	mv a0, s4			//colocar res en a0

	end_else:
	lw ra, 24(sp)			// EPÍLOGO
	lw s0, 20(sp)
	lw s1, 16(sp)
	lw s2, 12(sp)
	lw s3, 8(sp)
	lw s4, 4(sp)
	lw s5, 0(sp)
	addi sp, sp, 28

	ret

i_sqrt:
	addi sp, sp, -28		// PRÓLOGO
	sw ra, 24(sp)
	sw s0, 20(sp)
	sw s1, 16(sp)
	sw s2, 12(sp)
	sw s3, 8(sp)
	sw s4, 4(sp)
	sw s5, 0(sp)

	li s0, 0		//root = s0
	mv s2, a0		//s2=a


	wh:
		mv a0, s0
		mv a1, s0
		call mul
		mv s3, a0
		mv s4, a1
		bge s3, s2, ewhile 	//condicion
		addi s0, s0, 1		//root++
		j wh
	ewhile:
	mv a0, s0
	lw ra, 24(sp)			// EPÍLOGO
	lw s0, 20(sp)
	lw s1, 16(sp)
	lw s2, 12(sp)
	lw s3, 8(sp)
	lw s4, 4(sp)
	lw s5, 0(sp)
	addi sp, sp, 28
	ret


.end
