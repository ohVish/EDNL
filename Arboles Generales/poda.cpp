#include "poda.hpp"
#include <iostream>
#include "agen_E-S.h"

int main()
{
    Agen<int> A;
    rellenarAgen(A,-1);
    poda(A,0);
    imprimirAgen(A);
    return 0;
}