#ifndef DECORATOR_H_INCLUDED
#define DECORATOR_H_INCLUDED

#include "component.h"

class CakeDecorator : public Cake
{
protected :
    Cake *pCake;
public :
    virtual void showCake() = 0;
    virtual ~CakeDecorator() {  }
};

class CakeDecoratorMilk : public CakeDecorator
{
public :
    CakeDecoratorMilk(Cake *pCake) { this -> pCake = pCake; }

    void showCake()
    {
        this -> name = pCake -> name + "加奶油";
        std :: cout << name.c_str() << std :: endl;
    }
    virtual ~CakeDecoratorMilk() {  }
};

class CakeDecoratorChoclate : public CakeDecorator
{
public:
    CakeDecoratorChoclate(Cake* pCake) { this -> pCake = pCake; }
    void showCake()
    {
        this -> name = pCake -> name + "加巧克力";
        std :: cout << name.c_str() << std :: endl;
    };
    virtual ~CakeDecoratorChoclate(){  }
};


#endif // DECORATOR_H_INCLUDED
