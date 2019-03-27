#ifndef GRADO_HPP
#define GRADO_HPP

#include "agenEnlazado.h"
#include <algorithm>
#include <iostream>

template <typename T>
unsigned numHijos(typename Agen<T>::nodo n, Agen<T> &Arbol)
{
    int nHijos;
    typename Agen<T>::nodo hijo;

    nHijos = 0;
    hijo = Arbol.hijoIzqdo(n);
    while (hijo != Agen<T>::NODO_NULO)
    {
        nHijos++;
        hijo = Arbol.hermDrcho(hijo);
    }

    return nHijos;
}

template <typename T>
unsigned grado_rec(typename Agen<T>::nodo n, Agen<T> &Arbol)
{
    typename Agen<T>::nodo hijo;
    unsigned nHijos,maxgr;

    if (Agen<T>::NODO_NULO == n)
        return 0;
    else
    {
        nHijos = numHijos(n, Arbol);
        maxgr=0;
        hijo = Arbol.hijoIzqdo(n);
        while (hijo != Agen<T>::NODO_NULO)
        {
            maxgr = std::max(maxgr, grado_rec(hijo, Arbol));
            hijo = Arbol.hermDrcho(hijo);
        }

        return std::max(nHijos,maxgr);
    }
}

template <typename T>
unsigned grado(Agen<T> &Arbol)
{
    return grado_rec(Arbol.raiz(), Arbol);
}

#endif //GRADO_HPP