#include <cstdlib>
#include <iostream>

using namespace std;
// ����ָ��������Ϊ�������ı�ָ��
// ����ָ��������Ϊ����ֵ��ʵ�ֵ���getitrp(p)("dir");
// int (* (&p) )(const char * cmd)((int (* (&) )(const char * cmd))showcmd);

int gocmd(const char * cmd)
{
    system(cmd);
    return 0;
}
int showcmd(const char * cmd)
{
    cout << cmd << endl;
    return 0;
}
void change(int (* (&p) )(const char *cmd)) // ������Ϊ����
{
    p = showcmd;
}
// ����һ������ָ��
int (* getp() )(const char *cmd)
{
    int (* p )(const char * cmd)(gocmd); // ����ָ��
    return p;
}
// ������һ�����ã� ����ָ��
int (* getitp(int (* (&p) )(const char * cmd)))(const char *cmd)
{
    p = showcmd;
    return p;
}
// ������һ�����ã� ����ֵҲ��һ������
int (* (&getitrp(int (* (&p) )(const char * cmd))))(const char *cmd)
{
    p = gocmd;
    return p;
}
int (* (&getitrp2()))(const char *cmd)
{
    //! int (*p)(const char * cmd)(showcmd); // ջ��
    // ǿ���ͣ�ע������ת��
    // int (* (&p) )(const char * cmd) = (int (* (&) )(const char * cmd))showcmd;
    int (* (&p) )(const char * cmd)((int (* (&) )(const char * cmd))showcmd);
    return p;
}
int main()
{
    int (*p)(const char * cmd)(gocmd);// ���庯��ָ�벢��ʼ��
    p("calc");
    change(p);
    p("echo maomaoyu");

    p = getp();
    p("mspaint");
    getitp(p);
    p ("echo hehe");
    p = getitrp(p);
    p ("notepad");
    getitrp(p)("dir");
    //! p = getitrp2();
    //! p("cls");
    return 0;
}
