#include<stdio.h>
#include<conio.h>
void main()
{
    int i=0,j=0,k=0,count=0,option;
    while(i+j+k!=20-count)
    {
        printf("������1~3������һ������");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            i++;
            break;
        case 2:
            j++;
            break;
        case 3:
            k++;
            break;
        default:
            count++;
        }
    }
    printf("1��ѡ������Ʊ%d\n",i);
    printf("2��ѡ������Ʊ%d\n",j);
    printf("3��ѡ������Ʊ%d\n",k);
}



