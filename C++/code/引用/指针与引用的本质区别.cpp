#include <iostream>

using namespace std;
// �����ǵ�ַ���������õȼ��ڲ���ԭ��

struct MyStruct
{
    int &rint;
    int *p;
}; // ���õı��ʾ���ָ��

int * getp()
{
    int a = 5;
    return &a; // ���ؾֲ���������ʱ�����ĵ�ַ��a
}

int & getrp()
{
    int a = 5;
    return a; // ���ؾֲ���������ʱ�����ĵ�ַ��a
}

int & getint(int &rint) // ���������ض��ǵ�ַ
{
    rint = 1;
    return rint;
}

int main()
{
    cout << __FILE__ << endl;
    cout << sizeof(MyStruct) << endl;
    cout << sizeof(int *) << endl;

    cout << "-------------" << endl;
    //! int *p(new int);
    //! p = getp();
    //! cout << *p << endl;
    //! int &ra = getrp();
    //! cout << ra << endl;

    cout << "-------------" << endl;
    int a(10);
    getint(a);
    cout << a << endl;

    cout << "-------------" << endl;
    int *p(new int(5));
    getint(*p);
    cout << *p << endl;

    int &ra(a); // ���ã�ջ��
    //! int & *pr; // ������ʹ��ָ�����õĵ�ָ�룬ָ�����õ�ָ��Ƿ�

    return 0;
}
