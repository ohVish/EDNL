
#include "arbol_binario_enlazada.h"
#include "coladinamica.h"

/*
    Precondiciones: Recibe un Arbol binario de char.
    Postcondiciones: Comprueba que las letras de cada nivel forman una palabra que se considera palíndromo.
                     Si lo cumplen todos los niveles devuelve true, en otro caso false.

    Definición de palíndromo -> https://es.wikipedia.org/wiki/Pal%C3%ADndromo
*/

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

