//�������ļӷ�
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<stdbool.h>
//#include<cstring>
//#define MAX_LEN 200
//int an1[MAX_LEN+10];
//int an2[MAX_LEN+10];
//char szLine1[MAX_LEN+10];
//char szLine2[MAX_LEN+10];
//using namespace std;
//int main()
//{
//    scanf("%s",szLine1);
//    scanf("%s",szLine2);
//
//    //�⺯��memset����ַan1��ʼ��sizeof(an1)�ֽ������ó�0
//    //sizeof��an1����ֵ����an1�ĳ���
//    //memset������string.h������
//    memset(an1,0,sizeof(an1));
//    memset(an2,0,sizeof(an2));
//
//    //���潫szLine1�д洢���ַ����γɵ�����ת����an1��ȥ
//    //an1[0]��Ӧ�ڸ�λ
//    int nLen1=strlen(szLine1);
//    int j=0;
//    for(int i=nLen1-1; i>=0; i--)
//        an1[j++]=szLine1[i]-'0';
//
//    int nLen2=strlen(szLine2);
//    j=0;
//    for(int i=nLen2-1; i>=0; i--)
//        an2[j++]=szLine2[i]-'0';
//
//    for(int i=0; i<MAX_LEN; i++)
//    {
//        an1[i]+=an2[i];//�������
//        if(an1[i]>=10)//���Ƿ�Ҫ��λ
//        {
//            an1[i]-=10;
//            an1[i+1]++;//��λ
//        }
//    }
//    bool bStartOutput=false;//�˱����������������0
//    for(int i=MAX_LEN;i>=0;i--)
//    {
//        if(bStartOutput)
//            printf("%d",an1[i]);//��������0�Ѿ��������������
//        else if(an1[i])
//        {
//            printf("%d",an1[i]);
//            bStartOutput=true;//������һ����0��ֵ����˵�������0�Ѿ�����
//        }
//    }
//    return 0;
//}

//�������ĳ˷�
//#include<cstdio>
//#include<iostream>
//#include<algorithm>
//#include<stdbool.h>
//#include<cstring>
//#define MAX_LEN 200
//unsigned an1[MAX_LEN+10];
//unsigned an2[MAX_LEN+10];
//unsigned aResult[MAX_LEN*2+10];
//char szLine1[MAX_LEN+10];
//char szLine2[MAX_LEN+10];
//using namespace std;
//int main()
//{
//    gets(szLine1);//get������ȡһ��
//    gets(szLine2);
//
//    //�⺯��memset����ַan1��ʼ��sizeof(an1)�ֽ������ó�0
//    //sizeof��an1����ֵ����an1�ĳ���
//    //memset������string.h������
//    memset(an1,0,sizeof(an1));
//    memset(an2,0,sizeof(an2));
//
//    //���潫szLine1�д洢���ַ����γɵ�����ת����an1��ȥ
//    //an1[0]��Ӧ�ڸ�λ
//    int nLen1=strlen(szLine1);
//    int j=0;
//    for(int i=nLen1-1; i>=0; i--)
//        an1[j++]=szLine1[i]-'0';
//
//    int nLen2=strlen(szLine2);
//    j=0;
//    for(int i=nLen2-1; i>=0; i--)
//        an2[j++]=szLine2[i]-'0';
//
//    for(int i=0; i<nLen2; i++)//ÿһ�ֶ���an1��һλ��ȥan2��λ���
//                              //��an1�ĸ�λ��ʼ
//        for(j=0;j<nLen1;j++)//��ѡ����an1����һλ��ȥ��an2�ĸ�λ
//        aResult[i+j]+=an2[i]*an1[j];//������i��jλ��ˣ��ۼӵ�����ĵ�i+jλ
//    //�����ѭ��ͳһ�����λ����
//    for(int i=0;i<MAX_LEN*2;i++)
//        if(aResult[i]>=10)
//    {
//        aResult[i+1]+=aResult[i]/10;
//        aResult[i]%=10;
//    }
//    //����������
//    bool bStartOutput=false;//�˱����������������0
//    for(int i=MAX_LEN*2;i>=0;i--)
//    {
//        if(bStartOutput)
//            printf("%d",aResult[i]);//��������0�Ѿ��������������
//        else if(aResult[i])
//        {
//            printf("%d",aResult[i]);
//            bStartOutput=true;//������һ����0��ֵ����˵�������0�Ѿ�����
//        }
//    }
//    if(!bStartOutput)
//        printf("0");
//    return 0;
//}

