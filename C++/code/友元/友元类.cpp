#include <iostream>

using namespace std;

class MyClass
{
public :
    MyClass();
    ~MyClass();
    friend class newclass;
private :
    int x = 1, y = 2, z = 3;
};
MyClass :: MyClass()
{

}
MyClass :: ~MyClass()
{

}
class newclass
{
    MyClass my;
    const char *password{"calc"};
public :
    void outit()
    {
        cout << password << " " << my.x << " " <<  my.y << " " << my.z << endl;
    }
};
int main()
{
    newclass new1;
    new1.outit();
    return 0;
}
