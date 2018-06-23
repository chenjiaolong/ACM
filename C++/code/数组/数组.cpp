#include <iostream>

using namespace std;

// CPP 数组，for(auto i : a) begin, end
// 可以通过begin，end获取开始地址，结束地址
int main()
{
    int arr[3][4];
    // CPP 只处理一维数组，vector<vector<int>>;
    const char str[100] = "hello, world!";
    const char *p1 = begin(str); // 首元素地址
    const char *p2 = end(str); // 末尾结束地址
    for(auto ib = begin(str), ie = end(str); ib != ie; ib ++)
        cout << *ib;
    puts("SSS");

    int a[5]{1, 2, 3, 4, 5};
    int *p3 = begin(a);
    int *p4 = end(a);
    for(int i = 0; i < 5; i ++)
        cout << a + i << endl;
    cout << "p3 = " << p3 << endl;
    cout << "p4 = " << p4 << endl;

    return 0;
}
