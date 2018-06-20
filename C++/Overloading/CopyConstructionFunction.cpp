#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

class Point// Point ��Ķ���
{
public :
    Point(int xx = 0, int yy = 0) { x = xx; y = yy; }    //���캯��������
    Point(const Point& p) /*= delete*/;  //ָʾ������������Ĭ�ϸ��ƹ��캯��
    Point& operator = (const Point &p);
    bool operator == (const Point &p) const
    {
        return x == p.x && y == p.y;
    }
    int getX() { return x; }
private :// ˽������
    int x, y;
};
// ��Ա������ʵ��
Point :: Point(const Point& p)
{
    x = p.x;
    y = p.y;
    cout << "Calling the copy constructor" << endl;
}
Point& Point :: operator = (const Point& p)
{
    if(*this == p) return *this;
    cout << "Assignment Copying" << endl;
    x = p.x, y = p.y;
    return *this;
}

// �β�ΪPoint �����ĺ���
void fun1(Point p)
{
    cout << p.getX() << endl;
}
// ����ֵΪPoint�����ĺ���
Point fun2()
{
    Point a(1, 1);
    return a;
}
int main()
{
    Point a; // ��һ������a
    Point b(a); // ���һ�� ��a��ʼ��b����һ�ε��ÿ������캯��
    cout << b.getX() << endl;

    fun1(b); // �����������b��Ϊfun1��ʵ�Ρ��ڶ��ε��ÿ������캯��
    puts("OK1");
    b = fun2(); // ������������ķ���ֵ������󣬺�������ʱ�� ���ÿ������캯��
    puts("OK2");
    cout << b.getX() << endl;

    // ��ֵ����
    Point c(1, 2), d(3, 4);
    cout << c.getX() << endl;
    c = d;
    cout << c.getX() << endl;

    return 0;
}

//#include<string.h>
//#include<iostream>
//
//using namespace std;
//
//class Name
//{
//    char name[20];
//public:
//    Name(){ strcpy(name, ""); cout << '?'; }
//    Name(char *fname){ strcpy(name, fname); cout << '*'; }
//};
//
//int main()
//{
//    Name names[3] = {Name("����"), Name("����")};
//    return 0;
//}
