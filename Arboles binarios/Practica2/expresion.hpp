#ifndef EXPRESION_HPP
#define EXPRESION_HPP

#include "arbol_binario_enlazada.h"

//Definición del tipo de datos necesario para realizarloo
union estructura
{
    double operando;
    char operador; 
};

double expresion(Abin<estructura>& A)
{
    return expresion_rec(A.raizB(),A);
}

double expresion_rec(typename Abin<estructura>::nodo n,Abin<estructura>& A)
{
    //Podemos realizar esta suposición debido a que la expresión aritmética es correcta.
    if(A.hijoIzqdoB(n)==Abin<estructura>::NODO_NULO)
        return A.elemento(n).operando;
    else
    {
        switch(A.elemento(n).operador)
        {
            case '+':
                return expresion_rec(A.hijoIzqdoB(n),A) + expresion_rec(A.hijoDrchoB(n),A);
            case '-':
                return expresion_rec(A.hijoIzqdoB(n),A) - expresion_rec(A.hijoDrchoB(n),A);
            case '*':
                return expresion_rec(A.hijoIzqdoB(n),A) * expresion_rec(A.hijoDrchoB(n),A);
            case '/':
                return expresion_rec(A.hijoIzqdoB(n),A) / expresion_rec(A.hijoDrchoB(n),A);
        }
    }
    
}



#endif //EXPRESION_HPP