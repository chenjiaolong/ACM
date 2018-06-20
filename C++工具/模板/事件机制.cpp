// 事件机制
// 事件基本概念
// 操作系统或应用程序内部发生某事件，程序的某个组件需要相应该事件，并进行待定处理

// 面向对象架构中，事件响应函数最可能为成员函数
// 问题：指向类成员函数的指针不能转换位哑型指针 void *,也不能随意转换为指向另一个类的成员函数的指针
// 注：指向类成员函数的指针不仅仅包括了那个成员函数的特性，还包括了类的特性。
// 解决方案：使用指向指向类成员函数的指针的指针——二级指针

// 实现的策略：事件委托模型
// Event类模板：管理事件响应者对象，实现事件多播
// EventResponsor类模板：响应者对象与响应者行为配对
// Empty类：委托模型和指针转换

// 注：有的时候在模板中，很难决定一个特定的名字他是型还是一个量，如果是一个型的话，可以在前面加上typename
#include<vector>
#include<iostream>

using namespace std;

// 空类，用于指代响应者对象
class Empty {  };

// 事件响应者类模板，保存待定事件的响应者与响应行为
template<typename EventAction> class EventResponsor
{
public:
    EventResponsor(): actor(NULL), action(NULL) { }
    EventResponsor(Empty *actor, EventAction * action): actor(actor), action(action) {  }
    friend bool operator == (const EventResponsor &lhs, const EventResponsor &rhs)
    {
        return lhs.actor== rhs.actor && *lhs.action == *rhs.action;
    }
public: // 公开的数据成员，以方便使用者
    Empty *actor;// 指向响应这个行动的那个指针
    EventAction * action;// 指向指向响应行动函数的指针的指针
};
// 事件类模板，用于管理待定事件的所有响应者
template <typename EventAction> class Event
{
public:
    // 事件响应者集合
    typedef vector<EventResponsor<EventAction> > EventResponsors;
    typedef typename vector<EventResponsor<EventAction> > :: iterator EventIterator;

public:
    virtual ~Event()
    {
        for(EventIterator it = this -> _ers.begin(); it != this -> _ers.end(); ++ it)
        {
            delete it -> action;
            it -> action = NULL;
        }
    }
    EventResponsors & GetResponsors()
    {
        return this -> _ers;
    }
    // 事件绑定，将实际响应者和响应行为挂接到事件响应者对象上
    template<typename Responsor, typename Action>
    void Bind(Responsor *actor, Action action)
    {
        Action * act = new Action(action);
        EventResponsor<EventAction> er((Empty *) actor, (EventAction *)act);
        bool unbound = true;
        for(EventIterator it = this -> _ers.begin(); it != this -> _ers.end(); ++ it)
            if(*it == er) // 发现重复的事件响应者，说明已绑定
            {
                unbound = false;
                break;
            }
        if(unbound) this -> _ers.push_back(er);
        else delete er.action, er.action = NULL;
    }
    // 解除事件绑定，删除事件相应者对象
    template<typename Responsor, typename Action>
    void Unbind(Responsor *actor, Action action)
    {
        Action * act = new Action(action);
        EventResponsor<EventAction> er((Empty *) actor, (EventAction *)act);
        for(EventIterator it = this -> _ers.begin(); it != this -> _ers.end(); ++ it)
        {
            if(*it == er) // 找到待删除的事件响应者对象
            {
                delete it -> action, this -> _ers.erase(it);
                break;
            }
        }
        delete er.action, er.action = NULL;
    }
private:
    EventResponsors _ers;
};
// 定义事件委托模型、指向类成员函数的指针
typedef Empty EventDelegator;
typedef void (EventDelegator :: *ValueChanged)(int value, void *tag);

// 触发者
class Trigger
{
public :
    Trigger(): _value(0) {  }
    void SetValue(int value, void *tag);
    int GetValue(){ return _value; }
public :
    // 值变化事件，公开属性，方便类外设定
    Event<ValueChanged> value_changed;
private:
    int _value;// 保存一个对象的特定的值
};
// 设定值，遍历特定事件的响应对象列表，逐一触发值变更事件
void Trigger :: SetValue(int value, void * tag)
{
    if(_value == value) return ;
    _value = value;
    Event<ValueChanged> :: EventResponsors ers;
    ers = this -> value_changed.GetResponsors();
    if(!ers.empty())
    {
        Event<ValueChanged> :: EventIterator it;
        // *it 就指代那个事件响应者 -> EventResponsor(EventResponsor<ValueChanged>)，而it相当于指向那个事件响应者的指针
        for(it = ers.begin(); it != ers.end(); ++ it)
            // 优先级 '->' > '*' > '->*'
            ((it -> actor) ->* (*(it -> action)))(value, tag); // 响应事件
    }
}
// 行动者
class Actor
{
public:
    // 侦听事件，绑定本对象的事件响应函数到侦听的事件
    void Listen(Trigger * trigger)
    {
        trigger -> value_changed.Bind(this, &Actor :: OnValueChanged);
    }
    // 停止侦听，从侦听的事件中取消绑定本对象的事件响应活动
    void Unlisten(Trigger * trigger)
    {
        trigger -> value_changed.Unbind(this, &Actor :: OnValueChanged);
    }
    // 值变更事件的响应函数
    void OnValueChanged(int value, void *tag)
    {
        cout << reinterpret_cast<char *>(tag) << value << "." << endl;
    }
};
int main()
{
    const char * s = "Now the value is ";
    Trigger t;
    Actor a1, a2;

    a1.Listen(&t);
    a2.Listen(&t);

    cout << "Listen..." << endl;
    t.SetValue(10, reinterpret_cast<void * > (const_cast<char *>(s)));

    a2.Unlisten(&t);
    cout << "Listen again..." << endl;
    t.SetValue(20, reinterpret_cast<void *>(const_cast<char *>(s)));

    return 0;
}
