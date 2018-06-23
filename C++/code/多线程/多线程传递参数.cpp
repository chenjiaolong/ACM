#include <thread>
#include <iostream>
#include <windows.h>

using namespace std;

void showmsg(const char *str1, const char *str2, const int index)
{
    MessageBox(0, str1, str2, index);
}

int main()
{
    thread th1(showmsg, "1", "1", 0);
    thread th2(showmsg, "12", "12", 1);
    thread th3(showmsg, "123", "123", 2);
    thread th4(showmsg, "1234", "1234", 3);
    thread th5(showmsg, "12345", "12345", 4);
    thread th6(showmsg, "123456", "123456", 5);
    thread th7(showmsg, "1234567", "1234567", 6);
    cin.get();
    return 0;
}
