#include<iostream>

using namespace std;

class ConstCastTest
{
public :
    void SetNum(int num) { _num = num; }
    void PrintNum() const;
    void Print() const;
private :
    int _num;
};

void ConstCastTest :: PrintNum() const
{
    // 临时取消常量约束，修改目标对象的内容
    const_cast<ConstCastTest *> (this) -> _num --;
    cout << _num << endl;
}
void ConstCastTest :: Print() const
{
    cout << _num << endl;
}

int main()
{
    ConstCastTest M;
    M.SetNum(5);
    M.PrintNum();
    M.Print();
    return 0;
}
