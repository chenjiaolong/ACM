#include <iostream>

using namespace std;

// 对于基本数据类型，可以互相混合使用
// 对于基本数据类型，delete和delete []一致;

// 复合数据类型
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
    int *p1(new int(4)); // 指向一个变量
    int *p2(new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}); // 指向数组

    // 对于基本数据类型，可以互相混合使用
    delete p1;
    cout << p2 << endl;
    // delete p2; // 对于基本数据类型，delete和delete []一致; delete []p2;


    cout << "------------" << endl;
    mydata *pNew(new mydata);
    delete pNew;
    //! delete[] pNew; // 单个堆上的对象，不可以delete[]

    mydata *ppNew(new mydata[10]);
    delete[] ppNew;
    //! delete ppNew; // 触发断点

    return 0;
}
