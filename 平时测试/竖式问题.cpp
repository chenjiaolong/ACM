#include<stdio.h>
#include<string.h>
int main()
{
    char s[20];
    while(~scanf("%s",s))
    {
        int count = 0;
        char buffer[99];
        for(int abc = 111; abc <= 999; abc++)
            for(int de = 11; de <= 99; de++)
            {
                int x = abc * (de % 10),y = abc *(de / 10),z = abc * de;
                sprintf(buffer,"%d%d%d%d",abc,de,x,y,z);
                int ok = 1;
                for(int i = 0; i < strlen(buffer); i++)
                    if(strchr(s,buffer[i]) == NULL)//查找字符串s中首次出现字符buffer[i]的位置
                    {
                        ok = 0;
                        break;
                    }
                if(ok)
                {
                    printf("<%d>\n",++count);
                    printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z);
                }
            }
        printf("The numbers of solutions = %d \n",count);
    }
    return 0;
}
