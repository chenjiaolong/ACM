#include<iostream>
#include<strstream>
using namespace std;
int main(int argc, char * argv[])
{
    char str[50] = "12 34 65 -23 -32 33 61 99 321 32";
    int array[10];
    cout << "array str : " << str << endl;//显示字符数组中的字符串
    istrstream strin(str,sizeof(str));//建立输入串流对象 strin 并与字符数组 str 关联
    for(int i = 0; i < 10; i ++)
        strin >> array[i];//从字符数组 str 读入10个整数赋给整型数组 array
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
    ostrstream strout(str, sizeof(str));//建立输出串流对象 strut 并与字符数组 str 关联
    for(int i = 0; i < 10; i ++)
        strout << array[i] << " ";
    strout << ends;
    cout << "array str : " << str << endl;
    return 0;
}
