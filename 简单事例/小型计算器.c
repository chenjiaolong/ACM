#include<stdio.h>
#include<conio.h>
void main()
{
    int m,n,option;
    printf("  *--------------------*\n");
    printf("  |   ��ѡ����������   |\n");
    printf("  |--------------------|\n");
    printf("  |      1.�ӷ�        |\n");
    printf("  |      2.����        |\n");
    printf("  |      3.�˷�        |\n");
    printf("  |      4.����        |\n");
    printf("  |      5.����        |\n");
    printf("  |      0.�˳�        |\n");
    printf("  *--------------------*\n");
    while(1)
    {
        printf("  ������ѡ��0~5����   \n");
        scanf("%d",&option);
        while(option<0||option>5)
        {
            printf("�Բ��𲻴������ѡ��������������룺\n");
            printf("  ������ѡ��0~5����   \n");
            scanf("%d",&option);
        }
        switch(option)
        {
        case 1:
            printf("����������������\n");
            scanf("%d%d",&m,&n);
            printf("%d+%d=%d\n",m,n,m+n);
            break;
        case 2:
            printf("����������������\n");
            scanf("%d%d",&m,&n);
            printf("%d-%d=%d\n",m,n,m-n);
            break;
        case 3:
            printf("����������������\n");
            scanf("%d%d",&m,&n);
            printf("%d*%d=%d\n",m,n,m*n);
            break;
        case 4:
            printf("����������������\n");
            scanf("%d%d",&m,&n);
            printf("%d/%d=%.2f\n",m,n,(float)m/n);
            break;
        case 5:
            printf("����������������\n");
            scanf("%d%d",&m,&n);
            printf("��������������Ϊ%d\n",m,n,m % n);
            break;
        case 0:
            return ;
        }
    }

}


