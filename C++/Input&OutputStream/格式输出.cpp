//���Ʒ�
#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
    int a;
    cout << "input a : ";
    cin >> a;
    cout << "dec : " << dec << a << endl;//��ʮ������ʽ�������
    cout << "hex : " << hex << a << endl;//��ʮ��������ʽ�������
    cout << "oct : " << oct << a << endl;//�԰˽�����ʽ�������
    cout << "oct : " << setbase(8) << a << endl;//���������Ļ���Ϊ n ��setbase(n) n ֻ��Ϊ 8, 10,16 ����֮һ

    char *pt = "China";
    cout << setw(10) << pt << endl;//setw(n) �����ֶο��Ϊ n λ����ֵ�����
    cout << setfill('*') << setw(10) << pt << endl;//setfill(c),��������ַ� c ��c�������ַ����������ַ����� ����������������� ' * ' ���

    double pi = 22.0 / 7.0;
    //setprecision(n) ����ʵ���ľ���Ϊ n λ������һ��ʮ����С����ʽ�����n������Ч���֡�����fixed(�̶�С��λ��)��ʽ��scientific(ָ��)��ʽ���ʱnΪС��λ��
    //setiosflags(ios :: scientific) ���ø������Կ�ѧ����������ָ����ʽ����ʾ
    cout << setiosflags(ios :: scientific) << setprecision(8);//��ָ����ʽ�����8λС��
    cout << "pi = " << pi << endl;
    cout << "pi = " << setprecision(4) << pi << endl;//��Ϊ4λС��
    //setiosflags(ios :: fixed)���ø������Թ̶�С��λ����ʾ
    cout << "pi = " << setiosflags(ios :: fixed) << pi << endl;//��ΪС����ʽ���
    //setiosflags(ios :: left) ������������
    //setiosflags(ios :: right) ��������Ҷ���
    //setiosflags(ios :: skipws) ����ǰ���Ŀո�
    //setiosflags(ios :: uppercase) ���Կ�ѧ���������E����ʮ�����������ĸXʱ�Դ�д��ʾ
    //setiosflags(ios :: showpos) �������ʱ���� " + " ��
    //resetiosflags() ��ֹ�����õ������ʽ״̬����������Ӧָ������
    return 0;
}

//ʹ����������йس�Ա����
//#include<iostream>
//using namespace std;
//int main()
//{
//    int a = 21;
//    //ios :: showbase ǿ����������Ļ������˽����� 0 ��ͷ��ʮ������ �� 0x ��ͷ��
//    cout.setf(ios :: showbase);//�������ʱ�Ļ�������
//    cout << "dec : " << a << endl;//Ĭ����ʮ������ʽ���
//    cout.unsetf(ios :: dec);//��ֹʮ���Ƶĸ�ʽ����
//    cout.setf(ios :: hex);//������ʮ�����������״̬
//    cout << "hex : " << a << endl;//��ʮ��������ʽ���
//    cout.unsetf(ios :: hex);
//    cout.setf(ios :: oct);
//    cout << "oct : " << a << endl;
//
//    char * pt = "China";
//    cout.width(10);
//    cout << pt << endl;
//    cout.width(10);
//    cout.fill('*');
//    cout << pt << endl;
//
//    double pi = 22.0 / 7.0;
//    cout.setf(ios :: scientific);
//    cout << "pi = ";
//    cout.width(14);
//    cout << pi << endl;
//    cout.unsetf(ios :: scientific);
//    cout.setf(ios :: fixed);
//    cout.width(12);
//    cout.setf(ios :: showpos);
//    //ios :: internal ��ֵ�ķ���λ�����������룬��ֵ�Ҷ��룬�м�������ַ����
//    cout.setf(ios :: internal);//�������������
//    cout.precision(6);
//    cout << pi << endl;
//    //ios :: showpoint ǿ�������������С���β�� 0
//    //ios :: unitbuf ÿ������Ժ�ˢ����������
//    //ios :: stdio ÿ�����֮����� stdout,stderr
//    return 0;
//}
