#include <iostream>

using namespace std;
// ���Ա����ָ�룬����thisָ�룬������ȷ˭������
// ���Ա����ָ�룬��ָ����Ե��ã�û�����Ա����
// ���÷�ʽ: ->* .*
// ���Ա����ָ������
// int (A :: *ps[4])(int, int){&A :: Add, &A :: Sub, &A :: Mul, &A :: Div};

class A
{
public :
    int Add(int a, int b)
    {
        return a + b;
    }
    int Sub(int a, int b)
    {
        return a - b;
    }
    int Mul(int a, int b)
    {
        return a * b;
    }
    int Div(int a, int b)
    {
        try{
        if(b == 0) throw 1;
        return a / b;
        }catch(int code)
        {
            cout << "��������Ϊ0" << endl;
        }
    }
};

void change(int (A :: * &p)(int, int)) // int (A :: * &p)(int, int) ���Ա����ָ�������
{
    p = &A :: Sub;
}

// changeit �Ĳ��������Ա����ָ������ã�����ֵ�����Ա����ָ�������
int (A :: * &changeit(int (A :: * &p)(int, int)))(int, int)
{

    p = &A :: Mul;
    return p;
}
// ���Ա����ָ��������Ϊ�����˻�Ϊ�������Ա����ָ��
void showit(int (A :: *p[4])(int, int))
{
    p += 3;
    cout << "showit " << sizeof(p) << endl;
}
void show(int (A :: **p)(int, int))
{
    A *pclass(nullptr);
    for(int (A :: **pp)(int, int) = p; pp < p + 4; pp ++) // �������Ա����ָ�������������ָ������
        cout << (pclass ->** pp)(100, 10) << endl; // ָ��ѭ��
}
int main()
{
    // ���Ա����ָ��
    int (A :: *p)(int, int) = &A :: Add;
    A *pclass(nullptr);
    // ���Ա����ָ�룬��ָ����Ե��ã�û�����Ա����
    cout << pclass -> Add(1, 2) << endl;
    cout << (pclass ->* p)(2, 3) << endl;
    cout << ((*pclass).*p)(2, 3) << endl;

    cout << "-----" << endl;
    // ���Ա����ָ������
    // ջ
    // int (A :: *ps[4])(int, int){&A :: Add, &A :: Sub, &A :: Mul, &A :: Div};
    // ��
    int (A :: **ps)(int, int) = new( int(A :: *[4])(int, int) ) {&A :: Add, &A :: Sub, &A :: Mul, &A :: Div}; // �������Ա��������ָ������
    // �������Ա����ָ��
    cout << sizeof(ps) << endl;
    for(int i = 0; i < 4; i ++)
        cout << (pclass ->* ps[i])(100, 10) << endl; // �±�ѭ��
    for(int (A :: **pp)(int, int) = ps; pp < ps + 4; pp ++) // �������Ա����ָ�������������ָ������
        cout << (pclass ->** pp)(100, 10) << endl; // ָ��ѭ��

    cout << "----" << endl;
    cout << (pclass ->* p)(100, 10) << endl;
    change(p);
    cout << (pclass ->* p)(100, 10) << endl;
    p = changeit(p);
    cout << (pclass ->* p)(100, 10) << endl;

    cout << "----" << endl;
    cout << sizeof(ps) << endl;
    //! ps += 3;
    showit(ps);
    show(ps);

    return 0;
}
