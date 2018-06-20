//控制符
#include<iomanip>
#include<iostream>
using namespace std;
int main()
{
    int a;
    cout << "input a : ";
    cin >> a;
    cout << "dec : " << dec << a << endl;//以十进制形式输出整数
    cout << "hex : " << hex << a << endl;//以十六进制形式输出整数
    cout << "oct : " << oct << a << endl;//以八进制形式输出整数
    cout << "oct : " << setbase(8) << a << endl;//设置整数的基数为 n ，setbase(n) n 只能为 8, 10,16 三者之一

    char *pt = "China";
    cout << setw(10) << pt << endl;//setw(n) 设置字段宽度为 n 位（阈值、域宽）
    cout << setfill('*') << setw(10) << pt << endl;//setfill(c),设置填充字符 c ，c可以是字符常量或者字符变量 不足域宽的情况从左以 ' * ' 填充

    double pi = 22.0 / 7.0;
    //setprecision(n) 设置实数的精度为 n 位。在以一般十进制小数形式输出是n代表有效数字。在以fixed(固定小数位数)形式和scientific(指数)形式输出时n为小数位数
    //setiosflags(ios :: scientific) 设置浮点数以科学记数法（即指数形式）显示
    cout << setiosflags(ios :: scientific) << setprecision(8);//按指数形式输出，8位小数
    cout << "pi = " << pi << endl;
    cout << "pi = " << setprecision(4) << pi << endl;//改为4位小数
    //setiosflags(ios :: fixed)设置浮点数以固定小数位数显示
    cout << "pi = " << setiosflags(ios :: fixed) << pi << endl;//改为小数形式输出
    //setiosflags(ios :: left) 输出数据左对齐
    //setiosflags(ios :: right) 输出数据右对齐
    //setiosflags(ios :: skipws) 忽略前导的空格
    //setiosflags(ios :: uppercase) 在以科学记数法输出E和以十六进制输出字母X时以大写表示
    //setiosflags(ios :: showpos) 输出整数时给出 " + " 号
    //resetiosflags() 终止已设置的输出格式状态，在括号中应指定内容
    return 0;
}

//使用流对象的有关成员函数
//#include<iostream>
//using namespace std;
//int main()
//{
//    int a = 21;
//    //ios :: showbase 强制输出整数的基数（八进制以 0 打头，十六进制 以 0x 打头）
//    cout.setf(ios :: showbase);//设置输出时的基数符号
//    cout << "dec : " << a << endl;//默认以十进制形式输出
//    cout.unsetf(ios :: dec);//终止十进制的格式设置
//    cout.setf(ios :: hex);//设置以十六进制输出的状态
//    cout << "hex : " << a << endl;//以十六进制形式输出
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
//    //ios :: internal 数值的符号位在域宽内左对齐，数值右对齐，中间由填充字符填充
//    cout.setf(ios :: internal);//数符出现在左侧
//    cout.precision(6);
//    cout << pi << endl;
//    //ios :: showpoint 强制输出浮点数的小点和尾数 0
//    //ios :: unitbuf 每次输出以后刷新所有流’
//    //ios :: stdio 每次输出之后清除 stdout,stderr
//    return 0;
//}
