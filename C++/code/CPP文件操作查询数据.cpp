#include <list>
#include <vector>
#include <memory>
#include <string>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

// vector <string> g_all; // ��̬���飬�ַ���
list<string> g_all;
void loadmem()
{
    ifstream fin("CPP�ļ�������ѯ����.in");
    // ofstream fout(CPP�ļ�������ѯ����.out");
    if(!fin)
    {
        cout << "�ļ���ʧ��" << endl;
        exit(1);
    }
    while(!fin.eof())
    {
        char str[500]{0};
        fin.getline(str, 500);
        string putstr;
        putstr += str; // ����C++�ַ���
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

// Ӳ��ģʽ
int main()
{
    ifstream fin("CPP�ļ�������ѯ����.in");
    ofstream fout("CPP�ļ�������ѯ����.out");
    if(!fin || !fout)
    {
        cout << "�ļ���ʧ��" << endl;
        exit(1);
    }
    // char name[300] {0};
    string name;
    cin >> name;
    while(!fin.eof()) // û�е��ļ���β�ͼ���
    {
        char strpos[500]{ 0 };
        string str;
        fin.getline(strpos, 500); // ��ȡһ��
        // fin.getline(const_cast<char *>(str.c_str()), 500);
        str += strpos;
        // char *p = strstr(str, name);
        int pos = str.find(name, 0); // find_first_of,�ҵ���һ����ͬ����ĸ
        // find��������
        if(pos != -1)
        {
            // ��ӡ����Ļ��д�뵽�ļ�
            cout << str << endl;
            fout << str << endl;
        }

    }
    fin.close();
    fout.close();
    system(R"(CPP�ļ�������ѯ����.out)");
    return 0;
}


// �ڴ�ģʽ
//int main()
//{
//    loadmem();
//    search();
//    return 0;
//}
