#ifndef ACLASS_H
#define ACLASS_H

#pragma once

#include "Bclass.h"
#include <iostream>

using namespace std;

class Bclass;

class Aclass
{
public:
    Aclass();
    virtual ~Aclass();
    void show(Bclass b);
};

#endif // ACLASS_H
