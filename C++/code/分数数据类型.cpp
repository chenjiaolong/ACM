#include <ratio> // ������׷����Ծ�ȷ
#include <iostream>

using namespace std;

int main()
{
    ratio<1, 2> er;
    ratio<1, 3> th;
    // ���ӣ���ĸ
    cout << er.num << " / " << er.den << endl;
    cout << th.num << " / " << th.den << endl;

    typedef ratio<1, 2> two;
    typedef ratio<1, 3> three;
    two t1;
    three t2;
    cout << t1.num << " / " << t1.den << endl;
    cout << t2.num << " / " << t2.den << endl;
    typedef ratio_add<two, three> sum; // �ӷ�
    cout << sum :: num << " / " << sum :: den << endl;
    cout << (double) (sum :: num) / (sum :: den) << endl; // ת��

    return 0;
}
