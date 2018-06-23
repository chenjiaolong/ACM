#include <iostream>

using namespace std;

void show(const int &rint) // 明确只读不写
{

}
void show(int &rint) // 可读可写
{

}
int main()
{
    int num(100);
    // int const &rnum(num); // 让别人引用，限定权限
    // const int &rnum(num);
    //! rnum = 3;

    // not surport!!
    // int & const rnum(num); // 使用了记时错误：忽略引用上的限定符
    // rnum = 3;
    cout << num << endl;

    cout << "---------" << endl;
    int a[5]{1, 2, 3, 4, 5};
    const int(&ra)[5](a);
    for(auto &i : ra)
    {
        // i += 1;
        cout << i << endl;
    }

    cout << "---------" << endl;
    const int *p(new int(5)); // 指针，只向常量
    // int (* (&rp) )(p);
    const int (* (&rp) )(p); // 引用一个指向常量的指针
    // *rp = 3;
    cout << *p << endl;

    cout << "---------" << endl;
    int * const p2(new int(4));
    *p2 = 1;
    int (* const (&rp2) )(p2); // 引用一个常量指针
    *rp2 = 2;

    const int * const p3(new int(4));
    const int (* const (&rp3) )(p3);// 引用一个指向常量的常量指针

    int *p4(new int(4));
    const int (* (&rp4) )((const int * &)p4); // 引用
    //! *rp = 3;
    cout << *rp4 << endl;
    return 0;
}
