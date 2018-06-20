//s=（3）Σ（k=1）k
#include<stdio.h>
int main()
{
    int k = 1,s = 0;
loop:
    if(k <= 3)//loop为语句标号：用于定义程序中的某个位置，用标识符表示，不能只用数字
    {
        s = s + k;
        k++;
        printf("%d%c",k,k == 4?'\n':' ');
        goto loop;//goto+语句标号，容易破坏程序模块结构化，不提倡
    }
    printf("s = %d",s);
    return 0;
}

