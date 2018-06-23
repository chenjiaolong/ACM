#include <iomanip>
#include <iostream>

using namespace std;

// 改变指针，需要二级指针

int num1 = 10;
int num2 = 20;

void change(int * &rp) // C++能用引用，就不用指针
{
	rp = &num2;
}

int data1 = 10;
int data2 = 20;
int *pd = &data1;
void changeit(int ** &rpp) // 引用
{
    *rpp = &data2;
}

int main()
{
    int a(4); // 初始化为4
    int *p(new int(5));
    cout << a << endl;
    cout << *p << endl;

    int &ra(a); // 引用变量
    int * &rp(p); // 引用一级指针
    ra = 3;
    *rp = 12;
    cout << a << endl;
    cout << *p << endl;

    cout << "----------" << endl;
    int && rra(move(a)); // 右值引用，有内存实体，就直接引用，没有开辟内存
    int * &&rrp(move(p));
    rra = 1;
    *rrp = 3;
    cout << a << endl;
    cout << *p << endl;

	// int &  // 引用整数，本质是指针
	// int && // 引用整数，本质是指针，处理左值（move）右值
	// int 整数类型


	cout << "----------" << endl;
	int *p2 = &num1;
	change(p2);
	cout << *p2 << endl;

	int *p3(nullptr);
	// int **pp(&p3);
	int (**pp)(&p3);
	// int **rpp = pp;
	// int **&rpp(pp); // C++14 支持
	int (** (&rpp) )(pp); // VS2013d的C++11 bug

	// int * &rp2(p); // 引用指针 VS2015
	int (* (& rp2) )(p); // VS2013的C++11 bug

	cout << "----------" << endl;
	int **pp2 = &pd; // 二级指针
	cout << **pp2 << endl;
	changeit(pp2);
	cout << **pp2 << endl;


    return 0;
}
