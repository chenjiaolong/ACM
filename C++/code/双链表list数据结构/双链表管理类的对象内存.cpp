#include <list>
#include <cstdlib>
#include <windows.h>
#include <iostream>

using namespace std;

class myclass; // �������

// �࣬�����ǹ���ģ�������ÿ������˽�еģ�
// ��ָ�룬���ó�Ա�������������ݣ����Ե��ã��������ݲ�����

// �������ǹ����
struct info
{
    myclass *p; // ָ�룬�ڴ���׵�ַ
    int n; // ������ٸ�����
};
list<info> myclasslist; // ˫�������ݽṹ������һ��������ж���
struct classinfo
{
    myclass *p;
    int n;
    char name[10]; // �������
};
list<list<classinfo>> myclassList; // ����������ڴ�

void showmem()
{
    // ��ʾ�ڴ�
    for(auto i : myclasslist) cout << "�ڴ��ַ��" << i.p << "������" << i.n << endl;
}

class myclass
{
public :
    int i = 0;
    void show()
    {
        //! i = 0;
        MessageBoxA(0, "content", "title", 0);
    }
    myclass() { cout << "myclass()" << endl; }
    ~myclass() { cout << "~myclass()" << endl; }
    void * operator new(size_t size)
    {
        cout << "new " << size << endl;
        void *p(malloc(size)); // ���Ԫ��
        if(p != nullptr)
        {
            info infonow;
            infonow.p = (myclass *)p; // �����˾ͼ�¼һ��
            // infonow.n = 1; // ��¼��ַ�����
            if(size / sizeof(myclass) == 1)
                infonow.n = 1;
            else infonow.n = (size - sizeof(myclass *)) / sizeof(myclass);
            myclasslist.push_back(infonow);
            return p;
        }
        return nullptr;
    }
    void * operator new[](size_t size)
    {
        cout << "new [] " << size << endl;
        return operator new(size); // �ص���new
    }
    void operator delete(void *p)
    {
        // ˫�����м����ڴ棬���ھ�ɾ���������ڣ�����
        for(auto ib = myclasslist.begin(), ie = myclasslist.end(); ib != ie; ib ++)
        {
            if(p == (*ib).p)
            {
                myclasslist.erase(ib); // ɾ��
                free(p);
                break;
            }
        }
    }
    void operator delete[] (void *p)
    {
        operator delete(p); // �ص���delete
    }
};

void callallobject()
{
    for(auto i : myclasslist)
    {
        if(i.n == 1) i.p -> show();
        // ��������ĵ�һ����ַ��������
        else for(int j = 0; j < i.n; j ++) i.p[j + 1].show(); // ������ͷ
    }
}

int main()
{
    myclass *p(nullptr);
    p -> show();

    cout << "--------" << endl;
    myclass *p1(new myclass);
    myclass *p2(new myclass);
    myclass *p3(new myclass);
    myclass *p4(new myclass);
    delete p1;
    delete p1;
    showmem();

    delete p2;
    showmem();

    cout << "--------" << endl;
    myclass *pa1{ new myclass[5] };
    myclass *pa2{ new myclass[10] };
    myclass *pa3{ new myclass[15] };
    delete[] pa2;
    delete[] pa3;
    showmem();
    callallobject();

    return 0;
}
