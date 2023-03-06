/*---------------------------------------------------------------------
**
**  Fichero:
**    pr2_a.asm  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 2a
**
**  Notas de diseño:
**
** 	# define N 8
** 	# define INT_MAX 2147483647
**	int V [ N ] = { -7 ,3 , -9 ,8 ,15 , -16 ,0 ,3};
**	int min = INT_MAX ;
**	for ( i = 0; i < N ; i ++) {
**		if ( V [ i ] < min )
**			min = V [ i ];
**	}
**
**-------------------------------------------------------------------*/

.global main
.equ N, 8
.equ INT_MAX, 2147483647
.data
V:   .word -7,3,-9,8,15,-16,0,3

.bss
min: .space 4

.text
main:
	li t1, N		//t1=N
    la s0, min
    li t0, INT_MAX
    sw t0, 0(s0)
    li t2, 0		//t2=i

for:
	bge t2, t1, fin_for
	addi t2, t2, 1 			//incrementar indice
	//bge s0, v[i], si_menor
	//si condicion contraria v[i]<min (s0), si_menor
	j for

fin_for:
	j end

end:
	j .
	.end

si_menor:
	//min toma valor de v[i]
	j for
