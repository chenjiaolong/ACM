#include <iostream>

using namespace std;

class myclass; // �������,����������������ָ��������ã������Ƕ���

myclass *p;
//! myclass &ra; // �����ڶ���ʱ�����ʼ������Ϊ����ʱ����
void run(myclass & rmy)
{

}
// myclass my;

// ���м���԰������ó�Ա��Ĭ�ϣ������ʼ��(ע��Ϳ��������ʼ���г�ͻ)

int g_num = 100;
class myclass
{
public :
    int x, y;
    // int &rx = x;
    // int &rx{x}; // Ĭ�ϳ�ʼ��
    //! int &rx(x); // ����ĳ�Ա������ͻ
    int &rx;
    myclass() : rx(g_num) // �����ʼ��
    {
        rx = 10; // �ı����õ�ֵ
    }
//    myclass(const myclass &my) // �����ù����ʼ���г�ͻ
//    {
//        cout << "copy call" << endl;
//    }
    void show() const
    {
        cout << x << "  " << y << endl;
    }
};
// ���ÿ��Ա��ⲻ��Ҫ�Ŀ�������
myclass &get(myclass &data)
{
    return data;
}
int main()
{
    cout << sizeof(myclass) << endl;
    myclass my1;
    cout << g_num << endl;
    get(my1);

    myclass my2;
    const myclass & my3(my2); // ����my2 �ȼ���my1,�ڴ�ռ�ĸ��ֽڣ�32bit��
    my3.show();// �����õȼ��ڳ�����
    return 0;
}
