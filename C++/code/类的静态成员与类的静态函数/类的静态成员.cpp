#include <iostream>

using namespace std;

class myclass
{
public :
    static int num; // ֻ���ʼ��һ��
    int data; // ÿ����һ�ζ����ʼ��һ��
    myclass()
    {
        num += 1;
    }
    ~myclass()
    {
        num -= 1;
    }
};

int myclass :: num = 0; // ��̬��Ա�����еĶ��󶼿��Է���

int main()
{
    myclass my1, my2, my3;
    my3.~myclass();
    // ��̬��Ա�������κ�һ�������κ�һ�����󶼿��Է��ʣ���̬��
    // ����ͬ�����ͨ��
    myclass *p = new myclass;
    cout << my1.num << endl;
    cout << my2.num << endl;
    cout << my3.num << endl;
    cout << myclass :: num << endl;
    return 0;
}
