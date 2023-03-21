/*---------------------------------------------------------------------
**
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


//rellenar con directivas .extern y .global
//con las funciones apropiadas
.extern i_sqrt
.extern mul
.global eucl_dist
.global guardar

//int eucl_dist(int * w, int size);
eucl_dist:
	//recibo dirección de W en a0, y tamaño N en a1

	li a2, 0	//i=0
	li a3, 0	//a3=mul
	//poner direccion de W (a0) a otra a
	//poner  en a0
	mv a4, a0		// a4 es dir W
	mv a5, a1		// a5 es N
	li t3, 0

	for:
		bge a2, a5, efor
		mv a0, t3
		slli t2, t2, 2	//
		add t2, t2, a4	//
		lw 	a0, 0(t2)	//a0=w[i]
		mv t3, a0
		mv a1, a0		//a1 tiene que coger el valor de a0

		call mul		//a0 =mul

		add a3, a3, a0  //acc+=mul(w(i), w(i))
		addi a2, a2, 1	// i++
		j for
	efor:
		//colocar acc en a0
		mv a0, a3
		call i_sqrt//llamar a i_sqrt(acc) con un call
		ret

//int guardar(char valor, char * ubicacion);
guardar:
    //recibo el valor en a0, y la dirección destino en a1
    mv a1, a0	//a1=a0
    //asegurarse que sólo se guarda UN BYTE!! --sb

.end

