/*
N�mero de grupo:

Nombre y apellidos de los autores de la pr�ctica (si alguno de los miembros del grupo
no hay realizado la pr�ctica, no debe incluirse su nombre): 
Alai Miranda Blanco
Catalina Fullana Mora
*/

using namespace std;
#include <iostream>

#ifndef _MEMORIA_H_
#define _MEMORIA_H_

/// Excepci�n de direccion invalida
class EDireccionInvalida {
};

/// Excepci�n de celda sin inicializar
class ECeldaSinInicializar {
};

template<class T>
class Memoria {
private:
	unsigned int _capacidad;
	
	T** _celdas;
public:
	/**
	 * crea una memoria con 'capacidad' celdas.
	 */
	Memoria(unsigned int capacidad) {
		_capacidad = capacidad;
		_celdas = new T * [_capacidad];

		for (unsigned int i = 0; i < _capacidad; ++i) {
			_celdas[i] = nullptr;
		}
	}
	
	//constructor de copia
	Memoria(const Memoria& m) {
		this->_capacidad = m._capacidad;
		this->_celdas = new T * [_capacidad];

		for (unsigned int i = 0; i < m._capacidad; i++) {
			if (m._celdas[i] != nullptr) {
				this->_celdas[i] = new T(*m._celdas[i]);
			}
			else {
				this->_celdas[i] = nullptr;
			}
		}	

	}
	/*
	~Memoria() {
		for (unsigned int i = 0; i < _capacidad; i++) {
			//delete _celdas[i];
			//_celdas[i] = nullptr;
		}
		delete[] _celdas;
	}
	*/

	/**
	 * Devuelve el valor almacenado en la celda 'd'.
	 * Si 'd' est� fuera de rango, levanta EDireccionInvalida.
	 * Si la celda 'd' no est� inicializada, levanta ECeldaSinInicializar.
	 */

	//try - catch
	const T& valor(unsigned int d) const {
		if (d < 0 || d >= _capacidad) throw EDireccionInvalida();
		else if (_celdas[d] == nullptr) throw ECeldaSinInicializar();
		else return *_celdas[d];

	}

	/**
	 * Almacena 'v' en la celda 'd'.
	 * Si 'd' est� fuera de rango, levanta EDireccionInvalida.
	 */
	void almacena(unsigned  d, const T& v) {
		if (d < 0 || d >= _capacidad)
			throw EDireccionInvalida();
		else{
			if (_celdas[d]==nullptr) {
				_celdas[d] = new T(v);
			}
			else {
				*_celdas[d] = v;
			}
		}
	}

	/**
	 * Devuelve 'true' si la celda 'd' est� inicializada.
	 * En otro caso devuelve 'false'.
	 * Si 'd' est� fuera de rango, levanta EDireccionInvalida.
	 */
	bool inicializada(unsigned int d) const {
		// A implementar 
		if (d < 0 || d >= _capacidad ) throw EDireccionInvalida();
		else return _celdas[d] != nullptr;
	}

	
	
	//operador de asignacion
	Memoria& operator=(const Memoria& m1) {
		if (&m1!=this) {
			this->_capacidad = m1._capacidad;
			_celdas = new T * [_capacidad];

			for (int i = 0; i < m1._capacidad; i++)
				if (m1._celdas[i] != nullptr)
					this->_celdas[i] = m1._celdas[i];
				else this->_celdas = nullptr;
		}
		return *this;
	}


	/* Implementar el resto de operaciones y m�todos necesarios
	   para que la implementaci�n funcione */

//private:
	/* Declarar los campos necesarios para representar los
	   valores de este TAD, as� como las operaciones auxiliares
	   que se consideren oportunas */

};


#endif


