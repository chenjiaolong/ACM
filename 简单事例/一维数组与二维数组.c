#include<stdio.h>
#define MAX 5
int main()
{
    //一维数组初始化（赋值）
    /*int i;
    int math[MAX]={0,1,2,3,4};
    int english[MAX]={0,1,2,3,4};
    int computer[MAX]={0,1,2,3,4};
    int average[MAX];
    int max[3]={0,0,0};
    for(i=0;i<5;i++)
    {
        if(max[0]<math[i])
            max[0]=math[i];
        if(max[1]<english[i])
            max[1]=english[i];
        if(max[2]<computer[i])
            max[2]=computer[i];
    }
    printf("max[0]=%d,max[1]=%d,max[2]=%d\n",max[0],max[1],max[2]);
    for(i=0;i<5;i++)
    {
            average[i]=(math[i]+english[i]+computer[i])/3;
            printf("average%d=%d\n",i,average[i]);
    }*/
    //二维数组初始化（赋值）
    int scores[3][2];
    int i,j;
    scores[0][0]=95;
    scores[0][1]=98;
    scores[1][0]=97;
    scores[1][1]=99;
    scores[2][0]=100;
    scores[2][1]=99;
    int max[3]= {0,0,0};
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
            printf("%d\t",scores[i][j]);
        printf("\n");
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<2; j++)
            if(max[i]<scores[i][j])
                max[i]=scores[i][j];
        printf("max[ %d ] = %d\n",i,max[i]);

    }
}
