#include <iostream>
#include "lib/Embarcado.cpp"


using namespace std;


int main()
{

    Iniciar* init;
    
    init = new Menu();
    //init = new Embarcado();
    
    delete init;
return 0;
}
