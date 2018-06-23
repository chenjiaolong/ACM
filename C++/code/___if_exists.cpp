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
    // �жϱ�ʶ���Ƿ����
    __if_exists(num) cout << "num is exists." << endl;
    __if_not_exists(num) cout << "num is not exists." << endl;

    TClass<int >t1;
    __if_exists(TClass<int >) cout << "TClass<int > is exists." << endl;
    __if_not_exists(TClass<int >) cout << "TClass<int > is not exists." << endl;

    list<int >mylist; // ���ĳ��ģ����û�и���ĳ������ʵ����
    __if_exists(list<int >) cout << "list<int > is exists." << endl;
    __if_not_exists(list<int >) cout << "list<int > is not exists." << endl;
    return 0;
}
