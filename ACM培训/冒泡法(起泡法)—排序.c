#include <stdio.h>
main()
{
    int a[10],i,j,t;
    printf("Please input 10 numbers: ");
    /*����Դ����*/
    for(i=0; i<10; i++)
        scanf("%d",&a[i]);
    /*����*/
    for(j=0; j<9; j++)   	/*��ѭ����������������n������n-1��*/
        for(i=0; i<9-j; i++)  	/*��ѭ��ÿ�˱ȽϵĴ�������j�˱Ƚ�n-j��*/
            if(a[i]>a[i+1])   	/*����Ԫ�رȽϣ������򽻻�*/
            {
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
    /*���������*/
    printf("The sorted numbers: ");
    for(i=0; i<10; i++)
        printf("%d   ",a[i]);
    printf("\n");
}

