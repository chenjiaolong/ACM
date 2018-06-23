//#include <cstdarg> // 可变参数
//#include <typeinfo>
//#include <iostream>
//
//using namespace std;
//
//// 类型一致
//template<typename T>
//T add(int n, T t ...) // 第一个代表多少个参数，最后多少个类型的列表
//{
//    cout << typeid(T).name() << endl;
//    va_list arg_ptr; // 开头指针
//    va_start(arg_ptr, n); // 从arg_ptr开始,读取N个
//    T res(0); // 初始化为0
//    for(int i = 0; i < n; i ++)
//        res += va_arg(arg_ptr, T); // 根据数据类型取出数据
//    va_end(arg_ptr);
//    return res;
//}
//int main()
//{
//    cout << add(4, 1, 2, 3, 4) << endl;
//
//    cout << add(5, 1, 2, 3, 4, 5) << endl;
//
//    cout << add(5, 11.1, 12.2, 13.3, 14.4, 15.5) << endl;
//    return 0;
//}

//#include <cstdarg>
//#include <iostream>
//
//using namespace std;
//
//// 为空时结束递归
//void show()
//{
//
//}
//
//// 参数类型不一致，个数不确定
//template<typename T, typename... Args> // typename... Args可变参数
//void show(T t, Args... args)
//{
//    cout << t << endl; // 打印
//    show(args...); // 不能省略
//}
//
//int main()
//{
//    show(1, 1.2, "123", 'A');
//    return 0;
//}

#include <cstdarg>
#include <iostream>

using namespace std;

void show(const char *str)
{
    cout << str;
}

template<typename T, typename... Args>
void show(const char *str, T t, Args... args)
{
    while(str && *str) // 指针不为空，且字符串没有到末尾
    {
        if(*str == '%' && *(str + 1) != '%')
        {
            ++ str; // 指针向前移动
            cout << t; // 打印
            show(++ str, args...); // 继续调用
            return;
        }
        else cout << *str ++; // 跳过一个字符
    }
}
int main()
{
    printf("%dABCDEFG%s%c%%%fXXXX", 10, "1234", '0', 1234.5);
    putchar('\n');
    show("%dABCDEFG%s%c%%%fXXXX", 10, "1234", '0', 1234.5);
    return 0;
}
