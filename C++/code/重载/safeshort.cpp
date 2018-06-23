#include <iostream>

using namespace std;
// ()���԰Ѷ�����������������

class shortsafe
{
public :
    unsigned short sh = 0;
    // ��ǰ������������
    shortsafe operator ++()
    {
        cout << "shortsafe operator ++ front() " << endl;
        if( sh < 65535) sh++;
        else abort();
        return *this;
    }
    // �ں�����������������Ҫ���渱��
    shortsafe operator ++(int)
    {
        cout << "shortsafe operator ++ back(int) " << endl;
        shortsafe temp(*this);
        if( sh < 65535) sh ++;
        else abort();
        return temp;
    }
    shortsafe operator --()
    {
        cout << "shortsafe operator -- front()" << endl;
        if(sh > 0) sh--;
        else abort();
        return *this;
    }
    shortsafe operator --(int)
    {
        cout << "shortsafe operator -- back(int)" << endl;
        shortsafe temp(*this);
        if(sh > 0) sh --;
        else abort();
        return temp;
    }
    unsigned operator()()
    {
        cout << "unsigned operator()()" << endl;
        return sh;
    }
    shortsafe operator + (unsigned int num)
    {
        cout << "shortsafe operator+()" << endl;
        shortsafe tmp;
        if(tmp.sh += num <= 65535)
            tmp.sh += num;
        else abort();
        return tmp;
    }
};

int main()
{
    unsigned short sh = 65535;
    sh += 1;
    cout << sh << endl;

    shortsafe shsafe;
    shsafe.sh = 3;
    --shsafe; // û�в�����ʱ�򡪡�ǰ��
    cout << shsafe.sh << endl;
    shsafe--;
    cout << shsafe.sh << endl;
    ++shsafe;
    cout << shsafe.sh << endl;
    shsafe++;
    cout << shsafe.sh << endl;
    puts("---");
    shsafe = shsafe ++ + 4; // ���ز��ı����ȼ�
    cout << shsafe() << endl;
    return 0;
}
