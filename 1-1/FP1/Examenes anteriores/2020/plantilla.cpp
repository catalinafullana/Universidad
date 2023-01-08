#include <iostream>
#include<string>
using namespace std;


// define aqu� las CONSTANTES Y TIPOS PEDIDOS 




//
// prototipos de los subprogramas pedidos en el enunciado (salvo buscar)
//
bool cargarLiga(tLiga & liga);
bool cargarJornada(tJornada & jornada, int numEquipos);
void mostrarLiga(const tLiga & liga);
void actualizarLiga(const tJornada & jornada, tLiga & liga);
void primeroYultimo(const tLiga& liga, string& primero, string& ultimo);
/* incorpora aqu� el prototipo de tu subprograma buscar*/



int main(){
	tLiga liga;
	tJornada jornada;
	string primero, ultimo;
	
	if ( /* sustituye este comentario por el c�digo necesario */ )
		cout << "carga fallida" << endl;
	else {
		cout << "CLASIFICACION...\n";
		mostrarLiga(liga);
		actualizarLiga(jornada, liga);
		cout << "\nCLASIFICACION ACTUALIZADA...\n";
		mostrarLiga(liga);
		primeroYultimo(liga, primero, ultimo);
		cout << endl;
		cout << "Primer clasificado: " << primero << endl;
		cout << "Ultimo clasificado: " << ultimo << endl;
	}
	
	return 0;
}



bool cargarLiga(tLiga & liga){
	// incluye aqu� tu c�digo

}

bool cargarJornada(tJornada & jornada, int numEquipos){
	// incluye aqu� tu c�digo

}


void mostrarLiga(const tLiga & liga){ 
	// incluye aqu� tu c�digo

}


void actualizarLiga(const tJornada & jornada, tLiga & liga) { 
	// incluye aqu� tu c�digo

}


void primeroYultimo(const tLiga & liga, string & primero, string & ultimo){ 
	// incluye aqu� tu c�digo

}

