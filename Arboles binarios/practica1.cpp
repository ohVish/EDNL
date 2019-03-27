#include <iostream>
#include "arbol_binario_enlazada.h"
#include "abin_E-S.h"
#include <algorithm>
#include <cmath>

using namespace std;

/*
    Precondición: Recibe un árbol binario.
    Postcondición: Calcula el número de nodos del árbol binario.
*/
template <typename T>
unsigned numeroNodos(Abin<T> &Arbol)
{
    return (Arbol.raizB(), Arbol);
}

template <typename T>
unsigned numeroNodos_rec(typename Abin<T>::nodo n, Abin<T> &Arbol)
{
    if (n == Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        1 + numeroNodos_rec(Arbol.hijoDrchoB(n), Arbol) + numeroNodos_rec(Arbol.hijoIzqdoB(n), Arbol);
    }
}

/*
    Precondición: Recibe un árbol binario.
    Postcondición: Si el árbol binario esta vacío devuelve -1. En caso contrario devuelve la altura del árbol binario.
*/
template <typename T>
int altura(Abin<T> &Arbol)
{
    return altura_rec(Arbol.raizB(), Arbol);
}

template <typename T>
int altura_rec(typename Abin<T>::nodo n, Abin<T> &Arbol)
{
    if (n == Abin<T>::NODO_NULO)
    {
        return -1; //La altura de una hoja es cero --> Altura nodo_nulo = -1
    }
    else
    {
        return 1 + fmax(altura_rec(Arbol.hijoIzqdoB(n), Arbol), altura_rec(Arbol.hijoDrchoB(n), Arbol));
    }
}
/*
    Precondición: Recibe un árbol binario y un nodo de ese árbol.
    Postcondición: Calcula la profundidad del nodo.
*/
template <typename T>
int profundidad(typename Abin<T>::nodo n, Abin<T> &Arbol)
{
    int prof;

    prof = 0;
    while (n != Arbol.raizB())
    {
        n = Arbol.padreB(n);
        prof++;
    }

    return prof;
}

/*
    Precondición: Recibe un árbol binario y un nodo de ese árbol.
    Postcondición: Calcula la profundidad del nodo.
*/

template <typename T>
int profundidad_rec(typename Abin<T>::nodo n, Abin<T> &Arbol)
{
    if (n == Arbol.raizB())
    {
        return 0;
    }
    else
    {
        1 + profundidad_rec(Arbol.padreB(n), Arbol);
    }
}

template <typename T>
int difAltura(typename Abin<T>::nodo n, Abin<T> &Arbol)
{
    return fabs(Arbol.altura(Arbol.hijoDrchoB(n)) - Arbol.altura(Arbol.hijoIzqdoB(n)));
}
template <typename T>
int desequilibrio(typename Abin<T>::nodo n, Abin<T> &Arbol)
{
    if (n == Abin<T>::NODO_NULO)
    {
        return 0;
    }
    else
    {
        return fmax(difAltura(n, Arbol), fmax(desequilibrio(Arbol.hijoDrchoB(n), Arbol), desequilibrio(Arbol.hijoIzqdoB(n), Arbol)));
    }
}

/*
    Precondición: Recibe un árbol binario.
    Postcondición: Calcula el desequilibrio del árbol.
*/
template <typename T>
int desequilibrio(Abin<T> &Arbol)
{
    return desequilibrio(Arbol.raizB(), Arbol);
}

/*

    Precondiciones: Recibe un árbol binario.
    Postcondiciones:  Devuelve true si el árbol binario es pseudocompleto. False si no lo es.

*/

template <typename T>
bool pseudocompleto(Abin<T> &Arbol)
{
    return pseudocompleto_rec(Arbol.raizB(), Arbol);
}

template <typename T>
bool pseudocompleto_rec(typename Abin<T>::nodo n, Abin<T> &Arbol)
{
    if (Arbol.altura(n) < 2)
    {
        if (Arbol.altura(n) < 1)
            return true;
        else
            return (Arbol.hijoDrchoB(n) != Abin<T>::NODO_NULO && Arbol.hijoIzqdoB(n) != Abin<T>::NODO_NULO);
    }
    else
    {
        if( Arbol.altura(Arbol.hijoDrchoB(n))==Arbol.altura(Arbol.hijoIzqdoB(n)))
        {
            return (pseudocompleto_rec(Arbol.hijoIzqdoB(n), Arbol) && pseudocompleto_rec(Arbol.hijoDrchoB(n), Arbol));
        }
        else
        {
            if(Arbol.altura(Arbol.hijoDrchoB(n))>Arbol.altura(Arbol.hijoIzqdoB(n)))
                return pseudocompleto_rec(Arbol.hijoDrchoB(n), Arbol);
            else
                return pseudocompleto_rec(Arbol.hijoIzqdoB(n), Arbol);
        }
    }
}

int main()
{
    Abin<int> arb;
    rellenarAbin(arb, -1);
    imprimirAbin(arb);
    cout << "El arbol tiene un pseudocompleto de: " << pseudocompleto(arb) << endl;
    return 0;
}