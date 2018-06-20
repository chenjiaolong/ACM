#include<stdio.h>
#include<string.h>
int pan(char a)
{
    if(a>='A'&&a<='Z') return 1;
    return -1;
}
int main()
{
    int i;
    char a[20]= {"VwXyZ"},b[20]= {"abcdefg"};
    printf("字符串a=%s\n字符串b=%s\n\n\n",a,b);
    printf("a字符串输出大写字母对应1，小写字母对应-1:\n");
    for(i=0; i<strlen(a); i++)
        printf("%d ",pan(a[i]));
    printf("\n\n");
    printf("strcmp(a,b)和strcmp(b,a)的输出:\n");
    printf("%d %d\n\n",strcmp(a,b),strcmp(b,a));
    printf("代码：strcat(a,b);\n将b字符串拼接到a字符串后面后，输出a、b字符串:\n");
    strcat(a,b);
    printf("a=%s\nb=%s\n\n",a,b);
    printf("代码：strncpy(a,b,4);\n将b字符串的前四个字符复制到a对应的位置后，输出a、b字符串:\n");
    strncpy(a,b,4);
    printf("a=%s\nb=%s\n\n",a,b);
    printf("代码：a[4]='/0';\n将a字符串下标为4的字符赋值为/0后，输出a、b字符串:\n");
    a[4]='\0';
    printf("a=%s\nb=%s\n\n",a,b);
    return 0;
}
