/*********************************************
*读取windows系统下的win.ini文件，并显示*
**********************************************/
#include <string>
#include <fstream>//read函数所在的头文件
#include <iostream>
#include <Windows.h>

int main()
{
    char buffer[100];
    char winFilePath[MAX_PATH];
    GetWindowsDirectoryA(winFilePath,MAX_PATH);
    strcat(winFilePath,"C:\\Windows\\win.ini");//得到win.ini文件绝对路径
    std::ifstream win_ini(winFilePath,std::ios::in|std::ios::binary);//构造时关联文件
    if(!win_ini . is_open())
    {
        std::clog<<"打开文件失败"<<std::endl;
        exit(0);
    }
    while(!win_ini.eof())
    {
        win_ini.read(buffer,99);
        buffer[win_ini.gcount()]='\0';//read函数不会在读入的字节中加入
        std::cout<<buffer;
    }
    std::cout<<std::endl;
    win_ini.close();
    return 1;
}
