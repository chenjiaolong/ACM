#include <iostream>
#include "myarray.h"

using namespace std;

int main()
{
    myarray my{11, 2, 23, 4 , 15};
    my.sort();
    my.show();
    myarray *p(new myarray{11, 12, 13, 14, 15});
    p -> show();

    my + (*p);
    my.show();

    return 0;
}
