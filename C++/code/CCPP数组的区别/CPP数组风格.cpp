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
    int *p1 = new int[5]{1, 2, 3, 4, 5};// malloc.new分配内存并初始化 -> 堆(对象)
    for(int i = 0; i < 5; i ++)
        cout << *(p1 + i) << endl; // cout << p1[i] << endl;

    cout << "----------" << endl;
    int *p2(new int[5]{1, 2, 3, 4, 5}); // CPP的正式写法
    for(int i = 0; i < 5; i ++)
        cout << p2[i] << endl;
    return 0;
}
