#include <iomanip>
#include <iostream>

using namespace std;

// �ı�ָ�룬��Ҫ����ָ��

int num1 = 10;
int num2 = 20;

void change(int * &rp) // C++�������ã��Ͳ���ָ��
{
	rp = &num2;
}

int data1 = 10;
int data2 = 20;
int *pd = &data1;
void changeit(int ** &rpp) // ����
{
    *rpp = &data2;
}

int main()
{
    int a(4); // ��ʼ��Ϊ4
    int *p(new int(5));
    cout << a << endl;
    cout << *p << endl;

    int &ra(a); // ���ñ���
    int * &rp(p); // ����һ��ָ��
    ra = 3;
    *rp = 12;
    cout << a << endl;
    cout << *p << endl;

    cout << "----------" << endl;
    int && rra(move(a)); // ��ֵ���ã����ڴ�ʵ�壬��ֱ�����ã�û�п����ڴ�
    int * &&rrp(move(p));
    rra = 1;
    *rrp = 3;
    cout << a << endl;
    cout << *p << endl;

	// int &  // ����������������ָ��
	// int && // ����������������ָ�룬������ֵ��move����ֵ
	// int ��������


	cout << "----------" << endl;
	int *p2 = &num1;
	change(p2);
	cout << *p2 << endl;

	int *p3(nullptr);
	// int **pp(&p3);
	int (**pp)(&p3);
	// int **rpp = pp;
	// int **&rpp(pp); // C++14 ֧��
	int (** (&rpp) )(pp); // VS2013d��C++11 bug

	// int * &rp2(p); // ����ָ�� VS2015
	int (* (& rp2) )(p); // VS2013��C++11 bug

	cout << "----------" << endl;
	int **pp2 = &pd; // ����ָ��
	cout << **pp2 << endl;
	changeit(pp2);
	cout << **pp2 << endl;


    return 0;
}
