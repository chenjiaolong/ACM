#include <iostream>

namespace run1
{
    int x = 10;
}
namespace run2
{
    int x = 10;
    void show()
    {
        std :: cout << x << std :: endl;
    }
}

void run()
{
    using namespace std; // ��ͬ�ھֲ�����
    cout << "hello world" << endl;
    using namespace run1;
    using namespace run2;
    // cout << x << endl;
}

int main()
{
    run();
    std :: cout << "hello ëë��" << std :: endl;
    // using namespace run2;
    using run2 :: x;
    std :: cout << x << std :: endl;
    using run2 :: show; // �������������ռ�������ߺ���
    show();
    return 0;
}
