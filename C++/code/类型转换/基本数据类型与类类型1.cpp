#include <iostream>

using namespace std;

class myclass
{
public :
    int x, y;
    myclass(int a) : x(a), y(a){ cout << "���캯��" << endl; } // ��ֵ��ʼ��
};

int main()
{
    // ���캯����ʼ������������ת��
    myclass my1 = 5;
    myclass my2(5);
    myclass my3 = myclass(5);
    myclass my4 = (myclass)5;




    return 0;
}
