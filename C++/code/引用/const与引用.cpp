#include <iostream>

using namespace std;

void show(const int &rint) // ��ȷֻ����д
{

}
void show(int &rint) // �ɶ���д
{

}
int main()
{
    int num(100);
    // int const &rnum(num); // �ñ������ã��޶�Ȩ��
    // const int &rnum(num);
    //! rnum = 3;

    // not surport!!
    // int & const rnum(num); // ʹ���˼�ʱ���󣺺��������ϵ��޶���
    // rnum = 3;
    cout << num << endl;

    cout << "---------" << endl;
    int a[5]{1, 2, 3, 4, 5};
    const int(&ra)[5](a);
    for(auto &i : ra)
    {
        // i += 1;
        cout << i << endl;
    }

    cout << "---------" << endl;
    const int *p(new int(5)); // ָ�룬ֻ����
    // int (* (&rp) )(p);
    const int (* (&rp) )(p); // ����һ��ָ������ָ��
    // *rp = 3;
    cout << *p << endl;

    cout << "---------" << endl;
    int * const p2(new int(4));
    *p2 = 1;
    int (* const (&rp2) )(p2); // ����һ������ָ��
    *rp2 = 2;

    const int * const p3(new int(4));
    const int (* const (&rp3) )(p3);// ����һ��ָ�����ĳ���ָ��

    int *p4(new int(4));
    const int (* (&rp4) )((const int * &)p4); // ����
    //! *rp = 3;
    cout << *rp4 << endl;
    return 0;
}
