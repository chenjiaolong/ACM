#include <stdio.h>
#include <stdlib.h>

// ��Լ�ڴ棬���ܸ���ʼֵ
// �޷��к���
union u
{
    int num; // ���ܸ���ʼֵ
    double data;
    //! void go() {  } // �����к���
    void (*p)(); // �����к���ָ��
};
void go()
{

}

int main()
{
    return 0;
}
