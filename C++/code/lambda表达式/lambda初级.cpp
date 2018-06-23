#include <typeinfo>
#include <iostream>

using namespace std;

// ���������������
int main()
{
    auto fun = []{ cout << "hello, world!" << endl; }; // ����ָ��
    fun(); // ����
    cout << typeid(fun).name() << endl;

    cout << "----------" << endl;
    [] { cout << "hello, world!" << endl; }(); // ����lambda��ʾʽ
    // ()���������ǵ���

    cout << "----------" << endl;
    // {  }�����壬ִ��
    [] { cout << "hello, world, ", cout << "maomaoyu!" << endl; }();

    // ()�����б�{}�����壬()����
    cout << "----------" << endl;
    [](const char * str){ cout << str << endl; }("maomaoyu");

    cout << "----------" << endl;
    auto f = [](char * str){ cout << str << endl; };
    f("Lee");// �����࣬
    cout << typeid(f).name() << endl; // class <lambda_8fcff5e887e1a3c06bf0d6c40e66b8c>

    //! cout << f << endl; // lambda���ʽ������ֱ��ȡ��ַ���޷���������ָ��

    cout << "---------" << endl;
    // -> ��(){}֮��ָ������ֵ����
    auto f1 = [](double a, double b) -> int { return a + b; };
    cout << f1(10, 19.1) << endl;
    // ����չ�����޷�ȡ����ַ

    cout << "---------" << endl;
    // -> decltype(a + b) ��������
    auto f2 = [](double a, int b) -> decltype(a + b) { return a + b; };
    cout << f2(10.1, 10) << endl;

    // []
    int num = 100;
    auto f3 = [](int num){num = 5; cout << num << endl; };
    f3(num); // ��ѭ��������
    cout << "main = " << num << endl;

    return 0;
}
