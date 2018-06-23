#include <cstdlib>
#include <typeinfo>
#include <iostream>

using namespace std;

class myclass
{
public :
    int num;
    void go()
    {
        cout << (void *)this << endl; // this ��ǰ������׵�ַ
    }
    void show()
    {
        cout << (void *)this << endl;
        cout << "show AAA" << endl;
    }
    void run()
    {
        cout << "show CCC" << endl;
    }
    static void showit(int data)
    {
        // �޷������ڲ��������޷��������Ա����
        //! num = 1;
        //! show();
        //! run();
        // ��̬�����޷�ʹ��thisָ��
        //! cout << (void *)this << endl;
        cout << "show BBB " << data << endl;
    }
};

class tools
{
public :
    static void runcmd(const char *cmd)
    {
        system(cmd);
    }
    static int add(int, int)
    {
        return 1;
    }
};

int main()
{
    myclass my1;
    cout << (void *)&my1 << endl;
    my1.go();
    myclass my2;
    cout << (void *)&my2 << endl;
    my2.go();

    cout << typeid(&myclass :: show).name() << endl; // void<__thiscall myclass :: *><void>
    cout << typeid(&myclass :: showit).name() << endl; // void<__cdecl*><int>
    void (*p)(int ) = &myclass :: showit; // C�����ָ��
    void(myclass :: *px)() = &myclass :: show; // ���Ա�����ķ��

    puts("---");
    myclass :: showit(10); // ���о�̬��������������Ϳ���ֱ�ӷ��ʣ�û��this ָ��

    // ���ʾ�̬������Ҳ���Խ�������������
    my1.showit(11);
    my2.showit(12);

    puts("---");
    tools :: runcmd("notepad"); // ���Զ�C����ʵ�ֹ��ܺ����������װ����
    tools ts1;
    ts1.runcmd("calc");

    return 0;
}
