#include <cstring>
#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    // typeid获取数据类型
    int a;
    cout << typeid(a).name() << endl;
    cout << typeid(10).name() << endl;
    cout << typeid(10 + 1.2).name() << endl;
    cout << typeid("maomaoyu").name() << endl;

    int *px;
    int *py;
    if(strcmp(typeid(px).name(), typeid(py).name()) == 0) cout << "==" << endl;
    else cout << "!=" << endl;
    return 0;
}
