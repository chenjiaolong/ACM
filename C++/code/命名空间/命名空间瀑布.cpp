#include <iostream>

using namespace std;

// һ��������������������ռ��⣬�����ռ��ڷ�����
namespace data
{
    int a;
    int b;
    int add(int a, int b);
}
int data :: add(int a, int b)
{
    return a + b;
}
namespace data
{
    int sub(int a, int b);
}
int data :: sub(int a, int b)
{
    return a - b;
}
using namespace data;
int main()
{
    int num = add(10, 29);
    cout << num << endl;
    int num2 = data :: add(19, 20);
    cout << num2 << endl;
    int num3 = data :: sub(20, 10);
    cout << num3 << endl;
    return 0;
}
