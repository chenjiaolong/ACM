#include <iostream>

using namespace std;
// ()可以把对象名当作函数操作

class shortsafe
{
public :
    unsigned short sh = 0;
    // 在前先自增再引用
    shortsafe operator ++()
    {
        cout << "shortsafe operator ++ front() " << endl;
        if( sh < 65535) sh++;
        else abort();
        return *this;
    }
    // 在后先引用再自增，需要保存副本
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
    --shsafe; // 没有参数的时候——前面
    cout << shsafe.sh << endl;
    shsafe--;
    cout << shsafe.sh << endl;
    ++shsafe;
    cout << shsafe.sh << endl;
    shsafe++;
    cout << shsafe.sh << endl;
    puts("---");
    shsafe = shsafe ++ + 4; // 重载不改变优先级
    cout << shsafe() << endl;
    return 0;
}
