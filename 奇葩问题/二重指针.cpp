//int *ptr =��int *��(&a + 1);
//�����鿴��һ������Ŀռ䣬�����ĺ��棨��̬���䣩����һ���µĿռ䣬����������malloc��������ʱptrָ������¿��ٵ�����ռ�����һλ;
//����ptr - 1 ����İ�ptrָ����ǰ�ƶ�һλ����Ϊԭ����������һλ������
#include<stdio.h>
int main()
{
    int a[5] = {1,2,3,4,5};
    int *ptr = (int *)(&a+1);
    printf("a = %p, &a = %p, a+4=%p\n",a,&a,a+4);
    printf("a + 1 = %p,&a + 1 = %p\n",a + 1,&a + 1);
    printf("ptr = %p\n",ptr);
    printf("&a[0] = %p,&a[1] = %p,&a[4] = %p\n",&a[0],&a[1],&a[4]);
    printf("%d,%d\n",*(a+1),*(ptr - 1));
    printf("ptr - 1 = %p\n",ptr - 1);

    int b[10];
    for(int i=0; i<5; i++)
    {
        scanf("%d",b+i);
        printf("%d\n",*(b+i));
    }
    return 0;
}
