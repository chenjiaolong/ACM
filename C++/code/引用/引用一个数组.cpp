#include <iostream>

using namespace std;

int main()
{
    // 栈上
    cout << "---------" <<endl;
    int a[5] {1, 2, 3, 4, 5}; // 一维数组
    int *pa[5] {a, a + 1, a + 2, a + 3, a + 4}; // 指针数组
    int (&ra)[5](a); // 引用一个数组
    for(auto & i : ra) cout << (i += 1) << endl;
    for(auto i : ra) cout << i << endl;
    int(* (&rpa)[5])(pa); // 引用一个指针数组
    for(auto i : rpa) cout << *i << endl;

    // 堆上
    cout << "---------" <<endl;
    int *p1(new int[5] {1, 2, 3, 4, 5}); // 堆上一维数组
    // int *(*pp)(nullptr);// 初始化VS2013空余一个指针
    int *(*pp)(new int *[5] {p1, p1 + 1, p1 + 2, p1 + 3, p1 + 4});
    int(* (&rp) )(p1);
    int(** (&rpp) )(pp);
    for(int i = 0; i < 5; i ++) cout << rp[i] << endl;
    for(int i = 0; i < 5; i ++) cout << *rpp[i] << endl;

    cout << "---------" <<endl;
    int b[2][3] {1, 2, 3, 4, 5, 6}; // 二维数组
    // 二维数组，每一个元素是一个指针
    int *pb[2][3] {&b[0][0], &b[0][0] + 1,
                   &b[0][0] + 2, &b[0][0] + 3,
                   &b[0][0] + 4, &b[0][0] + 5
                  };
    int (&rb)[2][3](b); // 引用二维数组
    int *( (&rpb)[2][3] )(pb); // 引用二维指针数组
    for(int i = 0; i < 2; i ++)
    {
        for(int j = 0; j < 3; j ++)
            cout << rb[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < 2; i ++)
    {
        for(int j = 0; j < 3; j ++)
            cout << *(rpb[i][j]) << " ";
        cout << endl;
    }

    // 指向数组的指针，{}包含
    cout << "---------" << endl;
    int (*p2)[4] {new int[3][4] {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}}; // 堆上二维数组

    int (* (&rp2) )[4](p2); // 引用一个行指针
    for(int i = 0; i < 3; i ++)
    {
        for(int j = 0; j < 4; j ++)
            cout << rp2[i][j] << " ";
        cout << endl;
    }

    cout << "---------"<< endl;
    // 堆上开辟二维指针数组
    int *(*pp2)[3] { new int *[2][3]{
            { &b[0][0], &b[0][0] + 1, &b[0][0] + 2},
            { &b[0][0] + 3, &b[0][0] + 4, &b[0][0] + 5}
        }
    };
    int (* (*&rpp2)[3])(pp2); // 引用二维的指针数组
    for(int i = 0; i < 2; i ++)
    {
        for(int j = 0; j < 3; j ++)
            cout << *rpp2[i][j] << " ";
        cout << endl;
    }
    return 0;
}
