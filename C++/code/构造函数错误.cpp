#include <string>
#include <cstring>
#include <iostream>

using namespace std;

// union�ڲ�������Զ�����࣬���Լ��Ĺ��캯����unionԭ���Ĺ��캯�������������ᱻɾ���������Լ�ʵ��
union U
{
    string str; // string��һ���࣬�Լ��й��캯��
    int a;
    int b;
};

union Union
{
    string str;
    int a;
    int b;
    Union()
    {
        new(&str)string; // ����string���캯��
    }
    ~Union()
    {
        str.~basic_string(); // ����
    }
};

struct node
{
    string str;
    int a;
    int b;
};
// ��ʼ�����ݵ�ʱ������������������࣬��д���캯��
struct Node
{
    int x, y;
    Node(int a, int b) : x(a), y(b){  }
};
class Per
{
    string str;
    int a;
    int b;
};

int main()
{
    //! U u;
    node p;
    Per o;
    Union u;

    Node *ptr = new Node[3]{{1, 2}, {2, 3}, {3, 4}};
    for(int i = 0; i < 3; i ++)
        cout << ptr[i].x << " " << ptr[i].y << endl;

    return 0;
}
