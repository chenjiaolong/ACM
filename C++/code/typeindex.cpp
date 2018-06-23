#include <string>
#include <iostream>
#include <typeinfo> // 类型信息
#include <typeindex> // 类型的索引
#include <unordered_map> // 映射，红黑树

using namespace std;

struct node
{

};

int main()
{
    unordered_map<type_index, string> mytype; // 类型与字符串的映射
    mytype[typeid(int)] = "整数类型";
    mytype[typeid(double)] = "实数类型";
    mytype[typeid(node)] = "node class";

    cout << mytype[typeid(int)] << endl;
    cout << mytype[typeid(double)] << endl;
    cout << mytype[typeid(node)] << endl;

    return 0;
}
