#include <iostream>

using namespace std;

// ���ڻ����������ͣ����Ի�����ʹ��
// ���ڻ����������ͣ�delete��delete []һ��;

// ������������
// mydata *pNew(new mydata);        delete pNew;
// mydata *ppNew(new mydata[10]);   delete[] ppNew;
class mydata
{
public :
    mydata() { cout << "create" << endl; }
    ~mydata() { cout << "delete" << endl; }
};

int main()
{
    int *p1(new int(4)); // ָ��һ������
    int *p2(new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}); // ָ������

    // ���ڻ����������ͣ����Ի�����ʹ��
    delete p1;
    cout << p2 << endl;
    // delete p2; // ���ڻ����������ͣ�delete��delete []һ��; delete []p2;


    cout << "------------" << endl;
    mydata *pNew(new mydata);
    delete pNew;
    //! delete[] pNew; // �������ϵĶ��󣬲�����delete[]

    mydata *ppNew(new mydata[10]);
    delete[] ppNew;
    //! delete ppNew; // �����ϵ�

    return 0;
}
