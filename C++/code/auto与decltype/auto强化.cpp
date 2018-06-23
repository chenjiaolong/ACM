#include <typeinfo>
#include <iostream>

using namespace std;

// C++14 自动推理返回值
// C++11 需要返回 -> 指定类型
// auto add(int a, int b) -> decltype(a + b)
auto add(int a, int b) -> int
{
    return a + b;
}

auto (*f)() -> int(*)(); // f是什么
// int(*	(*f)()	)(); // 返回值函数指针

// auto pf(void) ->     auto(*)(int x) ->   int(*)(int a, int b);
// int(*    (* pf(void) )(int x) )(int a, int b);
auto pf(void ) -> auto(*)(int x) -> int(*)(int a, int b)
{
	return nullptr; // 返回空指针
}

auto go(int a, int b) -> auto(*)(void) -> int (*)(int, int(*)(int, int));
// int(*(*go(int a, int b))(void))(int, int(*)(int, int));


int main()
{
    cout << add(1, 2) << endl;
    cout << typeid(f).name() << endl;

    cout << typeid(pf).name() << endl;// int <__cdecl*<__cdecl*__cdecl<void>><void>><void>

    cout << typeid(go).name() << endl; // int<__cdecl*<__cdecl*__cdecl<int, int>><void>><int, <__cdecl*><int, int>>
    return 0;
}
