#ifndef AGEN_LIS_H_
#define AGEN_LIS_H_

#include <cassert>
#include <cstddef>			// Define size_t
#include "listaEnlazada.h"

/*/
 * Definición:
 *	
 * Un árbol general se define como un árbol cuyos nodos son de cualquier grado, es
 * decir, pueden tener un número cualquiera de hijos. Los hijos de un nodo están
 * ordenados de izquierda a derecha, de tal forma que el primer hijo de un nodo se
 * llama hijo izquierdo, el segundo es el hermano derecho de éste, el tercero es el
 * hermano derecho del segundo y así sucesivamente.
/*/

template <typename T> class Agen{
	
	public:

		/* Índide de la matriz. Entre 0 y maxNodos-1 */
		typedef int nodo;

		static const nodo NODO_NULO;

		// Post: Construye un árbol vacío.
		explicit Agen(size_t maxNodos);

		// Pre: El árbol está vacío.
		// Post: Inserta el nodo raíz de A cuyo contenido será e.
		void insertarRaiz(const T& e);

		// Pre: n es un nodo del árbol.
		// Post: Inserta el elemento e como hijo iquierdo del nodo n. Si ya existe
		//		 hijo izquierdo, éste se convierte en el hermano derecho del nuevo nodo
		void insertarHijoIzqdo(nodo n, const T& e);

		// Pre: n es un nodo del árbol y no es el nodo raíz.
		// Post: Inserta el elemento e como hermano derecho del nodo n del árbol.
		//		 Si ya existe hermano derecho, éste se convierte en el hermano derecho del nuevo nodo.
		void insertarHermDrcho(nodo n, const T& e);

		// Pre: n es un nodo del árbol. Tiene hijo izquierdo que es hoja.
		// Post: Destruye el hijo izquierdo del nodo n. El segundo hijo, si existe, se convierte en el
		//		 nuevo hijo izquierdo de n.
		void eliminarHijoIzqdo(nodo n);

		// Pre: n es un nodo del árbol. Tiene hermano derecho que es hoja.
		// Post: destruye el hermano derecho del nodo n. El siguiente hermano se convierte en el nuevo hermano derecho de n.
		void eliminarHermDrcho(nodo n);

		// Pre: El árbol tiene un único nodo.
		// Post: Destruye la raíz.
		void eliminarRaiz();

		// Post: Devuelve true si el árbol está vacío y false en caso contrario.
		bool arbolVacio() const;

		// Pre: n es un nodo del árbol.
		// Post: Devuelve el elemento del nodo n.
		const T& elemento(nodo n) const;
		T& elemento(nodo n);

		// Post: Devuelve el nodo raíz del árbol. Si el árbol está vacío, devuelve NODO_NULO.
		nodo raiz() const;

		// Pre: n es un nodo del árbol.
		// Post: Devuelve el padre del nodo n. Si n es el nodo raíz, devuelve NODO_NULO.
		nodo padre(nodo n) const;

		// Pre: n es un nodo del árbol.
		// Post: Devuelve el hijo izquierdo de n. Si no existe devuelve NODO_NULO.
		nodo hijoIzqdo(nodo n) const;

		// Pre: n es un nodo del árbol.
		// Post: Devuelve el hermano derecho de n. Si no existe devuelve NODO_NULO.
		nodo hermDrcho(nodo n) const;

		Agen(const Agen<T>& A);
		Agen<T>& operator =(const Agen<T>& A);

		~Agen();


	private:

		struct celda
		{
			T elto;
			nodo padre;
			Lista<nodo> hijos;
		};

		celda* nodos;	// Vector de nodos.
		int maxNodos;	// Tamaño del vector.
		int numNodos;	// Número de nodos del árbol.
};

/*_____________________________________________________________________________________________*/

/* Definición de NODO_NULO */
template <typename T>
const typename Agen<T>::nodo Agen<T>::NODO_NULO(-1);

template <typename T>
inline Agen<T>::Agen(size_t maxNodos):
	nodos(new celda[maxNodos]),
	maxNodos(maxNodos),
	numNodos(0)
{
	/* Marcar todas las celdas como libres */
	for(nodo i = 0; i < maxNodos ; ++i)
		nodos[i].padre = NODO_NULO;
}

