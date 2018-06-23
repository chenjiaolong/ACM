#include <iostream>
#include <functional>

using namespace std;
// 变量，左值引用，右值引用，原则不能冲突
// ref 变量 -> 左值引用
// move 左值引用 -> 右值引用

// 模板自带引用，无论&，&&都是原本
// T t, ref都是原本，否则都是副本

template<typename T>
void print1(T t)
{
    t += 1;
    cout << "void print1(T t)" << t << endl;
}
template<typename T>
void print2(T & t) // ref
{
    t += 1;
    cout << "void print2(T & t)" << t << endl;
}
template<typename T>
void print3(T && t) // move
{
    t += 1;
    cout << "void print3(T && t)" << t << endl;
}
void printint(int && t)
{
    cout << t << endl;
}
int main()
{
    int data1 = 100;
    int &rdata1(data1);
    int && rrdata1(data1 + 1);
    print1(data1); // 副本
    cout << "data1 = " << data1 << endl;

    print1(ref(data1)); // 原本引用包装器，包装变量或者引用
    cout << "ref(data1) = " << data1 << endl;

    print1(rdata1); // 模板并不能识别变量的引用，副本
    cout << "rdata1 = " << rdata1 << endl;

    print1(rrdata1); // 右值引用内存保存的临时值， 副本
    cout << "rrdata1 = " << rrdata1 << endl;

    print1(ref(rrdata1)); // 右值引用内存保存的临时值， 副本
    cout << "ref(data1) = " << rrdata1 << endl;

    cout << "------------" << endl;
    int data2 = 100;
    int &rdata2(data2);
    int && rrdata2(data2 + 1);
    // print2(data2); // 原本，模板自带引用
    // print2(rdata2);
    print2(rrdata2);
    cout << "data2 = " << data2 << endl;
    cout << "rdata2 = " << rdata2 << endl;
    cout << "rrdata2 = " << rrdata2 << endl;

    cout << "------------" << endl;
    int data3 = 100;
    int &rdata3(data3);
    int && rrdata3(data3 + 1);
    // print3(data3); // 原本，模板自带引用
    // print3(rdata3);
    print3(rrdata3);
    cout << "data3 = " << data3 << endl;
    cout << "rdata3 = " << rdata3 << endl;
    cout << "rrdata3 = " << rrdata3 << endl;

    cout << "------------" << endl;
    int num = 10;
    int & rnum(num);
    //! printint(num);
    printint(move(num)); // 移动语义， 数据，左值引用转换右值引用
    printint(move(rnum));
    printint(rnum  + 1);

    return 0;
}
