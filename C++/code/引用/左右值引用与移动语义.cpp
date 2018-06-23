#include <iostream>

using namespace std;
// C++能用引用的情况，别用指针
void change(int &rnum) // 变量名的别名
{
    rnum = 111;
}

void showit(int &&rrnum)
{
    cout << rrnum << endl;
}
void showitt(int &rnum)
{
    cout << (rnum += 1)<< endl;
}
int main()
{
    int num = 10; // num 左值，内存实体
    int &rnum(num); // 变量的别名
    rnum = 1; // rnum 等价于num的别名
    cout << num << endl;
    change(num);
    cout << num << endl;

    cout << "---------" << endl;
    int num2 = 1;
    int data = 0;
    cout << (void *)&data << endl;
    data = num2 + 1;
    data = num2 + 2;
    data = num2 + 3;

    cout << "--------" << endl;
    int num3 = 1;
    // num3 + 4 寄存器中，不是内存
    int && rnum2(num3 + 4); //右值引用，快速备份。编译器，自动回收
    printf("%x\n", &rnum2);

    int data2 = num3 + 4;
    int &rdata(data2); // 左值引用


    cout << "--------" << endl;
    int a[5]{1, 2, 3, 4, 5};
    int *p(a);
    cout << *p << endl;
    // int a -> int &ra; & 放在类型与变量名之间
    // int *p -> int * &rp;
    int * & rp(p); // 左值引用改变指针
    rp += 1;
    cout << *p << endl;

    // int * && rrp(p + 2); // 右值引用, &&
    int * && rrp(&a[1]);
    rrp += 2;
    cout << *rrp << endl;

    cout << "--------" << endl;
    showit(a[3] + 2); // 节约内存
    showit(move(a[3])); // move移动语义，左值变成右值

    showitt(a[3]); // 左值引用
    showitt(a[3]);
    return 0;
}
