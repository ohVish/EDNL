#include "desequilibro.hpp"
#include <iostream>
#include "agen_E-S.h"

int main()
{
    Agen<int> A;
    rellenarAgen(A,-1);
    std::cout<<alturaMinima(A.raiz(),A)<<std::endl;
    return 0;
}