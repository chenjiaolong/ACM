/**
 * ����ģʽ
 * ֻ����ĳ��ĵ�һ�������
 * ����ĳ��ȫ�ַ��ʲ��ԣ�������Ҫʱ���ʸö���
 */
// ����ģʽ��������
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
//    // ��̬��Ա���������󲻴���ʱ���������򷵻�֮����֤Ψһ��
//    static Singleton *Get() { if(!_s) _s = new Singleton; return _s; }
//    int GetData() { return ++a; }
//private : // ˽�й����������������ֹ���ⲿ�������������Ķ���
//    Singleton() { a = 0; }
//    Singleton(const Singleton &that); // ֻ������ʵ�֣���ֹ�����͸�ֵ����
//    Singleton &operator = (const Singleton &that);
//    ~Singleton(); // ֻ������ʵ�֣���ֹ����
//private :
//    static Singleton *_s;
//    int a; // ��֤����
//};
//
//// ʹ�÷��� �� ��Single ::Get() -> GetData()��ʽֱ�ӷ���
//// Singleton :: Get()
//
//Singleton *Singleton :: _s = NULL;// ��̬���ݳ�Ա��ָ�����Ψһ�����ָ��
//
//int main()
//{
//    cout << Singleton :: Get() -> GetData() << endl;
//    return 0;
//}

// ����ģʽ �� ��������
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<iostream>
//
//using namespace std;
//
//class Singleton
//{
//public:  // ��̬��Ա���������󲻴���ʱ���죬���򷵻�֮����֤Ψһ��
//  static Singleton * Get() {  if (!_s)  _s = new Singleton;  return _s;  }
//  int GetData() { return ++a; }
//private:  // ˽�й����������������ֹ���ⲿ�������������Ķ���
//  Singleton() { a = 0; }
//  Singleton( const Singleton & that );  // ֻ������ʵ�֣���ֹ�����͸�ֵ����
//  Singleton & operator=( const Singleton & that );
//  //  �����������������ʿ��Ƹ�ΪpublicҲ����
//  //  delete������������Ҫ������������
//  //  �ҷǾ�̬���������ͷž�ָ̬���Ա��������ܵ���ϵͳ����
//  ~Singleton() {  if(Singleton::_s) {  delete Singleton::_s, Singleton::_s = NULL; }  }
//private:
//  static Singleton * _s;  // ��̬���ݳ�Ա��ָ����Ψһ�����ָ��
//  int a;  // ��֤����
//};
//
//// ʹ�÷��� �� ��Single ::Get() -> GetData()��ʽֱ�ӷ���
//// Singleton :: Get()
//
//Singleton *Singleton :: _s = NULL;// ��̬���ݳ�Ա��ָ�����Ψһ�����ָ��
//
//int main()
//{
//    cout << Singleton :: Get() -> GetData() << endl;
//    return 0;
//}

// ����ģʽ :: ��ȷ����
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
//    // ��̬��Ա���������󲻴���ʱ���죬���򷵻�֮����֤Ψһ��
//    static Singleton * Get() {  if (!_s)  _s = new Singleton;  return _s;  }
//    int GetData() { return ++a; }
//private :  // ˽�й��캯������ֹ���ⲿ���챾��Ķ���
//  Singleton() { a = 0; }
//  Singleton( const Singleton & that );  // ֻ������ʵ�֣���ֹ�����͸�ֵ����
//  Singleton & operator=( const Singleton & that );
//public:  // �ڲ���ϵͳ��ʹ��private��ɣ�ϵͳ���ͷ�ȫ���ڴ棬����������
//  ~Singleton() { }  // ��ˣ���������ǿգ��������ݳ־û������п��ܵ�������
//private:
//  static Singleton * _s;  // ��̬���ݳ�Ա��ָ����Ψһ�����ָ��
//  // Destroyer���Ψһ������ɾ������
//  class Destroyer
//  {
//    public :
//        ~Destroyer() {  if(Singleton::_s) {  delete Singleton::_s, Singleton::_s = NULL;  }  }
//  };
//    static Destroyer _d;  // �������ʱ��ϵͳ�Զ����þ�̬��Ա����������
//    int a;  // ��֤����
//};
//
//// ʹ�÷��� �� ��Single ::Get() -> GetData()��ʽֱ�ӷ���
//// Singleton :: Get()
//
//Singleton *Singleton :: _s = NULL;// ��̬���ݳ�Ա��ָ�����Ψһ�����ָ��
//
//int main()
//{
//    cout << Singleton :: Get() -> GetData() << endl;
//    return 0;
//}

// ����ģʽ :: ��ȷ����
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<iostream>
//
//using namespace std;
//
//class Singleton
//{
//public:  // ��̬��Ա���������󲻴���ʱ���죬���򷵻�֮����֤Ψһ��
//  static Singleton * Get() {  if (!_s)  _s = new Singleton;  return _s;  }
//  // ����������������Release����ʱ���ɳ���Աȷ��
//  static void Release() {  if(_s)  {  free(_s),  _s = NULL;  }  }
//  int GetData() { return ++a; }
//private:  // ˽�й����������������ֹ���ⲿ�������������Ķ���
//  Singleton() { a = 0; }
//  Singleton( const Singleton & that );  // ֻ������ʵ�֣���ֹ�����͸�ֵ����
//  Singleton & operator=( const Singleton & that );
//  ~Singleton();
//private:
//  static Singleton * _s;  // ��̬���ݳ�Ա��ָ����Ψһ�����ָ��
//  int a;  // ��֤����
//};
//
//// ʹ�÷��� �� ��Single ::Get() -> GetData()��ʽֱ�ӷ���
//// Singleton :: Get()
//
//Singleton *Singleton :: _s = NULL;// ��̬���ݳ�Ա��ָ�����Ψһ�����ָ��
//
//int main()
//{
//    cout << Singleton :: Get() -> GetData() << endl;
//    Singleton :: Release();
//    return 0;
//}


// ����ģʽ :��̬����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

class Singleton
{
public:  // ��̬��Ա�����еľ�̬��������֤Ψһ��
  static Singleton & Get() {  static Singleton _s;  return _s;  }
  int GetData() { return ++a; }
private:  // ˽�й����������������ֹ���ⲿ�������������Ķ���
  Singleton() { a = 0; }
  Singleton( const Singleton & that );
  Singleton & operator=( const Singleton & that );
  ~Singleton() { }
private:
  int a;  // ��֤����
};

//  ��ʵ��û�ж�̬�ڴ���䣬����������ٵ��Ӷ���
//  ʹ�÷������������û���Singleton::Get().GetData()��ʽֱ�ӷ���
Singleton & sing = Singleton::Get();
int n = sing.GetData();

int main()
{
    // cout << Singleton :: Get().GetData() << endl;
    cout << n << endl;
    return 0;
}
