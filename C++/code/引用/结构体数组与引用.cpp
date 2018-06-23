#include <iostream>

using namespace std;

struct info
{
    int id;
    int num;
    // û�з���ֵ��������������һ��
    info(int nid, int nnum) : id(nid), num(nnum){  } // �����ʼ������
};

int main()
{
    // ջ��
    info infos[5]{ {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5} };
    info (&rinfos)[5](infos);
    for(auto i : infos) cout << i.id << " " << i.num << endl;
    cout << endl;
    for(auto i : rinfos) cout << i.id << " " << i.num << endl;


    cout << "---------" << endl;
    // ����
    info *p(new info[5]{ {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5} });
    info (* (&rp))(p); // ���ýṹ������
    for(int i = 0; i < 5; i ++) cout << p[i].id << " " << p[i].num << endl;
    cout << endl;
    for(int i = 0; i < 5; i ++) cout << rp[i].id << " " << rp[i].num << endl;

    return 0;
}
