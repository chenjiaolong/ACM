/*********************************************
*��ȡwindowsϵͳ�µ�win.ini�ļ�������ʾ*
**********************************************/
#include <string>
#include <fstream>//read�������ڵ�ͷ�ļ�
#include <iostream>
#include <Windows.h>

int main()
{
    char buffer[100];
    char winFilePath[MAX_PATH];
    GetWindowsDirectoryA(winFilePath,MAX_PATH);
    strcat(winFilePath,"C:\\Windows\\win.ini");//�õ�win.ini�ļ�����·��
    std::ifstream win_ini(winFilePath,std::ios::in|std::ios::binary);//����ʱ�����ļ�
    if(!win_ini . is_open())
    {
        std::clog<<"���ļ�ʧ��"<<std::endl;
        exit(0);
    }
    while(!win_ini.eof())
    {
        win_ini.read(buffer,99);
        buffer[win_ini.gcount()]='\0';//read���������ڶ�����ֽ��м���
        std::cout<<buffer;
    }
    std::cout<<std::endl;
    win_ini.close();
    return 1;
}
