#include <iostream>

using namespace std;

int num = 10;

namespace data
{
    int num = 100;
    int numx = 10;
}

// �;ֲ�����������ͻ
int main()
{
    int numx = 5;
    using namespace data;
    cout << numx << endl;// �ֲ��������������ռ�
    return 0;
}


// ��ȫ�ֱ�����ͻ
//int main()
//{
//    using namespace data;// ע���ͻ
//    cout << :: num << endl;
//    cout << data :: num << endl;
//    return 0;
//}
