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
    // û��explicit,�������嶨�壬�������Ϊ���죬����Ϊת��
    // myclass my1(5); // ��explicit
    //! myclass my1 = 5; // explicit�޶��Զ�ת��������ǿ��ת��
    myclass my1 = (myclass) 5;
    cout << my1.num << endl;
    return 0;
}
