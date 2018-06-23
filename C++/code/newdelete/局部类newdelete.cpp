#include <iostream>

using namespace std;

int objs = 0;
void *g_p = nullptr;

class myclass
{
public :
    myclass() { cout << "create" << endl; }
    ~myclass() { cout << "delete" << endl; }
    // operator���أ����new ��������һ�ֽ��ͣ�ֻ��Ե�ǰ��
    static void * operator new (size_t size)
    {
        if(g_p == nullptr)
        {
            objs ++;
            cout << "new call" << endl;
            // return nullptr;
            myclass *p = :: new myclass;
            g_p = p; // ����ģʽ
            return p;
        }
        return g_p;
    }
    static void operator delete (void *p)
    {
        if(g_p == nullptr) return ;
        objs --;
        cout << "delete call" << endl;
        :: delete p;
        g_p = nullptr;
    }
};

// ��һ�����ܣ��޷��ڶ��ϱ���������
// ʵ��ͳ�Ʒ����ڴ棬�ͷ��ڴ�Ĵ���
// ʵ�ֵ������ģʽ��ʵ�ֱ��ⷴ��delete����
// new delete ���ڲ���ֻ��Ե�ǰ�࣬int double �Ȼ�������������Ӱ��
int main()
{
    myclass *p1 = new myclass;
    myclass *p2 = new myclass;
    myclass *p3 = new myclass;
    delete p1;
    delete p1;
    cout << objs << endl;
    delete p2;
    delete p3;

    int *p = new int;
    delete p;

    return 0;
}
