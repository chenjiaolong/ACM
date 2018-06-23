#include <iostream>

using namespace std;
// 保证所有的类型参数可以推导，默认，指定明确
// 函数参数遵循默认值规则
template<typename T = int, int n = 10> // 模板参数可以有默认值
void show(T t)
{
    cout << n << endl;
    cout << t << endl;
}

// 节约输入的参数，类型参数，可以指定，任意，填充从左向右，必须覆盖类型参数
template<typename T1 = int, typename T2 = int, typename T3 = double, typename T4 = double>
// 函数参数，默认同意在右边，至少要把默认的填充了才能使用
void go(T1 t1 = 250.1111, T2 t2 = 250.111, T3 t3 = 250.11, T4 t4 = 250.1)
{
    cout << t1 << " " << t2 << " " << t3 << " " << t4 << endl;
}

int main()
{
    show<>(250.250); // 自动推理
    show<int, 250>(250.250);

    go<double, double, double, double>();
    go();
    go(1, 2, 3, 4);
    return 0;
}