template <typename T>
void Agen<T>::insertarRaiz(const T& e)
{
	assert(numNodos == 0); // Árbol vacío.

	numNodos = 1;
	nodos[0].elto = e;

	/* La lista de hijos está vacía */
}

template <typename T>
void Agen<T>::insertarHijoIzqdo(Agen<T>::nodo n, const T& e)
{
	nodo izquierdo;

	assert(numNodos > 0);			 			// Árbol no vacío.
	assert(n >= 0 && n < maxNodos); 			// n es una celda del vector.
	assert(n == 0 || nodos.padre != NODO_NULO); // La celda está ocupada.
	assert(numNodos < maxNodos);				// Árbol no lleno.

	/* Añadir el nuevo nodo en la primera celda libre */
	for(izquierdo = 1 ; nodos[izquierdo].padre != NODO_NULO ; ++izquierdo);

	nodos[izquierdo].elto  = e;
	nodos[izquierdo].padre = n;

	/* Insertar el nuevo nodo al inicio de la lista de hijos de n */
	Lista<nodo>& Lh = nodos[n].hijos;

	Lh.insertar(izquierdo, Lh.primera());
	++numNodos;
}

template <typename T>
void Agen<T>::insertarHermDrcho(Agen<T>::nodo n, const T& e)
{
	nodo hermano;

	assert(n >= 0 && n < maxNodos); 		// n es una celda del vector.
	assert(nodos[n].padre != NODO_NULO);	// n existe y no es la raíz.
	assert(numNodos < maxNodos);			// Árbol no lleno.

	/* Añadir el nuevo nodo en la primera celda libre */
	for(hermano = 1 ; nodos[hermano].padre != NODO_NULO ; ++hermano);

	nodos[hermano].elto  = e;
	nodos[hermano].padre = nodos[n].padre;

	/* Insertar el nuevo nodo en la lista de hijos del padre en la posicion siguiente a la de n */
	Lista<nodo>& Lhp = nodos[nodos[n].padre].hijos;

	Lhp.insertar(hermano, Lhp.siguiente(Lhp.buscar(n)));
	++numNodos;
}

template <typename T>
void Agen<T>::eliminarHijoIzqdo(Agen<T>::nodo n)
{
	nodo izquierdo;

	assert(numNodos > 0);			 			// Árbol no vacío.
	assert(n >= 0 && n < maxNodos); 			// n es una celda del vector.
	assert(n == 0 || nodos.padre != NODO_NULO); // La celda está ocupada.

	/* Lista de hijos de n */
	Lista<nodo>& Lh = nodos[n].hijos;

	assert(Lh.primera() != Lh.fin());			// Lista no vacía. n tiene hijos.

	izquierdo = Lh.elemento(Lh.primera());

	// Lista vacía. Hijo izquierdo de n es hoja.
	assert(nodos[izquierdo].hijos.primera() == nodos[izquierdo].hijos.fin());

	/* Marcar celda libre */
	nodos[izquierdo].padre = NODO_NULO;

	/* Eliminar el primer nodo de la lista de hijos de n */
	Lh.eliminar(Lh.primera());

	--numNodos;
}

template <typename T>
void Agen<T>::eliminarHermDrcho(Agen<T>::nodo n)
{
	nodo hermano;
	Lista<nodo>::posicion p;

	assert(n >= 0 && n < maxNodos); 			// n es una celda del vector.
	assert(n == 0 || nodos.padre != NODO_NULO); // La celda está ocupada.

	/* Buscar hermano derecho de n en la lista de hijos del padre */
	Lista<nodo>& Lhp = nodos[nodos[n].padre].hijos;

	p = Lhp.siguiente(Lhp.buscar(n));

	assert(p != Lhp.fin()); 					// n tiene hermano derecho.

	hermano = Lhp.elemento(p);

	// Lista vacía. Hermano derecho de n es hoja.
	assert(nodos[hermano].hijos.primera() == nodos[hermano].hijos.fin());

	/* Marcar celda libre */
	nodos[hermano].padre = NODO_NULO;

	/* Eliminar hermano de la lista de hijos del padre */
	Lhp.eliminar(p);

	--numNodos;
}

