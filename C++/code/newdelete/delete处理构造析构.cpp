#include <iostream>

using namespace std;

class myclass
{
public :
    // myclass() = delete; // É¾³ý¹¹Ôìº¯Êý
    ~myclass() = delete;
};

int main()
{
    // myclass my1;
    myclass *p(new myclass);
    // delete p;
    return 0;
}
