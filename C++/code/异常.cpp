#include <cstdlib>
#include <iostream>

using namespace std;
// �쳣�����һ�����쳣һ���ܹ���������
// ������ǳ����޷������������޷�����
// �쳣�ó����ڴ�������룬�ļ������ڣ��ڴ��쳣��Ȼ������������
int Div(int a, int b)
{
    try // ����
    {
        if(b == 0) throw 1; // �׳�
        cout << "a = " << a << " , b = " << b << endl;
        return a / b;
    }catch(int code) // �����쳣
    {
        if(code == 1)
            cout << "����������Ϊ0" << endl;
        return 0;
    }

}

int main()
{
    int num1;
    int num2;
    cin >> num1 >> num2;
    cout << Div(num1, num2) << endl;
    return 0;
}
