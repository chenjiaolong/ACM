#include<iostream>
#include<strstream>
using namespace std;
int main(int argc, char * argv[])
{
    char str[50] = "12 34 65 -23 -32 33 61 99 321 32";
    int array[10];
    cout << "array str : " << str << endl;//��ʾ�ַ������е��ַ���
    istrstream strin(str,sizeof(str));//�������봮������ strin �����ַ����� str ����
    for(int i = 0; i < 10; i ++)
        strin >> array[i];//���ַ����� str ����10������������������ array
    cout << "array array : ";
    for(int i = 0; i < 9; i ++)
        cout << array[i] << " ";
    cout << array[9] << endl;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9 - i; j ++)
            if(array[j] > array[j + 1])
            {
                array[j] = array[j] + array[j + 1];
                array[j + 1] = array[j] - array[j + 1];
                array[j] = array[j] - array[j+ 1];
                //        int temp;
                //        temp = array[j];
                //        array[j] = array[j + 1];
                //        array[j + 1] = temp;
            }
    ostrstream strout(str, sizeof(str));//��������������� strut �����ַ����� str ����
    for(int i = 0; i < 10; i ++)
        strout << array[i] << " ";
    strout << ends;
    cout << "array str : " << str << endl;
    return 0;
}