template <typename T>
inline void Agen<T>::eliminarRaiz()
{
	assert(numNodos == 1);

	numNodos = 0;
}

template <typename T>
inline bool Agen<T>::arbolVacio() const
{
	return numNodos == 0;
}

template <typename T>
inline const T& Agen<T>::elemento(Agen<T>::nodo n) const
{
	assert(numNodos > 0);							// Árbol no vacío.
	assert(n >= 0 && n < maxNodos);					// n es una celda válida
	assert(n == 0 || nodos[n].padre != NODO_NULO);	// La celda está ocupada.

	return nodos[n].elto;
}

template <typename T>
inline T& Agen<T>::elemento(Agen<T>::nodo n)
{
	assert(numNodos > 0);							// Árbol no vacío.
	assert(n >= 0 && n < maxNodos);					// n es una celda válida
	assert(n == 0 || nodos[n].padre != NODO_NULO);	// La celda está ocupada.

	return nodos[n].elto;
}

template <typename T>
inline typename Agen<T>::nodo Agen<T>::raiz() const
{
	return numNodos > 0 ? 0 : NODO_NULO;
}

template <typename T>
inline typename Agen<T>::nodo Agen<T>::padre(Agen<T>::nodo n) const
{
	assert(numNodos > 0);							// Árbol no vacío.
	assert(n >= 0 && n < maxNodos);					// n es una celda válida
	assert(n == 0 || nodos[n].padre != NODO_NULO);	// La celda está ocupada.

	return nodos[n].padre;
}

template <typename T>
inline typename Agen<T>::nodo Agen<T>::hijoIzqdo(Agen<T>::nodo n) const
{
	assert(numNodos > 0);							// Árbol no vacío.
	assert(n >= 0 && n < maxNodos);					// n es una celda válida
	assert(n == 0 || nodos[n].padre != NODO_NULO);	// La celda está ocupada.

	Lista<nodo>& Lh = nodos[n].hijos;

	if(Lh.primera() != Lh.fin())
		return Lh.elemento(Lh.primera());
	else
		return NODO_NULO;
}

template <typename T>
inline typename Agen<T>::nodo Agen<T>::hermDrcho(Agen<T>::nodo n) const
{
	Lista<nodo>::posicion p;

	assert(numNodos > 0);							// Árbol no vacío.
	assert(n >= 0 && n < maxNodos);					// n es una celda válida
	assert(n == 0 || nodos[n].padre != NODO_NULO);	// La celda está ocupada.

	/* n es la raíz */
	if(n == 0)
		return NODO_NULO;
	else
	{
		Lista<nodo>& Lhp = nodos[nodos[n].padre].hijos;

		p = Lhp.siguiente(Lhp.buscar(n));

		/* n tiene hermano derecho */
		if(p != Lhp.fin())
			return Lhp.elemento(p);
		else
			return NODO_NULO;
	}
}

/*_________________________________________________________________________________________________________________*/

template <typename T>
Agen<T>::Agen(const Agen<T>& A):
	nodos(new celda[A.maxNodos]),
	maxNodos(A.maxNodos),
	numNodos(A.numNodos)
{
	/* Copiar el vector */
	for(nodo n = 0 ; n < maxNodos ; ++n)
		nodos[n] = A.nodos[n];
}

template <typename T>
Agen<T>& Agen<T>::operator =(const Agen<T>& A)
{
	if(this != &A)
	{
		if(maxNodos != A.maxNodos)
		{
			delete[] nodos;
			maxNodos = A.maxNodos;
			nodos = new celda[maxNodos];
		}

		numNodos = A.numNodos;

		/* Copiar el vector */
		for(nodo n = 0 ; n < maxNodos ; ++n)
			nodos[n] = A.nodos[n];
	}

	return *this;
}

template <typename T>
inline Agen<T>::~Agen()
{
	/* También destruye las listas de hijos */
	delete[] nodos;
}

/*__________________________________________________________________________________________________*/

#endif // AGEN_LIS_H_