#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;
// ��̬����û��thisָ�룬�޷����ó�Ա������Ա����

struct runit
{
    static vector<runit *> all;
    int a, b;
    runit(int x, int y) : a(x), b(y)
    {
        all.push_back(this); // ÿ�ι��죬ѹ���ַ
    }
    void show()
    {
        cout << a << " " << b << endl;
    }
    static void showall() // ��Ͼ�̬��Ա�����������������������
    {
        for(auto i : all)
            cout << (*i).a << " " << (*i).b << endl;
    }
};

vector<runit *>runit :: all;

int main()
{
    runit run1(1, 1);
    runit run2(1, 2);
    runit run3(1, 3);
    run1.show();
    run2.show();
    run3.show();
    runit :: showall();
    return 0;
}
