#include <cstdarg>
#include <iostream>

using namespace std;

template<typename T>
void show(T t)
{
    cout << t << endl;
}

template<typename ... Args>
void all(Args ... args)
{
    int arr[] = {(show(args), 0)...};
}
template<typename ... Args>
void allit(Args ... args)
{
    int arr[] = {(show(args), 0)...}; // Ô¼ÊøÕ¹¿ª
}
int main()
{
    // all(1, 2, 3, 4, 5);
    all(1, 2, 3, 4, 5, 6, 7, 8);
    allit(1, 'A', "123", 7.89);
    return 0;
}
