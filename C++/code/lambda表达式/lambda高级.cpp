#include <array>
#include <iostream>
#include <algorithm>

using namespace std;

// lambda���ʽ��Ҫ�������������CPP
// []()mutable -> int {}(); // �������ʽ
// [], =ֵ����ֻ����=mutable��ԭ���ĸ�����&��дԭ��
// ()����, int a, int b
// {} ���ʵ��,()����
// -> ָ������ֵ����
// C++11��֧�ֲ���auto��C++14֧��

int main()
{
    int num1 = 100;
    int num2 = 99;
    // [=]ֻ�ܶ��ⲿ������������д
    [=](){cout << num1 << " " << num2 << endl;}();
    [&](){ num1 = 20, num2 = 90; cout << num1 << " " << num2 << endl; }();
    [=]()mutable{ num1 = 10, num2 = 20, cout << num1 << " " << num2 << endl;}();

    cout << "main = " << num1 << " " << num2 << endl;

    int a{10};
    int b{9};
    int c{8};
    // &a, b, c: a�ɶ���д��bcֻ�ܶ�
    [&a, b, c](){ a = 5, cout << a << " " << b << " " << c << endl;}();

    // a, b, c ֻ�ܶ�
    [a, b, c](){ cout << a << " " << b << " " << c << endl; }();
    [a, b, c]()mutable{ a = 1, b = 2, c = 3, cout << a << " " << b << " " << c << endl; }();

    cout << a << " " << b << " " << c << endl; // [a, b, c]() mutable�������ܶ�д������ԭ���� д�ĸ���

    // = ֻ���ƶ�ȫ��
    // [&a, = ](){cout << a << " " << b << " " << c << endl; }();

    [](auto a, auto b) { cout << a + b << endl; }(10, 11); // C++14������������
    [](auto a, auto b) { cout << a + b << endl; }(10.8, 11); // auto ������������
    [](auto a = 0, auto b = 0) { cout << a + b << endl; }(1, 1); // Ĭ�ϲ�����ʼ����=
    [](int a = 0, int b = 0){ cout << a + b << endl; }();

    array<int, 10> myint{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; // CPP��������
//    for(auto i : myint)
//        cout << i << endl;
    for_each(myint.begin(), myint.end(), [](int num) { cout << num << endl; }); // ��ʾ
    for_each(myint.begin(), myint.end(), [](int &num) { num += 1, cout << num << endl; }); // �޸�
    for_each(myint.begin(), myint.end(), [](int num) {cout << num << endl; });
    return 0;
}
