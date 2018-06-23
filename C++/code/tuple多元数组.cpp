#include <tuple>
#include <iostream>

using namespace std;
// 多元数组，存取不同的数据类型
int main()
{
    char ch = 'x';
    short sh = 12;
    int num = 1234567;
    double db = 123;
    char *p = "calc";
    tuple<char, short, int, double, char *>mytuple(ch, sh, num, db, p);
    const int i = 0;
    auto autov = get<i>(mytuple);
    cout << autov << endl;
    auto autov1 = get<1>(mytuple);
    cout << autov1 << endl;
    auto autov2 = get<2>(mytuple);
    cout << autov2 << endl;
    auto autov3 = get<3>(mytuple);
    cout << autov3 << endl;
    auto autov4 = get<4>(mytuple);
    cout << autov4 << endl;

    // for(auto i : mytuple)
        // cout << i << endl;

    return 0;
}
