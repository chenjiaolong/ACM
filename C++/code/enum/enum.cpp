#include <iostream>

using namespace std;

// û�и�ֵ��Ĭ��0-��������ֵ�Ӹ�ֵ��ʼ����
enum color { red = 10, yellow, white, blue };

// ָ���������ͣ�ö�����Ʋ������������ڲ������ԣ��ⲿ������
enum colorX : char {redX = 'A', yellowX, whiteX, blueX};
enum class colorY : unsigned long { redY, yellowY, whiteY, blueY };

//

int main()
{
    cout << red << endl;
    cout << yellow << endl;

    enum color color1(red);
    enum color color2(color :: white); // ��ʼ����һ����ʽ
    //! color1 = 3; // C++ �����ԣ�C++�����ϸ�
    color1 = blue;

    cout << redX << endl;
    cout << yellowX << endl;

    colorX color3(redX);
    //! color3 = '0';

    colorY c1(colorY :: redY); // ��ѭ�ϸ�

    return 0;
}
