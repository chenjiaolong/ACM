#include "Aclass.h"

Aclass::Aclass()
{
    //ctor
    // Bclass b;
    cout << "Aclass::Aclass()" << endl;
}

void Aclass::show(Bclass b)
{
    cout << "class Aclass void show(Bclass b)" << endl;
}

Aclass::~Aclass()
{
    //dtor
    cout << "Aclass::~Aclass()" << endl;
}

