#include<iostream>
using namespace std;
int main()
{
    cout.put(71).put(79).put(79).put(68).put('\n');

    char * p = "BASIC";//字符指针指向 'B'
    for(int i = 4; i >= 0; i--)
        cout.put(*(p + i));//从最后一个字符输出
    cout.put('\n');
    return 0;
}
