// �¼�����
// �¼���������
// ����ϵͳ��Ӧ�ó����ڲ�����ĳ�¼��������ĳ�������Ҫ��Ӧ���¼��������д�������

// �������ܹ��У��¼���Ӧ���������Ϊ��Ա����
// ���⣺ָ�����Ա������ָ�벻��ת��λ����ָ�� void *,Ҳ��������ת��Ϊָ����һ����ĳ�Ա������ָ��
// ע��ָ�����Ա������ָ�벻�����������Ǹ���Ա���������ԣ���������������ԡ�
// ���������ʹ��ָ��ָ�����Ա������ָ���ָ�롪������ָ��

// ʵ�ֵĲ��ԣ��¼�ί��ģ��
// Event��ģ�壺�����¼���Ӧ�߶���ʵ���¼��ಥ
// EventResponsor��ģ�壺��Ӧ�߶�������Ӧ����Ϊ���
// Empty�ࣺί��ģ�ͺ�ָ��ת��

// ע���е�ʱ����ģ���У����Ѿ���һ���ض������������ͻ���һ�����������һ���͵Ļ���������ǰ�����typename
#include<vector>
#include<iostream>

using namespace std;

// ���࣬����ָ����Ӧ�߶���
class Empty {  };

// �¼���Ӧ����ģ�壬��������¼�����Ӧ������Ӧ��Ϊ
template<typename EventAction> class EventResponsor
{
public:
    EventResponsor(): actor(NULL), action(NULL) { }
    EventResponsor(Empty *actor, EventAction * action): actor(actor), action(action) {  }
    friend bool operator == (const EventResponsor &lhs, const EventResponsor &rhs)
    {
        return lhs.actor== rhs.actor && *lhs.action == *rhs.action;
    }
public: // ���������ݳ�Ա���Է���ʹ����
    Empty *actor;// ָ����Ӧ����ж����Ǹ�ָ��
    EventAction * action;// ָ��ָ����Ӧ�ж�������ָ���ָ��
};
// �¼���ģ�壬���ڹ�������¼���������Ӧ��
template <typename EventAction> class Event
{
public:
    // �¼���Ӧ�߼���
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
    // �¼��󶨣���ʵ����Ӧ�ߺ���Ӧ��Ϊ�ҽӵ��¼���Ӧ�߶�����
    template<typename Responsor, typename Action>
    void Bind(Responsor *actor, Action action)
    {
        Action * act = new Action(action);
        EventResponsor<EventAction> er((Empty *) actor, (EventAction *)act);
        bool unbound = true;
        for(EventIterator it = this -> _ers.begin(); it != this -> _ers.end(); ++ it)
            if(*it == er) // �����ظ����¼���Ӧ�ߣ�˵���Ѱ�
            {
                unbound = false;
                break;
            }
        if(unbound) this -> _ers.push_back(er);
        else delete er.action, er.action = NULL;
    }
    // ����¼��󶨣�ɾ���¼���Ӧ�߶���
    template<typename Responsor, typename Action>
    void Unbind(Responsor *actor, Action action)
    {
        Action * act = new Action(action);
        EventResponsor<EventAction> er((Empty *) actor, (EventAction *)act);
        for(EventIterator it = this -> _ers.begin(); it != this -> _ers.end(); ++ it)
        {
            if(*it == er) // �ҵ���ɾ�����¼���Ӧ�߶���
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
// �����¼�ί��ģ�͡�ָ�����Ա������ָ��
typedef Empty EventDelegator;
typedef void (EventDelegator :: *ValueChanged)(int value, void *tag);

// ������
class Trigger
{
public :
    Trigger(): _value(0) {  }
    void SetValue(int value, void *tag);
    int GetValue(){ return _value; }
public :
    // ֵ�仯�¼����������ԣ����������趨
    Event<ValueChanged> value_changed;
private:
    int _value;// ����һ��������ض���ֵ
};
// �趨ֵ�������ض��¼�����Ӧ�����б���һ����ֵ����¼�
void Trigger :: SetValue(int value, void * tag)
{
    if(_value == value) return ;
    _value = value;
    Event<ValueChanged> :: EventResponsors ers;
    ers = this -> value_changed.GetResponsors();
    if(!ers.empty())
    {
        Event<ValueChanged> :: EventIterator it;
        // *it ��ָ���Ǹ��¼���Ӧ�� -> EventResponsor(EventResponsor<ValueChanged>)����it�൱��ָ���Ǹ��¼���Ӧ�ߵ�ָ��
        for(it = ers.begin(); it != ers.end(); ++ it)
            // ���ȼ� '->' > '*' > '->*'
            ((it -> actor) ->* (*(it -> action)))(value, tag); // ��Ӧ�¼�
    }
}
// �ж���
class Actor
{
public:
    // �����¼����󶨱�������¼���Ӧ�������������¼�
    void Listen(Trigger * trigger)
    {
        trigger -> value_changed.Bind(this, &Actor :: OnValueChanged);
    }
    // ֹͣ���������������¼���ȡ���󶨱�������¼���Ӧ�
    void Unlisten(Trigger * trigger)
    {
        trigger -> value_changed.Unbind(this, &Actor :: OnValueChanged);
    }
    // ֵ����¼�����Ӧ����
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
