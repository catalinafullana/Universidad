/*---------------------------------------------------------------------
**
**  Fichero:
**    pr2_b.asm  19/10/2022
**
**    (c) Daniel Báscones García
**    Fundamentos de Computadores II
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Fichero de código para la práctica 2b
**
**  Notas de diseño:
**
**	int mul(int a, int b) {
**	    int res = 0;
**	    while (b > 0) {
**	        res += a;
**	        b--;
**	    }
**	    return res;
**	}
**
**	int dotprod(int[] V, int[] W, int n) {
**	    int acc = 0;
**	    for (int i = 0; i < n; i++) {
**	        acc += mul(V[i], W[i]);
**	    }
**	    return acc;
**	}
**
**	#define N 4
**	int[] A = {3, 5, 1, 9}
**	int[] B = {1, 6, 2, 3}
**
**	int res;
**
**	void main() {
**	    int normA = dotprod(A, A, N);
**	    int normB = dotprod(B, B, N);
**	    if (normA > normB)
**	        res = 0xa;
**	    else
**	        res = 0xb;
**	}
**
**-------------------------------------------------------------------*/
.global main
.data
A: .word 3, 5, 1, 9
B: .word 1, 6, 2, 3
.bss
res: .space
main:
	li s1, 4	//n=4

	li a0, 1	//a0=normA

	call dot_prod
	//guarda normA en var
	call dot_prod2
	//normB eb var
	if:
		bge normB, normA, else
		//res=0xa

	else:
		//res=0xb



end:
	j .

dot_prod:
	lw t0, 0(a0)
	li s4, 0 //int acc=0
	li s2, 0		//s2=i
	for:
		beq s2, s1, fin_for
		la t1, V
		slli t3, s2, 2
		add t2, t1, t3
		lw s3, 0(t2)
		//acc += mul(V[i], W[i]); donde v(i) es s3, acc es s4 y w[i] es x

		sw s3, 0(t2)
		addi s2, s2, 1
		j for
	fin_for:
	sw t0, 0(a0)
	ret
mul:

	li s3, 0;					//int res = 0;
	while:
		beq 0, b, end_while
		add s3,s3, a
		addi b, b, -1
		j while
	end_while:
	ret

.end