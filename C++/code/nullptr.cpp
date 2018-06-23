#include <iostream>
#include <typeinfo>
using namespace std;

void show(int num)
{
    cout << "int " << endl;
}
void show(int *p)
{
    cout << "int *" << endl;
}
int main()
{
    //! show(NULL); 编译无法通过C风格空指针，会被误认为整数
    show(nullptr); // C++ 风格的空指针
    cout << typeid(NULL).name() << endl; // int
    cout << typeid(nullptr).name() << endl; // std :: nullptr_t
    // 严格类型匹配

    int *p1 = NULL;
    int *p2 = nullptr;
    show(p1);
    show(p2);

    return 0;
}
