#include<iostream>

using namespace std;

// �쳣�ࣺ��ջ�쳣������ջ�쳣��
class EStackEmpty { };
class EStackFull { };

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
        throw EStackFull();
    _stk[_top] = value;
    _top++, _cnt ++;
}

const int err_stack_full = 30;

int main()
{
    JuStack stack(45);
    try
    {
        for(int i = 0; i < 32; i ++)
            stack.Push(i); // ���������쳣�ĺ�������
    }catch(const EStackFull &) // �����׳����쳣�� ִ����Ӧ�Ĵ���
    {
        cerr << "Error : Stack full" << endl;
        return err_stack_full;
    }
    return 0;
}
