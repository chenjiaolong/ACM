//变量i正好和a[10]在内存中重叠。
//当i = 10的时候，a[10] = 10 -10 = 0,实际上就是将变量i的值修改成了0，这样循环变量始终就不会超过10而停止循环
#include<stdio.h>
int main()
{
    int a[10];
    for(int i = 0; i <= 10; i++)//越界
    {
        a[i] = 10 - i;
        printf("a[%d] = %d\n",i,a[i]);
    }
    return 0;
}
