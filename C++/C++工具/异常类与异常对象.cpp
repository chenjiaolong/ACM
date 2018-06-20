#include<iostream>

using namespace std;

// 异常类：空栈异常类与满栈异常类
// 精心设计异常类，提供必要的异常信息
class EStackFull
{
public :
    EStackFull (int i) : _value(i) {  }
    int GetValue() { return _value; }
private :
    int _value;
};
class EStackEmpty {  };
class JuStack
{
public :
    JuStack(int cap) : _stk(new int[cap + 1]), _cap(cap), _cnt(0), _top(0) {}
    virtual ~JuStack(){ if(_stk) delete[] _stk, _stk = NULL; }
public :
    int Pop();
    void Push(int value);
    bool IsFull() const { return _cap == _cnt; }
    bool IsEmpty() const { return _cnt == 0; }
    int GetCapacity() const { return _cap; }
    int GetCount() const { return _cnt; }
private :
    int *_stk;
    int _cap, _cnt, _top;
};

int JuStack :: Pop()
{
    if(IsEmpty()) // 引发空栈异常， 构造该异常类的一个对象并抛出
        throw EStackEmpty();
    -- _top, -- _cnt;
    return _stk[_top];
}
void JuStack :: Push(int value)
{
    if(IsFull()) // 引发满栈异常，构造该异常类的一个对象并抛出
        throw EStackFull(value);// 使用 value 构造异常类对象并抛出
    _stk[_top] = value;
    _top++, _cnt ++;
}

const int err_stack_full = 1;

int main()
{
    JuStack stack(17);
    try
    {
        for(int i = 0; i < 32; i ++)
            stack.Push(i); // 可能引发异常的函数调用
    }catch(const EStackFull & e) // 使用异常对象获取详细信息
    {
        cerr << "Stack full when trying to push" << e.GetValue() << endl;
        return err_stack_full;
    }
    return 0;
}

