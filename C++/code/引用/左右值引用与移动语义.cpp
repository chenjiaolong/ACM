#include <iostream>

using namespace std;
// C++�������õ����������ָ��
void change(int &rnum) // �������ı���
{
    rnum = 111;
}

void showit(int &&rrnum)
{
    cout << rrnum << endl;
}
void showitt(int &rnum)
{
    cout << (rnum += 1)<< endl;
}
int main()
{
    int num = 10; // num ��ֵ���ڴ�ʵ��
    int &rnum(num); // �����ı���
    rnum = 1; // rnum �ȼ���num�ı���
    cout << num << endl;
    change(num);
    cout << num << endl;

    cout << "---------" << endl;
    int num2 = 1;
    int data = 0;
    cout << (void *)&data << endl;
    data = num2 + 1;
    data = num2 + 2;
    data = num2 + 3;

    cout << "--------" << endl;
    int num3 = 1;
    // num3 + 4 �Ĵ����У������ڴ�
    int && rnum2(num3 + 4); //��ֵ���ã����ٱ��ݡ����������Զ�����
    printf("%x\n", &rnum2);

    int data2 = num3 + 4;
    int &rdata(data2); // ��ֵ����


    cout << "--------" << endl;
    int a[5]{1, 2, 3, 4, 5};
    int *p(a);
    cout << *p << endl;
    // int a -> int &ra; & ���������������֮��
    // int *p -> int * &rp;
    int * & rp(p); // ��ֵ���øı�ָ��
    rp += 1;
    cout << *p << endl;

    // int * && rrp(p + 2); // ��ֵ����, &&
    int * && rrp(&a[1]);
    rrp += 2;
    cout << *rrp << endl;

    cout << "--------" << endl;
    showit(a[3] + 2); // ��Լ�ڴ�
    showit(move(a[3])); // move�ƶ����壬��ֵ�����ֵ

    showitt(a[3]); // ��ֵ����
    showitt(a[3]);
    return 0;
}
