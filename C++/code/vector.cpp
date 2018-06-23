#include <vector>
#include <iostream>

using namespace std;
// vector ��̬���飬����Ƕ��
// ��ɾ��ģ���̬�����ݽṹ�����Ա��˳��洢

int main()
{
    vector<int >myint{1, 2, 3, 4, 5};

    for(int i = 10; i < 20; i ++) myint.push_back(i);
    for(auto i : myint) cout << i << endl;

    cout << "---------" << endl;
    for(int i = 0; i < myint.size(); i ++)
    cout << myint[i] << " " << myint.at(i) << endl;

    // ��������������ָ��
    cout << "---------" << endl;
    for(auto ib = myint.begin(), ie = myint.end(); ib != ie; ib ++)
        cout << *ib << endl;

    cout << "---------" << endl;
    for(auto rb = myint.rbegin(), re = myint.rend(); rb != re; rb ++)
        cout << *rb << endl;

    // ��ȡ����
    cout << "---------" << endl;
    cout << myint.front() << endl;
    cout << myint.back() << endl;

    cout << "---------" << endl;
    // myint.resize(5); // ��̬������С
    myint.resize(5, 90); // vector��ֻ��6�����飬������90
    for(auto i : myint) cout << i << endl;

    cout << "---------" << endl;
    auto it = myint.begin() + 3;
    it = myint.insert(it, 400); // ����λ�ò���
    cout << "*it = " << *it << endl;
    int a[5]{21, 22, 23, 24, 25};
    it = myint.insert(it, a, a + 5); // ����һ������
    vector<int> myintX{11, 12, 13, 14, 15};
    it = myint.insert(it, myintX.begin(), myintX.end()); // ��������
    for(auto i : myint) cout << i << endl;

    cout << "---------" << endl;
    // myint.erase(it);
    myint.erase(myint.begin(), myint.begin() + 3); // ����ɾ�������������һ��
    for(auto i : myint) cout << i << endl;

    cout << "---------" << endl;
    vector<int>myintY{13, 32, 33, 34, 35};
    myint.swap(myintY);
    for(auto i : myint) cout << i << endl;
    cout << endl;
    for(auto i : myintY) cout << i << endl;

    vector<double> mydb; // ���ϣ�����ջ���
    for(int i = 0; i < 1000000; i ++)
        mydb.push_back(i);

    for(int i = 0; i < 5; i ++) // �ڴ�����
        cout << myint[i] << " " << &myint[i] << endl;

    // vector �����Զ������ڴ�
    cout << "---------" << endl;
    vector<int> v;
    int *p = v.get_allocator().allocate(5); // ��ȡ�����������ڴ�
    cout << v.size() << endl << endl;
    for(int i = 0; i < 5; i ++)
        cout << (p[i] = i) << endl;
    v.get_allocator().deallocate(p, 5); // �ͷ��ڴ�

    cout << "---------" << endl;
    myint.assign(7, 100); // ���³�ʼ��
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
