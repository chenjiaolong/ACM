#include <iostream>

// using, ����ʡ��std
// �ƶ������ռ�
// ԭ���ֹʹ��using namespace std; // ��ȷ�ռ�

namespace maomaoyu = std;// ����׼���������Ƽ�
// CPP���������ã���ֹ�ı��׼

namespace stdrun
{
    int num = 101;
    void show()
    {
        std :: cout << num << std :: endl;
    }
}

namespace mmy = stdrun; // ���Զ���ı���

int main()
{
    maomaoyu :: cout << "hello" << maomaoyu :: endl;
    mmy :: show();
    return 0;
}
