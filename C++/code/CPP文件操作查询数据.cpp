#include <list>
#include <vector>
#include <memory>
#include <string>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

// vector <string> g_all; // 动态数组，字符组
list<string> g_all;
void loadmem()
{
    ifstream fin("CPP文件操作查询数据.in");
    // ofstream fout(CPP文件操作查询数据.out");
    if(!fin)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    while(!fin.eof())
    {
        char str[500]{0};
        fin.getline(str, 500);
        string putstr;
        putstr += str; // 生成C++字符串
        g_all.push_back(putstr);
    }
    fin.close();
}
void search()
{
    while(1)
    {
        string str;
        cin >> str;
        for(auto i : g_all)
        {
            int pos = i.find(str, 0);
            if(pos != -1) cout << i << endl;
        }
    }
}

// 硬盘模式
int main()
{
    ifstream fin("CPP文件操作查询数据.in");
    ofstream fout("CPP文件操作查询数据.out");
    if(!fin || !fout)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    // char name[300] {0};
    string name;
    cin >> name;
    while(!fin.eof()) // 没有到文件结尾就继续
    {
        char strpos[500]{ 0 };
        string str;
        fin.getline(strpos, 500); // 读取一行
        // fin.getline(const_cast<char *>(str.c_str()), 500);
        str += strpos;
        // char *p = strstr(str, name);
        int pos = str.find(name, 0); // find_first_of,找到第一个相同的字母
        // find查找整体
        if(pos != -1)
        {
            // 打印到屏幕，写入到文件
            cout << str << endl;
            fout << str << endl;
        }

    }
    fin.close();
    fout.close();
    system(R"(CPP文件操作查询数据.out)");
    return 0;
}


// 内存模式
//int main()
//{
//    loadmem();
//    search();
//    return 0;
//}
