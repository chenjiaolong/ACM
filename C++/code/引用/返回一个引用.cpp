#include <iostream>

using namespace std;

// ��������ֵ�и������ƣ����ر���
// ջ�����Զ����գ��ͷţ�����ֵΪָ�룬����ָ��ջ�����������ã���������ջ��
// ָ�룬ָ����ջ����ָ��ָ���ڴ�����������
int getdata()
{
    int num = 10; // ջ��
    return num;
}

int &getdata1()
{
    int num = 10; // �����ˣ����ڴ棬
    return num;
}
// ����
int &getdata2()
{
    int *p(new int(5));
    return *p; // *p == int num;
}
// ȫ�ֱ��������Զ����ͷ�
int g_num = 20;
int &getdata3()
{
    return g_num;
}
char * &getcode()
{
    // p ��ջ�ϣ�ָ��������ڴ�����
    char *p("maomaoyu");
    return p;
}
int main()
{
    cout << getdata() << endl;

    // ջ��
    cout << "-----------" << endl;
    //! int & rnum = getdata1(); // ����ԭ���ڴ�
    cout << "hello" << endl;
    //! cout << rnum << endl;
    // int rnum = getdata1(); // �������µ��ڴ�
    // cout << rnum << endl;

    // ����
    cout << "-----------" << endl;
    int &rnum = getdata2();
    cout << "xixi" << endl;
    cout << rnum << endl;

    // ȫ�ֱ���
    cout << "-----------" << endl;
    int &gnum = getdata3();
    cout << "hehe" << endl;
    cout << gnum << endl;

    // �ַ���
    // cout << "-----------" << endl;
    // char * &rp = getcode();
    // char *newp = rp; // ����rp�洢�Ĵ�������ַ
    // cout << "heihei" << endl;
    // cout << newp << endl;
    //! cout << rp << endl;

    return 0;
}
