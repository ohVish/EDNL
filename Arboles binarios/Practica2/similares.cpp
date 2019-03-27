#include "similares.hpp"
#include "abin_E-S.h"
#include <string>
#include "coladinamica.h"
const int fin = -1;
bool arbolPalindromo(Abin<char> Arbol);


int main()
{
    Abin<char> A1, A2;
    rellenarAbin(A1,'0');
    borrarNodos_rec(A1.raizB(),A1);
    imprimirAbin(A1);
    return 0;
}
