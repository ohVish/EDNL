#ifndef _COLADINAMICA_H
#define _COLADINAMICA_H
#include <cassert>


template<typename T> class Cola{
public:
Cola();
Cola(const Cola<T>& C);
Cola<T>& operator = (const Cola<T>& C);
bool vacia()const;
const T& frente() const;
void pop();
void push(const T& x);
~Cola();
private:
struct nodo{
    T elem;
    nodo* sig;
    nodo(const T& x, nodo* p=0):elem(x),sig(p){}
};

nodo* inicio;
nodo* fin;
void copiar(const Cola<T>& C);
};

template<typename T>
inline Cola<T>::Cola():inicio(0),fin(0){}

template<typename T>
inline Cola<T>::Cola(const Cola<T>& C): inicio(0),fin(0){
    copiar(C);
}

template<typename T>
Cola<T>& Cola<T>::operator =(const Cola<T>& C){
    if(this!=&C);{
        this->~Cola();
        copiar(C);
    }
    return *this;
}

template<typename T>
bool Cola<T>::vacia()const{
    return(inicio==0);
}

template<typename T>
const T& Cola<T>::frente()const{
    assert(!vacia());
    return(inicio->elem);
}



template<typename T>
void Cola<T>::pop(){
    assert(!vacia());
    nodo *p = inicio;
    inicio=p->sig;
    if(!inicio)fin=0;
    delete p;
}

template<typename T>
void Cola<T>::push(const T& x){
    nodo* p= new nodo(x);
    if(inicio==0){
        inicio=fin=p;
    }
    else{
        fin=fin->sig=p;
    }
}

template<typename T>
void Cola<T>::copiar(const Cola<T>& C){
    if(C.inicio){
        inicio=fin=new nodo(C.inicio->elem);
        nodo *q = C.inicio->sig;
        while(q){
            fin->sig=new nodo(q->elem);
            fin=fin->sig;
            q=q->sig;
        }
    }
}


template<typename T>
Cola<T>::~Cola(){
    nodo *p;
    while(inicio){
        p=inicio->sig;
        delete inicio;
        inicio=p;
    }
    fin=0;
}

#endif // _COLADINAMICA_H
