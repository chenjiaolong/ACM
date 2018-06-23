#include <iostream>

using namespace std;

class myclass
{
public :
    int num;
    explicit myclass(int data) : num(data) {  }

};

int main()
{
//    myclass my1 = 5;
//    myclass my1(5);
//    myclass my1 = (myclass)5;
//    myclass my1 = myclass(5);
    // 没有explicit,代码歧义定义，可以理解为构造，解释为转换
    // myclass my1(5); // 有explicit
    //! myclass my1 = 5; // explicit限定自动转换，可以强制转换
    myclass my1 = (myclass) 5;
    cout << my1.num << endl;
    return 0;
}
