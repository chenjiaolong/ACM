#include<fstream>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main(int argc, char * argv[])
{
    ofstream outfile("f1.data", ios :: out);//�����ļ������󣬴򿪴����ļ� "f1.data"
    int array[10];
    if(!outfile)//������ļ�ʧ�ܣ�outfile����ֵ0ֵ
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    cout << "enter 10 integer numbers : " << endl;
    for(int i = 0; i < 9; i ++)
    {
        cin >> array[i];
        outfile << array[i] << " ";//������ļ� "f1.data" �������
    }
    cin >> array[9];
    outfile << array[9];
    outfile.close();//�رմ����ļ� "f1.data"
    return 0;
}
