#include<fstream>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main(int argc, char * argv[])
{
    int array[10];
    //ifstream infile("f1.data",ios :: in | ios :: nocreate);//���������ļ������������뷽ʽ�򿪴����ļ� f1.data
    ifstream infile("f1.data",ios :: in);
    if(! infile)
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    for(int i = 0; i < 9; i ++)
    {
        infile >> array[i];
        cout << array[i] << " ";
    }
    infile >> array[9];
    cout << array[9] << endl;
    int max = array[0],order = 0;
    for(int i = 1; i < 10; i ++)
        if(max < array[i])
        {
            max = array[i];
            order = i;
        }
    cout << "max = " << max << endl << "order = " << order << endl;
    infile.close();
    return 0;
}
