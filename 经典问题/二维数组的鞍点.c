//�����ڸ���������ڸ�������С
/*#include<stdio.h>
#define N 4
#define M 5
void main()
{
    int i,j,k,a[N][M],max,maxj,flag;
    printf("�������飺\n");
    for(i=0; i<N; i++) //��������
        for(j=0; j<M; j++)
            scanf("%d",&a[i][j]);
    for(i=0; i<N; i++)
    {
        max=a[i][0];//��ʼʱ����a[i][0]���
        maxj=0;//���к�0��ֵ��maxj����
        for(j=0; j<M; j++) //�ҳ���i���е������
            if(a[i][j]>max)
            {
                max=a[i][j];//�����е������������max��
                maxj=j;//����������ڵ��кű�����maxj��
            }
        flag=1;//�ȼ����ǰ��㣬��flagΪ1����
        for(k=0; k<N; k++)
            if(max>a[k][maxj])//�����������ͬ��Ԫ�����
            {
                flag=0;//���max����ͬ����С����ʾ���ǰ��㣬��flag=0
                continue;
            }
        if(flag)//���flagΪ1��ʾ�ǰ���
        {
            printf("a[%d][%d]=%d\n",i,maxj,max);//�������ֵ�������к��к�
            break;
        }
    }
    if(!flag)//���flagΪ0��ʾ���㲻����
        printf("���������ڣ�");
}*/
#include<stdio.h>
void main()
{
    int i,j,a[4][5];
    int m=0,n=0,k,min,max;
    for(i=0; i<4; i++)
        for(j=0; j<5; j++)
            scanf("%d",&a[i][j]);
    for(i=0; i<4; i++)
    {
        max=a[i][0];
        for(j=1; j<5; j++)
            if(a[i][j]>max)
            {
                max=a[i][j];
                m=j;
            }
        for(k=1; k<4; k++)
        {
            min=a[0][m];
            if(a[k][m]<min)
                {
                    min=a[k][m];
                    n=k;
                }
        }
        if(max==min)
            {
                printf("������İ����ǵ�%d�е�%d�е�%d\n",n+1,m+1,max);
                break;
            }
    }
    if(i==4)
        printf("������û���ҵ�����\n");
}

