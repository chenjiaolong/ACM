#include <list>
#include <iostream>

using namespace std;

template<typename T>
class TClass
{
public:
    T t;
    void show(T tx)
    {
        cout << tx << endl;
    }
};

int main()
{
    int num;
    // 判断标识符是否存在
    __if_exists(num) cout << "num is exists." << endl;
    __if_not_exists(num) cout << "num is not exists." << endl;

    TClass<int >t1;
    __if_exists(TClass<int >) cout << "TClass<int > is exists." << endl;
    __if_not_exists(TClass<int >) cout << "TClass<int > is not exists." << endl;

    list<int >mylist; // 检测某个模板有没有根据某个类型实例化
    __if_exists(list<int >) cout << "list<int > is exists." << endl;
    __if_not_exists(list<int >) cout << "list<int > is not exists." << endl;
    return 0;
}
