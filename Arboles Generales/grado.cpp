#include "grado.hpp"
#include "agen_E-S.h"
#include <iostream>


int main()
{
    Agen<int> Arbol;
    rellenarAgen(Arbol,-1);
    std::cout<<grado(Arbol)<<std::endl;
    return 0;
}