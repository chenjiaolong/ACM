//#include <cstdarg> // �ɱ����
//#include <typeinfo>
//#include <iostream>
//
//using namespace std;
//
//// ����һ��
//template<typename T>
//T add(int n, T t ...) // ��һ��������ٸ������������ٸ����͵��б�
//{
//    cout << typeid(T).name() << endl;
//    va_list arg_ptr; // ��ͷָ��
//    va_start(arg_ptr, n); // ��arg_ptr��ʼ,��ȡN��
//    T res(0); // ��ʼ��Ϊ0
//    for(int i = 0; i < n; i ++)
//        res += va_arg(arg_ptr, T); // ������������ȡ������
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
//// Ϊ��ʱ�����ݹ�
//void show()
//{
//
//}
//
//// �������Ͳ�һ�£�������ȷ��
//template<typename T, typename... Args> // typename... Args�ɱ����
//void show(T t, Args... args)
//{
//    cout << t << endl; // ��ӡ
//    show(args...); // ����ʡ��
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
    while(str && *str) // ָ�벻Ϊ�գ����ַ���û�е�ĩβ
    {
        if(*str == '%' && *(str + 1) != '%')
        {
            ++ str; // ָ����ǰ�ƶ�
            cout << t; // ��ӡ
            show(++ str, args...); // ��������
            return;
        }
        else cout << *str ++; // ����һ���ַ�
    }
}
int main()
{
    printf("%dABCDEFG%s%c%%%fXXXX", 10, "1234", '0', 1234.5);
    putchar('\n');
    show("%dABCDEFG%s%c%%%fXXXX", 10, "1234", '0', 1234.5);
    return 0;
}
