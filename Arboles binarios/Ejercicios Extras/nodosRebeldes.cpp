#include "arbol_binario_enlazada.h"

// Se considera Nodo Rebelde aquel que es diferente del valor ocupado por la mayoria de los ancestros. (Valores booleanos)

/* 
    Precondiciones: Recibe un nodo n y el árbol al que pertenece.
    Postcondiciones: Cuenta el valor booleano de sus ascentros, y calcula la mayoria.
*/
bool mayoria(Abin<int>::nodo n, Abin<int> &A)
{
    int verdaderos, falsos;

    verdaderos = 0;
    falsos = 0;
    n=A.padreB(n);
    while (n != Abin<int>::NODO_NULO)
    {
        if (A.elemento(n) == true)
            verdaderos++;
        else
            falsos++;
        n = A.padreB(n);
    }
    if (verdaderos > falsos)
        return true;
    else
        return false;
}
/* 
    Precondiciones: Recibe un nodo y el arbol al que pertenece.
    Postcondiciones: True si el nodo es rebelde.
*/

int rebelde(Abin<int>::nodo n, Abin<int> &A)
{
    if (A.raizB() == n)
        return false;
    else
    {
        return A.elemento(n)!=mayoria(n,A);
    }
}
/* 
    Función auxiliar que cuenta los nodos recorriendo el árbol mediante su naturaleza recursiva.
*/
int cuentaRebeldes_rec(Abin<int>::nodo n, Abin<int> &A)
{
    if(Abin<int>::NODO_NULO == n)
        return 0;
    else{
        if(rebelde(n,A))
            return 1 + cuentaRebeldes_rec(A.hijoIzqdoB(n),A) + cuentaRebeldes_rec(A.hijoDrchoB(n),A);
        else
            return cuentaRebeldes_rec(A.hijoIzqdoB(n),A) + cuentaRebeldes_rec(A.hijoDrchoB(n),A);
        
    }

}

/* 
    Precondiciones: Recibe un árbol.
    Postcondiciones: Cuenta el número de nodos rebeldes del árbol.
*/

int cuentaRebeldes(Abin<int> &A)
{
    return cuentaRebeldes_rec(A.raizB(),A);
}