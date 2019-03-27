#ifndef PODA_HPP
#define PODA_HPP

#include "agenEnlazado.h"
#include <iostream>

void borrarDescendencia(Agen<int>::nodo n, Agen<int> &Arbol)
{
    Agen<int>::nodo hijo;

    if (n != Agen<int>::NODO_NULO)
    {
        hijo = Arbol.hijoIzqdo(n);
        if(hijo!=Agen<int>::NODO_NULO)
        {
            while(Arbol.hermDrcho(hijo)!=Agen<int>::NODO_NULO)
            {
                borrarDescendencia(Arbol.hermDrcho(hijo),Arbol);
                Arbol.eliminarHermDrcho(hijo);
            }
            borrarDescendencia(hijo,Arbol);
            Arbol.eliminarHijoIzqdo(n);
        }
    }
}

void podarNodo(Agen<int>::nodo n, Agen<int> &Arbol)
{
    Agen<int>::nodo padre,aux;
    borrarDescendencia(n,Arbol);
    if(n==Arbol.raiz())
        Arbol.eliminarRaiz();
    else{
        padre = Arbol.padre(n);
        aux = Arbol.hijoIzqdo(padre);
        if(aux==n)
            Arbol.eliminarHijoIzqdo(padre);
        else
        {
            while(Arbol.hermDrcho(aux)!=n)
            {
                aux = Arbol.hermDrcho(aux);
            }
            Arbol.eliminarHermDrcho(aux);
        }
    }
}

void poda_rec(Agen<int>::nodo n, Agen<int> &Arbol, int x)
{
    Agen<int>::nodo hijo;

    if (n != Agen<int>::NODO_NULO)
    {
        if (Arbol.elemento(n) == x)
            podarNodo(n, Arbol);
        else
        {
            hijo = Arbol.hijoIzqdo(n);
            while (hijo != Agen<int>::NODO_NULO)
            {
                poda_rec(hijo, Arbol, x);
                hijo = Arbol.hermDrcho(hijo);
            }
        }
    }
}
void poda(Agen<int> &Arbol, int x)
{
    return poda_rec(Arbol.raiz(), Arbol, x);
}
#endif //PODA_HPP