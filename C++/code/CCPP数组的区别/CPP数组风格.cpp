#include <iostream>

using namespace std;

int main()
{
    // C int a[5] = {1, 2, 3, 4, 5};
    // CPP
    int a[5]{1, 2, 3, 4, 5};
    for(auto i : a)
        cout << i << endl;

    cout << "----------" << endl;
    int *p1 = new int[5]{1, 2, 3, 4, 5};// malloc.new�����ڴ沢��ʼ�� -> ��(����)
    for(int i = 0; i < 5; i ++)
        cout << *(p1 + i) << endl; // cout << p1[i] << endl;

    cout << "----------" << endl;
    int *p2(new int[5]{1, 2, 3, 4, 5}); // CPP����ʽд��
    for(int i = 0; i < 5; i ++)
        cout << p2[i] << endl;
    return 0;
}
