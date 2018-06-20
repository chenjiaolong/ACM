#include<iostream>
using namespace std;
int main()
{
    //cin.getline(×Ö·ûÊı×é(×Ö·ûÖ¸Õë), ×Ö·û¸öÊın, ÖÕÖ¹×Ö·û)
    char str[20];
    cout << "enter a sentence : " << endl;
    cin >> str;
    cout << "The string read with cin is : " << str << endl;
    cin.getline(str, 20, '/');//¶Á19¸ö×Ö·û»òÓö '/' ½áÊø
    cout << "The second part is : " << str << endl;
    cin.getline(str, 20);//¶Á19¸ö×Ö·û »òÓö '\n'½áÊø
    cout << "The third apart is : " << str << endl;
    return 0;
}
