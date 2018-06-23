#include <stdio.h>
//! register int num = 10;
int main(register int gnum)
{
    register int num = 10;
    //! &num; 无法取内存地址
    return 0;
}
