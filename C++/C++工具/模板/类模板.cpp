//��ģ��
//��ģ���Ŀ��
//���ͨ�õ�����ʽ������Ӧ�㷺�ĳ�Ա������ʽ
//��ģ��Ķ����ʽ
//template <ģ����ʽ�����б�>class ������{...};
//ԭ�ͣ�template<typename T> class A;
//��ģ��ĳ�Ա
//����ͨ��ĳ�Աһ������
//���������л�������ɣ�������Ҫ����������Щģ��������������ģ����ĳ�Ա����
//template<typename T> T A<T> :: f(u)
//���Ա������ģ��
//��Ա��������ʹ��������ģ��
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
//��ģ����廯
//�뺯��ģ�岻ͬ����ģ���廯ʱ�������ģ��ʵ�ʲ������磺A<T> a;
//��ģ���廯ʱ������������ģ������Ա�����Ĵ��룻��Ա�����ڵ���ʱ�廯���麯�����๹��ʱ�廯
//
//��ģ�����ʾ�廯
//template class A<int>;
//���ģ���Ĵ������⣬���ʹ���߿���û���廯�Ļ��ᣬ��δ�廯��ģ�嶨�岻�������Ŀ���ļ���
//��ʽ�廯��ģ�����ʾ�廯���캯��
//������Ա��������ʾ�廯��Ҳ�ɲ���ʾ�廯
//
//��ģ�����ʾ�ػ�
//ʹ���ض����ͻ�ֵ��ʽ�ػ���ģ�壬�Ѷ�����ģ����룬�磺template<>class A<char >{...};
//��ʽ�ػ��汾�����廯�汾
//��ʽ�ػ�����Ҫ����ԭʼģ����ͬ���ػ��汾���Ծ��в�ͬ�����ݳ�Ա���Ա����
//��ģ����Բ����ػ������������ģ�壬��֧����ģ��Ĳ��ֶ���
//��ģ���ȱʡģ�����
//�뺯��ģ����ͬ����ģ����Ծ���ȱʡģ�����


#include<stdlib.h>
#include<iostream>

using namespace std;

// �ն����쳣��
class EQueueEmpty{  };
// ��������ǰ������
template<typename T> class JuQueueItem;
// ������
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

// �������࣬��������ṹ
template<typename T> class JuQueueItem
{
    friend class JuQueue<T>;
public :
    JuQueueItem(const T &item) : _item(item), _next(0) { }
private :
    T _item;
    JuQueueItem<T> *_next;
};
// ��������������
template<typename T> JuQueue<T> :: ~JuQueue()
{
    while(!IsEmpty())
        Leave();
};
// ���
template <typename T> void JuQueue<T> :: Enter(const T &item)
{
    JuQueueItem<T> *p = new JuQueueItem<T>(item);
    if(IsEmpty()) _head = _tail = p;
    else _tail -> _next = p, _tail = p;
}
// ����
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
