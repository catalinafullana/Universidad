/**
  @file Cola.h

  Implementaci�n del TAD Pila utilizando un
  array est�tico circular.

  Estructura de Datos y Algoritmos
  Facultad de Inform�tica
  Universidad Complutense de Madrid

 (c) Mercedes G�mez Albarr�n, 2016
*/

#ifndef ARRAY_QUEUE_
#define ARRAY_QUEUE_


/// Excepciones generadas por algunos m�todos
class EColaVacia {};
class EColaLlena {};


/**
Implementaci�n del TAD Cola utilizando el array circular.

Las operaciones son:

- ColaVacia: -> Cola. Generadora implementada en el
constructor sin par�metros.
- pon: Cola, Elem -> Cola. Generadora
- quita: Cola - -> Cola. Modificadora parcial.
- primero: Cola - -> Elem. Observadora parcial.
- esVacia: Cola -> Bool. Observadora.

@author Mercedes G�mez Albarr�n
*/

template<class ItemType>
class Cola {
public:
	static const int DEFAULT_CAPACITY = 5;

	/** Constructor; operacion ColaVacia */
	Cola() : _front(0), _back(DEFAULT_CAPACITY - 1), _count(0) {}

	/**
	Indica si la cola est� vac�a.
	@return true si la cola no tiene ning�n elemento.
	*/
	bool esVacia() const {
		return _count == 0;
	}

	/**
	A�ade un elemento en la parte trasera de la cola.
	Operaci�n generadora parcial.

	error: falla si la cola est� llena
	@param newEntry Elemento a a�adir.
	*/
	void pon(const ItemType& newEntry) {
		if (_count == DEFAULT_CAPACITY)
			throw EColaLlena();
		_back = (_back + 1) % DEFAULT_CAPACITY;
		_items[_back] = newEntry;
		_count++;
	}


	/**
	Elimina el primer elemento de la cola.
	Operaci�n modificadora parcial.

	error: falla si la cola est� vac�a.
	*/
	void quita() {
		if (esVacia())
			throw EColaVacia();
		_front = (_front + 1) % DEFAULT_CAPACITY;
		_count--;
	}

	/**
	Devuelve el primer elemento de la cola.
	Operaci�n observadora parcial

	error: falla si la cola est� vac�a
	@return El primer elemento de la cola.
	*/
	const ItemType& primero() {
		if (esVacia())
			throw EColaVacia();
		return _items[_front];
	}


private:
	ItemType _items[DEFAULT_CAPACITY]; // array de elementos
	int      _front;                   // �ndice del primer elemento de la cola
	int      _back;                    // �ndice del �ltimo elemento de la cola
	int      _count;                   // n� real de elementos de la cola

};
#endif