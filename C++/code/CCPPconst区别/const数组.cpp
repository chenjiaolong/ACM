#include <iostream>

using namespace std;

void run1(const int *p); // �ı��ַ�����ܸı�����
void run2(int const *p);
void run3(int *const p); // ���ı��ַ���ܸı�����
void run4(const int * const p);// ���ı��ַ�����ܸı�����
void run5(int const * const p);

int main()
{
    const int num[5]{1, 2, 3, 4, 5};
    const int *p = num;
    *(int *)p = 100;
    // const ����û���Ż������Լ�Ӹı�
    //! *(p + 2) = 1; // ָ������ָ�룬�޷��޸�
    for(auto i : num)
        cout << i << endl;
    return 0;
}
