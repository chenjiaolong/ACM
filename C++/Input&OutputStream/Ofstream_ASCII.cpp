#include<fstream>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main(int argc, char * argv[])
{
    ofstream outfile("f1.data", ios :: out);//定义文件流对象，打开磁盘文件 "f1.data"
    int array[10];
    if(!outfile)//如果打开文件失败，outfile返回值0值
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    cout << "enter 10 integer numbers : " << endl;
    for(int i = 0; i < 9; i ++)
    {
        cin >> array[i];
        outfile << array[i] << " ";//向磁盘文件 "f1.data" 输出数据
    }
    cin >> array[9];
    outfile << array[9];
    outfile.close();//关闭磁盘文件 "f1.data"
    return 0;
}
