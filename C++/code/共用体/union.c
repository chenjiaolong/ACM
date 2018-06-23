#include <stdio.h>
#include <stdlib.h>

// 节约内存，不能给初始值
// 无法有函数
union u
{
    int num; // 不能给初始值
    double data;
    //! void go() {  } // 不能有函数
    void (*p)(); // 可以有函数指针
};
void go()
{

}

int main()
{
    return 0;
}
