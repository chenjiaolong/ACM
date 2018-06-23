#include <limits>
#include <iostream>

using namespace std;

int main()
{
    // 整数一样的含义min()
    cout << numeric_limits<int > :: max() << endl;
    cout << numeric_limits<int > :: min() << endl;
    cout << numeric_limits<int > :: lowest() << endl;
    cout << numeric_limits<unsigned int > :: max() << endl;
    cout << numeric_limits<unsigned int > :: min() << endl;


    cout << numeric_limits<double > :: max() << endl;
    cout << numeric_limits<double > :: min() << endl; // 能表示最小精度的数
    cout << numeric_limits<double > :: lowest() << endl; // 能表示最小的数

    return 0;
}
