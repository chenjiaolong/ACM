#include <iostream>

using namespace std;

int main()
{
//    const int n = 10;
//    int a[n]; // C++ �������Զ��Ż��� n�滻10
//    cout << sizeof(a) << endl;

    int a = 10;
    const int n = a;
    cout << n << endl;
    //! int data[n]; // C++�������������Ż������Ǳ��������仯

    const int num = 10;
    *(int *)(&num) = 3;
    cout << (void *)&num << endl;

    // cout << *(int *)(&num) << endl;
    cout << *(&num) << endl;// �Ż���ǿ���滻10
    cout << num << endl;

    const int num2 = a;
    *(int *)(&num2) = 3;
    cout << (void *)&num2 << endl;

    // cout << *(int *)(&num2) << endl;
    cout << *(&num2) << endl;// ֱ�Ӷ��ڴ棬�����Ż�
    cout << num2 << endl;

    return 0;
}
