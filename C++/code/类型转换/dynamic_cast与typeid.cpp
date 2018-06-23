#include <iostream>
#include <typeinfo>

// ����ͬ���������Ǹ���
// ����ָ��洢�����ַ�����麯��������������෽����������ø��෽��
class base
{
public:
    virtual void show() { std :: cout << "base show" << std :: endl; }
};
class baseX: public base
{
public:
    void show() { std :: cout << "baseX show" << std :: endl; }
};

int main()
{
    base *p = new baseX;
    p -> show();
    std :: cout << typeid(p).name() << std :: endl; // class base *
    std :: cout << typeid(*p).name() << std :: endl; // ���麯�� class baseX������ class base
    // typeid�Զ�ʶ���ͣ��������麯��


    // dynamic_castֻ��ʶ���̬�������ͣ�ת��ʧ�ܣ�����nulll
    baseX *px = dynamic_cast<baseX *>(p); // ����Ҫ���麯����ת���ɹ�������ʧ��
    px -> show();

    // ��̬����������ָ����Ը��ݶ�̬ת��Ϊ����ָ��
    // ʶ��Ϊ�������ת��ʧ�ܣ�����null
    // ʶ��Ϊ�������ת���ɹ���������ȷ�ĵ�ַ
    base *p1 = new base;
    base *p2 = new baseX;
    baseX *ptr = dynamic_cast<baseX *>(p1);
    std :: cout << (void *)ptr << std :: endl;

    // dynamic_castֻ��ת��ָ��������ã�����ת������
    //! base b = dynamic_cast<baseX>(*p2);

    baseX *p3 = new baseX;
    base *p4 = p3; // CPP�Զ�������ָ��ת��Ϊ����

    base & rbase(*p2);
    rbase.show();

    baseX &rx = dynamic_cast<baseX &>(rbase);

    return 0;
}
