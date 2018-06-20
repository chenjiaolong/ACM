//int *ptr =（int *）(&a + 1);
//把数组看做一个整体的空间，在它的后面（动态分配）开辟一个新的空间，功能类似于malloc函数，这时ptr指向的是新开辟的数组空间的最后一位;
//而它ptr - 1 代表的把ptr指针往前移动一位，即为原本数组的最后一位！！！
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
