//����д��ΪСд������ǷǴ�д��ĸ��ԭ�����,ֱ������'\0'�ͽ�����
#include<stdio.h>
#define MAX 100
int main()
{
    char ch[MAX];
    int i=0;
    scanf("%s",ch);
    for(i=0;ch[i]!='\0';i++)
        if(ch[i]>='A'&&ch[i]<='Z')
        {
            ch[i]=ch[i]+32;
            printf("%c",ch[i]);
        }
        else
            printf("%c",ch[i]);
    return 0;
}
