

#include "Abin_inorden.hpp"
#include <iostream>

using namespace std;
int main(){
    Abin<int> arbol(31,-1);
    arbol.insertarRaizB(31);
    arbol.insertarHijoIzqdoB(15,20);
    cout<<arbol.padreB(7)<<endl;
    return 0;
}