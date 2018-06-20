//类模板
//类模板的目的
//设计通用的类型式，以适应广泛的成员数据型式
//类模板的定义格式
//template <模板型式参数列表>class 类名称{...};
//原型：template<typename T> class A;
//类模板的成员
//像普通类的成员一样定义
//定义在类中或类外均可，后者需要在类名后列些模板参数，以区别非模板类的成员函数
//template<typename T> T A<T> :: f(u)
//类成员函数的模板
//成员函数可以使用其他的模板
//template<typename T> class A
//{
//public :
//template<typename U> T f(const U &u);
//}
//template<typename T>  template<typename U> T A<T> :: f(const U &u)
//{
//
//}
//
//类模板的体化
//与函数模板不同，类模板体化时必须给定模板实际参数，如：A<T> a;
//类模板体化时，编译器生成模板类或成员函数的代码；成员函数在调用时体化，虚函数在类构造时体化
//
//类模板的显示体化
//template class A<int>;
//解决模板库的创建问题，库的使用者可能没有体化的机会，而未体化的模板定义不会出现在目标文件中
//显式体化类模板后，显示体化起构造函数
//其他成员函数可显示体化，也可不显示体化
//
//类模板的显示特化
//使用特定的型或值显式特化类模板，已定制类模板代码，如：template<>class A<char >{...};
//显式特化版本覆盖体化版本
//显式特化并不要求与原始模板相同，特化版本可以具有不同的数据成员或成员函数
//类模板可以部分特化，结果仍是类模板，以支持类模板的部分定制
//类模板的缺省模板参数
//与函数模板相同，类模板可以具有缺省模板参数


#include<stdlib.h>
#include<iostream>

using namespace std;

// 空队列异常类
class EQueueEmpty{  };
// 队列项类前置声明
template<typename T> class JuQueueItem;
// 队列类
template<typename T> class JuQueue
{
public :
    JuQueue() : _head(NULL), _tail(NULL) {  }
    virtual ~JuQueue();
    virtual void Enter(const T & item);
    virtual T Leave();
    bool IsEmpty() const { return _head == 0; }
private :
    JuQueueItem<T> *_head, *_tail;
};

// 队列项类，单项链表结构
template<typename T> class JuQueueItem
{
    friend class JuQueue<T>;
public :
    JuQueueItem(const T &item) : _item(item), _next(0) { }
private :
    T _item;
    JuQueueItem<T> *_next;
};
// 队列类析构函数
template<typename T> JuQueue<T> :: ~JuQueue()
{
    while(!IsEmpty())
        Leave();
};
// 入队
template <typename T> void JuQueue<T> :: Enter(const T &item)
{
    JuQueueItem<T> *p = new JuQueueItem<T>(item);
    if(IsEmpty()) _head = _tail = p;
    else _tail -> _next = p, _tail = p;
}
// 出列
template <typename T> T JuQueue<T> :: Leave()
{
    if(IsEmpty()) throw EQueueEmpty();
    JuQueueItem<T> *p = _head;
    T _retval = p -> _item;
    _head = _head -> _next;
    delete p;
    return _retval;
}
int main()
{
    JuQueue<int > *p = new JuQueue<int >;
    for(int i = 0; i < 10; i ++)
        p -> Enter(i);
    cout << p -> Leave() << endl;

    int *r = new int(10), *q = new int(20);
    JuQueue<int *> *t = new JuQueue<int *>;
    t -> Enter(r);
    t -> Enter(q);

    int *s = t -> Leave();
    cout << *s << endl;
    return 0;
}
