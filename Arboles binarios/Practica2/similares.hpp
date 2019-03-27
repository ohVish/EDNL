#ifndef SIMILARES_HPP
#define SIMILARES_HPP
#include "arbol_binario_enlazada.h"

template <typename T>
int cuentaNodosVerdes(typename Abin<T>::nodo n, Abin<T> &A)
{
    if (Abin<T>::NODO_NULO == n)
        return 0;
    else
    {
        if (cuentaNietos(n, A) == 3)
            return 1 + cuentaNodosVerdes(A.hijoIzqdoB(n), A) + cuentaNodosVerdes(A.hijoDrchoB(n), A);
        else
            return cuentaNodosVerdes(A.hijoIzqdoB(n), A) + cuentaNodosVerdes(A.hijoDrchoB(n), A);
    }
}
template <typename T>
int cuentaNietos(typename Abin<T>::nodo n, Abin<T> &A)
{
    int cont;
    typename Abin<T>::nodo izqdo, drcho;

    izqdo = A.hijoIzqdoB(n);
    drcho = A.hijoDrchoB(n);
    cont = 0;
    if (izqdo != Abin<T>::NODO_NULO)
    {
        if (A.hijoIzqdoB(izqdo) != Abin<T>::NODO_NULO)
            cont++;
        if (A.hijoDrchoB(izqdo) != Abin<T>::NODO_NULO)
            cont++;
    }
    if (drcho != Abin<T>::NODO_NULO)
    {
        if (A.hijoIzqdoB(drcho) != Abin<T>::NODO_NULO)
            cont++;
        if (A.hijoDrchoB(drcho) != Abin<T>::NODO_NULO)
            cont++;
    }
    return cont;
}
/*
    Precondiciones: Recibe dos árboles binarios.
    Postcondiciones: Si los árboles son similares devuelve True. En caso contrario devuelve false.
*/
template <typename T>
bool similares(Abin<T> &Arbol1, Abin<T> &Arbol2)
{
    return similares_rec(Arbol1.raizB(), Arbol1, Arbol2.raizB(), Arbol2);
}

template <typename T>
bool similares_rec(typename Abin<T>::nodo n1, Abin<T> &Arbol1, typename Abin<T>::nodo n2, Abin<T> &Arbol2)
{
    if (Abin<T>::NODO_NULO == n1 && Abin<T>::NODO_NULO == n2)
        return true;
    else
    {
        if (Abin<T>::NODO_NULO == n1 || Abin<T>::NODO_NULO == n2)
            return false;
        else
        {
            return (similares_rec(Arbol1.hijoIzqdoB(n1), Arbol1, Arbol2.hijoIzqdoB(n2), Arbol2) && similares_rec(Arbol1.hijoDrchoB(n1), Arbol1, Arbol2.hijoDrchoB(n2), Arbol2));
        }
    }
}

#endif //SIMILARES_HPP