#include <iostream>

using namespace std;
// ȫ���ڴ����ͳ���ͷ��ڴ棬�����ڴ�
// new  new[]  delete  delete[]
// �����ڴ������ڹ��캯��
// ���������������ͷ��ڴ�

// ���ȼ�:
// new -> ���캯��(new -> :: new -> malloc -> create)
// �������� -> delete(�������� -> delete -> :: delete -> free)

class myclass
{
public :
    myclass() { cout << "create call" << endl; }
    ~myclass() { cout << "delete call" << endl; }
};

class all
{
    char ch;
    void run(int d)
    {

    }
};

void * operator new(size_t size)
{
    cout << "g_new call" << endl;
    void *p(malloc(size));
    return p;
}
void * operator new [](size_t size)
{
    cout << size << endl; // 18 = һ��ָ��ռ8���ֽڣ�10������ռ10�ֽ�
    cout << "g_new call []" << endl;
    return operator new(size); // ÿ��Ԫ�ص���һ��new
}

void operator delete(void *p)
{
    cout << "g_delete call" << endl;
    free(p);
}
void operator delete [](void *p)
{
    cout << "g_delete call []" << endl;
    operator delete(p);
}

// sizeofͳ����Ĵ�С��ԭ�򣬲�ͳ�ƴ�����
// ����ռ1���ֽڱ�ʾ���ڣ��ȼ��ڽṹ��
int main()
{
    int *p(new int(5));
    delete p;

    cout << "--------" << endl;
    // :: new
    myclass *ptr(new myclass);
    delete ptr;

    cout << "--------" << endl;
    int *pint { new int[10] };
    delete pint;

    cout << "--------" << endl;
    myclass *px{ new myclass[10] };
    delete[] px;

    cout << sizeof(all) << endl;

    return 0;
}

