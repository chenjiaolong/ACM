#include <iostream>
#include <functional>

using namespace std;
// C++�ṹ�����Ϊ�գ�C������
// C++�ṹ�������Ĭ��ֵ��C������
// C++�ṹ�嶨�����������ؼ���struct
// C++�ṹ������к���
// ��������ָ�룬������lambda�����죬���������
// �ṹ��Ĭ����˽�У�Ҳ��������Ϊ˽��
// û��˽�б����ĳ�ʼ��
// ˽�У���Ҫ���캯��
// �ṹ���������ֻ�ܴ���ָ�룬����:��չ�ṹ������
// �ṹ���ڲ����Դ���ָ�������
// �����ṹ�壬�����Գ�ʼ��
struct node
{
    int num = 3;
    function<void(void)> fun = [](){  };
    //! auto fu; // �ṹ���޷�����auto
    void go()
    {

    }
};

struct nodex
{
    void (*p)() = []() {};

    /** function<void (void )>fun = [](){};
    function<void (int )>fun1 = [](int a){};
    function<void (char *)>fun2 = [](char *str){ cout << "1111111111111111111111111111111111111111" << endl;};
    */
};
struct point
{
// private :
    int x, y;
};
struct size
{
private :
    int x, y;
public :
    size() {   }
    size(int a, int b) : x(a), y(b){  }
    void show()
    {
        cout << x << " " << y << endl;
    }
};
int main()
{
    node p;
    cout << p.num << endl;

    // fun��װ��һ��ռ40��32�����ֽ�
    // ����ָ��4��8�����ֽ�
    cout << sizeof(nodex) << endl;

    point p1 {1, 2};
    //! point p1(1, 2);
    point *ptr = new point{1, 2};
    point px[2]{{1, 2}, {3, 4}};
    point *pp = new point[2]{{1, 2}, {3, 4}};

    // p1.x = p1.y = 20; // �ⲿ����
    cout << p1.x << " " << p1.y << endl;

    size s1{1, 2};
    s1.show();
    size *p3 = new size(3, 4);
    p3 -> show();
    size ss[3] {size(13, 4), size(23, 4), size(33, 4)};
    size *ps = new size[3]{size(13, 4), size(23, 4), size(33, 4)};
    return 0;
}
