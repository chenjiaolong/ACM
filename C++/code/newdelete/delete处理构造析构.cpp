#include <iostream>

using namespace std;

class myclass
{
public :
    // myclass() = delete; // ɾ�����캯��
    ~myclass() = delete;
};

int main()
{
    // myclass my1;
    myclass *p(new myclass);
    // delete p;
    return 0;
}
