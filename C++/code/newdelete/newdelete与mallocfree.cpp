#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;


class mydata
{
public :
    void *p;
    mydata() { cout << "mydata create" << endl;
    p = malloc(1024 * 1024 * 1024); // ����
     }
    ~mydata() { cout << "mydata delete" << endl;
    free(p); // �ͷ�
     }
};
// mydata d1; // ���������Զ����ù��캯��
void test()
{
    mydata d1; // ջ��,�������ù��캯�������ٵ�����������
}
int main()
{
    // �����������ͣ� int double char
    int *p(new int(5));
    cout << (void *)p << "  p = " << p << endl;
    delete p;
    // free(p);
    p = nullptr; // delete ����ı�ָ���ֵ��������;ָ�룬ָ���趨Ϊnullptr
    cout << "   p = " << p << endl;
    // delete p;

    // delete free ���ڻ����������ͣ��ͷţ��ͷ����ζ������
    // free���ı�ָ���ֵ��delete��ı�


    cout << "------------" << endl;
    int *ptr = (int *)malloc(4);
    *ptr = 4;
    free(p);// �����������ͣ�free malloc new delete Ч��һ��

    // test();
    // puts("OK");

    mydata *pNew = new mydata;

    delete pNew; // �Զ����ã����죬����
    // free(pNew); // free ���������������

    mydata *pMalloc = (mydata *) malloc(sizeof(mydata));

    free(pMalloc);
    //! delete pMalloc; // �ڴ�й¶

    system("pause");


    return 0;
}
