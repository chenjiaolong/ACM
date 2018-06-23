#include <iostream>
#include <type_traits>

using namespace std;

template<typename T1, typename T2>
void check_type(const T1 &t1, const T2 & t2,
                typename enable_if<is_same<T1, T2> :: value> :: type *p = nullptr)
{
    cout << t1 << " " << t2 << endl;
    cout << "类型相同" << endl;
}
template<typename T1, typename T2>
void check_type(const T1 &t1, const T2 & t2,
                typename enable_if<!is_same<T1, T2> :: value> :: type *p = nullptr)
{
    cout << t1 << " " << t2 << endl;
    cout << "类型不相同" << endl;
}

int main()
{
    check_type(1, 10);
    check_type(1, 10.1);
    return 0;
}
