// Ԫ���
// ʲôԪ���(metaprogramming)?
// ����ģ����Խ��б����ڼ��㣨��ֵ���㡢��ʽ���㡢������㣩���ص���г������
//
// Ϊʲô���Խ���Ԫ��̣�
// C++���������ԣ�ִ�б����ڼ���Ĵ����Ϊ��̬���룬ִ�������ڼ���Ĵ����Ϊ��̬����
// ģ������ں���ʽ��̣�functional programming��:ǿ��������㣬����ģ�廯��ʹ�õݹ��������
// ģ��ʱͼ���걸�ģ������ϣ�ģ�����ִ���κμ�������
//
// Ϊʲô��ҪԪ��̣�
// �����ڼ������ʹ�����ͨ�ã������ã���������ִ������
//
// Ԫ��̵�ȱ��
// ��Խṹ����̣�����Ч�ʼ���
// �����ª�������Ķ��ѡ������ѡ�ά���ѣ��׵��´�������
//
// Ԫ��̿�����ʲô��
// ��ֵ���м��㡢�����жϡ����ƽṹ��ѭ��չ������ʽ�ж������ʽ�������ڶ�̬�����������ԡ���ǩ��Ԫ������.����
// ע���Բ���ϵͳ��̶��ԣ�Ԫ������岻��
//#include<iostream>
//
//using namespace std;
//��ģ�壬����Fibonacci���еĵ�i��
//template<int i = 1>class Fibonacci
//{
//public:
//    enum{value = Fibonacci<i - 1> :: value + Fibonacci<i - 2> :: value};
//};
// ��ģ���ػ����ݹ���ֹ����
//template<> class Fibonacci<2> { public: enum{ value = 1}; };
//template<> class Fibonacci<1> { public: enum{ value = 1}; };
//
//int main()
//{
//    cout << "Fib(" << 1 << ") = " << Fibonacci<1> :: value << endl;
//    cout << "Fib(" << 2 << ") = " << Fibonacci<2> :: value << endl;
//    cout << "Fib(" << 3 << ") = " << Fibonacci<3> :: value << endl;
//    cout << "Fib(" << 4 << ") = " << Fibonacci<4> :: value << endl;
//    return 0;
//}

// ����ö��
#include<iostream>
#include<iomanip>

using namespace std;

// �ݹ����p�Ƿ�Ϊ����;���ǣ������ж�����answerΪ1������Ϊ0
template<int p, int i> struct PrimeMagicCube
{
    enum {answer = p % i && PrimeMagicCube<p, i - 1> :: answer};
};
// ����ħ����ģ�岿���ػ����ݹ���ֹ����������Ϊ1��û���ҵ�����
template<int p> struct PrimeMagicCube<p, 1> {enum { answer = 1 }; };

// ��ֵ��ģ�壬���������i��ȫ������
template<int i> struct Number
{
    Number<i - 1> a; // �ݹ鶨����ֵ����
    enum{ answer = PrimeMagicCube<i, i - 1> :: answer };
    void IsPrime()
    {
        // �Ƚ������ȫ�����������������ȫ����ֵ��������
        if(answer) cout << setw(4) << right << i;
        a.IsPrime(); // �ݹ���ã�������һ����ֵ������
        cout << setw(2) << answer;
    }
};
// ��ֵ��ģ���ػ�����ֹ��2
template<> struct Number<2>
{
    enum { answer = 1};
    void IsPrime()
    {
        cout << setw(4) << right << 2 << endl;
        cout << setw(2) << answer;
    }
};
int main()
{
    Number<100> a;
    a.IsPrime();
    cout << endl;
    return 0;
}
