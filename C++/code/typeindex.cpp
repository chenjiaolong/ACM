#include <string>
#include <iostream>
#include <typeinfo> // ������Ϣ
#include <typeindex> // ���͵�����
#include <unordered_map> // ӳ�䣬�����

using namespace std;

struct node
{

};

int main()
{
    unordered_map<type_index, string> mytype; // �������ַ�����ӳ��
    mytype[typeid(int)] = "��������";
    mytype[typeid(double)] = "ʵ������";
    mytype[typeid(node)] = "node class";

    cout << mytype[typeid(int)] << endl;
    cout << mytype[typeid(double)] << endl;
    cout << mytype[typeid(node)] << endl;

    return 0;
}
