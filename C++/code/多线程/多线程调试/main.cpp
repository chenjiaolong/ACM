#include <thread>
#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;

void test()
{
    int i = 0;
    while(1)
    {
        cout << ++i << endl;
        Sleep(1000);
    }
}

int main()
{
    thread *p(new thread(test));
    system("pause");
    return 0;
}
