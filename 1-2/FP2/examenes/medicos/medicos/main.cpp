using namespace std;
#include <iostream>
#include "medicos.h"
#include "citas.h"


void procesarPeticiones(tListaCitas& lc, tListaMedicos& lm);

int main() {
	tListaMedicos lm;
	tListaCitas lc;

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	inicializarListaCitas(lc);
	inicializarListaMedicos(lm);

	if(cargaListaCitas(lc)&&cargaListaMedicos(lm)){
		cout << "LISTA CITAS:" << endl;
		muestraListaCitas(lc);

		cout <<endl<< "LISTA MEDICOS:" << endl;
		muestraListaMedicos(lm);

		procesarPeticiones(lc, lm);

		cout << "LISTA CITAS:" << endl;
		muestraListaCitas(lc);

		cout << endl << "LISTA MEDICOS:" << endl;
		muestraListaMedicos(lm);
		cout << endl;

		liberarCitas(lc);
		liberarMedicos(lm);
	}
	return 0;
}

void procesarPeticiones(tListaCitas& lc, tListaMedicos& lm) {
	/*
	Desarrolla el subprograma procesarPeticiones, que recibe una lista de
	m�dicos y una lista de peticiones de citas y, con las citas que son posibles, calcula
	el coste total de las citas y actualiza las citas disponibles en la lista de m�dicos .
	Ten en cuenta que
	? La lista de peticiones de citas puede incluir m�dicos que no existan en la lista
	de m�dicos, no pudiendo contabilizarse.
	? El procesamiento de las solicitudes de citas debe actualizar convenientemente
	el n�mero de citas disponible de cada m�dico en la lista de m�dicos, teniendo
	en cuenta que si un m�dico se queda sin citas , �ste desaparecer� de la lista.
	Tomando como ejemplo la lista de m�dicos y la lista de citas anteriores, el coste total
	a mostrar ser�a 190� (resultado de 40 + 70 + 80). Se mostrar� esto:
	El importe total es: 190 euros
	*/
	int suma=0;
	for (int i = 0; i < lc.cont; i++) {
		//buscar medico
		int pos = buscaMedico(lm, lc.citas[i].codMed);
		//mirar si tiene citas libres
		if (pos!=-1&&getNumLib(lm, pos)>0) {
			//asignar cita
			
			//sumar coste cita
			suma += lm.lm[pos]->importe;
			//restar 1 hora libre
			if(getNumLib(lm, pos)>0)
			setNumLib(lm, pos, getNumLib(lm, pos)-1);

		}
	}

	cout << "SUMA: " << suma<<endl;

}