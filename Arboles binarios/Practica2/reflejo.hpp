#ifndef REFLEJO_HPP
#define REFLEJO_HPP

#include "arbol_binario_enlazada.h"

template<typename T>
void reflejo(Abin<T>& A,Abin<T>& B)
{  
    if(!A.arbolVacioB())
    {
        B.insertarRaizB(A.raizB());
        reflejo_rec(A.raizB(),A,B.raizB(),B);
    }
    
}

template<typename T>
void reflejo_rec(typename Abin<T>::nodo na,Abin<T>& A,typename Abin<T>::nodo nb,Abin<T>& B)
{
    if(Abin<T>::NODO_NULO!=A.hijoIzqdoB(na))
    {
        B.insertarHijoDrchoB(nb,A.elemento(A.hijoIzqdoB(na)));
        reflejo_rec(A.hijoIzqdoB(na),A,B.hijoDrchoB(nb),B)
    }
    if(Abin<T>::NODO_NULO!=A.hijoDrchoB(na))
    {
        B.insertarHijoIzqdoB(nb,A.elemento(A.hijoDrchoB(na)));
        reflejo_rec(A.hijoDrchoB(na),A,B.hijoIzqdoB(nb),B);
    }
    
}

#endif //REFLEJO_HPP
