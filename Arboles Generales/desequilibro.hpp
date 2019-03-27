
#ifndef DESEQUILIBRIO_HPP
#define DESEQUILIBRIO_HPP

#include <cmath>
#include <iostream>
#include "agenEnlazado.h"

template <typename T>
int altura(typename Agen<T>::nodo n, Agen<T> &Arbol)
{
    int altura_actual;
    typename Agen<T>::nodo  hijo;

    if (n == Agen<T>::NODO_NULO)
        return -1;
    else
    {
        altura_actual=-1;
        hijo=Arbol.hijoIzqdo(n);
        while(hijo!=Agen<T>::NODO_NULO)
        {
            altura_actual = fmax(altura_actual,altura(hijo,Arbol));
            hijo = Arbol.hermDrcho(hijo);
        }
        return altura_actual + 1;
    }
}

template<typename T>
int alturaMinima(typename Agen<T>::nodo n,Agen<T> &Arbol)
{
    int alt;
    if(n==Agen<T>::NODO_NULO)
        return -1;
    else
    {

        n=Arbol.hijoIzqdo(n);
        alt=altura(n,Arbol);
        
        while(n!=Agen<T>::NODO_NULO)
        {
            alt=fmin(alturaMinima(n,Arbol),alt);
            n=Arbol.hermDrcho(n);
        }
        return alt+1;
    }
}

template <typename T>
int desequilibro_rec(typename Agen<T>::nodo n,Agen<T> &Arbol)
{
    int altura_minima,des_max,des_nodo;
    if(Agen<T>::NODO_NULO==n)
        return 0;
    else
    {
        des_max = 0;
        altura_minima = alturaMinima(n,Arbol);
        des_nodo = fabs(altura(n,Arbol) - altura_minima);
        n=Arbol.hijoIzqdo(n);
        while(n!=Agen<T>::NODO_NULO)
        {
            des_max=fmax(des_nodo,desequilibro_rec(n,Arbol));
            n=Arbol.hermDrcho(n);
        }
        return des_max;
    }
}

template <typename T>
int desequilibro(Agen<T> &Arbol)
{
    return desequilibro_rec(Arbol.raiz(),Arbol);
}

#endif //DESEQUILIBRIO_HPP