#include <limits>
#include <iostream>

using namespace std;

int main()
{
    // ����һ���ĺ���min()
    cout << numeric_limits<int > :: max() << endl;
    cout << numeric_limits<int > :: min() << endl;
    cout << numeric_limits<int > :: lowest() << endl;
    cout << numeric_limits<unsigned int > :: max() << endl;
    cout << numeric_limits<unsigned int > :: min() << endl;


    cout << numeric_limits<double > :: max() << endl;
    cout << numeric_limits<double > :: min() << endl; // �ܱ�ʾ��С���ȵ���
    cout << numeric_limits<double > :: lowest() << endl; // �ܱ�ʾ��С����

    return 0;
}
