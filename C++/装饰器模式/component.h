#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <iostream>

// ����һ��ԭʼ�����൰�⣬װ�����Ĺ����Ǹ�������ϸ���װ�Σ������ͣ��ɿ����������ʣ�ˮ����
class Cake
{
public :
    virtual void showCake() = 0;
    // ��ʾ�ú���û�к����⣬���������������ﶨ��

    virtual ~Cake() {};
    std :: string name;
};

class ConcreateCake : public Cake
{
public :
    ConcreateCake() { name = "ԭʼ����"; }

    void showCake() { std :: cout << name.c_str() << std :: endl; }
    virtual ~ConcreateCake() {}
};

#endif // COMPONENT_H_INCLUDED
