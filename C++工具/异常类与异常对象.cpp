#include<iostream>

using namespace std;

// �쳣�ࣺ��ջ�쳣������ջ�쳣��
// ��������쳣�࣬�ṩ��Ҫ���쳣��Ϣ
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
    if(IsEmpty()) // ������ջ�쳣�� ������쳣���һ�������׳�
        throw EStackEmpty();
    -- _top, -- _cnt;
    return _stk[_top];
}
void JuStack :: Push(int value)
{
    if(IsFull()) // ������ջ�쳣��������쳣���һ�������׳�
        throw EStackFull(value);// ʹ�� value �����쳣������׳�
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
            stack.Push(i); // ���������쳣�ĺ�������
    }catch(const EStackFull & e) // ʹ���쳣�����ȡ��ϸ��Ϣ
    {
        cerr << "Stack full when trying to push" << e.GetValue() << endl;
        return err_stack_full;
    }
    return 0;
}

