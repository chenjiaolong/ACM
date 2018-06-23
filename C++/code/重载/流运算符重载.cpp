#include <iostream>

using namespace std;
// ��������أ���Ա�������أ��ⲿ���أ�����˽�У�����Ҫ��Ԫ

class box
{
private :
    int x, y, z;
    friend box operator + (const box &box1, const int num);
    friend box operator +(const box &box1, const box &box2);
    friend ostream & operator << (ostream &out, const box & box1);
    friend istream & operator >> (istream &in, box &box1);
public :
    box() : x(10), y(20), z(30){  }
    void show()
    {
        cout << x << " " << y << " " << z << endl;
    }

};
// �ⲿ���أ�����ע��û��thisָ����������
// ���ǹ��б������ⲿ����ֱ�����أ��漰˽�б�������Ҫ��Ԫ
box operator +(const box &box1, const box &box2)
{
    box temp;
    temp.x = box1.x + box2.x;
    temp.y = box1.y + box2.y;
    temp.z = box1.z + box2.z;
    return temp;
}
box operator +(const box &box1, const int num)
{
    box temp;
    temp.x = box1.x + num;
    temp.y = box1.y + num;
    temp.z = box1.z + num;
    return temp;
}
// ������ʽ�����������һ�����ã����һ������
ostream & operator << (ostream &out, const box & box1)
{
    out << box1.x << " " << box1.y << " " << box1.z;
    return out;
}
istream & operator >> (istream &in, box &box1)
{
    in >> box1.x >> box1.y >> box1.z;
    return in;
}
template<class T>
void show(T &t)
{
    cout << t << endl;
}
int main()
{
    box box1;
    box box2;
    box box3 = box1 + box2;
    box3.show();
    box box4 = box1 + 30;
    box4.show();

    puts("---");
    cin >> box1;
    cout << box1 << endl;
    return 0;
}
