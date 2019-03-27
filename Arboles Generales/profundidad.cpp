#include <iostream>
#include "profundidad.hpp"
#include "agen_E-S.h"

int main()
{
    Agen<int> A;
    rellenarAgen(A,-1);
    std::cout<<profundidad(A.hijoIzqdo(A.hermDrcho(A.hijoIzqdo(A.raiz()))),A)<<std::endl;
    return 0;
}