#include <list>
#include <iostream>

using namespace std;

int main()
{
    list <int > mylist{1, 2, 3, 4, 5};
    mylist.push_back(10); // 尾部添加
    mylist.push_front(123); // 头部添加

    int a[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    mylist.assign(a, a + 5); // 处理填充
    // mylist.assign(3, 5); // 重新初始化链表，3个5
    cout << "-----------" << endl;
    for(auto i : mylist) cout << i << endl;

    cout << "-----------" << endl;
    // 正向迭代器
    for(auto ib = mylist.begin(), ie = mylist.end(); ib != ie; ib ++) cout << *ib << endl;

    cout << "-----------" << endl;
    // 反向迭代器
    for(auto rb = mylist.rbegin(), re = mylist.rend(); rb != re; rb ++) cout << * rb << endl;

    cout << "-----------" << endl;
    cout << "第一个" << mylist.front() << endl;
    cout << "最后一个" << mylist.back() << endl;
    cout << "个数" << mylist.size() << endl;;

    cout << "-----------" << endl;
    for(auto rb = mylist.rbegin(), re = mylist.rend(); rb != re; rb ++) if(*rb == 4) *rb = 4;
    for(auto i : mylist) cout << i << endl;

    cout << "-----------" << endl;
    for(auto ib = mylist.begin(), ie = mylist.end(); ib != ie; ib ++) if(*ib == 3) mylist.insert(ib, 123);
    for(auto i : mylist) cout << i << endl;

    cout << "-----------" << endl;
    for(auto ib = mylist.begin(), ie = mylist.end(); ib != ie; ib ++)
        if(*ib == 123)
        {
            mylist.erase(ib);
            break;
        }
    for(auto i : mylist) cout << i << endl;

    cout << "-----------" << endl;
    mylist.pop_back(); // 删除尾部
    mylist.pop_front(); // 删除头部
    for(auto i : mylist) cout << i << endl;

    cout << "-----------" << endl;
    mylist.reverse(); // 反转
    for(auto i : mylist) cout << i << endl;

    cout << "-----------" << endl;
    mylist.sort(); // 排序
    for(auto i : mylist) cout << i << endl;

    mylist.clear();

    cout << "-----------" << endl;
    list <int > mylist1 { 11, 22, 13, 14, 15 };
    list <int > mylist2 { 1, 2, 13, 4, 5, 8, 9, 0};
    list <int > mylist3 { 1, 2, 13, 4 };

    mylist1.sort();
    mylist2.sort();

    // mylist1.merge(mylist2); // 归并排序
    mylist1.swap(mylist2);
    cout << "-----------" << endl;
    for(auto i : mylist1) cout << i << endl;
    cout << "-----------" << endl;
    for(auto i : mylist2) cout << i << endl;

    cout << "-----------" << endl;
    list<list<int>>myList{ mylist1, mylist2, mylist3 }; // 链表的每一元素都是链表
    for(auto i : myList)
    {
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}
