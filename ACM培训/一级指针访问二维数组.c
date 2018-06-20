// 建立索引表
#include<stdio.h>
void inputArray(int *p,int m,int n)
{
    int i,j;
    printf("Input %d*%d array:\n",m,n);
    int num = m * n;
    for(i=0; i< num; i++)
        scanf("%d", p + i);
}
int FindMax(int *p, int m, int n, int *pRow, int *pCol)
{
    int i,j;
    int max=*p;
    int num = m *n;
    for(i=1; i< num; i++)
    {
        if(max < *(p + i))
        {
            max = *(p + i);
            *pRow = i / n;
            *pCol = i % n;
        }
    }
    return max;
}
int main()
{
    int m,n,j=0,k=0,max;
    printf("Input m,n:\n");
    scanf("%d,%d",&m,&n);
    int Array[m][n];
    inputArray(Array,m,n);
    max=FindMax(Array,m,n,&j,&k);
    printf("max=%d,row=%d,col=%d\n",max,j,k);
    int i;
    for(i = 0; i < m; i ++)
        for(j = 0; j < n; j ++)
            printf("%d%c", Array[i][j], j == n - 1? '\n' : ' ');
    return 0;
}

// 一维数组存储二维数组
//#include<stdio.h>
//void inputArray(int *p,int m,int n)
//{
//    int i,j;
//    printf("Input %d*%d array:\n",m,n);
//    for(i=0; i< m; i++)
//        for(j = 0; j < n; j ++)
//            scanf("%d", p + i * n + j);
//}
//int FindMax(int *p, int m, int n, int *pRow, int *pCol)
//{
//    int i,max,j;
//    max=p[0];
//    *pRow = 0;
//    *pCol = 0;
//    for(i=0; i<m; i++)
//    {
//        for(j=0; j<n; j++)
//        {
//            if(max < *(p + i * n + j))
//            {
//                *pRow=i;
//                *pCol=j;
//                max=*(p + i * n + j);
//            }
//
//        }
//    }
//    return max;
//}
//int main()
//{
//    int m,n,j=0,k=0,max;
//    printf("Input m,n:\n");
//    scanf("%d,%d",&m,&n);
//    int *p = (int *)calloc(m * n, sizeof(int));
//    inputArray(p,m,n);
//    max=FindMax(p,m,n,&j,&k);
//    printf("max=%d,row=%d,col=%d\n",max,j,k);
//    int i;
//    for(i = 0; i < m; i ++)
//        for(j = 0; j < n; j ++)
//            printf("%d%c", p[i * n + j], j == n - 1 ? '\n' : ' ');
//    return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//    int iArray[2][3] = {{1,2,3},{4,5,6}};
//    int *pArray = NULL;
//    pArray = iArray;
//    printf("array[0][0] = %d\n", *pArray);
//    printf("array[1][2] = %d\n", *(pArray + 1 * 3 + 2));
//    return 0;
//}
