// ��ͨ���캯��ʵ��
//#include<iostream>
//
//using namespace std;
//
//class A
//{
//public :
//    A(const string &s, const string &t) : _s(s), _t(t) { cout << 1 << endl; }
//    A(const string &s, string &&t) : _s(s), _t(move(t)) { cout << 2 << endl; }
//    A(string &&s, const string &t) : _s(move(s)), _t(t) { cout << 3 << endl; }
//    A(string &&s, string &&t) : _s(move(s)), _t(move(t)){ cout << 4 << endl; }
//private :
//    string _s, _t;
//};
//
//int main()
//{
//    string s1("Hello");
//    const string s2("World");
//    A a1(s1, s2);
//    A a2(s1, string("Bingo"));
//    A a3(string("Good"), s2);
//    A a4(string("Good"), string("Bingo"));
//    return 0;
//}

//����ת��
//����ת��������
//����������Ҫ���һ��ͨ�ú����������յ��Ĳ���ת������������
//ת�������У����в�������ԭ�����岻��
//����ת����ʵ�ֲ���
//����Ҫͬʱ�ṩ�ƶ������뿽������ʱ��Ҫ�����ش���������������̹������޴��׳���
//��ֵ�����ں���ģ�廥����ϣ�����ʵ������ת�������󽵵ʹ����д��

#include<iostream>

using namespace std;
class A
{
public :
    // ����ʵ�ʲ�����ʽ���ɲ�ͬ����ֵ����ֵ���������������汾
    // T1��T2������Ϊ��ͬ�ͣ��˴���ͬ��Ϊʾ��
    // ʵ������ʱ��ʹ�������۵�����
    // ����ʽ����ΪT&&��ʱ�����ҽ���ʵ�ʲ���Ϊ��ֵ����ֵ����ʱ��
    // ʵ�ʲ�����ʽ��Ϊ��ֵ����
    // �����۵�������const/volatile�޹أ�������������ʲ���
    // std :: forward<T>(t) ת����������ֵ����T &&
    template<typename T1, typename T2> A(T1 &&s, T2 &&t)
    : _s(std :: forward<T1>(s)), _t(std :: forward<T2>(t)) {  }
private :
    std :: string _s, _t;
};

int main()
{
    string s1("Hello");
    const string s2("World");
    A a1(s1, s2);
    A a2(s1, string("Bingo"));
    A a3(string("Good"), s2);
    A a4(string("Good"), string("Bingo"));
    return 0;
}