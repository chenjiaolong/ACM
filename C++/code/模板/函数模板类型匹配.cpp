#include <typeinfo>
#include <iostream>

using namespace std;
// ģ���Զ�ƥ��*��ģ�

template<typename T>
void com(T *p)
{
    cout << "*" << endl;
    cout << typeid(T).name() << endl;
}
template<typename T>
void com(T **p)
{
    cout << "**" << endl;
    cout << typeid(T).name() << endl;
}
template<typename T>
void com(T ***p)
{
    cout << "***" << endl;
    cout << typeid(T).name() << endl;
}

int main()
{
    int *p(nullptr);
    int **pp(nullptr);
    int ***ppp(nullptr);

    com(p);
    com(pp);
    com(ppp);

    return 0;
}
