#include <iostream>

using namespace std;

// static_cast<type>(X)  static_cast��̬ת����<>Ҫת�������� () Ҫת��������, ��������ָ��
// reinterpret_cast<type *>(Y)����ָ��ת����C���ԣ�ָ��ֱ�Ӹ�ֵ


// ����
class A
{
public :
    int a;
    // �����麯������ʵ�ֶ�̬
    virtual void run()
    {
        cout << "A is running!" << endl;
    }
};
// ����
class B: public A
{
public :
    int b;
    void run()
    {
        cout << "B is playing!" << endl;
    }
};

int main()
{
    printf("%d\n", 10.2); // printf�����Զ�������������
    printf("%f\n", 1);

    cout << "---------" << endl;
    printf("%d\n", static_cast<int>(10.2)); // Ĭ��ת��
    printf("%f\n", static_cast<float>(1));

    cout << "---------" << endl;
    int *pint(new int(1));
    char *pch = reinterpret_cast<char *>(pint); // ָ�����͵�ת��
    for(int i = 0; i < 4; i ++)
        cout << static_cast<int>(*(pch + i)) << " " << reinterpret_cast<void *>(pch + i) << endl;

    cout << "---------" << endl;
    int num[5]{1, 2, 3, 4, 5};
    const int *p(num);
    //! pint = reinterpret_cast<int *>p; // reinterpret_cast��������const
    // �漰const,������const_cast
    pint = const_cast<int *>(p);
    for(int i = 0; i < 5; i ++)
        cout << pint[i] << " " << reinterpret_cast<void *>(pint + i) << endl;

    cout << "-----------" << endl;
    // ��̬
    A a;
    B b;
    A *px = &a;
    px -> run();
    px = &b;
    px -> run();

    cout << "-----------" << endl;
    A *pfa(new A);
    B *pson(new B); // ����һ����������Լ�����
    cout << reinterpret_cast<void *>(pfa) << endl;
    cout << reinterpret_cast<void *>(pson) << endl;
    pfa -> run();
    pson -> run();

    // dynamic_cast���ڰ�ȫ������ת�����������������������ƥ��ת��ʧ��Ϊnullptr
    // ֻ������ת����̬���������麯�����Ƕ�̬����
    A *pY = dynamic_cast<A *>(pson); // �������ת��Ϊ����ָ��
    cout << reinterpret_cast<void *>(pY) << endl;
    pY -> run();

    /* B *py = dynamic_cast<B *>(pfa); // ���԰��������ĵ�ַ���ݸ�����ָ�룬���ܰѸ�����󴫵ݸ�����ָ��
    cout << reinterpret_cast<void *>(py) << endl;
    if(py != nullptr) py -> run();*/

    //! ���Ƽ�
    B *py = reinterpret_cast<B *>(pfa);
    cout << reinterpret_cast<void *>(py) << endl;
    if(py != nullptr)
    {
        py -> a = 10; // ��������̳и������ı���
        py -> b = 10;

        py -> run();

        (*py).A :: run(); // �����м丸��ķ���
        (*py).B :: run();
    }

    return 0;
}
