#include "decorator.h"
#include "component.h"

int main()
{
    ConcreateCake *pConCake = new ConcreateCake();
    pConCake -> showCake();

    CakeDecoratorMilk* pDecMilk = new CakeDecoratorMilk(pConCake);
    pDecMilk -> showCake();
    CakeDecoratorChoclate *pDecCho = new CakeDecoratorChoclate(pDecMilk);
    pDecCho -> showCake();

    delete pConCake;
    delete pDecMilk;
    delete pDecCho;
    return 0;
}
