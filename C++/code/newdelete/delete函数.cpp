#include <iostream>

using namespace std;
// �������� = delete;
// void show(char num) = delete; // �����ͽ��о�׼��ƥ��



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
