#include <stdio.h>
int main()
{
    int a[10],i,j,t;
    printf("Please input 10 numbers: \n");
    for(i=0; i<10; i++)
        scanf("%d",&a[i]);
    for(i=1; i<10; i++)		/*��ѭ������������n�����ӵ�2������ʼ����󹲽���n-1�β���*/
    {
        t=a[i];    			/*�����������ݴ��ڱ���t��*/
        for( j=i-1 ; j>=0 && t>a[j] ; j-- ) 	/*���������У��±�0 ~ i-1����Ѱ�Ҳ���λ��*/
            a[j+1]=a[j]; 		/*��δ�ҵ�����λ�ã���ǰԪ�غ���һ��λ��*/
        a[j+1]=t; /*�ҵ�����λ�ã���ɲ���*/
    }
    printf("The sorted numbers: ",i);
    for(i=0; i<10; i++)
        printf("%d   ",a[i]);
    printf("\n");
    return 0;
}