//�������ĳ���
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stdbool.h>
#include<cstring>
#define MAX_LEN 200
int an1[MAX_LEN+10];//��������an1[0]��Ӧ�ڸ�λ
int an2[MAX_LEN+10];//������an2[0]��Ӧ�ڸ�λ
int aResult[MAX_LEN+10];//����̣�aResult[0]��Ӧ�ڸ�λ
char szLine1[MAX_LEN+10];
char szLine2[MAX_LEN+10];
using namespace std;
/*Substrcat����������ΪnLen1�Ĵ�����p1��ȥ����ΪnLen2�Ĵ�����p2
���Ľ�������p1�����ֵ�������ĳ���
�粻��������-1�����ü��귵��0
p1[0]��p2[0]�Ǹ�λ*/
int Substrcat(int *p1,int *p2,int nLen1,int nLen2)
{
    if(nLen1<nLen2)
        return -1;
    //�����ж�p1�Ƿ��p2��������ǣ�����-1
    bool bLarger=false;
    if(nLen1==nLen2)
    {
        for(int i=nLen1-1; i>=0; i--)
        {
            if(p1[i]>p2[i])
                bLarger=true;
            else if(p1[i]<p2[i])
                if(!bLarger)
                    return -1;
        }
    }
    for(int i=0; i<nLen1; i++) //������
    {
        p1[i]-=p2[i];//Ҫ����ñ�����ʱ���Ĳ�����ȷ����i>=nLen2ʱ��p2[i]=0
        if(p1[i]<0)
        {
            p1[i]+=10;
            p1[i+1]--;
        }
    }
    for(int i=nLen1-1; i>=0; i--)
        if(p1[i])
            return i+1;
    return 0;
}
int main()
{
    int n;
    char szBlank[20];
    scanf("%d",&n);
    for(int t=0; t<n; t++)
    {
        scanf("%s",szLine1);//get������ȡһ��
        scanf("%s",szLine2);

        //�⺯��memset����ַan1��ʼ��sizeof(an1)�ֽ������ó�0
        //sizeof��an1����ֵ����an1�ĳ���
        //memset������string.h������
        memset(an1,0,sizeof(an1));
        memset(an2,0,sizeof(an2));

        //���潫szLine1�д洢���ַ����γɵ�����ת����an1��ȥ
        //an1[0]��Ӧ�ڸ�λ
        int nLen1=strlen(szLine1);
        int j=0;
        for(int i=nLen1-1; i>=0; i--)
            an1[j++]=szLine1[i]-'0';

        int nLen2=strlen(szLine2);
        j=0;
        for(int i=nLen2-1; i>=0; i--)
            an2[j++]=szLine2[i]-'0';
        if(nLen1<nLen2)
        {
            printf("0\n");
            continue;
        }
        nLen1=Substrcat(an1,an2,nLen1,nLen2);
        if(nLen1<0)
        {
            printf("0\n");
            continue;
        }
        else if(nLen1==0)
        {
            printf("1\n");
            continue;
        }
        aResult[0]++;//����һ���ˣ��̼�1
        //����һ�κ�Ľ��������nLen1��
        int nTimes=nLen1-nLen2;
        if(nTimes<0)//����һ�κ�Ͳ����ټ���
            goto OutputResult;
        else if(nTimes>0)
            //��an2����10��ĳ���ݣ�ʹ�ý�����Ⱥ�an1��ͬ
        {
            for(int i=nLen1-1; i>=0; i--)
            {
                if(i>=nTimes)
                    an2[i]=an2[i-nTimes];
                else
                    an2[i]=0;
            }
        }
        nLen2=nLen1;
        for(int i=0; i<=nTimes; i++)
        {
            int nTmp;
            //һֱ����������Ϊֹ
            //�ȼ�ȥ���ɸ�an2*��10��nTimes�η���
            //�������ˣ��ټ�ȥ���ɸ�an2*��10��nTimes-1�η���������
            while((nTmp=Substrcat(an1,an2+i,nLen1,nLen2-i))>=0)
            {
                nLen1=nTmp;
                aResult[nTimes-i]++;//ÿ�ɹ���һ�Σ����̵���Ӧλ��1
            }
        }
OutputResult:
        //�����ѭ��ͳһ�����
        for(int i=0; i<MAX_LEN; i++)
            if(aResult[i]>=10)
            {
                aResult[i+1]+=aResult[i]/10;
                aResult[i]%=10;
            }
        //����������
        bool bStartOutput=false;//�˱����������������0
        for(int i=MAX_LEN; i>=0; i--)
        {
            if(bStartOutput)
                printf("%d",aResult[i]);//��������0�Ѿ��������������
            else if(aResult[i])
            {
                printf("%d",aResult[i]);
                bStartOutput=true;//������һ����0��ֵ����˵�������0�Ѿ�����
            }
        }
        if(!bStartOutput)
            printf("0");
        printf("\n");
    }
    return 0;
}
