#include<iostream>
#include "header1.h"
#include "header2.h"
using namespace std;
int main(int argc, char * argv[])
{
    ns1 :: Student stu1(101, "Wang", 18);
    stu1.get_data();
    cout << "¡Ì(5 + 3) = " << ns1 :: fun(5,3) << endl;
    ns2 :: Student stu2(102, "Li",'f');
    stu2.get_data();
    cout << "¡Ì(5 - 3) = " << ns2 :: fun(5,3) << endl;
    return 0;
}
