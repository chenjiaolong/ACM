#include <iostream>

using namespace std;

int num = 10;

namespace data
{
    int num = 100;
    int numx = 10;
}

// 和局部变量发生冲突
int main()
{
    int numx = 5;
    using namespace data;
    cout << numx << endl;// 局部变量覆盖命名空间
    return 0;
}


// 和全局变量冲突
//int main()
//{
//    using namespace data;// 注意冲突
//    cout << :: num << endl;
//    cout << data :: num << endl;
//    return 0;
//}
