//��200~300������������
#include<stdio.h>
int main()
{
    int x,i;
    for(x=200; x<=300; x++)
    {
        for(i=2; i<x; i++)
            if(x%i==0)
                break;
        if(i>=x&&x>1)
            printf("%d ������\n",x);
    }
    return 0;
}

