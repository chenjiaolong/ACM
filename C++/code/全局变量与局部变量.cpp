#include <iostream>

using namespace std;

int num = 100;

int main()
{
    int num = 20;
    {
        int num = 30;
        cout << num << endl;
        cout << :: num << endl;
    }
    cout << num << endl;
    cout << :: num << endl;

    return 0;
}
