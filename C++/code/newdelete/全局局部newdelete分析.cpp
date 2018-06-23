#include <cstdlib>
#include <iostream>

using namespace std;

// C++ C ���Բ�
// C���Բ�����ڴ棬����malloc free
// ȫ��new �ֲ�new ���ᱻ����һ�ι��캯��
// �����ڴ棬�ȵ��þֲ������ù���
// �ֲ��������ڹ��������ȫ�ֹ��������������
// �ֲ�new -> ȫ��new -> malloc -> ���� , �ֲ���new -> malloc -> ����
// ���� -> �ֲ�delete -> ȫ��delete -> free�� ���� -> �ֲ�delete -> free

void * mymalloc(size_t size)
{
    cout << "malloc call" << endl;
    return malloc(size);
}
void myfree(void *p)
{
    cout << "free call" << endl;
    free(p);
}

#define malloc mymalloc
#define free myfree

// new ���۾ֲ�����ȫ�ֶ������һ�ι���

void * operator new(size_t size)
{
    cout << "g_all new" << endl;
    void *p(malloc(size));
    return p;
}
void operator delete (void *p)
{
    cout << "g_all delete" << endl;
    free(p);
}

class myclass
{
public :
    myclass()
    {
        cout << "myclass()" << endl;
    }
    ~myclass()
    {
        cout << "~myclass()" << endl;
    }
    void * operator new(size_t size)
    {
        cout << "myclass new" << endl;
        // myclass *p(:: new myclass);
        void *p(malloc(size));
        return p;
    }
    void operator delete (void *p)
    {
        cout << "myclass delete" << endl;
        // :: delete p;
        free(p);
    }

};

int main()
{
//    int *p1(new int(5));
//    int *p2{new int[5]{1, 2, 3, 4, 5}};
    // new delete�����Ǻ�����C++��׼�⺯������д

    // ���þֲ�����дnew delete��ʵ�־���ķ��������ٵ��������͹���
    myclass *p(new myclass);
    delete p;

    // ����ȫ��
//    myclass *p( :: new myclass);
//    :: delete p;

    return 0;
}
