#include <list>
#include <iostream>

using namespace std;

int main()
{
    list <int > mylist{1, 2, 3, 4, 5};
    mylist.push_back(10); // β�����
    mylist.push_front(123); // ͷ�����

    int a[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    mylist.assign(a, a + 5); // �������
    // mylist.assign(3, 5); // ���³�ʼ������3��5
    cout << "-----------" << endl;
    for(auto i : mylist) cout << i << endl;

    cout << "-----------" << endl;
    // ���������
    for(auto ib = mylist.begin(), ie = mylist.end(); ib != ie; ib ++) cout << *ib << endl;

    cout << "-----------" << endl;
    // ���������
    for(auto rb = mylist.rbegin(), re = mylist.rend(); rb != re; rb ++) cout << * rb << endl;

    cout << "-----------" << endl;
    cout << "��һ��" << mylist.front() << endl;
    cout << "���һ��" << mylist.back() << endl;
    cout << "����" << mylist.size() << endl;;

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
    mylist.pop_back(); // ɾ��β��
    mylist.pop_front(); // ɾ��ͷ��
    for(auto i : mylist) cout << i << endl;

    cout << "-----------" << endl;
    mylist.reverse(); // ��ת
    for(auto i : mylist) cout << i << endl;

    cout << "-----------" << endl;
    mylist.sort(); // ����
    for(auto i : mylist) cout << i << endl;

    mylist.clear();

    cout << "-----------" << endl;
    list <int > mylist1 { 11, 22, 13, 14, 15 };
    list <int > mylist2 { 1, 2, 13, 4, 5, 8, 9, 0};
    list <int > mylist3 { 1, 2, 13, 4 };

    mylist1.sort();
    mylist2.sort();

    // mylist1.merge(mylist2); // �鲢����
    mylist1.swap(mylist2);
    cout << "-----------" << endl;
    for(auto i : mylist1) cout << i << endl;
    cout << "-----------" << endl;
    for(auto i : mylist2) cout << i << endl;

    cout << "-----------" << endl;
    list<list<int>>myList{ mylist1, mylist2, mylist3 }; // �����ÿһԪ�ض�������
    for(auto i : myList)
    {
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}
