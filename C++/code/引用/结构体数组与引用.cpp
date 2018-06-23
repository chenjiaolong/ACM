#include <iostream>

using namespace std;

struct info
{
    int id;
    int num;
    // 没有返回值，命名与类型名一致
    info(int nid, int nnum) : id(nid), num(nnum){  } // 构造初始化函数
};

int main()
{
    // 栈上
    info infos[5]{ {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5} };
    info (&rinfos)[5](infos);
    for(auto i : infos) cout << i.id << " " << i.num << endl;
    cout << endl;
    for(auto i : rinfos) cout << i.id << " " << i.num << endl;


    cout << "---------" << endl;
    // 堆上
    info *p(new info[5]{ {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5} });
    info (* (&rp))(p); // 引用结构体数组
    for(int i = 0; i < 5; i ++) cout << p[i].id << " " << p[i].num << endl;
    cout << endl;
    for(int i = 0; i < 5; i ++) cout << rp[i].id << " " << rp[i].num << endl;

    return 0;
}
