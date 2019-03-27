#include "similares.hpp"
#include "abin_E-S.h"
#include <string>
#include "coladinamica.h"
const int fin = -1;
bool arbolPalindromo(Abin<char> Arbol);



bool arbolPalindromo(Abin<char> Arbol)
{
    bool val = true;
    if (!Arbol.arbolVacioB())
    {
        Cola<Abin<char>::nodo> C1, C2;
        if (Arbol.hijoIzqdoB(Arbol.raizB()) != Abin<char>::NODO_NULO)
            C1.push(Arbol.hijoIzqdoB(Arbol.raizB()));
        if (Arbol.hijoDrchoB(Arbol.raizB()) != Abin<char>::NODO_NULO)
            C1.push(Arbol.hijoDrchoB(Arbol.raizB()));
        while (!C1.vacia() && val)
        {
            int i;
            i = 0;
            std::string x;
            while (!C1.vacia())
            {
                C2.push(C1.frente());
                x += Arbol.elemento(C1.frente());
                C1.pop();
            }
            for (int j = 0; j < x.length(); j++)
            {
                val = (x[j] == x[x.length() - 1 - j]);
            }
            std::cout << x << std::endl;

            if (val)
            {
                while (!C2.vacia())
                {
                    Abin<char>::nodo n = C2.frente();
                    C2.pop();
                    if (Arbol.hijoIzqdoB(n) != Abin<char>::NODO_NULO)
                        C1.push(Arbol.hijoIzqdoB(n));
                    if (Arbol.hijoDrchoB(n) != Abin<char>::NODO_NULO)
                        C1.push(Arbol.hijoDrchoB(n));
                }
            }
        }
    }
    return val;
}

// Precondición: Recibe un árbol binario
// Postcondición: Devuelve true si cada nivel del árbol es un palíndromo o false en caso contrario.
template <typename T>
bool palindromoNiveles(Abin<T> A)
{
    return palindromoNiveles_rec(A.raizB(), A.raizB(), A);
}

// Precondicion: Recibe un nodo y su reflejo en el árbol y el árbol.
// Postcondición: Devuelve true si los árboles de los que los nodos son raíz son reflejo el uno del otro.
template <typename T>
bool palindromoNiveles_rec(typename Abin<T>::nodo i, typename Abin<T>::nodo d, Abin<T> A)
{
    if (i == Abin<T>::NODO_NULO && d == Abin<T>::NODO_NULO)
    {
        return true;
    }

    else
    {
        if (i != Abin<T>::NODO_NULO || d != Abin<T>::NODO_NULO)
            return A.elemento(i) == A.elemento(d) && palindromoNiveles_rec(A.hijoIzqdoB(i), A.hijoDrchoB(d), A) && palindromoNiveles_rec(A.hijoDrchoB(i), A.hijoIzqdoB(d), A);
    }
}

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

int rebelde(Abin<int>::nodo n, Abin<int> &A)
{
    if (A.raizB() == n)
        return false;
    else
    {
        return A.elemento(n)!=mayoria(n,A);
    }
}
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
int cuentaRebeldes(Abin<int> &A)
{
    return cuentaRebeldes_rec(A.raizB(),A);
}


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

template<typename T>
int numNodos(typename Abin<T>::nodo n,Abin<T>& A)
{
    return((Abin<T>::NODO_NULO!=A.hijoIzqdoB(n)) + (Abin<T>::NODO_NULO!=A.hijoDrchoB(n)));
}

int main()
{
    Abin<char> A1, A2;
    rellenarAbin(A1,'0');
    borrarNodos_rec(A1.raizB(),A1);
    imprimirAbin(A1);
    return 0;
}