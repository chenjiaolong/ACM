#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;


// 左值引用 不接受文字作为实际参数，因无法获取文字的左值
// int f( int & x )  {  return ++x;  }

//  接受文字作为实际参数，传递右值引用
//  具名右值引用作为左值，匿名右值引用作为右值
//  在函数内部理论如此，但实际上……
int f( int && x )  {  return ++x;  }

int main()
{

  cout << atoi("2147483648") << endl;
  //  错误代码，++操作符的操作数必须为左值
  //  std::cout << ++10 << std::endl;
  //  可能有问题，传递右值引用，但部分编译器可能将其作为左值
  std::cout << f(10) << std::endl;    //  11?
  return 0;
}

