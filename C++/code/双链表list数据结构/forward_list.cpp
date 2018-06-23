#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int >list1{1, 2, 3, 4, 5};
    list1.push_front(10);
    //! list1.push_back(10); // ֻ��ͷ��
    for(auto i : list1) cout << i << endl;

    cout << "---------" << endl;
    auto it = list1.before_begin(); // ����ͷ���
    cout << *it << endl;

    cout << "---------" << endl;
    auto ib = list1.before_begin();
    // auto ib = list1.begin();
    // list1.insert_after(ib,19); // ����Ĳ���
    int a[5]{11, 12, 13, 14, 15};
    list1.insert_after(ib, a, a + 5); // ����
    for(auto ib = list1.begin(), ie = list1.end(); ib != ie; ib ++) cout << *ib << endl;

    cout << "---------" << endl;
    list1.erase_after(++ib); // ɾ��
    for(auto ib = list1.begin(), ie = list1.end(); ib != ie; ib ++) cout << *ib << endl;

    cout << "---------" << endl;
    forward_list<int >list2{11, 2, 13, 4, 15};
    forward_list<int >list3{119, 28, 37};
    list2.sort(); // ����
    list3.sort();
    list2.merge(list3);
    //list2.reverse(); // ��ת
    cout << "list2.max_size() = "<< list2.max_size() << endl; // ���
    for(auto i : list2) cout << i << endl;

    cout << "---------" << endl;
    list3.assign(10, 19);
    for(auto i : list3) cout << i << endl;

    return 0;
}
