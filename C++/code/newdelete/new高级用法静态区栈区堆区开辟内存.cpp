#include <cstdlib>
#include <iostream>

using namespace std;

// char str[1024]{0}; // �ڴ澲̬��

// ��̬����ջ��������
// int *p2(new (str) int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0});
// ������delete p2
// ջ������̬�������Ը�����д��������delete p2


int main()
{
    // char str[1024]{0}; // �ڴ�ջ��
    char *str(new char[1024]{0}); // ����

    // ���Ͽ����ڴ�
    int *p1(new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}); // һ���ڶ���
    int *p2(new (str) int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}); // �����ڴ棬str��ʼ�ĵ�ַ
    for(int i = 0; i < 10; i ++) cout << p1[i] << " " << p1 + i << p2[i] << " " << p2 + i << endl;

    cout << "---------------" << endl;
    free(str); // �ͷ�
    for(int i = 0; i < 10; i ++) cout << p1[i] << " " << p1 + i << p2[i] << " " << p2 + i << endl;

//    cout << "---------------" << endl;
//    p1 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//    p2 = new (str + 40) int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; //! ջ���;�̬�� free(str)���ڴ�й¶��ǿ��ָ���ڴ棬�ٴη���
//    for(int i = 0; i < 10; i ++) cout << p1[i] << " " << p1 + i << p2[i] << " " << p2 + i << endl;
//
//    cout << "---------------" << endl;
//    p1 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//    p2 = new (str + 40) int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//    for(int i = 0; i < 10; i ++) cout << p1[i] << " " << p1 + i << p2[i] << " " << p2 + i << endl;

    return 0;
}
