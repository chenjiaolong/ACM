#include <iostream>

using namespace std;

// 没有赋值，默认0-递增，赋值从赋值开始递增
enum color { red = 10, yellow, white, blue };

// 指定数据类型，枚举名称不可以重名，内部不可以，外部不可以
enum colorX : char {redX = 'A', yellowX, whiteX, blueX};
enum class colorY : unsigned long { redY, yellowY, whiteY, blueY };

//

int main()
{
    cout << red << endl;
    cout << yellow << endl;

    enum color color1(red);
    enum color color2(color :: white); // 初始化的一般形式
    //! color1 = 3; // C++ 不可以，C++类型严格
    color1 = blue;

    cout << redX << endl;
    cout << yellowX << endl;

    colorX color3(redX);
    //! color3 = '0';

    colorY c1(colorY :: redY); // 遵循严格

    return 0;
}
