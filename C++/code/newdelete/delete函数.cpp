#include <iostream>

using namespace std;
// 函数声明 = delete;
// void show(char num) = delete; // 对类型进行精准的匹配



void show(int num)
{
    cout << num << endl;
}
int main()
{
    //show('A');
    show(100);
    return 0;
}
