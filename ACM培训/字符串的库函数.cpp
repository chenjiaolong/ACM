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
    printf("�ַ���a=%s\n�ַ���b=%s\n\n\n",a,b);
    printf("a�ַ��������д��ĸ��Ӧ1��Сд��ĸ��Ӧ-1:\n");
    for(i=0; i<strlen(a); i++)
        printf("%d ",pan(a[i]));
    printf("\n\n");
    printf("strcmp(a,b)��strcmp(b,a)�����:\n");
    printf("%d %d\n\n",strcmp(a,b),strcmp(b,a));
    printf("���룺strcat(a,b);\n��b�ַ���ƴ�ӵ�a�ַ�����������a��b�ַ���:\n");
    strcat(a,b);
    printf("a=%s\nb=%s\n\n",a,b);
    printf("���룺strncpy(a,b,4);\n��b�ַ�����ǰ�ĸ��ַ����Ƶ�a��Ӧ��λ�ú����a��b�ַ���:\n");
    strncpy(a,b,4);
    printf("a=%s\nb=%s\n\n",a,b);
    printf("���룺a[4]='/0';\n��a�ַ����±�Ϊ4���ַ���ֵΪ/0�����a��b�ַ���:\n");
    a[4]='\0';
    printf("a=%s\nb=%s\n\n",a,b);
    return 0;
}
