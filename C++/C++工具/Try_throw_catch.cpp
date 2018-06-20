#include<math.h>
#include<iostream>
using namespace std;
int main()
{
    double triangle(double, double, double);
    double a,b,c;
    cin >> a >> b >> c;
    try//�� try ���а���Ҫ���ĺ���
    {
        while(a > 0 && b > 0 && c > 0)
        {
            cout << triangle(a,b,c) << endl;
            cin >> a >> b >> c;
        }
    }catch(double)//�� catch ���쳣��Ϣ������Ӧ����
    {
        cout << "a = " << a << ", b = " << b << ", c = " << c << ",that is not a triangle!" << endl;
    }
    cout << "end" << endl;
    return 0;
}
double triangle(double a, double b, double c)//���������ε��������
{
    double s = (a + b + c) / 2;
    if(a + b <= c || b + c <= a || a + c <= b) throw a;//�������������������׳��쳣��Ϣ
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
