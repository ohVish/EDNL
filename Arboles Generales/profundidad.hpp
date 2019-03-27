#ifndef PROFUNDIDAD_HPP
#define PROFUNDIDAD_HPP

#include "agenEnlazado.h"

template <typename T>
int profundidad(typename Agen<T>::nodo n, Agen<T> &Arbol)
{
    int prof;

    prof = 0;
    if (n != Agen<T>::NODO_NULO)
    {
        while (n != Arbol.raiz())
        {
            prof++;
            n = Arbol.padre(n);
        }
    }
    return prof;
}

#endif //PROFUNDIDAD_HPP