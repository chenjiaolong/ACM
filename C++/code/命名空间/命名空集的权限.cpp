#include <iostream>

using namespace std;

// �����ռ�û��˽�У�ȫ�ֱ��������������ж����Է���
namespace data
{
    int num;
    void show()
    {
        cout << num << endl;
    }
}

using namespace data; // ʹ�������ռ䣬ֱ�ӷ��ʵ���ȫ�ֱ���

// �ڲ㸲�����
namespace dataX
{
    int num = 100;
    namespace run
    {
        int num = 10;
        void show()
        {
            // cout << num << endl;

            // :: num ֱ��ȫ�ֱ�����ȫ�ֱ��������ھ���0
            // cout << :: num << endl;

            cout << dataX :: num << endl;
        }
    }

}

using namespace dataX; // ʹ�������ռ�����ڶ���֮��

int main()
{
    data :: num = 15;
    show();
    dataX :: run :: show();
    run :: show();
    return 0;
}
