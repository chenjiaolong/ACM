#include <iostream>

using namespace std;

class myclass
{
public :
    int x, y;
    myclass() : x(0), y(0) {  }
    explicit myclass(int a) : x(a), y(a) { cout << "����" << endl; }

    void operator = (int num)
    {
        cout << "��ֵ����" << endl;
        x = y = num;
    }
    // û�в�����û�з������ͣ���һ��Ҫ�з���ֵ
    operator int() // ������ת��Ϊint
    {
        return (x + y) / 2;
    }
    operator double();
};
// operator�������ͣ�������������װ��
// ֻ���ǳ�Ա������������this
myclass :: operator double()
{
    return (x + y) / 2.0;
}

int main()
{
    // explicit ��ֹ��ʽת��
    ///! myclass my1 = 5; ///! ������ȷ
    myclass my1 = static_cast<myclass>(5);
    myclass my2(5);
    myclass my3 = myclass(5);
    myclass my4 = (myclass)5;

    myclass my5;
    my5 = 5; // ��ֵ���ص�װ��

    myclass my6;
    my6.x = 4;
    my6.y = 3;
    int a = my6;
    cout << a << endl;
    double b = my6;
    cout << b << endl;


    return 0;
}
