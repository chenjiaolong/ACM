#include <iostream>
#include <initializer_list>

using namespace std;

void show(initializer_list<int >list)
{
    for(auto i : list) cout << i << endl;
}
void show(initializer_list<char *>list)
{
    for(auto i : list) cout << i << endl;
}

int *getmem(initializer_list<int > list)
{
    int length = list.size();
    int *p(new int[length]);
    int *pbak = p; // 备份地址
    for(auto i : list) *(p++) = i; // 循环赋值
    return pbak;
}

int main()
{
    int a[5]{1, 2, 3, 4, 5};
    show({1, 2, 3, 4, 5, 6, 7, 8, 9});
    show({"A", "B", "abc"});

    int *p{getmem({1, 2, 3, 4, 5, 6, 7})};
    for(int i = 0; i < 7; i ++) cout << p[i] << " " << (void *)(p + i) << endl;
    return 0;
}
