#ifndef ABIN_INORDEN_HPP
#define ABIN_INORDEN_HPP

#include <cmath>
#include <cassert>
#include <iostream>
template<typename T> class Abin
{
    public:
        typedef int nodo;
        explicit Abin<T>(unsigned tam,const T& elto_nulo);
        Abin<T>(const Abin<T>& copia);
        Abin<T>& operator =(const Abin<T>& copia);

        static const nodo NODO_NULO;

        void insertarRaizB(const T& x);
        void insertarHijoIzqdoB(nodo n,const T& x);
        void insertarHijoDrchoB(nodo n,const T& x);

        void eliminarRaizB();
        void eliminarHijoIzqdoB(nodo n);
        void eliminarHijoDrchoB(nodo n);

        //Función extra de este TAD.
        int profundidad(nodo n)const;

        bool arbolVacio();

        const T& elemento(nodo n)const;
        T& elemento(nodo n);

        nodo raizB()const;
        nodo padreB(nodo n)const;
        nodo hijoDrchoB(nodo n)const;
        nodo hijoIzqdoB(nodo n)const;

        //~Abin();

    private:
    //Función privada recursiva que me permite el calculo de la profundidad.
    int profundidad_rec(nodo na,nodo nb)const;
    T* nodos;
    T nulo;
    int maxNodos;
};
template<typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO(-1);

template<typename T>
Abin<T>::Abin(unsigned tam,const T& elto_nulo):
    nulo(elto_nulo),
    nodos(new T[tam]),
    maxNodos(tam)
{
    for(int i=0;i<maxNodos;i++)
        nodos[i]=nulo;
}

template<typename T>
void Abin<T>::insertarRaizB(const T& x)
{
    assert(nodos[maxNodos/2]==nulo); //nodo válido
    nodos[maxNodos/2]=x;
}

template<typename T>
void Abin<T>::insertarHijoIzqdoB(nodo n,const T& x)
{
    assert(n>=0  && n<maxNodos); // Nodo válido.
    assert(nodos[n]!=nulo); //Nodo no vacío.
    nodo izqdo = n - (maxNodos+1)/pow(2,profundidad(n)+2);
    assert(izqdo>=0); // nodo cabe en el árbol
    assert(nodos[izqdo]==nulo);
    nodos[izqdo]=x; 
}

template<typename T>
void Abin<T>::insertarHijoDrchoB(nodo n,const T& x)
{
    assert(n>=0 && n<maxNodos);
    assert(nodos[n]!=nulo);
    nodo drcho = n + (maxNodos+1)/pow(2,profundidad(n)+2);
    assert(drcho<maxNodos);
    assert(nodos[drcho]==nulo);
    nodos[drcho]=x;
}

template<typename T>
void Abin<T>::eliminarRaizB()
{
    assert(nodos[maxNodos/2+(maxNodos+1)/4]==nulo && nodos[maxNodos/2-(maxNodos+1)/4]==nulo); //raiz es hoja
    assert(nodos[maxNodos/2]!=nulo); //raiz no esta vacia
    nodos[maxNodos]=nulo;
}

template<typename T>
void Abin<T>::eliminarHijoIzqdoB(nodo n)
{
    assert(n>=0 && n<maxNodos);
    assert(nodos[n]!=nulo);
    nodo izqdo = n - (maxNodos-1)/pow(2,profundidad(n)+2);
    assert(izqdo>=0); //Izquierdo cabe?
    assert(nodos[izqdo]!=nulo);
    nodo izqdo_d = izqdo - (maxNodos-1)/pow(2,profundidad(izqdo)+2);
    nodo izqdo_i = izqdo + (maxNodos-1)/pow(2,profundidad(izqdo)+2);
    if(izqdo%2==1){
        if(izqdo_i>=0)
            assert(nodos[izqdo_d]==nulo && nodos[izqdo_i]==nulo);
        else
            assert(nodos[izqdo_d]==nulo);
    }
    nodos[izqdo]=nulo;
}
template<typename T>
void Abin<T>::eliminarHijoDrchoB(nodo n)
{
    assert(n>=0 && n<maxNodos);
    assert(nodos[n]!=nulo);
    nodo drcho = n + (maxNodos-1)/pow(2,profundidad(n)+2);
    assert(drcho<maxNodos); //Derecho cabe?
    assert(nodos[drcho]!=nulo);
    nodo drcho_d = drcho - (maxNodos-1)/pow(2,profundidad(drcho)+2);
    nodo drcho_i = drcho + (maxNodos-1)/pow(2,profundidad(drcho)+2);
    if(drcho%2==1){
        if(drcho_d<maxNodos)
            assert(nodos[drcho_d]==nulo && nodos[drcho_i]==nulo);
        else
            assert(nodos[drcho_i]==nulo);
    }
    nodos[drcho]=nulo;
}
template<typename T>
const T& Abin<T>::elemento(nodo n)const
{
    assert(nodos[n]!=nulo);
    return nodos[n];
}
template<typename T>
 T& Abin<T>::elemento(nodo n)
{
    assert(nodos[n]!=nulo);
    return nodos[n];
}

template<typename T>
int Abin<T>::profundidad(nodo n)const
{
    assert(n>=0 && n<maxNodos);
    assert(nodos[n]!=NODO_NULO);
    return profundidad_rec(maxNodos/2,n);   
}

template<typename T>
int Abin<T>::profundidad_rec(nodo na,nodo nb)const
{
    if(na==nb)
    {
        return 0;
    }
    else
    {
        if(nb<na)
            return 1 + profundidad_rec(na/2,nb);
        else
        {
            return 1 + profundidad_rec(na+na/2+1,nb);
        }
    }
}

template <typename T>
typename Abin<T>::nodo Abin<T>::padreB(nodo n)const
{
    assert(n>=0 && n<maxNodos);
    assert(nodos[n]!=nulo);
    int prof = profundidad(n);
    if(n==maxNodos/2)
        return NODO_NULO;
    else
    {
        if(n%(int)((maxNodos+1)/pow(2,prof-1))==((maxNodos+1)/pow(2,prof+1)-1))
            return n+(maxNodos+1)/pow(2,prof+1);
        else
            return n-(maxNodos+1)/pow(2,prof+1);
    }
    
}
#endif //ABIN_INORDEN_HPP
