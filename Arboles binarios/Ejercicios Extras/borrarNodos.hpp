#ifndef BORRAR_HPP
#define BORRAR_HPP

#include "arbol_binario_enlazada.h"

/*
    Precondiciones: Recibe un nodo del Arbol y el propio Arbol al que pertenece.
    Postcondiciones: Elimina la descendencia del nodo y el propio nodo.
*/

template <typename T>
void borrarNodos(typename Abin<T>::nodo n, Abin<T> &Arbol)
{
    borrarNodos_rec(n, Arbol);
    if (Arbol.raizB() == n)
        Arbol.eliminarRaizB();
    else
    {
        if (Arbol.hijoIzqdoB(Arbol.padreB(n)) == n)
            Arbol.eliminarHijoIzqdoB(Arbol.padreB(n));
        else
            Arbol.eliminarHijoDrchoB(Arbol.padreB(n));
    }
}

template <typename T>
void borrarNodos_rec(typename Abin<T>::nodo n,Abin<T> &Arbol)
{
    if (Abin<T>::NODO_NULO != n)
    {
        borrarNodos_rec(Arbol.hijoIzqdoB(n), Arbol);
        borrarNodos_rec(Arbol.hijoDrchoB(n), Arbol);
        if (Abin<T>::NODO_NULO != Arbol.hijoDrchoB(n))
            Arbol.eliminarHijoDrchoB(n);
        if (Abin<T>::NODO_NULO != Arbol.hijoIzqdoB(n))
            Arbol.eliminarHijoIzqdoB(n);
    }
}

#endif //BORRAR_HPP