#include<iostream>
using namespace std;
class IntNum
{
public:
    IntNum(int x = 0) : xptr(new int(x))  //���캯��
    {
        cout << "Calling constructor..." << endl;
    }
    IntNum(const IntNum & n) : xptr(new int(*n.xptr)) //���ƹ��캯��
    {
        cout << "Calling copy constructor..." << endl;
    }
    IntNum(IntNum && n): xptr( n.xptr)  //�ƶ����캯��
    {
        n.xptr = nullptr;
        cout << "Calling move constructor..." << endl;
    }
    ~IntNum()  //��������
    {
        delete xptr;
        cout << "Destructing..." << endl;
    }
    int getInt() { return *xptr; }
private:
    int *xptr;
};
//����ֵΪIntNum�����
IntNum getNum()
{
    IntNum a(3);
    return a;
}
int main()
{
    cout << getNum().getInt() << endl;
    return 0;
}

// ���ƿ������ƶ�����
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<stdexcept>
//#include<iostream>
//
//using namespace std;
//
//class A
//{
//public :
//    A() : _n(0), _p(nullptr) { }
//    explicit A(int n) : _n(n), _p(new int[n + 1]) { }
//    A(int n, int *p) : _n(n), _p(p) { }
//    // ����ͬʱ�ṩ�����������ƶ�����汾��ǰ��ʹ�ó���ֵ����
//    // �����޸�Ŀ�����ݶ����ֵ������������޸�
//    A(const A & that);// ���س����汾���������
//    A(A && that); // ���طǳ����汾���ƶ���������
//    A & operator = (const A & that);// ���س����汾�������ֵ����
//    A & operator = (A && that);//���طǳ����汾���ƶ���ֵ����
//    virtual ~A() { if(_p) { delete[] _p, _p = nullptr;} }
//public :
//    int &operator[](int i)/* throw(out_of_range)*/;
//    const int & operator[](int i)const/* throw(out_of_range)*/;
//private :
//    int _n;
//    int *_p;
//};
//A :: A(const A & that)
//{
//    this -> _n = that._n;
//    _p = new int[_n];
//    for(int i = 0; i < _n; i ++) _p[i] = that._p[i];
//}
//A :: A(A && that)
//{
//    // nullptr: C++11Ԥ����Ŀ�ָ�����͵ĳ�����
//    // ����ʽת��Ϊ����ָ�����ͺ�bool���ͣ�������ת��Ϊ�������ͣ���ȡ��NULL
//    _n = that._n, _p = that._p, that._n = 0, that._p = nullptr;
//    // *this = that;// �˴��벻������������صĸ�ֵ����������
//    // ������ֵ����that�ں����ڲ���������ֵ��������ֵ
//    // ������ֵ���òŻᱻ������ֵ����������ˡ�����
//    // *this = static_cast<A && >(that);// �ȼ��� *this = std :: move(that);
//    // ��һ�д�����Ե�����������ص��ƶ���ֵ�������������п��ܵ��³������
//    // ��this ָ��ı�������ܸոշ����ڴ棬_p�ֶ���ָ���Ŀ�����ݶ����޶���
//}
//A & A :: operator = (const A & that)
//{
//    this -> _n = that._n;
//    if(_p) delete[] _p;// ɾ�����д�����ܻᵼ���ڴ�й¶
//    // ���Բ����Ƿ�Ϊͬһ���� �Ա��������Ʋ����������岻̫
//    _p = new int[_n];
//    for(int i = 0;i < _n; i ++) _p[i] = that._p[i];
//    return *this;
//}
//A & A :: operator = (A && that)
//{
//    if(_p) delete[] _p;// ɾ�����д�����ܻᵼ���ڴ�й¶
//    // ���Բ����Ƿ�Ϊͬһ���� �Ա��������Ʋ����������岻̫
//    _n = that._n, _p = that._p, that._n = 0, that._p = nullptr;
//    return *this;
//}
//int & A :: operator[](int index)
//{
//    if(index < 0 || index > 4)
//        throw out_of_range("Index is out of range!");
//    return _p[index];
//}
//const int & A :: operator[](int index) const
//{
//    if(index < 0 || index > 4)
//        throw out_of_range("Index is out of range!");
//    return _p[index];
//}
//int main()
//{
//    A a(4);
//    for(int i = 0; i < 4; i ++)
//        a[i] = i + 1;
//    A b(a); // ���ÿ�������汾
//    b = a; // ������ͨ��ֵ�汾
//
//    // ����ֵ����ת��Ϊ��ֵ���ã�����������ֵ�汾
//    A c(static_cast< A && >(a));// �����ƶ�����汾
//    c = static_cast< A && >(a);// �����ƶ���ֵ�汾
//
//    A a1; // ȱʡ����
//    const A a2; // ȱʡ����
//
//    A a3(a1);  // ����A :: A(A & ), �ƶ�����
//    A a4(a2); // ����A :: A(const A &), �������
//
//    // ���ڷǳ���������ת��Ϊ�������ܽ������
//    A a5(const_cast<const A & >(a1)); // ����A :: A(const int &)
//
//    A a6, a7, a8; // ȱʡ����
//    a6 = a1; // ����A :: operator = (A &), �ƶ���ֵ
//    a7 = a2; // ����A :: operator = (const A & ),�����ֵ
//    a8 = const_cast<const A & >(a1); // ����A :: operator = (const A &)
//
//    return 0;
//}
