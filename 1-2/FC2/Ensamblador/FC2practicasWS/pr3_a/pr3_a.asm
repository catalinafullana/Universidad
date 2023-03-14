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
.extern _stack
.global main
.equ N, 4


.data
A: .word 3, 5, 1, 9
B: .word 1, 6, 2, 3
.bss
res: .space 4
main:
	li a2, N	//n=4

	la a0, A	//a0=A
	la a1, B

	call dot_prod	//llamar a la funcion
	la t0, res		//dotprod devuelve res
	sw a0, 0(t0)	//guardado de res
	//guarda normA en var

	//call dot_prod2
	//normB eb var
	if:
		//bge normB, normA, else

		//mv t2, 0xa //res=0xa

	else:
		//res=0xb



end:
	j .

dot_prod:
	addi sp , sp , -24 // ///
	sw ra , 20( sp) //
	sw s0 , 16( sp) //
	sw s1 , 12( sp) // PRÓ LOGO
	sw s2 , 8( sp) //
	sw s3 , 4( sp) //
	sw s4 , 0( sp) // ///
	li s0 , 0 // s0 guarda acc
	li s1 , 0 // s1 guarda i
	mv s2 , a0 // s2 guarda A
	mv s3 , a1 // s3 guarda B
	mv s4 , a2 // s4 guarda n
	for:
		bge s1, s4, fin_for
		/*
		la t1, V
		slli t3, s2, 2
		add t2, t1, t3
		lw s3, 0(t2)
		//acc += mul(V[i], W[i]); donde v(i) es s3, acc es s4 y w[i] es x

		sw s3, 0(t2)*/
		nextiter:
		addi s1 , s1 , 1 // actualizo iterador
		addi s2 , s2 , 4 //A++
		addi s3 , s3 , 4 //B++
		addi s2, s2, 1
		j for
	fin_for:
		mv a0 , s0 // colocar acc para devolver
		lw ra , 20( sp) //
		lw s0 , 16( sp) //
		lw s1 , 12( sp) //
		lw s2 , 8( sp) // EPÍLOGO
		lw s3 , 4( sp) //
		lw s4 , 0( sp) //
		addi sp , sp , 24 // ///
		ret // devuelvo control

mul:
	//a1 =a
	//a2=b
	li a0, 0;			//int res = 0;
	while:
		beq zero, a2, end_while
		add a0, a0, a1
		addi a2, a2, -1
		j while

	end_while:
	ret

.end
