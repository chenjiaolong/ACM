#include "Bclass.h"


Bclass::Bclass()
{
    //ctor
    // Aclass a;
    cout << "Bclass::Bclass()" << endl;
}

void Bclass::show(Aclass a)
{
    cout << "class Bclass void show(Aclass a)" << endl;
}

Bclass::~Bclass()
{
    //dtor
    cout << "Bclass::~Bclass()" << endl;
}
