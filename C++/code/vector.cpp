#include <vector>
#include <iostream>

using namespace std;
// vector 动态数组，无限嵌套
// 增删查改，动态的数据结构，线性表的顺序存储

int main()
{
    vector<int >myint{1, 2, 3, 4, 5};

    for(int i = 10; i < 20; i ++) myint.push_back(i);
    for(auto i : myint) cout << i << endl;

    cout << "---------" << endl;
    for(int i = 0; i < myint.size(); i ++)
    cout << myint[i] << " " << myint.at(i) << endl;

    // 迭代器，本质是指针
    cout << "---------" << endl;
    for(auto ib = myint.begin(), ie = myint.end(); ib != ie; ib ++)
        cout << *ib << endl;

    cout << "---------" << endl;
    for(auto rb = myint.rbegin(), re = myint.rend(); rb != re; rb ++)
        cout << *rb << endl;

    // 存取数组
    cout << "---------" << endl;
    cout << myint.front() << endl;
    cout << myint.back() << endl;

    cout << "---------" << endl;
    // myint.resize(5); // 动态调整大小
    myint.resize(5, 90); // vector，只有6个数组，缓冲有90
    for(auto i : myint) cout << i << endl;

    cout << "---------" << endl;
    auto it = myint.begin() + 3;
    it = myint.insert(it, 400); // 根据位置插入
    cout << "*it = " << *it << endl;
    int a[5]{21, 22, 23, 24, 25};
    it = myint.insert(it, a, a + 5); // 插入一个数组
    vector<int> myintX{11, 12, 13, 14, 15};
    it = myint.insert(it, myintX.begin(), myintX.end()); // 批量插入
    for(auto i : myint) cout << i << endl;

    cout << "---------" << endl;
    // myint.erase(it);
    myint.erase(myint.begin(), myint.begin() + 3); // 批量删除，不包含最后一个
    for(auto i : myint) cout << i << endl;

    cout << "---------" << endl;
    vector<int>myintY{13, 32, 33, 34, 35};
    myint.swap(myintY);
    for(auto i : myint) cout << i << endl;
    cout << endl;
    for(auto i : myintY) cout << i << endl;

    vector<double> mydb; // 堆上，不会栈溢出
    for(int i = 0; i < 1000000; i ++)
        mydb.push_back(i);

    for(int i = 0; i < 5; i ++) // 内存连续
        cout << myint[i] << " " << &myint[i] << endl;

    // vector 允许自动管理内存
    cout << "---------" << endl;
    vector<int> v;
    int *p = v.get_allocator().allocate(5); // 获取分配器分配内存
    cout << v.size() << endl << endl;
    for(int i = 0; i < 5; i ++)
        cout << (p[i] = i) << endl;
    v.get_allocator().deallocate(p, 5); // 释放内存

    cout << "---------" << endl;
    myint.assign(7, 100); // 重新初始化
    for(auto i : myint) cout << i << endl;

    vector<int > myint1{1, 2, 3, 4, 5};
    vector<int > myint2{1, 2, 3, 4, 5, 6, 7};
    vector<int > myint3{1, 2, 3};
    vector<vector<int > >myallint{myint1, myint2, myint3};
    for(auto i : myallint)
    {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
