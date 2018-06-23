#include <iostream>

using namespace std;

void run1(const int *p); // 改变地址，不能改变内容
void run2(int const *p);
void run3(int *const p); // 不改变地址，能改变内容
void run4(const int * const p);// 不改变地址，不能改变内容
void run5(int const * const p);

int main()
{
    const int num[5]{1, 2, 3, 4, 5};
    const int *p = num;
    *(int *)p = 100;
    // const 数组没有优化，可以间接改变
    //! *(p + 2) = 1; // 指向常量的指针，无法修改
    for(auto i : num)
        cout << i << endl;
    return 0;
}
