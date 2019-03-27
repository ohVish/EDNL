#include "similares.hpp"
#include "abin_E-S.h"
#include <string>
#include "coladinamica.h"
const int fin = -1;
bool arbolPalindromo(Abin<char> Arbol);







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
