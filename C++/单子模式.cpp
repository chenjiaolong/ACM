/**
 * 单子模式
 * 只存在某类的单一共享对象
 * 存在某种全局访问策略，以在需要时访问该对象
 */
// 单子模式：无析构
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<iostream>
//
//using namespace std;
//
//class Singleton
//{
//public :
//    // 静态成员函数，对象不存在时析构，否则返回之，保证唯一性
//    static Singleton *Get() { if(!_s) _s = new Singleton; return _s; }
//    int GetData() { return ++a; }
//private : // 私有构造和析构函数，禁止在外部构造和析构本类的对象
//    Singleton() { a = 0; }
//    Singleton(const Singleton &that); // 只申明不实现，禁止拷贝和赋值构造
//    Singleton &operator = (const Singleton &that);
//    ~Singleton(); // 只申明不实现，禁止析构
//private :
//    static Singleton *_s;
//    int a; // 验证数据
//};
//
//// 使用方法 ： 以Single ::Get() -> GetData()方式直接访问
//// Singleton :: Get()
//
//Singleton *Singleton :: _s = NULL;// 静态数据成员，指向本类的唯一对象的指针
//
//int main()
//{
//    cout << Singleton :: Get() -> GetData() << endl;
//    return 0;
//}

// 单子模式 ： 错误析构
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<iostream>
//
//using namespace std;
//
//class Singleton
//{
//public:  // 静态成员函数，对象不存在时构造，否则返回之，保证唯一性
//  static Singleton * Get() {  if (!_s)  _s = new Singleton;  return _s;  }
//  int GetData() { return ++a; }
//private:  // 私有构造和析构函数，禁止在外部构造和析构本类的对象
//  Singleton() { a = 0; }
//  Singleton( const Singleton & that );  // 只声明不实现，禁止拷贝和赋值构造
//  Singleton & operator=( const Singleton & that );
//  //  错误析构函数，访问控制改为public也不行
//  //  delete操作符本身需要调用析构函数
//  //  且非静态函数不能释放静态指针成员，否则可能导致系统崩溃
//  ~Singleton() {  if(Singleton::_s) {  delete Singleton::_s, Singleton::_s = NULL; }  }
//private:
//  static Singleton * _s;  // 静态数据成员，指向本类唯一对象的指针
//  int a;  // 验证数据
//};
//
//// 使用方法 ： 以Single ::Get() -> GetData()方式直接访问
//// Singleton :: Get()
//
//Singleton *Singleton :: _s = NULL;// 静态数据成员，指向本类的唯一对象的指针
//
//int main()
//{
//    cout << Singleton :: Get() -> GetData() << endl;
//    return 0;
//}

// 单子模式 :: 正确析构
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<iostream>
//
//using namespace std;
//
//class Singleton
//{
//public :
//    // 静态成员函数，对象不存在时构造，否则返回之，保证唯一性
//    static Singleton * Get() {  if (!_s)  _s = new Singleton;  return _s;  }
//    int GetData() { return ++a; }
//private :  // 私有构造函数，禁止在外部构造本类的对象
//  Singleton() { a = 0; }
//  Singleton( const Singleton & that );  // 只声明不实现，禁止拷贝和赋值构造
//  Singleton & operator=( const Singleton & that );
//public:  // 在部分系统下使用private亦可，系统简单释放全部内存，并不调用它
//  ~Singleton() { }  // 因此，如果函数非空（如需数据持久化），有可能导致问题
//private:
//  static Singleton * _s;  // 静态数据成员，指向本类唯一对象的指针
//  // Destroyer类的唯一任务是删除单子
//  class Destroyer
//  {
//    public :
//        ~Destroyer() {  if(Singleton::_s) {  delete Singleton::_s, Singleton::_s = NULL;  }  }
//  };
//    static Destroyer _d;  // 程序结束时，系统自动调用静态成员的析构函数
//    int a;  // 验证数据
//};
//
//// 使用方法 ： 以Single ::Get() -> GetData()方式直接访问
//// Singleton :: Get()
//
//Singleton *Singleton :: _s = NULL;// 静态数据成员，指向本类的唯一对象的指针
//
//int main()
//{
//    cout << Singleton :: Get() -> GetData() << endl;
//    return 0;
//}

// 单子模式 :: 正确析构
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<iostream>
//
//using namespace std;
//
//class Singleton
//{
//public:  // 静态成员函数，对象不存在时构造，否则返回之，保证唯一性
//  static Singleton * Get() {  if (!_s)  _s = new Singleton;  return _s;  }
//  // 不调用析构函数，Release调用时机由程序员确定
//  static void Release() {  if(_s)  {  free(_s),  _s = NULL;  }  }
//  int GetData() { return ++a; }
//private:  // 私有构造和析构函数，禁止在外部构造和析构本类的对象
//  Singleton() { a = 0; }
//  Singleton( const Singleton & that );  // 只声明不实现，禁止拷贝和赋值构造
//  Singleton & operator=( const Singleton & that );
//  ~Singleton();
//private:
//  static Singleton * _s;  // 静态数据成员，指向本类唯一对象的指针
//  int a;  // 验证数据
//};
//
//// 使用方法 ： 以Single ::Get() -> GetData()方式直接访问
//// Singleton :: Get()
//
//Singleton *Singleton :: _s = NULL;// 静态数据成员，指向本类的唯一对象的指针
//
//int main()
//{
//    cout << Singleton :: Get() -> GetData() << endl;
//    Singleton :: Release();
//    return 0;
//}


// 单子模式 :静态数据
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

class Singleton
{
public:  // 静态成员函数中的静态变量，保证唯一性
  static Singleton & Get() {  static Singleton _s;  return _s;  }
  int GetData() { return ++a; }
private:  // 私有构造和析构函数，禁止在外部构造和析构本类的对象
  Singleton() { a = 0; }
  Singleton( const Singleton & that );
  Singleton & operator=( const Singleton & that );
  ~Singleton() { }
private:
  int a;  // 验证数据
};

//  本实现没有动态内存分配，因而无需销毁单子对象
//  使用方法：定义引用或以Singleton::Get().GetData()方式直接访问
Singleton & sing = Singleton::Get();
int n = sing.GetData();

int main()
{
    // cout << Singleton :: Get().GetData() << endl;
    cout << n << endl;
    return 0;
}
