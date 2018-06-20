// 调用标准模板库的find() 函数查找数组元素
#include<iostream>
#include<algorithm>

using namespace std;

const int size = 16;

int main()
{
    int a[size];
    for(int i = 0; i < size; i ++) a[i] = i;
    int key = 7;
    int *ip = find(a, a + size, key);
    if(ip == a + size) // 不要使用NULL做指针测试，指针使用过尾值
        cout << key << " not found." << endl;
    else cout << key << " found." << endl;
	return 0;
}
