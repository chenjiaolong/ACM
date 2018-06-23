#include <iostream>

using namespace std;

class box
{
public :
    int x = 1, y = 2, z = 3;
    mutable int time = 4;
    int get() const
    {
        time = 1; // ²»±»constËø¶¨
        //! x = 1;
        return x * y * z;
    }
};

int main()
{
    box b;
    cout << b.get() << endl;
    return 0;
}
