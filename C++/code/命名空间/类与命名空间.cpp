#include <iostream>

using namespace std;

// structӵ��class�����й���
// std��չ��׼�����ռ�
// �������Ϳ��Է��������ռ䣬�����������ͳ�ͻ
namespace stdfun
{
    class data
    {
        int a;
        int b;
        int getadd()
        {
            return a + b;
        }
        int getsub();
    };
    void run();
}

namespace stdfun
{
	void run()
	{
		cout << "run" << endl; // �ռ���չ
	}
	int getsub();
}
// �����ռ� :: ���� :: ������
int stdfun :: data :: getsub()
{
    return a - b;
}
int main()
{
    stdfun :: data data1;
    data1.a = 11; // ���ʱ��������÷���
    data1.b = 21;
    cout << data1.getadd() << endl;
    cout << data1.getsub() << endl;
    return 0;
}
