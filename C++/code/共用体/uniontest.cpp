#include <iostream>

using namespace std;
// union Ĭ�Ϲ��У�����˽��
// union ����ʵ�ַ�װ��ֻ��һ����������Լ
union u
{
// private :
    int num;
    float f;
    void go()
    {
        cout << "SSS" << endl;
    }
};
// �������޷��̳У���̬
//! union uSon : public u{  };

int main()
{
    u p1;
    p1.num = 10;
    p1.go();
    u p2{14}; // ֻ�ܳ�ʼ��һ������
    cout << p2.num << endl;
    p2.f = 10.8;
    cout << p2.num << endl;
    return 0;
}
