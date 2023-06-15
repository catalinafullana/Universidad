/*---------------------------------------------------------------------
**
**  Fichero:
**    pr1_lab.asm  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 1_lab
**
**  Notas de diseño:
**	propuesta para el laboratorio:
**	A=10
**	B=5
**	multiplicación =0
**	for (i=0;i<A;i++){
**		multiplicación =multiplicacion +B
**	}
**-------------------------------------------------------------------*/

.global main

.data
	a: .word 5
	b: .word 3
.bss
	multiplicacion: .space 4

.text
main:
	la t0, a	//	t0 = A
	lw t4, 0(t0)
	la t1, b	//	t1 = B
	lw t5, 0(t1)
	li t2, 0	//	t2 = i
	li t3, 0 	//	t3 = multiplicacion
	la t6, multiplicacion

for:
	bge t2, t4, end_for		//si condicion contraria saltar al end for
	add t3, t3, t5			//mult+=b
	addi t2, t2, 1			// incrementar indice
	j for

end_for:
	sw t3, 0(t6)
	j end
end:
	j .
	.end
