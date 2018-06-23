#ifndef BCLASS_H
#define BCLASS_H


#pragma once

#include "Aclass.h"
#include <iostream>

using namespace std;

class Aclass;

class Bclass
{
public:
    Bclass();
    virtual ~Bclass();
    void show(Aclass a);
};

#endif // BCLASS_H
