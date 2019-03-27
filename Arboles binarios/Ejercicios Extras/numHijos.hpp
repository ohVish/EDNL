#ifndef NUMHIJOS_HPP
#define NUMHIJOS_HPP

#include "arbol_binario_enlazada.h"

template<typename T>
int numHijos(typename Abin<T>::nodo n,Abin<T>& A)
{
    return((Abin<T>::NODO_NULO!=A.hijoIzqdoB(n)) + (Abin<T>::NODO_NULO!=A.hijoDrchoB(n)));
}

#endif //NUMHIJOS_HPP